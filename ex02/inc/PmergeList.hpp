/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:53:25 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/03 15:54:46 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGELIST_HPP
#define PMERGELIST_HPP

#include <iostream>
#include <list>

class PmergeList : public std::list<int>
{
	public:
		PmergeList();
		PmergeList(PmergeList& const obj);
		~PmergeList();
		PmergeList& operator=(PmergeList& const obj);
		int	MISort();
};

#endif