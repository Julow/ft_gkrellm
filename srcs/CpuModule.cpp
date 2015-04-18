/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:13:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"
# include <sys/types.h>
# include <sys/sysctl.h>
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
	return ("CpuModule");
}

int					CpuModule::getWidth(void) const
{
	return (WIN_WIDTH);
}

int					CpuModule::getHeight(void) const
{
	return (2);
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
	std::ostringstream			oss;

	display->print(0, y, this->_cpuName);
	display->print(0, y + 1, "Nb coeurs:");
	oss << this->_ncpu;
	display->print(15, y + 1, oss.str());
	display->print(0, y + 2, "Bus speed:");
	oss.str("");
	oss.clear();
	oss << this->_busFrequency;
	display->print(15, y + 2, oss.str());
	display->print(0, y + 3, "CPU speed:");
	oss.str("");
	oss.clear();
	oss << this->_cpuFrequency << " GHz";
	display->print(15, y + 3, oss.str());

	display->print(0, y + 4, "Activity:");
	display->print(15, y + 4, "TODO");

}
