/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 15:11:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADMODULE_HPP
# define LOADMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	LoadModule : public IMonitorModule
{
public:
	LoadModule(Core *core);
	virtual ~LoadModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

private:
	LoadModule(void);
	LoadModule(LoadModule const &src);
	LoadModule					&operator=(LoadModule const &rhs);
};

#endif
