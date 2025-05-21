/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:53:25 by flmuller          #+#    #+#             */
/*   Updated: 2025/05/21 15:04:05 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGELIST_HPP
# define PMERGELIST_HPP

# include "PmergeMe.hpp"

class PmergeList : public std::list<int>
{
	private:
		void	insertionSort(std::list<int>& lst);
		void	mergeInsertSort(std::list<int> &lst);
		std::list<int>	mergeMiniMaxi(const std::list<int>& minima, const std::list<int>& maxima);
		void	insertSorted(std::list<int> &lst, int value);
	public:
		PmergeList();
		PmergeList(PmergeList const& obj);
		~PmergeList();
		PmergeList& operator=(PmergeList const& obj);
		void	MISort();
};

#endif