/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 15:28:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Core.hpp"

Core::Core(void)
{
}

Core::~Core(void)
{
}

void					Core::refreshModules(void)
{
	std::cerr << "Refreshing modules ..." << std::endl;
	std::vector<IMonitorModule *>::const_iterator		it;

	it = this->_modules.begin();
	while (it != this->_modules.end())
	{
		std::cerr << "Refreshing [" << (*it)->getName() << "]" << std::endl;
		(*it)->refresh(*this);
		++it;
	}
}

void					Core::displayModules(void)
{
	std::vector<IMonitorDisplay *>::const_iterator		it;

	std::cerr << "Displaying modules ..." << std::endl;
	it = this->_displays.begin();
	while (it != this->_displays.end())
	{
		std::cerr << "Displaying on [" << (*it)->getName() << "]" << std::endl;
		(*it)->display(*this);
		++it;
	}
}

void					Core::start(void)
{
	while (1)
	{
		this->refreshModules();
		this->displayModules();
	}
}
