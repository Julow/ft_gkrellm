/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 14:04:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSMODULE_HPP
# define PROCESSMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	ProcessModule : public IMonitorModule
{
public:
	ProcessModule(Core *core);
	virtual ~ProcessModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

private:
	ProcessModule(void);
	ProcessModule(ProcessModule const &src);
	ProcessModule				&operator=(ProcessModule const &rhs);
};

#endif
