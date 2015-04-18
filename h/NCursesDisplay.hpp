/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 14:18:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:24:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

// # include <ostream>
// # include <string>
// # include <exception>

class	NCursesDisplay
{
public:
	NCursesDisplay(void);
	virtual ~NCursesDisplay(void);

protected:

private:
	NCursesDisplay(NCursesDisplay const &src);
	NCursesDisplay					&operator=(NCursesDisplay const &rhs);
};

#endif
