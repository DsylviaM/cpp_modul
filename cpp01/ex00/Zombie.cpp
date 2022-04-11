#include "Zombie.hpp"

const std::string &Zombie::getName() const {
	return this->name;
}

Zombie::Zombie(const std::string &name) : name(name) {
	this->ZombieCall();
	std::cout << "successful CREATED\n\n";
}

Zombie::~Zombie() {
	this->ZombieCall();
	std::cout << "successful DELETED\n\n";
}

void Zombie::ZombieCall() {
	std::cout << "Zombie <" << this->name <<">\n";
}

void Zombie::announce() {
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}
