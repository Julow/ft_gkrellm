/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:34:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:52:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleFactory.hpp"
#include "HostModule.hpp"
#include "CpuModule.hpp"
#include "TimeModule.hpp"
#include "OsInfoModule.hpp"
#include "DiskModule.hpp"
#include "ProcessModule.hpp"
#include "NetworkModule.hpp"
#include "LoadModule.hpp"
#include "CatModule.hpp"
#include "MemModule.hpp"
#include "MemActivityModule.hpp"

ModuleFactory::~ModuleFactory(void)
{
}

IMonitorModule				*ModuleFactory::createModule(Core *core, std::string const &name) throw(std::runtime_error)
{
	int					i;

	for (i = 0; _modules[i].f != NULL; ++i)
	{
		if (name.compare(_modules[i].name) == 0)
			return (_modules[i].f(core));
	}
	throw std::runtime_error(std::string("Unknow module: ") += name);
}

IMonitorModule				*ModuleFactory::createHostModule(Core *core)
{
	return (new HostModule(core));
}

IMonitorModule				*ModuleFactory::createCpuModule(Core *core)
{
	return (new CpuModule(core));
}

IMonitorModule				*ModuleFactory::createTimeModule(Core *core)
{
	return (new TimeModule(core));
}

IMonitorModule				*ModuleFactory::createOsInfoModule(Core *core)
{
	return (new OsInfoModule(core));
}

IMonitorModule				*ModuleFactory::createDiskModule(Core *core)
{
	return (new DiskModule(core));
}

IMonitorModule				*ModuleFactory::createProcessModule(Core *core)
{
	return (new ProcessModule(core));
}

IMonitorModule				*ModuleFactory::createNetworkModule(Core *core)
{
	return (new NetworkModule(core));
}

IMonitorModule				*ModuleFactory::createLoadModule(Core *core)
{
	return (new LoadModule(core));
}

IMonitorModule				*ModuleFactory::createCatModule(Core *core)
{
	return (new CatModule(core));
}

IMonitorModule				*ModuleFactory::createMemModule(Core *core)
{
	return (new MemModule(core));
}

IMonitorModule				*ModuleFactory::createMemActivityModule(Core *core)
{
	return (new MemActivityModule(core));
}

ModuleFactory::s_module		ModuleFactory::_modules[] = {
	{"host", &ModuleFactory::createHostModule},
	{"cpu", &ModuleFactory::createCpuModule},
	{"time", &ModuleFactory::createTimeModule},
	{"osinfo", &ModuleFactory::createOsInfoModule},
	{"disk", &ModuleFactory::createDiskModule},
	{"process", &ModuleFactory::createProcessModule},
	{"network", &ModuleFactory::createNetworkModule},
	{"load", &ModuleFactory::createLoadModule},
	{"cat", &ModuleFactory::createCatModule},
	{"mem", &ModuleFactory::createMemModule},
	{"memactivity", &ModuleFactory::createMemActivityModule},
	{"", NULL}
};
