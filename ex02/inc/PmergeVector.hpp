/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:56:11 by flmuller          #+#    #+#             */
/*   Updated: 2025/05/21 14:47:45 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEVECTOR_HPP
#define PMERGEVECTOR_HPP

#include "PmergeMe.hpp"

class PmergeVector : public std::vector<int>
{
	private:
		void				insertionSort(std::vector<int>& arr, int left, int right);
		void				mergeInsertSort(std::vector<int> &arr, std::vector<int> &temp, int left, int right);
		std::vector<int>	mergeMiniMaxi(const std::vector<int>& minima, const std::vector<int>& maxima);
		void				insertSorted(std::vector<int> &arr, int element);
	public:
		PmergeVector();
		PmergeVector(PmergeVector const& obj);
		~PmergeVector();
		PmergeVector& operator=(PmergeVector const& obj);
		void	MISort();
};

#endif