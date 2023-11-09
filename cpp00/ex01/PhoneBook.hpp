/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:43 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/09 15:27:44 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>

class PhoneBook
{
	private:
		std::size_t	m_count_contacts;
		Contact		contact[8];

	public:
		void		init();
		void		cmd_add();
		Contact		getInfo();
		void		cmd_search();
		void		printinfo(Contact contact, std::size_t i);
		void		printinfo_of_x(Contact contact);
};

#endif