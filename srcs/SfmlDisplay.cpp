/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:12:03 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/19 16:03:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SfmlDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Core.hpp"
#include <ncurses.h>
#include <vector>

SfmlDisplay::SfmlDisplay(Core *core)
	: sf::RenderWindow(sf::VideoMode(800, 800), "ft_gkrellm"), _core(core)
{
	sf::Text 	tx;
	tx.setString("Hello world !");
	this->draw(tx);
	this->display();
}

SfmlDisplay::~SfmlDisplay(void)
{
	return ;
}

const char* 				SfmlDisplay::getName(void) const
{
	return ("Sfml");
}

bool						SfmlDisplay::update(void)
{
	return true;
}

void						SfmlDisplay::display(void)
{
	return ;
}

void						SfmlDisplay::print(int x, int y, std::string const &data, int flags)
{
	IGNORE(x);
	IGNORE(y);
	IGNORE(data);
	IGNORE(flags);
}
