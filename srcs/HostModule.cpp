/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:13:49 by jaguillo         ###   ########.fr       */
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

int					HostModule::getWidth(void) const
{
	return (WIN_WIDTH);
}

int					HostModule::getHeight(void) const
{
	return (2);
}

void				HostModule::refresh(void)
{
	_hostname = "lol";
}

void				HostModule::display(IMonitorDisplay *display, int y)
{
	display->print(0, y, "Hostname: ");
	display->print(10, y, _hostname);
}
