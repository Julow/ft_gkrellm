/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemActivityModule.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 16:59:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MemActivityModule.hpp"
#include "Core.hpp"

MemActivityModule::MemActivityModule(Core *core)
	: _core(core)
{
}

MemActivityModule::~MemActivityModule(void)
{
}

const char			*MemActivityModule::getName(void) const
{
	return ("Memory Activity");
}

int					MemActivityModule::getHeight(void) const
{
	return (8);
}

void				MemActivityModule::refresh(void)
{
}

void				MemActivityModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().physMem;
	size_t				len;

	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 1, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(".");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str = _core->getStats().vMem;
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 4, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 5, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(".");
	display->print(-1, y + 6, str.substr(0, len), F_CENTER);
}
