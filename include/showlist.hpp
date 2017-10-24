#ifndef _SHOWLIST_HPP
#define _SHOWLIST_HPP

#include <iostream>

template <typename ParamType> 
inline void showlist(ParamType* head) {
	ParamType *p = head;
	while (p != NULL) {
		std::cout << p->val << " -> ";
		p = p->next;
	}
	std::cout << "NULL" << "\n";
}

#endif
