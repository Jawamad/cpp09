/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:58 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/04 11:11:26 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 4)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	int i = 1;
	PmergeList list;
	PmergeVector vector;
	while (i < ac)
	{
		if (atoi(av[i]) < 0)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		list.push_back(atoi(av[i]));
		vector.push_back(atoi(av[i]));
	}
	return(0);
}