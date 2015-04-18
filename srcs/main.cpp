/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:05:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:43:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gk.h"
#include "Core.hpp"
#include "NCursesDisplay.hpp"
#include "HostModule.hpp"
#include <iostream>

int				main(int argc, char **argv)
{
	Core			core;

	try
	{
		core.loadDisplay(new NCursesDisplay(&core));
		core.loadDisplay(new NCursesDisplay(&core));
		core.loadModule(new HostModule(&core));
		core.loadModule(new HostModule(&core));
		core.loadModule(new HostModule(&core));
		core.loadModule(new HostModule(&core));
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
