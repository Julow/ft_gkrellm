/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 16:12:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMMODULE_HPP
# define MEMMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	MemModule : public IMonitorModule
{
public:
	MemModule(Core *core);
	virtual ~MemModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

private:
	MemModule(void);
	MemModule(MemModule const &src);
	MemModule					&operator=(MemModule const &rhs);
};

#endif
