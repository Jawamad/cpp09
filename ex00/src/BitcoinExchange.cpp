/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:48:46 by flmuller          #+#    #+#             */
/*   Updated: 2025/03/20 15:22:10 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	*this = obj;
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& obj)
{
	if (this != &obj)
	{
		_database = obj._database;
	}
	return *this;
}
std::map<int, float> const& BitcoinExchange::getdatabase() const
{
	return _database;
}
void	BitcoinExchange::setData(std::ifstream& file)
{
	if (!file)
	{
		std::cerr << "Error cannot open file" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string dateStr, valueStr;
		if (std::getline(ss, dateStr, ','))
		{
			int dateInt = -1;
			if (dateStr.size() == 10 &&dateStr[4] == '-' && dateStr[7] == '-')
			{
				dateInt = std::atoi(dateStr.substr(0, 4).c_str())* 10000 +
						std::atoi(dateStr.substr(5, 2).c_str())* 100 +
						std::atoi(dateStr.substr(8, 2).c_str());
			}
			if (dateInt == -1)
			{
				std::cerr << "Date bad format :" << dateStr << std::endl;
				continue;
			}
			float value = 0.0;
			if (std::getline(ss, valueStr))
			{
				if (!valueStr.empty())
				{
					value = std::atof(valueStr.c_str());
					if (value < 0)
					{
						std::cerr << "negative value ignored : "<< valueStr << std::endl;
						continue;
					}
				}
			}
			_database[dateInt] = value;
		}
	}
	file.close();
}
void	BitcoinExchange::displayBtcValue(std::ifstream& inputFile)
{
	
}
void	BitcoinExchange::findclosestValue(int& date, float& value) const
{

}
