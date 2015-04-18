/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:01:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:39:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "ft_gk.h"
# include <string>

class	IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(void){}

	virtual const char* 				getName(void) const = 0;

	virtual bool						update(void) = 0;
	virtual void						display(void) = 0;

	virtual void						print(int x, int y, std::string const &data, int flags) = 0;

protected:

private:
};

#endif
