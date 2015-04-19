/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 15:22:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:24:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "ft_gk.h"
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class	CpuModule : public IMonitorModule
{
public:
	CpuModule(Core *core);
	virtual ~CpuModule(void);

	virtual const char			*getName(void) const;

	virtual int					getWidth(void) const;
	virtual int					getHeight(void) const;

	virtual void				refresh(void);
	virtual void				display(IMonitorDisplay *display, int y);

protected:
	Core						*_core;

	std::string					_cpuName;
	int							_ncpu;
	int							_busFrequency;
	double						_cpuFrequency;

private:
	CpuModule(void);
	CpuModule(CpuModule const &src);
	CpuModule					&operator=(CpuModule const &rhs);
};

#endif
