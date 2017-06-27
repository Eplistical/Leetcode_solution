#ifndef _SHOWVEC_HPP
#define _SHOWVEC_HPP

#include <iostream>
#include <vector>

template <typename ParamType> 
inline void showvec(std::vector<ParamType> v) {
	for (auto& i : v) {
		std::cout << i << "\t";
	}
	std::cout << "\n";
}

#endif
