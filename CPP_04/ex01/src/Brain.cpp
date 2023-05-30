#include "../inc/Brain.hpp"

Brain::Brain(): _num_ideas(0) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	_num_ideas = obj.getNumIdeas();
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(const std::string &idea) {
	if (_num_ideas >= 100) {
		std::cout << "My brain is full man, I'm just an animal..." << std::endl;
		return ;
	}
	_ideas[_num_ideas++] = idea;
}

int	Brain::getNumIdeas() const {
	return _num_ideas;
}

void	Brain::displayIdeas() const {
	for (int i = 0; i <= _num_ideas; i++)
		std::cout << _ideas[i] << std::endl;
}
