#include <iostream>	//std::cout, std::endl, std::cin, std::getline
#include <cstring>
#include <vector>		//std::vector
#include <list>
#include <algorithm>	//std::find_first_not_of, std::find_first_of, std::find_last_not_of
#include <stdexcept>
#include "../header/Cmd.h"
#include "../header/Semicolon.h"
#include "../header/And.h"
#include "../header/Or.h"

Base* parse(const std::string&);
void Tokenize(const std::string&, std::vector<std::string>&);
const std::string trim(const std::string&);	//Strips leading and trailing whitespace
Base* createTree(const std::vector<std::string>&);
Base* _createTree(std::string);
std::string clearCommentedCode(const std::string&);

int main() {
	while(1) {
		Base* root;
		std::string input;

		char host[100];
      char login[100];
      gethostname(host, 100);
      getlogin_r(login, 100);
     
      std::cout << login << "@" << host<< "$ ";
     
	   std::getline(std::cin, input);
		if (input.find_first_not_of(" ") == std::string::npos) {  // check if empty of valid characters
		   continue;
		}
   	try {
			root = parse(input);
			root->execute();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

Base* parse(const std::string& str) { 
	std::string strcp = str;
	Base* root;
	std::vector<std::string> tokens;

   strcp = clearCommentedCode(strcp);
   strcp = trim(strcp);
	tokens = Tokenize(strcp);  // Separate string into 'lines' of commands 
	                           // lines are separated by ;
	                           
	root = createTree(tokens); // Create parsing tree

	return root;
}

const std::string trim(const std::string& str) {
	std::string strcp = str;
	
   size_t found = strcp.find("  ");
   while (found != std::string::npos) { // Remove multiple whitespaces
		strcp.replace(found, 2, " ");
		found = strcp.find("  ");
	}
    return strcp;
}

std::vector<std::string>& Tokenize(const std::string& str)
{
	std::vector<std::string> tokens;
	size_t startPos = 0;
	std::string validCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~-`\'\"!#()[]_";
	
	for (size_t i = 0; i < str.size(); ++i) {
		if (str.at(i) == ';') {
			if (i == 0 || 
				 str.find_first_of(";|&", startPos) <= str.find_first_of(validCharacters, startPos)) {
				throw std::runtime_error("from Tokenize: Error, invalid syntax1");
			}
			tokens.push_back(str.substr(startPos, i - startPos));
			startPos = i + 1;
		}
		else if (i == str.size() - 1) {
			tokens.push_back(str.substr(startPos, i - startPos + 1));
		}
	}
	
	for (auto& a : tokens) {   // Validate syntax
		for (size_t i = 0; i < a.size(); ++i) {
		   
			if (a.at(i) == '&') {   // Connectors should always be in pairs
				if (i + 1 < a.size() && a.at(i + 1) != '&') {
					throw std::runtime_error("from Tokenize: Error, invalid syntax2");
				}
				++i;
			}
			if (a.at(i) == '|') {
				if (i + 1 < a.size() && a.at(i + 1) != '|') {
					throw std::runtime_error("from Tokenize: Error, invalid syntax3");
				}
				++i;
			}
		}
		if (a.find('&') == 0 || a.find('|') == 0) {  // Connectors should never be the first character
			throw std::runtime_error("from Tokenize: Error, invalid syntax4");
		}
	}
	//TODO: Validate brackets and parentheses
	return tokens;
}

Base* createTree(const std::vector<std::string>& tokens) {
	std::list<std::string> tokensList(tokens.begin(), tokens.end());
	
	if (tokens.size() == 0) {
		throw std::logic_error("from createTree: Error, createTree must be passed at least one token.");
	}
	if (tokens.size() == 1) {
		return _createTree(tokensList.front());
	}
	
	Base* tempNode = NULL;
	
	while (!tokensList.empty()) {
		if (tempNode) {	// leftNode already made from last iteration
			Base* rightNode = _createTree(tokensList.front());
			Base* newSemicolon = new Semicolon(tempNode, rightNode);
			tempNode = newSemicolon;
			tokensList.pop_front();
		}
		else {
			Base* leftNode = _createTree(tokensList.front());
			tokensList.pop_front();	// Get rid of tokens that we already processed
			Base* rightNode = _createTree(tokensList.front());
			tokensList.pop_front();
			Base* newSemicolon = new Semicolon(leftNode, rightNode);
			tempNode = newSemicolon;
		}
	}
	return tempNode;
}

Base* _createTree(std::string s) {
	Base* newNode = NULL;

	size_t found = s.find_last_of("])");
	if (found != std::string::npos) {	// 
		
	}
	
   found = s.find_last_of("&|");
		
	if (found == std::string::npos) {	// No connectors
		newNode = new Cmd(s);
		return newNode;
	}

	if (s.at(found) == '&') {
	   newNode = new And(_createTree(s.substr(0, found - 2)), new Cmd(s.substr(found + 1, s.size() - 1)));
	}
	else if (s.at(found) == '|') {
		newNode = new Or(_createTree(s.substr(0, found - 2)), new Cmd(s.substr(found + 1, s.size() - 1)));
	}
	else {
		throw std::logic_error("_createTree: Error, found character other than connector");
	}
	
	return newNode;
}

std::string clearCommentedCode(const std::string& input) {
   std::string output = input;
   if (input.find('#') != std::string::npos) {  // Truncate string if comments exist
      if (input.find('#') == 0) {
         output.clear();
      }
      else {
         output = input.substr(0, input.find('#'));
      }
   }
   return output;
}
