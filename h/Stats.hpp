/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stats.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 11:49:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 12:50:22 by jaguillo         ###   ########.fr       */
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

	void				_fgets(FILE *fp, std::string *dst) const;

	// int					processTotal;
	// int					processRunning;
	// int					processStuck;
	// int					processSleeping;
	// int					processThreads;

	// float				loadAvg1;
	// float				loadAvg2;
	// float				loadAvg3;

	// float				cpuUser;
	// float				cpuSys;
	// float				cpuIdle;

	// int					sharedResident;
	// int					sharedData;
	// int					sharedLinkedit;

	// int					memRegions;
	// int					memResident;
	// int					memPrivate;
	// int					memShared;

	// int					physUsed;
	// int					physWired;
	// int					physUnused;

	// int					vmSize;
	// int					vmFramework;
	// int					vmSwapins;
	// int					vmSwapouts;

	// int					netIns;
	// int					netDataIn;
	// int					netOuts;
	// int					netDataOut;

	// int					diskReads;
	// int					diskDataRead;
	// int					diskWrites;
	// int					diskDataWrite;

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

private:
	Stats(Stats const &src);
	Stats				&operator=(Stats const &rhs);
};

#endif
