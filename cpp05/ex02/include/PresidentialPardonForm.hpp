/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:25 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:02:32 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string m_target;

	public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm &copy); // copy constructor
        PresidentialPardonForm& operator=(const PresidentialPardonForm &copy); // assignment

		std::string getTarget( void ) const;

		void beExecuted(const Bureaucrat& executor) const;
	
};

#endif