/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 16:47:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MemModule.hpp"
#include "Core.hpp"

MemModule::MemModule(Core *core)
	: _core(core)
{
}

MemModule::~MemModule(void)
{
}

const char			*MemModule::getName(void) const
{
	return ("Memory");
}

int					MemModule::getHeight(void) const
{
	return (11);
}

void				MemModule::refresh(void)
{
}

void				MemModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().memRegions;
	size_t				len;

	display->print(10, y + 1, "MemRegions:", F_CENTER);
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 4, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(".");
	display->print(-1, y + 5, str.substr(0, len), F_CENTER);
	display->print(10, y + 6, "SharedLibs:", F_CENTER);
	str = _core->getStats().sharedLibs;
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 7, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 8, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(".");
	display->print(-1, y + 9, str.substr(0, len), F_CENTER);
}