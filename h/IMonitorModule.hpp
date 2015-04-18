/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:01:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:54:45 by jaguillo         ###   ########.fr       */
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

	virtual std::string const	&getName(void) const = 0;

	virtual int					getWidth(void) const = 0;
	virtual int					getHeight(void) const = 0;

	virtual void				refresh(Core &core) = 0;

protected:

private:
};

#endif
