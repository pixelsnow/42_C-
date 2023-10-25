/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:34 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 18:59:01 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(void) {}

Replacer::~Replacer(void) {}

int Replacer::go(std::string filename, std::string s1, std::string s2)
{
	std::ifstream inStream;
	std::ofstream outStream;
	std::stringstream buffer;
	std::string content;

	// Catch basic arg errors
	if (!filenameValid(filename))
		return (IN_FILE_OPEN_ERROR);
	if (!s1Valid(s1))
		return (EMPTY_S1_ERROR);

	// Open files and catch errors
	inStream.open(filename, std::ifstream::in);
	if (!inStream.is_open())
		return (IN_FILE_OPEN_ERROR);

	outStream.open(filename.append(".replace"), std::fstream::out);
	if (!outStream.is_open())
	{
		inStream.close();
		return (OUT_FILE_OPEN_ERROR);
	}

	// Get content of input file into a string
	buffer << inStream.rdbuf();
	content = buffer.str();

	// Modify the string, replacing s1 with s2
	replaceInString(content, s1, s2);

	// Write result to *.replace file
	outStream << content;

	// Close files and exit
	inStream.close();
	outStream.close();
	return (SUCCESS);
}

bool Replacer::filenameValid(std::string filename) const
{
	return (filename.length());
}

bool Replacer::s1Valid(std::string s1) const
{
	return (s1.length());
}

void Replacer::replaceInString(std::string &str, std::string s1, std::string s2)
{

	std::string::size_type found = 0;

	// std::cout << "BEFORE: " << str << std::endl;

	while (42)
	{
		found = str.find(s1, found);
		if (found == std::string::npos)
			break;
		// std::cout << "FOUND: " << found << std::endl;
		str.erase(found, s1.length());
		// std::cout << "ERASED: " << str << std::endl;
		str.insert(found, s2, 0, s2.length());
		// std::cout << "INSERTED: " << str << std::endl;
		found += s2.length();
		// std::cout << "NEW START: " << start << std::endl;
	}
	// std::cout << "AFTER: " << str << std::endl;
}