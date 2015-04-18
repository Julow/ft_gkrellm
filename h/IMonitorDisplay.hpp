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

class	IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(void){}

	virtual void						refresh(Core &core) = 0;
	virtual std::string const & 		getName() = 0;

protected:

private:
};

#endif
