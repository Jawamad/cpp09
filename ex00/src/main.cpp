/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:27:14 by flmuller          #+#    #+#             */
/*   Updated: 2025/03/26 15:10:46 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		BitcoinExchange btc;
		if (btc.setData("data/data.csv"))
		{
			btc.displayBtcValue(av[1]);
		}
		else
			std::cerr << "Invalid file data" << std::endl;
	}
	else
		std::cerr << "Error : wrong number of arguments." << std::endl;
	std::cout << "Auto quit" << std::endl;
	return 1;
}