/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:41:45 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/13 17:39:18 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		//attributes
		Contact		contacts[8];
		size_t		availSlot;
		//methods
		std::string formatString(const std::string str);
		void		displayContactList(void);
		void		displaySelectedList(size_t userIdx);
	public:
		//constructor & destructor
		PhoneBook();
		~PhoneBook();
		//methods
		void		setContact(void);
		void		display();
};

#endif