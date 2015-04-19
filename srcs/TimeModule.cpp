/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:41:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

TimeModule::TimeModule(Core *core)
	: _core(core), _time("NoData")
{
}

TimeModule::~TimeModule(void)
{
}

const char			*TimeModule::getName(void) const
{
	return ("TimeModule");
}

int					TimeModule::getHeight(void) const
{
	return (3);
}

void				TimeModule::refresh(void)
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  this->_time = asctime(timeinfo);
}

void				TimeModule::display(IMonitorDisplay *display, int y)
{
	display->print(-1, y + 1, _time, F_CENTER);
}
