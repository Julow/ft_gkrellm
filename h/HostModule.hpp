/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 15:50:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include "IMonitorModule.hpp"

class	HostModule : public IMonitorModule
{
public:
	HostModule(Core &core);
	virtual ~HostModule(void);

	virtual const char			*getName(void) const;

	virtual int					getWidth(void) const;
	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay &display);

protected:
	std::string					_hostname;

private:
	HostModule(HostModule const &src);
	HostModule					&operator=(HostModule const &rhs);
};

#endif
