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
	_hostname = "lol";
}

void				HostModule::display(IMonitorDisplay *display, int y)
{
	display->print(-1, y + 1, _hostname, F_CENTER);
}
