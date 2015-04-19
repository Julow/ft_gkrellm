/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:06:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 17:24:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GK_H
# define FT_GK_H

# define IGNORE(a)		(static_cast<void>(a))

# define REFRESH_TIME	(CLOCKS_PER_SEC)
# define UPDATE_TIME	(CLOCKS_PER_SEC / 60)

# define WIN_WIDTH		50

# define F_CENTER		(1 << 1)

class	IMonitorDisplay;
class	IMonitorModule;

class	Core;
class	Stats;

class	NCursesDisplay;
class	GtkDisplay;

#endif
