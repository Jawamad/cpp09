/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:08 by flmuller          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:47 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

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

		void	setData(std::ifstream& file);
		void	displayBtcValue(std::ifstream& inputFile);
		void	findclosestValue(int& date, float& value) const;
};

#endif