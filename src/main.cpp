#include <iostream>	//std::cout, std::endl, std::cin, std::getline
#include <cstring>	//std::strtok, std::strstr
#include <vector>		//std::vector
#include <list>
#include <algorithm>	//std::find_first_not_of, std::find_first_of, std::find_last_not_of
#include <stdexcept>
#include "../header/Cmd.h"
#include "../header/Semicolon.h"
#include "../header/And.h"
#include "../header/Or.h"

Base* parse(const std::string&);
void Tokenize(const std::string&, std::vector<std::string>&, const std::string&);
void Tokenize2(const std::string&, std::vector<std::string>&);
void Tokenize3(const std::string&, std::vector<std::string>&);
const std::string trim(const std::string&);	//Strips leading and trailing whitespace
Base* createTree(const std::vector<std::string>&);
Base* _createTree(std::string);

int main() {
	while(1) {
		Base* root;
		std::string input;

		std::cout << "$ ";
		std::getline(std::cin, input);
		input = trim(input);

		try{
			root = parse(input);
			root->execute();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

Base* parse(const std::string& str) {
	Base* root;
	std::vector<std::string> tokens;

	Tokenize2(str, tokens);
	root = createTree(tokens);

	return root;
}

// void Tokenize(const std::string& str,
//               std::vector<std::string>& tokens,
//               const std::string& delimiters)
// {
//     // Skip delimiters at beginning.
//     std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
//     // Find first "non-delimiter".
//     char* pos     = std::strstr(str.c_str(), delimiters.c_str());

//     str = str.substr(str.find((std::string)pos), );

//     while (pos != NULL || std::string::npos != lastPos)
//     {
//         // Found a token, add it to the vector.
//         tokens.push_back(str.substr(lastPos, pos - lastPos));
//         // Skip delimiters.  Note the "not_of"
//         lastPos = str.find_first_not_of(delimiters, pos);
//         // Find next "non-delimiter"
//         pos = str.find_first_of(delimiters, lastPos);
//     }
// }

const std::string trim(const std::string& str) {
	std::string strcp = str;
   // const std::string& whitespace = " \t\n";
   // const auto strBegin = str.find_first_not_of(whitespace);
   // if (strBegin == std::string::npos)
   //      return ""; // no content

   // const auto strEnd = str.find_last_not_of(whitespace);
   // const auto strRange = strEnd - strBegin + 1;

   // strcp = str.substr(strBegin, strRange);

   size_t found = strcp.find("  ");
   while (found != std::string::npos) { // Remove multiple whitespaces
		strcp.replace(found, 2, " ");
		found = strcp.find("  ");
	}
    return strcp;
}

void Tokenize2(const std::string& str,
              std::vector<std::string>& tokens)
{
	size_t startPos = 0;
	std::string validCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~-`\'\"!#()";
	for (size_t i = 0; i < str.size(); ++i) {
		if (str.at(i) == ';') {
			// std::cout << "i: " << i << std::endl;
			// std::cout << "startPos: " << startPos << std::endl;
			// std::cout << str.find_first_of(";|&", startPos) << std::endl;
			// std::cout << str.find_first_of(validCharacters, startPos) << std::endl;
			if (i == 0 || 
				 str.find_first_of(";|&", startPos) <= str.find_first_of(validCharacters, startPos)) {
				throw std::runtime_error("Tokenize2: Error, invalid syntax1");
			}
			tokens.push_back(str.substr(startPos, i - startPos));
			startPos = i + 1;
		}
		else if (i == str.size() - 1) {
			tokens.push_back(str.substr(startPos, i - startPos + 1));
		}
	}
	for (auto& a : tokens) {
		a = trim(a);
		for (size_t i = 0; i < a.size(); ++i) {
			if (a.at(i) == '&') {
				if (i + 1 < a.size() && a.at(i + 1) != '&') {
					throw std::runtime_error("Tokenize2: Error, invalid syntax2");
				}
				++i;
			}
			if (a.at(i) == '|') {
				if (i + 1 < a.size() && a.at(i + 1) != '|') {
					throw std::runtime_error("Tokenize2: Error, invalid syntax3");
				}
				++i;
			}
		}
		if (a.find('&') == 0 || a.find('|') == 0) {
			throw std::runtime_error("Tokenize2: Error, invalid syntax4");
		}
		// if (a.find('&') != std::string::npos) {
		// 	if (a.at(a.find('&')))
		// }
		// std::cout << a << std::endl;
	}
}

Base* createTree(const std::vector<std::string>& tokens) {
	std::list<std::string> tokensList(tokens.begin(), tokens.end());
	
	if (tokens.size() == 0) {
		throw std::logic_error("createTree: Error, createTree must be passed at least one token.");
	}
	if (tokens.size() == 1) {
		return _createTree(tokensList.front());
	}
	else {
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
}

// Base* _createTree(std::string s) {
// 	Base* tempNode = NULL;
// 	s = trim(s);
// 	size_t found = s.find_last_of("&|");
		
// 	if (found == std::string::npos) {	// No connectors
// 		tempNode = new Cmd(s);
// 		return tempNode;
// 	}

// 	// while (found != std::string::npos) {	// Create tree until no more connectors found
// 		size_t beginIndex;
// 		// size_t nextConnectorPos = s.find_last_of("&|", found - 2);	// find pos of the next connector to the left
		
// 		if (found == std::string::npos) {		// If there are no more connectors, set beginIndex to 0
// 			beginIndex = 0;
// 			if (s.at(found) == '&') {
// 				newNode = And(_createTree(s.substr(0, found - 1)), new Cmd(s.substr(beginIndex, found - 1)));
// 			}
// 			else if (s.at(found) == '|') {
// 				newNode = Or(_createTree(s.substr(0, found - 1)), new Cmd(s.substr(beginIndex, found - 1)));
// 			}
// 			else {
// 				throw std::logic_error("_createTree: Error, found character other than connector");
// 			}
// 		}
// 		else {														// Else, set beginIndex to index right after next found connector;
// 			beginIndex = nextConnectorPos + 1;
// 			if (s.at(found) == '&') {
// 				newNode = And(new Cmd(s.substr(beginIndex, found - 1)), _createTree(s.substr(beginIndex, )));
// 			}
// 			else if (s.at(found) == '|') {
// 				newNode = Or(_createTree(s.substr(0, found - 1)), new Cmd(s.substr(beginIndex, found - 1)));
// 			}
// 			else {
// 				throw std::logic_error("_createTree: Error, found character other than connector");
// 			}
// 		}
		
		
// 		tempNode = _createTree();
		
// 		found = nextConnectorPos;			// Update found for next iteration
// 	// }
// 	return tempNode;
// }

// Base* _createTree(std::string s) {
// 	Base* newNode = NULL;
// 	s = trim(s);
// 	size_t found = s.find_first_of("&|");
		
// 	if (found == std::string::npos) {	// No connectors
// 		newNode = new Cmd(s);
// 		return newNode;
// 	}

// 	if (s.at(found) == '&') {
// 	   newNode = new And(new Cmd(s.substr(0, found - 1)), _createTree(s.substr(found + 2, s.size() - 1)));
// 	}
// 	else if (s.at(found) == '|') {
// 		newNode = new Or(new Cmd(s.substr(0, found - 1)), _createTree(s.substr(found + 2, s.size() - 1)));
// 	}
// 	else {
// 		throw std::logic_error("_createTree: Error, found character other than connector");
// 	}
	
// 	return newNode;
// }

Base* _createTree(std::string s) {
	Base* newNode = NULL;
	s = trim(s);
	size_t found = s.find_last_of("&|");
		
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