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

# include "IMonitorDisplay.hpp"
# include <iostream>
# include "Core.hpp"

class	NCursesDisplay : public IMonitorDisplay
{
public:
	NCursesDisplay(void);
	virtual ~NCursesDisplay(void);

	virtual void						refresh(Core &core);
	virtual const char* 				getName() const;

protected:

private:
	NCursesDisplay(NCursesDisplay const &src);
	NCursesDisplay					&operator=(NCursesDisplay const &rhs);
};

#endif
