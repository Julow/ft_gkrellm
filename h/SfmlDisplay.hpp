/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 14:18:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 20:13:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include "ft_gk.h"
# include "IMonitorDisplay.hpp"
# include <exception>
# include <string>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

# define CHAR_WIDTH				12
# define WIN_HEIGHT				100

class	SfmlDisplay : public sf::RenderWindow, public IMonitorDisplay
{
public:
	SfmlDisplay(Core *core) throw(std::runtime_error);
	virtual ~SfmlDisplay(void);

	virtual const char* 		getName(void) const;

	virtual bool				update(void);
	virtual void				display(void);

	virtual void				print(int x, int y, std::string const &data, int flags);

protected:
	Core						*_core;

	int							_scrollY;

	sf::Text					_text;

	static sf::Font				_font;
	static sf::Image			_im;
	static sf::Sprite			_background;

	static bool					_initied;
	static void					_init(void) throw(std::runtime_error);

	static int					_windowCount;

private:
	SfmlDisplay(SfmlDisplay const &src);
	SfmlDisplay				&operator=(SfmlDisplay const &rhs);
};

#endif
