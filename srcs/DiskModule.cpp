/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 14:49:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiskModule.hpp"
#include "Core.hpp"

DiskModule::DiskModule(Core *core)
	: _core(core)
{
}

DiskModule::~DiskModule(void)
{
}

const char			*DiskModule::getName(void) const
{
	return ("Disk activity");
}

int					DiskModule::getHeight(void) const
{
	return (5);
}

void				DiskModule::refresh(void)
{
}

void				DiskModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().disk;
	size_t				len;

	display->print(10, y + 1, "Disk usage:", F_CENTER);
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
}
