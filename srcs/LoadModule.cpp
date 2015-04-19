/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 15:22:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoadModule.hpp"
#include "Core.hpp"

LoadModule::LoadModule(Core *core)
	: _core(core)
{
}

LoadModule::~LoadModule(void)
{
}

const char			*LoadModule::getName(void) const
{
	return ("CPU Activity");
}

int					LoadModule::getHeight(void) const
{
	return (8);
}

void				LoadModule::refresh(void)
{
}

void				LoadModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().cpuLoad;
	size_t				len;

	display->print(10, y + 1, "Load average:", F_CENTER);
	display->print(-1, y + 2, str, F_CENTER);
	str = _core->getStats().cpuUsage;
	display->print(10, y + 1, "Usage:", F_CENTER);
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
}
