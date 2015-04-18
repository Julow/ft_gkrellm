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
#include "Gkrellm.hpp"

int				main(int argc, char **argv)
{
	Gkrellm			gkrellm;

	gkrellm.start();
	IGNORE(argc);
	IGNORE(argv);
	return (0);
}
