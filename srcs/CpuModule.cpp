/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 17:17:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

CpuModule::CpuModule(Core *core)
	: _core(core), _cpuName("none"), _ncpu(-1), _busFrequency(-1), _cpuFrequency(-1)
{
}

CpuModule::~CpuModule(void)
{
}

const char			*CpuModule::getName(void) const
{
	return ("CPU");
}

int					CpuModule::getWidth(void) const
{
	return (WIN_WIDTH);
}

int					CpuModule::getHeight(void) const
{
	return (6);
}

void				CpuModule::refresh(void)
{
	long			data;
	size_t			len;
	char			str[1048];

	len = 1048;

	sysctlbyname("machdep.cpu.brand_string", str, &len, NULL, 0);
	this->_cpuName = str;
	len = sizeof(int);
	sysctlbyname("hw.ncpu", &(this->_ncpu), &len, NULL, 0);
	len = sizeof(long);
	sysctlbyname("hw.busfrequency", &(this->_busFrequency), &len, NULL, 0);
	len = sizeof(long);
	sysctlbyname("hw.cpufrequency", &data, &len, NULL, 0);
	this->_cpuFrequency = static_cast<double>(static_cast<double>(data) / static_cast<double>(this->_busFrequency) / 10.0);
}

void				CpuModule::display(IMonitorDisplay *display, int y)
{
	display->print(-1, ++y, this->_cpuName, F_CENTER);
	display->print(-1, ++y, std::string("Cores: ") += std::to_string(_ncpu), F_CENTER);
	display->print(-1, ++y, std::string("Bus speed: ") += std::to_string(_busFrequency), F_CENTER);
	display->print(-1, ++y, (std::string("CPU speed: ") += std::to_string(_cpuFrequency)) += " GHz", F_CENTER);
}
