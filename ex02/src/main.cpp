/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
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
=======
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:04:07 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/01 15:56:33 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"


int main(int ac, char** arg)
{
	if (ac !=2)
	{
		std::cout << "Error : too many arguments" << std::endl;
		return (1);
	}
	std::stringstream ss(arg[1]);
	RPN stack;
	std::string token;
	while (ss >> token)
	{
		if (!stack.addNewSym(token))
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	if (stack.size() > 1)
	{
		std::cout << "Error too many numbers in the stack" << std::endl;
		return (1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
>>>>>>> cccec2a5df13bb3202b3252e9a7f6f5ed837a61c
}