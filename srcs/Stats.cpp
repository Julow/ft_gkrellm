/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stats.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 11:49:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/19 12:50:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stats.hpp"
#include <fstream>
#include <istream>
#include <stdio.h>

Stats::Stats(void)
{
}

Stats::~Stats(void)
{
}

void			Stats::update(void)
{
	FILE			*fp;

	fp = popen("top -l 1 -n 0 -s 0", "r");
	if (fp == NULL)
		return ;
	_fgets(fp, &processes);
	_fgets(fp, NULL);
	_fgets(fp, &cpuLoad);
	_fgets(fp, &cpuUsage);
	_fgets(fp, &sharedLibs);
	_fgets(fp, &memRegions);
	_fgets(fp, &physMem);
	_fgets(fp, &vMem);
	_fgets(fp, &networks);
	_fgets(fp, &disk);
	pclose(fp);
}

void			Stats::_fgets(FILE *fp, std::string *dst) const
{
	char			buff[128];

	if (dst != NULL)
		dst->clear();
	if (fgets(buff, 128, fp) == NULL)
		return ;
	if (dst != NULL)
		*dst += buff;
}
