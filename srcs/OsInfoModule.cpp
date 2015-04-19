/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:13:49 by jaguillo         ###   ########.fr       */
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
	return ("OsInfoModule");
}

int					OsInfoModule::getWidth(void) const
{
	return (WIN_WIDTH);
}

int					OsInfoModule::getHeight(void) const
{
	return (4);
}

void				OsInfoModule::refresh(void)
{
	int				mib[2];
	size_t			len;
	char			str[1048];


	len = 1024;
	sysctlbyname("kern.ostype", str, &len, NULL, 0);
	this->_osType = str;

	len = 1024;
	sysctlbyname("kern.osrelease", str, &len, NULL, 0);
	this->_osRelease = str;

	len = 1024;
	mib[0] = CTL_KERN;
    mib[1] = KERN_OSRELEASE;
    sysctl(mib, 2, str, &len, NULL, 0);
    this->_os = str;
}

void				OsInfoModule::display(IMonitorDisplay *display, int y)
{
	std::ostringstream			oss;
	int							i;

	display->print(0, y, "Os:", 0);
	display->print(20, y, this->_os, 0);
	y++;
	display->print(0, y, "Kernel:", 0);
	display->print(20, y, this->_osType, 0);
	y++;
	display->print(0, y, "Kernel version:", 0);
	display->print(20, y, this->_osRelease, 0);
	y++;
	display->print(0, y, "Os X ", 0);

	i = 0;
	while (this->_oss[i].version != -1)
	{
		if (atoi(this->_osRelease.c_str()) == this->_oss[i].version)
		{
			display->print(20, y, this->_oss[i].name, 0);
			break ;
		}
		i++;
	}
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
