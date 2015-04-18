/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gkrellm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:04:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:55:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_HPP
# define GKRELLM_HPP

// # include <ostream>
// # include <string>
// # include <exception>
# include <vector>
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

class	Gkrellm
{
public:
	Gkrellm(void);
	virtual ~Gkrellm(void);

	void							loadMobule(IMonitorModule *module);

	void							start(void);

	std::vector<IMonitorModule*>	&getModules(void);

protected:
	std::vector<IMonitorDisplay*>	_display;

	std::vector<IMonitorModule*>	_modules;

private:
	Gkrellm(Gkrellm const &src);
	Gkrellm			&operator=(Gkrellm const &rhs);
};

// std::ostream		&operator<<(std::ostream &o, Gkrellm const &rhs);

#endif
