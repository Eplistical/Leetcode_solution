#ifndef _SHOWVEC_HPP
#define _SHOWVEC_HPP

#include <iostream>
#include <vector>

template <typename ParamType> 
inline void showvec(const std::vector<ParamType>& v) {
	for (const auto& i : v) {
		std::cout << i << "\t";
	}
	std::cout << "\n";
}

#endif
