/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 13:06:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/18 18:34:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GK_H
# define FT_GK_H

# define IGNORE(a)		(static_cast<void>(a))

# define WIN_WIDTH		30

# define F_CENTER		(1 << 1)

class	IMonitorDisplay;
class	IMonitorModule;

class	Core;

class	NCursesDisplay;
class	GtkDisplay;

#endif
