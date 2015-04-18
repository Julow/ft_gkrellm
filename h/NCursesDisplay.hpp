/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 14:18:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:39:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include "ft_gk.h"
# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include <exception>
# include <string>

class	NCursesDisplay : public IMonitorDisplay
{
public:
	NCursesDisplay(Core *core) throw(std::runtime_error);
	virtual ~NCursesDisplay(void);

	virtual const char* 		getName(void) const;

	virtual bool				update(void);
	virtual void				display(void);

	virtual void				print(int x, int y, std::string const &data, int flags);

	static void					init(void);
	static void					deinit(void);

protected:
	Core						*_core;

	WINDOW						*_win;

	static bool					_initied;
	static int					_winCount;

private:
	NCursesDisplay(NCursesDisplay const &src);
	NCursesDisplay				&operator=(NCursesDisplay const &rhs);
};

#endif
