/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:08 by flmuller          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:49 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <limits>

class BitcoinExchange 
{
	private :
		std::map<int, float> _database;
	public :

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange();

		BitcoinExchange&	operator=(BitcoinExchange const& obj);

		std::map<int, float> const& getdatabase() const;

		int		setData(std::string file);
		void	displayBtcValue(std::string inputFile);
		int		findclosestDate(int& date) const;
};
int	stringToDateInt(const std::string &dateStr);
bool	isValidDate(const std::string &dateStr);

#endif