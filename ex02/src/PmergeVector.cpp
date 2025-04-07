/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:07:49 by flmuller          #+#    #+#             */
/*   Updated: 2025/04/07 12:04:21 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeVector::PmergeVector(){}
PmergeVector::PmergeVector(PmergeVector const& obj)
{
	*this = obj;
}
PmergeVector::~PmergeVector(){}
PmergeVector& PmergeVector::operator=(PmergeVector const& obj)
{
	vector::operator=(obj);
	return *this;
}
void	PmergeVector::MISort()
{
	std::vector<int> temp;
	mergeInsertSort(*this, temp, 0, size());
}

void	PmergeVector::insertionSort(std::vector<int> arr, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr [j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void	PmergeVector::mergeInsertSort(std::vector<int> &arr, std::vector<int> &temp, int left, int right)
{
	if (right - left <= 16)
	{
		insertionSort(arr, left, right);
		return;
	}
	std::vector<int> minima, maxima;
	for (int i = left; i + 1 < right; i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		minima.push_back(arr[i]);
		maxima.push_back(arr[i + 1]);
	}
	if ((right - left) % 2 == 1)
		minima.push_back(arr[right - 1]);
	mergeInsertSort(minima, temp, 0, minima.size());
	temp = mergeMiniMaxi(minima, maxima);
	for (size_t i = 0; i < temp.size(); ++i)
		arr[left + i] = temp[i];
}

std::vector<int>	PmergeVector::mergeMiniMaxi(const std::vector<int>& minima, const std::vector<int>& maxima)
{
	std::vector<int> result = minima;
	for (size_t i = 0; i < maxima.size(); ++i)
		insertSorted(result, maxima[i]);
	return result;
}

void	PmergeVector::insertSorted(std::vector<int> &arr, int element)
{
	std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), element);
	arr.insert(pos, element);
}