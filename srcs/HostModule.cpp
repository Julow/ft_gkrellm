/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:41:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

HostModule::HostModule(Core *core)
	: _core(core), _hostname("")
{
}

HostModule::~HostModule(void)
{
}

const char			*HostModule::getName(void) const
{
	return ("HostModule");
}

int					HostModule::getHeight(void) const
{
	return (3);
}

void				HostModule::refresh(void)
{
	size_t			len;
	char			str[1048];

	len = 1048;
	sysctlbyname("kern.hostname", str, &len, NULL, 0);
	_hostname = str;

	struct passwd *pw;
	uid_t uid;
	uid = getuid();
	pw = getpwuid(uid);
	this->_username = "";
	if (pw)
	{
		this->_username = pw->pw_name;
	}
}

void				HostModule::display(IMonitorDisplay *display, int y)
{
	display->print(-1, y + 1, _hostname, F_CENTER);
	display->print(-1, y + 2, _username, F_CENTER);
}
