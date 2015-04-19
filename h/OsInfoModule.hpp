/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:25:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OSINFOMODULE_HPP
# define FT_OSINFOMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"


typedef struct 				s_osi
{
	int				version;
	std::string		name;
}							t_osi;

class	OsInfoModule : public IMonitorModule
{
public:
	OsInfoModule(Core *core);
	virtual ~OsInfoModule(void);

	virtual const char			*getName(void) const;

	virtual int					getWidth(void) const;
	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

	std::string					_os;
	std::string					_osType;
	std::string					_osRelease;
	static t_osi				_oss[];

private:
	OsInfoModule(void);
	OsInfoModule(OsInfoModule const &src);
	OsInfoModule					&operator=(OsInfoModule const &rhs);
};

#endif
