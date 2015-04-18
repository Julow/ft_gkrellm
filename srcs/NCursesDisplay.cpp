/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:12:03 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/18 15:12:04 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "NCursesDisplay.hpp"

NCursesDisplay::NCursesDisplay(void)
{
}

NCursesDisplay::~NCursesDisplay(void)
{
}

void					NCursesDisplay::refresh(Core &core)
{
	IGNORE(core);
}

const char*				NCursesDisplay::getName(void) const
{
	return ("NCurses");
}
