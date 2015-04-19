/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:05:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 15:23:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gk.h"
#include "Core.hpp"
#include "NCursesDisplay.hpp"
#include "HostModule.hpp"
#include "CpuModule.hpp"
#include "TimeModule.hpp"
#include "OsInfoModule.hpp"
#include "DiskModule.hpp"
#include "ProcessModule.hpp"
#include "NetworkModule.hpp"
#include "LoadModule.hpp"
#include <iostream>

int				main(int argc, char **argv)
{
	Core			core;

	try
	{
		core.loadDisplay(new NCursesDisplay(&core));
		core.loadDisplay(new NCursesDisplay(&core));
		core.loadModule(new HostModule(&core));
		core.loadModule(new CpuModule(&core));
		core.loadModule(new TimeModule(&core));
		core.loadModule(new OsInfoModule(&core));
		core.loadModule(new LoadModule(&core));
		core.loadModule(new DiskModule(&core));
		core.loadModule(new ProcessModule(&core));
		core.loadModule(new NetworkModule(&core));
		core.start();
	}
	catch (std::exception &e)
	{
		NCursesDisplay::deinit();
		std::cout << "Error: " << e.what() << std::endl;
	}
	IGNORE(argc);
	IGNORE(argv);
	return (0);
}
