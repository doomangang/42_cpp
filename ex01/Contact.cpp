/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:41:28 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/13 18:01:34 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

bool	Contact::setContact(void)
{
	std::string fName;
	std::string lName;
	std::string nName;
	std::string number;
	std::string secret;

	if (!getInfo("First Name", fName))
		return false;
	if (!getInfo("Last Name", lName))
		return false;
	if (!getInfo("Nickname", nName))
		return false;
	if (!getInfo("Phone Number", number))
		return false;
	if (!getInfo("Darkest Secret", secret))
		return false;
	firstName = fName;
	lastName = lName;
	nickName = nName;
	phoneNumber = number;
	darkestSecret = secret;
	std::cout << std::endl << "Contact successfully added!" << std::endl;
	return true;
}
std::string Contact::getFirstName()
{
	return (this->firstName);
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

std::string Contact::getNickname()
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

bool	Contact::getInfo(std::string fieldname, std::string &field)
{
	while (1)
	{
		std::cout << fieldname << "?" << std::endl;
		//EOF and ERROR
		if (!std::getline(std::cin, field)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "\033[32mEOF... Returning to main menu.\033[0m" << std::endl;
				clearerr(stdin);
				std::cin.clear();
				return false;
			}
			else {
				std::cout << std::endl << "\033[31mInput Error. Please try again.\033[0m" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
			}
		}
		//empty input
		if (!field.empty())
			return (true);
		std::cout << "\033[31mempty value not allowed\033[0m\n";
	}
}

Contact::~Contact(void)
{
	
}