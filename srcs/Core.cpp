/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:03:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Core.hpp"
#include "NCursesDisplay.hpp"
#include <unistd.h>

Core::Core(void)
{
}

Core::~Core(void)
{
	NCursesDisplay::deinit();
}

void							Core::start(void) throw (std::runtime_error)
{
	while (1)
	{
		_refresh();
		_update();
		if (_displays.size() <= 0 || _modules.size() <= 0)
			throw std::runtime_error("Nothing to display");
		_display();
		sleep(1);
	}
}

void							Core::loadModule(IMonitorModule *module)
{
	if (module != NULL)
		_modules.push_back(module);
}

void							Core::loadDisplay(IMonitorDisplay *display)
{
	if (display != NULL)
		_displays.push_back(display);
}

void							Core::removeModule(std::string const & moduleName)
{
	std::vector<IMonitorModule *>::const_iterator			it;

	it = _modules.begin();
	while (it != _modules.end())
	{
		if ((*it)->getName() == moduleName)
		{
			_modules.erase(it);
			return ;
		}
		++it;
	}
}

void							Core::removeDisplay(std::string const & displayName)
{
	std::vector<IMonitorDisplay *>::const_iterator			it;

	it = _displays.begin();
	while (it != _displays.end())
	{
		if ((*it)->getName() == displayName)
			_displays.erase(it);
		++it;
	}
}

std::vector<IMonitorModule*>	&Core::getModules(void)
{
	return (_modules);
}

void							Core::_update(void)
{
	std::cerr << "Updating displays ..." << std::endl;
	std::vector<IMonitorDisplay *>::const_iterator		it;

	it = _displays.begin();
	while (it != _displays.end())
	{
		if (!(*it)->update())
		{
			_displays.erase(it);
			_update();
			return ;
		}
		++it;
	}
}

void							Core::_refresh(void)
{
	std::cerr << "Refreshing modules ..." << std::endl;
	std::vector<IMonitorModule *>::const_iterator		it;

	it = _modules.begin();
	while (it != _modules.end())
	{
		std::cerr << "Refreshing [" << (*it)->getName() << "]" << std::endl;
		(*it)->refresh();
		++it;
	}
}

void							Core::_display(void)
{
	std::vector<IMonitorDisplay *>::const_iterator		it;

	std::cerr << "Displaying modules ..." << std::endl;
	it = _displays.begin();
	while (it != _displays.end())
	{
		std::cerr << "Displaying on [" << (*it)->getName() << "]" << std::endl;
		(*it)->display();
		++it;
	}
}
