/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 12:30:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include "ft_gk.h"
# include "Stats.hpp"
# include <list>
# include <vector>

class	Core
{
public:
	Core(void);
	virtual ~Core(void);

	void							start(void) throw (std::runtime_error);

	void							loadModule(IMonitorModule *module);
	void							loadDisplay(IMonitorDisplay *display);

	void							removeModule(std::string const & moduleName);
	void							removeDisplay(std::string const & displayName);

	std::list<IMonitorModule*>		&getModules(void);

	Stats const						&getStats(void) const;

protected:
	std::vector<IMonitorDisplay*>	_displays;
	std::list<IMonitorModule*>		_modules;

	Stats							_stats;

	void							_refresh(void);
	void							_update(void);
	void							_display(void);

private:
	Core(Core const &src);
	Core			&operator=(Core const &rhs);
};

#endif
