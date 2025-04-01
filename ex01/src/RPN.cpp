/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:05:05 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/01 15:54:48 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int	RPN::addNewSym(std::string arg)
{
	if (arg.size() > 1)
		return (0);
	if (arg.at(0) >= '0' && arg.at(0) <= '9')
		push(atoi(arg.c_str()));
	else if (!calc(arg.at(0)))
		return (0);
	return (1);
}


int	RPN::calc(char symb)
{
	if (size() < 2)
		return (0);
	int i = top();
	pop();
	int j = top();
	pop();
	switch (symb)
	{
		case '*':
			push(j * i);
		break;
		case '-':
			push(j - i);
		break;
		case '+':
			push(j + i);
		break;
		case '/':
			if (i == 0)
				return (0);
			push(j / i);
		break;
	
		default:
			return (0);
			break;
	}
	return (1);
}