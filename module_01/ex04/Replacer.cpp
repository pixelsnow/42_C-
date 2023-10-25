/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:34 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 17:47:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(void) {}

Replacer::~Replacer(void) {}

int Replacer::go(std::string filename, std::string s1, std::string s2)
{
	// std::fstream inStream;
	std::fstream outStream;
	std::string content;

	(void)s1;
	(void)s2;
	if (!filenameValid(filename))
		return (IN_FILE_OPEN_ERROR);
	if (!s1Valid(s1))
		return (EMPTY_S1_ERROR);

	std::ifstream inStream(filename);
	if (!inStream.is_open())
		return (IN_FILE_OPEN_ERROR);
	content << t.rdbuf();

	/* inStream.open(filename, std::fstream::in);
	if (!inStream.is_open())
		return (IN_FILE_OPEN_ERROR); */
	outStream.open(filename.append(".replace"), std::fstream::out);
	if (!outStream.is_open())
	{
		inStream.close();
		return (OUT_FILE_OPEN_ERROR);
	}
	// std::getline(inStream, content);
	outStream << content;
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