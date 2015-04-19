/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 16:47:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>

CatModule::CatModule(Core *core)
	: _core(core), _x(15)
{
}

CatModule::~CatModule(void)
{
}

const char			*CatModule::getName(void) const
{
	return ("Cat");
}

int					CatModule::getHeight(void) const
{
	return (10);
}

void				CatModule::refresh(void)
{

}

void				CatModule::display(IMonitorDisplay *display, int y)
{
	int				i;
	int				rn;

	rn = rand() % 4;
	i = ( 8 * rn);
	if (rn == 0)
		_x -= 8;
	else if (rn == 1)
		_x += 8;
	if (_x > 36 || _x < 0)
		_x = 15;
	while (i < (8 * (rn + 1)))
	{
		display->print(_x, y + i - (8 * rn), this->_cats[i], 0);		
		i++;
	}
}

const char			*CatModule::_cats[] = {
	"        ,_",
	"(\\(\\      \\\\",
"/.. \\      ||",
"\\Y_, '----.//",
" )        /",
" |   \\_/  ;",
"   \\ |\\`\\ |\\",
"  ((_/(_(_/", 


"_,",
" //      /)/)",
"||      / ..\\",
"\\\\.----' ,_Y/",
" \\        (",
" l  \\_/   |",
" | /`/| //",
" \\_)_)\\_))",

" (\\_/)",
" /. .\\",
"=\\_T_/=",
" /   \\ .-.",
" | _ |/",
"/| | |\\",
"\\)_|_(/  _",
"`"" ""` (_)_.-.",


"          (\\(\\",
"         / ..(",
"      .-' ,_Y/",
"    .'     (",
"   /   \\/  |",
"  _|  _/| //",
".',_\\__)\\_))",
"'----,)", NULL};
