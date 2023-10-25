/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:05:36 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:03 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#define SUCCESS 0
#define ARG_NUM_ERROR 1
#define IN_FILE_OPEN_ERROR 2
#define OUT_FILE_OPEN_ERROR 2
#define EMPTY_S1_ERROR 3

#include <fstream>

class Replacer
{
private:
	bool filenameValid(std::string filename) const;
	bool s1Valid(std::string s1) const;

public:
	Replacer(void);
	~Replacer(void);

	int go(std::string filename, std::string s1, std::string s2);
};

#endif