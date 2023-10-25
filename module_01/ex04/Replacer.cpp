/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:34 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 19:16:02 by vvagapov         ###   ########.fr       */
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

	// Open both files and catch errors
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

// Modifies string str by replacing every occurence of s1 with s2
void Replacer::replaceInString(std::string &str, std::string s1, std::string s2)
{
	std::string::size_type position = 0;

	while (42)
	{
		position = str.find(s1, position);
		if (position == std::string::npos)
			break;
		str.erase(position, s1.length());
		str.insert(position, s2, 0, s2.length());
		position += s2.length();
	}
}