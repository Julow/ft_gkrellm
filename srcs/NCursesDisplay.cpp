/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:12:03 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/18 18:44:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NCursesDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Core.hpp"
#include <ncurses.h>
#include <vector>

NCursesDisplay::NCursesDisplay(Core *core) throw(std::runtime_error)
	: _core(core)
{
	NCursesDisplay::init();
	_win = newwin(0, WIN_WIDTH + 2, 0, NCursesDisplay::_winCount * (WIN_WIDTH + 1));
	if (_win == NULL)
		throw std::runtime_error("Cannot create window");
	NCursesDisplay::_winCount++;
}

NCursesDisplay::~NCursesDisplay(void)
{
	werase(_win);
	wrefresh(_win);
	delwin(_win);
}

const char* 				NCursesDisplay::getName(void) const
{
	return ("NCurses");
}

bool						NCursesDisplay::update(void)
{
	int							c;

	while ((c = getch()) != ERR)
		if (c == 'q' || c == 27)
			return (false);
	return (true);
}

void						NCursesDisplay::display(void)
{
	int							y = 0;

	_core->getModules();
	std::vector<IMonitorModule*>::iterator it = _core->getModules().begin();
	std::vector<IMonitorModule*>::iterator end = _core->getModules().end();

	wclear(_win);
	for (; it != end; ++it)
	{
		wmove(_win, y++, 1);
		whline(_win, '=', WIN_WIDTH);
		print(-1, y++, (*it)->getName(), F_CENTER);
		wmove(_win, y++, 1);
		whline(_win, '-', WIN_WIDTH);
		(*it)->display(this, y);
		y += (*it)->getHeight();
	}
	wborder(_win, '|', '|', '=', '=', '+', '+', '+', '+');
	wrefresh(_win);
}

void						NCursesDisplay::print(int x, int y, std::string const &data, int flags)
{
	if (flags & F_CENTER)
	{
		if (x == -1)
			x = WIN_WIDTH / 2;
		x -= data.size() / 2;
	}
	wmove(_win, y, x + 1);
	wprintw(_win, data.c_str());
}

bool						NCursesDisplay::_initied = false;
int							NCursesDisplay::_winCount = 0;

void						NCursesDisplay::init(void)
{
	if (!NCursesDisplay::_initied)
	{
		initscr();
		cbreak();
		timeout(0);
		keypad(stdscr, TRUE);
		noecho();
		curs_set(0);
		NCursesDisplay::_initied = true;
	}
}

void						NCursesDisplay::deinit(void)
{
	if (NCursesDisplay::_initied)
	{
		clear();
		refresh();
		endwin();
	}
}
