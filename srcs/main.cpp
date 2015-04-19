/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:05:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:50:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gk.h"
#include "Core.hpp"
#include "NCursesDisplay.hpp"
#include "SfmlDisplay.hpp"
#include "ModuleFactory.hpp"
#include <iostream>

void			parse_argv(char **argv, Core *core) throw(std::exception)
{
	if (*argv == NULL)
		throw std::runtime_error("Please specifie monitor(s) to use and modules to display\n"
			"Available monitors: sfml, ncurses\n"
			"Available modules: host, cpu, time, osinfo, disk, process, network, load, cat, mem, memactivity");
	while (*argv != NULL)
	{
		if (strcmp(*argv, "sfml") == 0)
			core->loadDisplay(new SfmlDisplay(core));
		else if (strcmp(*argv, "ncurses") == 0)
			core->loadDisplay(new NCursesDisplay(core));
		else
			core->loadModule(ModuleFactory::createModule(core, *argv));
		argv++;
	}
}

int				main(int argc, char **argv)
{
	Core			core;

	try
	{
		parse_argv(argv + 1, &core);
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
