#pragma once
#include <vector>
using namespace std;

//基数排序
class Radix
{
public:
	Radix() {};
	~Radix() {};

	static void Sort(vector<int>& vec);

private:
	static int MaxBit(vector<int>& vec);
};

void Radix::Sort(vector<int>& vec)
{
	int n = vec.size();
	int* counts = new int[10];
	int* temp = new int[n];
	int radix = 1;

	int step = MaxBit(vec);
	for (; step > -1; --step, radix *= 10)
	{
		fill_n(counts, n, 0);

		for (auto it : vec)
		{
			++counts[(it / radix) % 10];
		}

		for (int i = 1; i < 10; ++i)
		{
			counts[i] += counts[i - 1];
		}

		for (auto it : vec)
		{
			temp[--counts[(it / radix) % 10]] = it;
		}

		for (int i = 0; i < n; ++i)
		{
			vec[i] = temp[i];
		}
	}
}

int Radix::MaxBit(vector<int>& vec)
{
	int maxValue = INT_MIN;
	for (auto it : vec)
	{
		if (maxValue < it)
		{
			maxValue = it;
		}
	}
	int step = 0;
	int radix = 1;
	while (maxValue / radix > 0)
	{
		radix *= 10;
		++step;
	}
	return step;
}