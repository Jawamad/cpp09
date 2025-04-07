/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:33:09 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/07 09:49:57 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <sstream>

class RPN :public std::stack <int>
{
	private:
		int	calc(char symb);
	public:
		RPN();
		RPN(RPN const& obj);
		~RPN();
		RPN& operator=(RPN const& obj);
		int	addNewSym(std::string arg);
};

#endif