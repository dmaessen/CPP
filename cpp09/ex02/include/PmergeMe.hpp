/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/04/17 11:12:28 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <vector>
#include <exception>
#include <time.h>

class PmergeMe
{
    private:
        std::deque<int> _deq;
        std::vector<int> _vec;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        
        int validateInput(char *argv);
        void printVec(void);
        void printDeque(void);

        int sort(int argc, char **argv);
        
        class NotIntException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    
        template<typename T>
        void insertionSort(T &container, int start, int size)
        {
            for (int i = start; i < size; i++) {
                int tmp = container[i + 1];
                int j = i + 1;
                while (j > start && container[j - 1] > tmp) {
                    container[j] = container[j -1];
                    j--;
                }
                container[j] = tmp;
            }
        }

        template<typename T>
        void mergeSort(T& container, int start, int mid, int size)
        {
            int n1 = mid - start + 1;
            int n2 = size - mid;
            
            T leftHalf(n1);
            T rightHalf(n2);
            for (int i = start; i < mid; i++)
                rightHalf[i - start] = container[i];
            int j = 0;
            for (int i = mid; i < size; i++) {
                leftHalf[j] = container[i];
                j++;
            }
            int rIndex = 0;
            int lIndex = 0;
            for (int i = start; i < size; i++) {
                if (rIndex == n2){
                    container[i] = leftHalf[lIndex];
                    lIndex++;
                }
                else if (lIndex == n1){
                    container[i] = rightHalf[rIndex];
                    rIndex++;
                }
                else if (rightHalf[rIndex] > leftHalf[lIndex]) {
                    container[i] = leftHalf[lIndex];
                    lIndex++;
                }
                else {
                    container[i] = rightHalf[rIndex];
                    rIndex++;
                }
            }
        }
        
        template<typename T>
        void mergeinsertSort(T &container, int pos, int size)
        {
            int k = 100;
            if (size - pos > k) {
                int midpoint = (pos + size) / 2;
                mergeinsertSort(container, pos, midpoint);
                mergeinsertSort(container, midpoint + 1, size);
                std::cout << "again\n" << pos << " " << midpoint << " " << size << '\n';
                mergeSort(container, pos, midpoint, size);
            }
            else
                insertionSort(container, pos, size);
        }
};

#endif