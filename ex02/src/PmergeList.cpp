/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:05:44 by flmuller          #+#    #+#             */
/*   Updated: 2025/05/21 15:04:15 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeList::PmergeList(){}
PmergeList::PmergeList(PmergeList const& obj)
{
	*this = obj;
}
PmergeList::~PmergeList(){}
PmergeList& PmergeList::operator=(PmergeList const& obj)
{
	list::operator=(obj);
	return *this;
}
void	PmergeList::MISort()
{
	mergeInsertSort(*this);
}
void	PmergeList::insertionSort(std::list<int>& lst)
{
	if (lst.size() < 2) return;
	std::list<int>::iterator it = ++lst.begin();
	while (it != lst.end())
	{
		int val = *it;
		std::list<int>::iterator prev = it;
		--prev;
		if (val < *prev)
		{
			std::list<int>::iterator pos = lst.begin();
			while (pos != it && *pos < val)
				++pos;
			lst.insert(pos, val);
			it = lst.erase(it);
		}
		else
			++it;
	}
}

void	PmergeList::mergeInsertSort(std::list<int> &lst)
{
	if (lst.size() <= 16)
	{
		insertionSort(lst);
		return;
	}
	std::list<int> minima, maxima;
	std::list<int>::iterator it = lst.begin(); 
	while (it != lst.end())
	{
		int first = *it++;
		if (it != lst.end())
		{
			int second = *it++;
			if (first > second)
				std::swap(first, second);
			minima.push_back(first);
			maxima.push_back(second);
		}
		else
		{
			minima.push_back(first);
		}
	}
	mergeInsertSort(minima);
	std::list<int> merged = mergeMiniMaxi(minima, maxima);
	lst = merged;
}

std::list<int>	PmergeList::mergeMiniMaxi(const std::list<int>& minima, const std::list<int>& maxima)
{
	std::list<int> result = minima;
	for (std::list<int>::const_iterator it = maxima.begin(); it != maxima.end(); ++it)
		insertSorted(result, *it);
	return result;
}

void	PmergeList::insertSorted(std::list<int> &lst, int value)
{
	std::list<int>::iterator pos = lst.begin();
	while(pos != lst.end() && * pos < value)
		++pos;
	lst.insert(pos, value);
}