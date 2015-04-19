/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:41:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATMODULE_HPP
# define CATMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	CatModule : public IMonitorModule
{
public:
	CatModule(Core *core);
	virtual ~CatModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core										*_core;

	static const char							*_cats[];
	int											_x;

private:
	CatModule(CatModule const &src);
	CatModule					&operator=(CatModule const &rhs);
};

#endif
