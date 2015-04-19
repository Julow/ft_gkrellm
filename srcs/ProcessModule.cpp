/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 17:06:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProcessModule.hpp"
#include "Core.hpp"

ProcessModule::ProcessModule(Core *core)
	: _core(core)
{
}

ProcessModule::~ProcessModule(void)
{
}

const char			*ProcessModule::getName(void) const
{
	return ("Processus");
}

int					ProcessModule::getHeight(void) const
{
	return (7);
}

void				ProcessModule::refresh(void)
{
}

void				ProcessModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().processes;
	size_t				len;

	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 1, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 4, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 5, str.substr(0, len), F_CENTER);
}
