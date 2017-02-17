#include <iostream>	//std::cout, std::endl, std::cin, std::getline
#include <cstring>	//std::strtok, std::strstr
// #include <string>
#include <vector>		//std::vector
#include <algorithm>	//std::find_first_not_of, std::find_first_of, std::find_last_not_of
#include <stdexcept>
#include "header/Base.h"

void parse(const std::string&, std::vector<Base*>&);
void Tokenize(const std::string&, std::vector<std::string>&, const std::string&);
void Tokenize2(const std::string&, std::vector<std::string>&);
void Tokenize3(const std::string&, std::vector<std::string>&);
std::string trim(const std::string&);	//Strips leading and trailing whitespace

int main() {
	while(1) {
		Base* root;
		std::string input;

		std::cout << "$ ";
		std::getline(std::cin, input);
		input = trim(input);

		try{
			root = parse(input);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void parse(const std::string& str) {
	Base* root;
	std::vector<std::string> tokens;
	std::string delimiters1 = ";";
	std::string delimiters2 = "&&";
	std::string delimiters3 = "||";

	Tokenize2(str, tokens);
	createTree(tokens);


	// Tokenize(str, tokens, delimiters1);
	// for (auto& s : tokens) {
	// 	s = trim(s);
	// 	std::cout << s << std::endl;
	// }
	// Tokenize(str, tokens, delimiters2);
	// for (auto& s : tokens) {
	// 	s = trim(s);
	// 	std::cout << s << std::endl;
	// }
	// Tokenize(str, tokens, delimiters3);
	// for (auto& s : tokens) {
	// 	s = trim(s);
	// 	std::cout << s << std::endl;
	// }

	parsedTokens = v;
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

std::string trim(const std::string& str) {
    const std::string& whitespace = " \t\n";
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
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
		if (a.find('&') == 0 || a.find('|') == 0) {
			throw std::runtime_error("Tokenize2: Error, invalid syntax2");
		}
		std::cout << a << std::endl;
	}
}