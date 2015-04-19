/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stats.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 11:49:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 13:57:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_HPP
# define STATS_HPP

# include <string>

class	Stats
{
public:
	Stats(void);
	virtual ~Stats(void);

	void				update(void);

	std::string				processes;
	std::string				cpuLoad;
	std::string				cpuUsage;
	std::string				sharedLibs;
	std::string				memRegions;
	std::string				physMem;
	std::string				vMem;
	std::string				networks;
	std::string				disk;

protected:
	void				_fgets(FILE *fp, std::string *dst) const;

private:
	Stats(Stats const &src);
	Stats				&operator=(Stats const &rhs);
};

#endif
