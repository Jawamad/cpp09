/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:57:13 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/03 16:18:44 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include "PmergeList.hpp"
#include "PmergeVector.hpp"

#endif
=======
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
>>>>>>> cccec2a5df13bb3202b3252e9a7f6f5ed837a61c
