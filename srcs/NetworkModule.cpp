/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 13:46:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 14:49:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"
#include "Core.hpp"

NetworkModule::NetworkModule(Core *core)
	: _core(core)
{
}

NetworkModule::~NetworkModule(void)
{
}

const char			*NetworkModule::getName(void) const
{
	return ("Network activity");
}

int					NetworkModule::getHeight(void) const
{
	return (5);
}

void				NetworkModule::refresh(void)
{
}

void				NetworkModule::display(IMonitorDisplay *display, int y)
{
	std::string			str = _core->getStats().networks;
	size_t				len;

	display->print(10, y + 1, "Network:", F_CENTER);
	str.erase(0, str.find(": ") + 2);
	len = str.find(", ");
	display->print(-1, y + 2, str.substr(0, len), F_CENTER);
	str.erase(0, len + 2);
	len = str.find(", ");
	display->print(-1, y + 3, str.substr(0, len), F_CENTER);
}
