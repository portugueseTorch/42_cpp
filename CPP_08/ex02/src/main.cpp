#include "../inc/MutantStack.hpp"

int main() {
	std::cout << "MUTANT STACK" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		display(mstack);
		std::cout << "Top of the MutantStack: " << mstack.top() << std::endl;
		std::cout << "MutantStack size: " << mstack.size() << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\nLIST" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.pop_back();
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		display(lst);
		std::cout << "Top of the List: " << lst.back() << std::endl;
		std::cout << "List size: " << lst.size() << std::endl;
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}