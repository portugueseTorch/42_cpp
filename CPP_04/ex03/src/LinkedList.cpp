#include "../inc/LinkedList.hpp"

LinkedList::LinkedList(): _head(NULL) {}

LinkedList::LinkedList(const LinkedList &obj) {
	*this = obj;
}

LinkedList &LinkedList::operator=(const LinkedList &obj) {
	if (this == &obj)
		return *this;
	_head = obj._head;
	return *this;
}

LinkedList::~LinkedList() {
	Node *tmp = _head;

	if (!_head)
		return ;
	while (_head) {
		_head = _head->next;
		delete tmp;
		tmp = _head;
	}
}

void LinkedList::addNode(AMateria *m) {
	Node *node = new Node;

	node->materia = m;
	node->next = NULL;
	if (!_head) {
		_head = node;
		return ;
	}

	Node *tmp = _head;
	for (; tmp->next; tmp = tmp->next)
		;
	tmp->next = node;
}

void LinkedList::clearItems() {
	Node *tmp = _head;
	if (!tmp)
		return ;
	for (; tmp; tmp = tmp->next) {
		if (tmp->materia)
			delete tmp->materia;
	}
}
