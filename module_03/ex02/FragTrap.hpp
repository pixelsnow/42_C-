/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:09 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 20:38:46 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "colours.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string newName);
	FragTrap(const FragTrap &source);
	~FragTrap(void);

	FragTrap &operator=(const FragTrap &source);

	void highFivesGuys(void) const;
};

#endif