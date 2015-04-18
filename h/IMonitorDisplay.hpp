/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:01:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 14:54:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "ft_gk.h"
# include <iostream>

class	IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(void){}

	virtual void						refresh(Core &core) = 0;
	virtual const char* 				getName(void) const = 0;

	virtual void						display(Core &core) = 0;

	virtual void						print(int x, int y, std::string const &data);

protected:

private:
};

#endif
