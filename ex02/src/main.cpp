/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:58 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/07 12:02:32 by flmuller         ###   ########.fr       */
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
	/* PmergeList list; */
	PmergeVector vector;
	for (int i = 0; i < ac; ++i)
	{
		if (atoi(av[i]) < 0)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		/* list.push_back(atoi(av[i])); */
		vector.push_back(atoi(av[i]));
	}
	vector.MISort();
	for (size_t i = 0; i < vector.size(); ++i)
	{
		std::cout << vector[i];
	}
	return(0);
}