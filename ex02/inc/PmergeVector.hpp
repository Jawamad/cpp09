/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:56:11 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/03 16:03:12 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEVECTOR_HPP
#define PMERGEVECTOR_HPP

#include <iostream>
#include <vector>

class PmergeVector : public std::vector<int>
{
	public:
		PmergeVector();
		PmergeVector(PmergeVector& const obj);
		~PmergeVector();
		PmergeVector& operator=(PmergeVector& const obj);
		int	MISort();
};

#endif