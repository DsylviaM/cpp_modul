#include "phonebook_main.hpp"

void	ft_add(Phonebook *phonebook, int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "Please enter first name:\n> ";
	std::getline(std::cin, first_name);
	if (std::cin.eof())
		return ;
	std::cout << "Please enter last name:\n> ";
	std::getline(std::cin, last_name);
	if (std::cin.eof())
		return ;
	std::cout << "Please enter nickname:\n> ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;
	std::cout << "Please enter phone number:\n> ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
		return ;
	std::cout << "Please enter secret:\n> ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
		return ;

	(*phonebook).create_new_contact(i, first_name, last_name, nickname, phone_number, darkest_secret);
}

void	ft_search(Phonebook *phonebook, int i)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	user_index;
	int			index;

	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int j = 1; j < i + 1; j++)
	{
		first_name = (*phonebook).get_first_name(j - 1);
		last_name = (*phonebook).get_last_name(j - 1);
		nickname = (*phonebook).get_nickname(j - 1);
		if (first_name.length() >= 10)
		{
			first_name.resize(9);
			first_name.resize(10, '.');
		}
		if (last_name.length() >= 10)
		{
			last_name.resize(9);
			last_name.resize(10, '.');
		}
		if (nickname.length() >= 10)
		{
			nickname.resize(9);
			nickname.resize(10, '.');
		}
		std::cout << std::setw(10) << j << "|" << std::setw(10) << first_name << "|" << std::setw(10) << last_name << "|" << std::setw(10) << nickname<< "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Please enter the contact's index to see more details:\n> ";
	std::getline(std::cin, user_index);
	if (std::cin.eof())
		return ;
	index = atoi(user_index.c_str());
	if (index && index >=1 && index <= i)
		(*phonebook).get_contact(stoi(user_index) - 1).ft_print();
	else
		std::cout << "Wrong index" << "\n> ";
	return ;
}

int main(void)
{
	std::string		user_command;
	Phonebook		phonebook;
	int				i;

	i = 0;
	while (!std::cin.eof())
	{
		std::cout << "Please enter a command (SEARCH / ADD / EXIT)\n> ";
		std::getline(std::cin, user_command);
		if (user_command == "EXIT")
			return (0);
		else if (user_command == "ADD")
		{
			if (i >= 8)
				std::cout << "Cannot add more than 8 contacts\n> ";
			else
			{
				ft_add(&phonebook, i);
				i++;
			}
		}
		else if (user_command == "SEARCH")
		{
			ft_search(&phonebook, i);
		}
		else
			if (!std::cin.eof())
				std::cout << "Only ADD, SEARCH and EXIT commands are accepted\n";
	}
	return (0);
}