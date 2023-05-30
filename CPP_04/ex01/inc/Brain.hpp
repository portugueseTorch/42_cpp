#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();

		void	setIdea(const std::string &idea);
		int		getNumIdeas() const;
		void	displayIdeas() const;
	private:
		std::string _ideas[100];
		int	_num_ideas;
};

#endif
