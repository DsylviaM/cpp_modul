#include "phonebook_main.hpp"

Phonebook::Phonebook()
{

}

Phonebook::~Phonebook()
{
	
}

Contact Phonebook::get_contact(int i)
{
	return (phonebook[i]);
}

std::string	Phonebook::get_first_name(int i)
{
	return (phonebook[i].get_first_name());
}

std::string	Phonebook::get_last_name(int i)
{
	return (phonebook[i].get_last_name());
}

std::string	Phonebook::get_nickname(int i)
{
	return (phonebook[i].get_nickname());
}

std::string	Phonebook::get_phone_number(int i)
{
	return (phonebook[i].get_phone_number());
}

std::string	Phonebook::get_darkest_secret(int i)
{
	return (phonebook[i].get_darkest_secret());
}


void	Phonebook::create_new_contact(int i,
	std::string f, std::string l, std::string n, std::string ph, std::string d)
{
	phonebook[i].ft_set_values(f, l, n, ph, d);
}
