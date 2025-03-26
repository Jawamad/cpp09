/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:48:46 by flmuller          #+#    #+#             */
/*   Updated: 2025/03/26 15:50:25 by flmuller         ###   ########.fr       */
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

int	BitcoinExchange::setData(std::string fileStr)
{
	std::ifstream file(fileStr.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error cannot open file" << std::endl;
		return (0);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string dateStr, valueStr;
		if (std::getline(ss, dateStr, ','))
		{
			int dateInt = -1;
			dateInt = stringToDateInt(dateStr);
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
	return (1);
}

void	BitcoinExchange::displayBtcValue(std::string inputFile)
{
	std::ifstream file(inputFile.c_str());

	if (!file)
	{
		std::cerr << "Error invalid input file" << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string dateStr, valueStr;

		if (!std::getline(ss, dateStr, '|'))
		{
			std::cerr << "line bad format : " << line << std::endl;
			continue;
		}
		if (!std::getline(ss, valueStr))
		{
			std::cerr << "line without value : " << line << std::endl;
			continue;
		}
		if (dateStr.empty() || valueStr.empty())
		{
			std::cerr << "empty field " << line << std::endl;
			continue;
		}

		int dateInt = stringToDateInt(line);
		if (dateInt ==-1)
		{
			std::cerr << "Invalid date ignored: " << line << std::endl;
			continue; 
		}

		char *end;
		float fileValue = std::strtof(valueStr.c_str(), &end);

		if (*end != '\0' || fileValue < 0 || fileValue > 1000 || fileValue == std::numeric_limits<float>::infinity())
		{
			std::cerr << "Invalid value ignored : " << valueStr << std::endl;
			continue;
		}

		int closestDate = findclosestDate(dateInt);
		if (closestDate != -1)
		{
			float mapValue = _database.find(closestDate)->second;
			float result = fileValue * mapValue;
			std::cout << dateInt << " => " << fileValue << " = " << result << std::endl;
		}
		else
			std::cerr << "Error: no inferior date : " << dateInt << std::endl;
	}
	file.close();
}
int	BitcoinExchange::findclosestDate(int& date) const
{
	std::map<int, float>::const_iterator lower = _database.lower_bound(date);
	if (lower != _database.end() && lower->first == date)
		return lower->first;
	if (lower == _database.begin())
		return -1;
	--lower;
	return lower->first;
}

int	stringToDateInt(const std::string &dateStr)
{
	if (!isValidDate(dateStr))
		return -1;
	return	std::atoi(dateStr.substr(0, 4).c_str())* 10000 +
			std::atoi(dateStr.substr(5, 2).c_str())* 100 +
			std::atoi(dateStr.substr(8, 2).c_str());
}

bool	isValidDate(const std::string &dateStr)
{
	if (dateStr[4] != '-' || dateStr[7] != '-') return false;

	int year = std::atoi(dateStr.substr(0, 4).c_str());
	int month = std::atoi(dateStr.substr(5, 2).c_str());
	int day = std::atoi(dateStr.substr(8, 2).c_str());

	if (year < 1900 || year > 2100) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	return true;
}