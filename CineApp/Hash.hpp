#pragma once
#include <string>
static class Security
{
public:
	static int Hash(char* s, int seed)
	{
		//Fisher-Yates shuffle
		int n = strlen(s);
		for (int i = n - 1; i > 0; i--)
		{
			int j = rand() % (i + 1);
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
		//Hash
		int hash = seed;
		for (int i = 0; i < n; i++)
		{
			hash = hash * (seed%100) + s[i];
		}
		return hash;
	}

	static int SeedGenerator(int id)
	{
		System::Random r;
		int newSeed = id * r.Next(1, 5);
		if (SeedGenerator(newSeed) > 999)
		{
			return newSeed;
		}
		else
		{
			return SeedGenerator(newSeed);
		}
	}
};