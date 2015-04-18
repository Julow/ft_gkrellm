/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:05:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:33:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gk.h"
#include "Core.hpp"

int				main(int argc, char **argv)
{
	Core			core;

	core.start();
	IGNORE(argc);
	IGNORE(argv);
	return (0);
}
