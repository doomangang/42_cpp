/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:40:59 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/13 18:01:53 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->availSlot = 0;
	return ;
}

void	PhoneBook::setContact(void)
{
	if (contacts[availSlot % 8].setContact())
		availSlot++;
}


void	PhoneBook::display(void)
{
    displayContactList();
	if (availSlot == 0)
	{
		std::cout << "\033[34m\nPhonebook is empty\033[0m\n";
		return ;
	}
	size_t	userIdx;
	while (1){
		std::cout << "\nwhich contact?\n";
		std::string	userInput;
		//EOF and ERROR
		if (!std::getline(std::cin, userInput)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "\033[32mEOF... Returning to main menu.\033[0m" << std::endl;
				clearerr(stdin);
				std::cin.clear();
				return ;
			}
			else {
				std::cout << std::endl << "\033[31mInput Error. Please try again.\033[0m" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
			}
		}
		userIdx = (size_t)userInput[0] - 49;
		//OUT OF INDEX
		if (userIdx > 7 || userIdx >= availSlot)
		{
			std::cout << "\033[31m\nwrong index\033[0m\n";
			continue ;
		}
		else
			break ;
	}
	displaySelectedList(userIdx);
}

void	PhoneBook::displayContactList(void)
{
	std::cout << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << std::right << "First Name" << "|"
              << std::setw(10) << std::right << "Last Name" << "|"
              << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < 8; ++i) {
            std::cout << std::setw(10) << std::right << i + 1 << "|"
                      << std::setw(10) << std::right << formatString(contacts[i].getFirstName()) << "|"
                      << std::setw(10) << std::right << formatString(contacts[i].getLastName()) << "|"
                      << std::setw(10) << std::right << formatString(contacts[i].getNickname()) << std::endl;
    }
}

void	PhoneBook::displaySelectedList(size_t userIdx)
{
	std::cout << "First Name\t:" << contacts[userIdx].getFirstName() << std::endl;
	std::cout << "Last Name\t:" << contacts[userIdx].getLastName() << std::endl;
	std::cout << "Nickname\t:" << contacts[userIdx].getNickname() << std::endl;
	std::cout << "Phone Number\t:" << contacts[userIdx].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret\t:" << contacts[userIdx].getDarkestSecret() << std::endl;
}

std::string PhoneBook::formatString(const std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}

PhoneBook::~PhoneBook(void)
{
	
}