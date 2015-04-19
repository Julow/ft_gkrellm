/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:34:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 19:53:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULEFACTORY_HPP
# define MODULEFACTORY_HPP

# include "IMonitorModule.hpp"

class	ModuleFactory
{
public:
	virtual ~ModuleFactory(void);

	static IMonitorModule	*createModule(Core *core, std::string const &name) throw(std::runtime_error);

protected:
	struct	s_module
	{
		std::string			name;
		IMonitorModule		*(*f)(Core *core);
	};

	static IMonitorModule	*createHostModule(Core *core);
	static IMonitorModule	*createCpuModule(Core *core);
	static IMonitorModule	*createTimeModule(Core *core);
	static IMonitorModule	*createOsInfoModule(Core *core);
	static IMonitorModule	*createDiskModule(Core *core);
	static IMonitorModule	*createProcessModule(Core *core);
	static IMonitorModule	*createNetworkModule(Core *core);
	static IMonitorModule	*createLoadModule(Core *core);
	static IMonitorModule	*createCatModule(Core *core);
	static IMonitorModule	*createMemModule(Core *core);
	static IMonitorModule	*createMemActivityModule(Core *core);

	static s_module			_modules[];

private:
	ModuleFactory(void);
	ModuleFactory(ModuleFactory const &src);
	ModuleFactory			&operator=(ModuleFactory const &rhs);
};

#endif
