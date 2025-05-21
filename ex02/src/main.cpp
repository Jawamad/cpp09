/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:58 by flmuller          #+#    #+#             */
/*   Updated: 2025/05/21 15:54:20 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 3)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeList list;
	PmergeVector vector;
	for (int i = 1; i < ac; ++i)
	{
		if (atoi(av[i]) < 0)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		list.push_back(atoi(av[i]));
		vector.push_back(atoi(av[i]));
	}
	std::cout << "Before:	" << vector[0];
	for (size_t i = 1; i < vector.size(); ++i)
	{
		std::cout << " " << vector[i];
	}
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	vector.MISort();
	std::clock_t endVec = std::clock();
	double durationVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:	" << vector[0];
	for (size_t i = 1; i < vector.size(); ++i)
	{
		std::cout << " " << vector[i];
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << durationVec << " µs" << std::endl;
	
	// std::list<int>::iterator it = list.begin();
	// std::cout << "Before:	" << *it++;
	// while (it != list.end())
	// {
	// 	std::cout << " " << *it;
	// 	it++;
	// }
	// std::cout << std::endl;

	std::clock_t startList = std::clock();
	list.MISort();
	std::clock_t endList = std::clock();
	double durationList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;
	
	// it = list.begin();
	// std::cout << "After:	" << *it++;
	// while (it != list.end())
	// {
	// 	std::cout << " " << *it;
	// 	it++;
	// }
	// std::cout << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << durationList << " µs" << std::endl;
	return(0);
}