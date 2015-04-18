/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GtkDisplay.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 14:18:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:48:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTKDISPLAY_HPP
# define GTKDISPLAY_HPP

// # include <ostream>
// # include <string>
// # include <exception>

class	GtkDisplay
{
public:
	GtkDisplay(void);
	virtual ~GtkDisplay(void);

protected:

private:
	GtkDisplay(GtkDisplay const &src);
	GtkDisplay			&operator=(GtkDisplay const &rhs);
};

#endif
