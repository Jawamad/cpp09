/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
}