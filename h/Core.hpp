/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:55:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_HPP
# define CORE_HPP

// # include <ostream>
// # include <string>
// # include <exception>
# include <iostream>
# include <vector>
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

class	Core
{
public:
	Core(void);
	virtual ~Core(void);

	void							loadMobule(IMonitorModule *module);

	void							start(void);

	std::vector<IMonitorModule*>	&getModules(void);

protected:
	std::vector<IMonitorDisplay*>	_displays;

	std::vector<IMonitorModule*>	_modules;
	void							refreshModules(void);
	void							displayModules(void);

private:
	Core(Core const &src);
	Core			&operator=(Core const &rhs);
};

// std::ostream		&operator<<(std::ostream &o, Core const &rhs);

#endif
