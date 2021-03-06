/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:12:03 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/19 20:17:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NCursesDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Core.hpp"
#include <ncurses.h>
#include <vector>
#include <exception>

NCursesDisplay::NCursesDisplay(Core *core) throw(std::runtime_error)
	: _core(core), _scrollY(0)
{
	if (NCursesDisplay::_winCount > MAX_NCURSES)
		throw std::runtime_error("Too many ncurses");
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
		else if (c >= '0' && c <= '9')
		{
			if (_core->getModules().size() > (c - '0'))
				_core->getModules().erase(_core->getModules().begin() + (c - '0'));
		}
		else if ((c == KEY_UP && _scrollY > 0)
			|| (c == KEY_DOWN && (_scrollY + 1) < _core->getModules().size()))
		{
			_scrollY += (c == KEY_UP) ? -1 : 1;
			this->display();
		}
	return (true);
}

void						NCursesDisplay::display(void)
{
	int							y = 0;
	std::vector<IMonitorModule*>::iterator it = _core->getModules().begin();
	std::vector<IMonitorModule*>::iterator end = _core->getModules().end();

	getmaxyx(_win, _height, _width);
	wclear(_win);
	it += _scrollY;
	for (; it != end; ++it)
	{
		wmove(_win, y++, 1);
		if (y >= _height)
			break ;
		wattron(_win, COLOR_PAIR(1));
		whline(_win, '=', WIN_WIDTH);
		wattron(_win, COLOR_PAIR(2));
		print(-1, y++, (*it)->getName(), F_CENTER);
		wmove(_win, y++, 1);
		wattron(_win, COLOR_PAIR(3));
		if (y >= _height)
			break ;
		whline(_win, '-', WIN_WIDTH);
		wattroff(_win, COLOR_PAIR(3));
		(*it)->display(this, y);
		y += (*it)->getHeight();
	}
	wattron(_win, COLOR_PAIR(3));
	wborder(_win, '|', '|', '=', '=', '+', '+', '+', '+');
	wrefresh(_win);
}

void						NCursesDisplay::print(int x, int y, std::string const &data, int flags)
{
	if (y >= _height)
		return ;
	if (flags & F_CENTER)
	{
		if (x == -1)
			x = WIN_WIDTH / 2;
		x -= data.size() / 2;
	}
	wmove(_win, y, x + 1);
	wprintw(_win, "%s", data.c_str());
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
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_GREEN, COLOR_BLACK);
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
