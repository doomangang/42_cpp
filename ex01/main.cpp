/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:41:37 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/13 18:01:17 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb = PhoneBook();
	std::string userCmd;
	while (1)
	{
		//EOF and input ERROR
		std::cout << std::endl << "\033[1mADD, SEARCH, or EXIT?\033[0m" << std::endl;
		if (!std::getline(std::cin, userCmd)) {
			if (std::cin.eof()) {
				std::cout << "\033[32mEOF - bye...\033[0m\n";
				break ;
			}
			else {
				std::cout << "Something gone wrong, please try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
			}
		}
		if (userCmd == "ADD")
			pb.setContact();
		else if (userCmd == "SEARCH"){
			pb.display();
		}
		else if (userCmd == "EXIT")
			break ;
		else
			std::cout << "\033[31m\nwrong command!\033[0m\n";
	}
}