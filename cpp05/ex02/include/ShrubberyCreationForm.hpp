/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:25 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 10:51:36 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string m_target;

	public:
		// ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy); // copy constructor
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy); // assignment

		std::string getTarget( void ) const;

		void beExecuted(const Bureaucrat& executor) const;
};

#endif