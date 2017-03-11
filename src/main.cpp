#include <iostream>	//std::cout, std::endl, std::cin, std::getline
#include <cstring>
#include <vector>		//std::vector
#include <list>
#include <queue>
#include <algorithm>	//std::find_first_not_of, std::find_first_of, std::find_last_not_of
#include <stdexcept>
#include "../header/Cmd.h"
#include "../header/Semicolon.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Parentheses.h"

Base* parse(const std::string&);
void Tokenize(const std::string&, std::vector<std::string>&);
std::vector<std::string> Tokenize(const std::string& str);
const std::string trim(const std::string&);	//Strips leading and trailing whitespace
Base* createTree(const std::vector<std::string>&);
Base* _createTree(std::string);
std::string clearCommentedCode(const std::string&);
Base* _createTree2(const std::string&, const int&); 
std::string trimParens(const std::string);

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
    std::queue<size_t> temp;
    
    size_t found = strcp.find("\"");
    while (found != std::string::npos){
        temp.push(found);
        found = strcp.find("\"",found+1);
        if(found != std::string::npos){
            temp.push(found);
            found = strcp.find("\"",found+1);
        }
    }
    
    int num_changed = 0;
   found = strcp.find("  ");
   while (found != std::string::npos) { // Remove multiple whitespaces
		if(temp.size() > 1){
		    if(found > (temp.front() - num_changed)){
                temp.pop();
		        found = strcp.find("  ", temp.front() - num_changed);
		        temp.pop();
		    }else{
		        strcp.replace(found, 2, " ");
		        found = strcp.find("  ", found);
		        num_changed++;
		    }
		}else{
		    strcp.replace(found, 2, " ");
		    found = strcp.find("  ", found);
		    num_changed++;
		}
	}
    return strcp;
}

std::vector<std::string> Tokenize(const std::string& str)
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
			tempNode = new Semicolon(tempNode, rightNode);
			tokensList.pop_front();
		}
		else {
			Base* leftNode = _createTree(tokensList.front());
			tokensList.pop_front();	// Get rid of tokens that we already processed
			Base* rightNode = _createTree(tokensList.front());
			tokensList.pop_front();
			tempNode = new Semicolon(leftNode, rightNode);
		}
	}
	return tempNode;
}

// Base* _createTree(std::string s) {
// 	Base* newNode = NULL;
// 	Base* insertNode = NULL;
	
//    size_t found = s.find_last_of("&|");
		
// 	if (found == std::string::npos) {	// Base case: No connectors
// 		newNode = new Cmd(s);
// 		return newNode;
// 	}

// 	if (s.at(found) == '&') {
// 	   newNode = new And(_createTree(s.substr(0, found - 2)), _createTree(s.substr(found + 1, s.size() - 1)));
// 	}
// 	else if (s.at(found) == '|') {
// 		newNode = new Or(_createTree(s.substr(0, found - 2)), _createTree(s.substr(found + 1, s.size() - 1)));
// 	}
// 	else {
// 		throw std::logic_error("_createTree: Error, found character other than connector");
// 	}
	
	
	
// 	while (found != std::string::npos) {
// 	   size_t nextFound = s.substr(found + 2, s.size() - 1).find_first_of("&|");
// 	   if (nextFound != std::string::npos) {
//    	   left = _createTree(s.substr(0, found - 1));
//    	   right = _createTree(s.substr(found + 2, nextFound))
// 	   }
// 	   else {
// 	      left = 
// 	   }
// 	   found = s.substr(found + 2, s.size() - 1).find_first_of("&|");
// 	}
	
// 	return newNode;
// }

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

std::string trimParens(const std::string s) {
   std::string strCpy = s;
   
   while (strCpy.at(0) == ' ') {    // Remove leading and trailing whitespace
      strCpy = strCpy.substr(1, strCpy.size() - 1);
   }
   while (strCpy.at(strCpy.size() - 1) == ' ') {
      strCpy = strCpy.substr(0, strCpy.size() - 2);
   }
   
   while (strCpy.at(strCpy.find_first_not_of(" ")) == '(' && strCpy.at(strCpy.find_last_not_of(" ")) == ')' ) {
      int numParens = 0;
      for (unsigned i = 0; i < strCpy.size(); i++) {
         if (strCpy.at(i) == '(') {
            numParens++;
         }
         if (strCpy.at(i) == ')') {
            numParens--;
         }
         if (numParens == 0 && i < strCpy.size() - 1) {
            std::cout << "if\n";
            return strCpy;
         }
      }
      strCpy = strCpy.substr(strCpy.find("(") + 1, strCpy.find_last_of(")") - 1);
   }
   return strCpy;
}

Base* _createTree(std::string s) {
   s = trimParens(s);
   
   if (s.find_first_of("&|") == std::string::npos) {  // Base Case: no connectors
      return new Cmd(s);
   }
   
   int found = -1;

   int numParens = 0;
   for (size_t i = 0; i < s.size(); i++) {
      if (s.at(i) == '(') {
         numParens++;
      }
      if (s.at(i) == ')') {
         numParens--;
      }
   
      if (numParens == 0) {
         if (s.at(i) == '&' || s.at(i) == '|') {
            found = i;
            i++;
         }
      }
   }
   return _createTree2(s, found);
}

Base* _createTree2(const std::string& s, const int& found) {
   std::string strRight;
   
   if (found == -1) {
      throw std::logic_error("from _createTree2: Error, did not find connector.");
   }
   
   strRight = s.substr(found + 2, s.size() - 1);
   
   if (s.at(found) == '|') {
      return new Or(_createTree(s.substr(0, found - 1)), _createTree(strRight));
   }
   else {
      return new And(_createTree(s.substr(0, found - 1)), _createTree(strRight));
   }
}