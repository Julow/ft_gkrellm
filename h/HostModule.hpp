/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 13:55:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	HostModule : public IMonitorModule
{
public:
	HostModule(Core *core);
	virtual ~HostModule(void);

	virtual const char			*getName(void) const;

	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

	std::string					_hostname;
	std::string					_username;

private:
	HostModule(void);
	HostModule(HostModule const &src);
	HostModule					&operator=(HostModule const &rhs);
};

#endif
