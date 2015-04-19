/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 15:47:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Core.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "NCursesDisplay.hpp"
#include <unistd.h>
#include <cstdlib>

Core::Core(void)
{
}

Core::~Core(void)
{
	NCursesDisplay::deinit();
}

void							Core::start(void) throw (std::runtime_error)
{
	clock_t							lastUpdate;

	lastUpdate = -CLOCKS_PER_SEC;
	while (1)
	{
		while ((clock() - lastUpdate) < CLOCKS_PER_SEC)
			;
		lastUpdate = clock();
		_refresh();
		_update();
		if (_displays.size() <= 0 || _modules.size() <= 0)
			throw std::runtime_error("Nothing to display");
		_display();
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
	std::vector<IMonitorModule*>::const_iterator	it;

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
	std::vector<IMonitorDisplay*>::const_iterator	it;

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

Stats const						&Core::getStats(void) const
{
	return (_stats);
}

void							Core::_update(void)
{
	std::vector<IMonitorDisplay*>::const_iterator	it;

	_stats.update();
	it = _displays.begin();
	while (it != _displays.end())
	{
		if (!(*it)->update())
		{
			delete *it;
			_displays.erase(it);
			_update();
			return ;
		}
		++it;
	}
}

void							Core::_refresh(void)
{
	std::vector<IMonitorModule *>::const_iterator		it;

	it = _modules.begin();
	while (it != _modules.end())
	{
		(*it)->refresh();
		++it;
	}
}

void							Core::_display(void)
{
	std::vector<IMonitorDisplay *>::const_iterator		it;

	it = _displays.begin();
	while (it != _displays.end())
	{
		(*it)->display();
		++it;
	}
}
