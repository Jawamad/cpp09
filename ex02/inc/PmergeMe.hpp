/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:33:09 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/02 14:22:02 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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