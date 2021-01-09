#pragma once

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