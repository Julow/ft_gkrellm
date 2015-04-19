/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:12:03 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/19 19:28:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SfmlDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Core.hpp"
#include <ncurses.h>
#include <vector>

SfmlDisplay::SfmlDisplay(Core *core) throw(std::runtime_error)
	: sf::RenderWindow(sf::VideoMode(CHAR_WIDTH * WIN_WIDTH, CHAR_WIDTH * WIN_HEIGHT), "ft_gkrellm"), _core(core), _scrollY(0), _im()
{

	if(!_font.loadFromFile("font1.ttf"))
		throw std::runtime_error("Can not load font !");
	if (!_im.loadFromFile("background1.jpg"))
		throw std::runtime_error("Can not load background !");

	_text = sf::Text("A", _font, CHAR_WIDTH);
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
	sf::Event					event;

	while (this->pollEvent(event))
		if (event.type == sf::Event::Closed)
			this->close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Up && _scrollY > 0)
			{
				_scrollY--;
				this->display();
			}
			else if (event.key.code == sf::Keyboard::Down
				&& (_scrollY + 1) < _core->getModules().size())
			{
				_scrollY++;
				this->display();
			}
			else if (event.key.code == sf::Keyboard::Q)
				this->close();
		}
	if (!this->isOpen())
		return (false);
	return true;
}

void						SfmlDisplay::display(void)
{
	int			y = 0;
	std::vector<IMonitorModule*>::iterator it = _core->getModules().begin();
	std::vector<IMonitorModule*>::iterator end = _core->getModules().end();

	this->clear();

	sf::Texture texture;
	texture.loadFromImage(this->_im);
	this->_background.setTexture(texture, true);
	this->_background.setPosition(0, 0);

	this->draw(this->_background);
	it += _scrollY;
	for (; it != end; ++it)
	{
		sf::RectangleShape			rectangle(sf::Vector2f(WIN_WIDTH * CHAR_WIDTH, 3 * CHAR_WIDTH));
		rectangle.setPosition(0, y * CHAR_WIDTH);
		rectangle.setFillColor(sf::Color(52, 152, 219, 64));
		this->draw(rectangle);
		this->print(-1, y + 1, (*it)->getName(), F_CENTER);
		y += 3;

		(*it)->display(this, y);
		y += (*it)->getHeight();
	}


	sf::RenderWindow::display();
	return ;
}

void						SfmlDisplay::print(int x, int y, std::string const &data, int flags)
{
	float						posX;
	float						posY;
	if (y >= WIN_HEIGHT)
		return ;
	posX = static_cast<float>(x * CHAR_WIDTH);
	posY = static_cast<float>(y * CHAR_WIDTH);
	_text.setString(data);
	if (flags & F_CENTER)
	{
		float w = _text.findCharacterPos(data.size() - 1).x - _text.findCharacterPos(0).x;
		posX = (CHAR_WIDTH * WIN_WIDTH - w) / 2;
	}
	_text.setPosition(posX, posY);
	this->draw(_text);
}
