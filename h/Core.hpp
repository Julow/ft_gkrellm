/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:03:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include <iostream>
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

	std::vector<IMonitorModule*>	&getModules(void);

protected:
	std::vector<IMonitorDisplay*>	_displays;
	std::vector<IMonitorModule*>	_modules;

	void							_refresh(void);
	void							_update(void);
	void							_display(void);

private:
	Core(Core const &src);
	Core			&operator=(Core const &rhs);
};

#endif
