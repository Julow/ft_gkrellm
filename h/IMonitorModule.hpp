/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:01:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 15:51:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <string>
# include "ft_gk.h"

class	IMonitorModule
{
public:
	virtual ~IMonitorModule(void){}

	virtual const char			*getName(void) const = 0;

	virtual int					getWidth(void) const = 0;
	virtual int					getHeight(void) const = 0;

	virtual void				refresh(void) = 0;
	virtual void				display(IMonitorDisplay &display) = 0;

protected:

private:
};

#endif
