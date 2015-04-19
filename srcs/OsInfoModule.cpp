/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 17:06:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsInfoModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>
#include <stdlib.h>

OsInfoModule::OsInfoModule(Core *core)
	: _core(core), _os(""), _osType(""), _osRelease("")
{
}

OsInfoModule::~OsInfoModule(void)
{
}

const char			*OsInfoModule::getName(void) const
{
	return ("OS Info");
}

int					OsInfoModule::getWidth(void) const
{
	return (WIN_WIDTH);
}

int					OsInfoModule::getHeight(void) const
{
	return (5);
}

void				OsInfoModule::refresh(void)
{
	size_t			len;
	char			str[1048];

	len = 1024;
	sysctlbyname("kern.ostype", str, &len, NULL, 0);
	this->_osType = str;
	len = 1024;
	sysctlbyname("kern.osrelease", str, &len, NULL, 0);
	this->_osRelease = str;
}

void				OsInfoModule::display(IMonitorDisplay *display, int y)
{
	int							i;

	y++;
	i = 0;
	while (this->_oss[i].version != -1)
	{
		if (atoi(this->_osRelease.c_str()) == this->_oss[i].version)
		{
			display->print(-1, y, std::string("MacOS X ") += this->_oss[i].name, F_CENTER);
			y++;
			break ;
		}
		i++;
	}
	display->print(-1, y, this->_osType, F_CENTER);
	y++;
	display->print(-1, y, this->_osRelease, F_CENTER);
}

t_osi				OsInfoModule::_oss[] = {
	{14, "Yosemite"},
	{13, "Mavericks"},
	{12, "Mountain Lion"},
	{11, "Lion"},
	{10, "Snow Leopard"},
	{9, "Leopard"},
	{8, "Tiger"},
	{7, "Panther"},
	{6, "Jaguar"},
	{5, "Puma"},
	{-1, ""}
};
