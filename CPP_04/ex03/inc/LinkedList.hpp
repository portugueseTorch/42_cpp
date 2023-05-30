#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include "AMateria.hpp"

class AMateria;

typedef struct s_node {
	AMateria *materia;
	struct s_node *next;
}	Node;

class LinkedList
{
	public:
		LinkedList();
		LinkedList(const LinkedList &obj);
		LinkedList &operator=(const LinkedList &obj);
		~LinkedList();

		void addNode(AMateria *m);
		void clearItems();
	private:
		Node *_head;
};

#endif
