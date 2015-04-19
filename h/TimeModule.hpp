/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:25:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	TimeModule : public IMonitorModule
{
public:
	TimeModule(Core *core);
	virtual ~TimeModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

	std::string					_time;

private:
	TimeModule(void);
	TimeModule(TimeModule const &src);
	TimeModule					&operator=(TimeModule const &rhs);
};

#endif
