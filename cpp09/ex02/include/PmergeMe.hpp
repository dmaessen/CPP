/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/13 10:55:20 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
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
        ~PmergeMe(); // virtual??
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        
        int validateInput(char *argv);
        void loadInput(void);

        //void sort(std::string const &input);
        int sort(int argc, char **argv);
        
        class NotIntException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    

    template<typename T>
	void mergeinsertSort(T &container, int l, int r, int k) // l = 0 // r = .size() -1 // k = 100
    {
    
    }
};

#endif