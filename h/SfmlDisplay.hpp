/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SfmlDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 14:18:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 15:59:51 by jaguillo         ###   ########.fr       */
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
	sf::Font					font;


private:
	SfmlDisplay(SfmlDisplay const &src);
	SfmlDisplay				&operator=(SfmlDisplay const &rhs);
};

#endif
