#pragma once
#include <iostream>
#include <string>
#include <vector>

#define HASHA 5409
#define HASHB 76963
#define HASHC 86969
#define FIRST 37

unsigned util_HashString(const char* s)
{
	unsigned h = FIRST;
	while (*s)
	{
		h = (h * HASHA) ^ (s[0] * HASHB);
		s++;
	}
	return h % HASHC;
}

template<typename T> void printVector(std::vector<T> v)
{
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << "\n";
	}
}