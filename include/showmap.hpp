#ifndef _SHOWMAP_HPP
#define _SHOWMAP_HPP

#include <iostream>
#include <map>
#include <unordered_map>

template <typename KeyType, typename ValType> 
inline void showmap(const std::map<KeyType, ValType>& m) {
	for (const auto& i : m) {
		std::cout << i.first << " => " << i.second << "\n";
	}
	std::cout << "\n";
}

template <typename KeyType, typename ValType> 
inline void showmap(const std::unordered_map<KeyType, ValType>& m) {
	for (const auto& i : m) {
		std::cout << i.first << " => " << i.second << "\n";
	}
	std::cout << "\n";
}

#endif
