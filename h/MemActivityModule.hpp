/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemActivityModule.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 16:48:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMACTIVITYMODULE_HPP
# define MEMACTIVITYMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	MemActivityModule : public IMonitorModule
{
public:
	MemActivityModule(Core *core);
	virtual ~MemActivityModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

private:
	MemActivityModule(void);
	MemActivityModule(MemActivityModule const &src);
	MemActivityModule					&operator=(MemActivityModule const &rhs);
};

#endif
