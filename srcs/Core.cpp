/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:52:58 by jaguillo         ###   ########.fr       */
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
		it++;
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
		(*it)->refresh(*this);
		it++;
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

void					Core::loadModule(IMonitorModule *module)
{
	if (module)
	{
		this->_modules.push_back(module);
	}
}

void					Core::loadDisplay(IMonitorDisplay *display)
{
	if (display)
	{
		this->_displays.push_back(display);
	}
}

void					Core::removeModule(std::string const & moduleName)
{
	std::vector<IMonitorModule *>::const_iterator			it;

	it = this->_modules.begin();
	while (it != this->_modules.end())
	{
		if ((*it)->getName() == moduleName)
		{
			this->_modules.erase(it);
		}
		++it;
	}
}

void					Core::removeDisplay(std::string const & displayName)
{
	std::vector<IMonitorDisplay *>::const_iterator			it;

	it = this->_displays.begin();
	while (it != this->_displays.end())
	{
		if ((*it)->getName() == displayName)
		{
			this->_displays.erase(it);
		}
		++it;
	}
}
