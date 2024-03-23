#pragma once
#include <vector>
using namespace std;

//计数排序，有很强的局限性，仅适合待排列数组范围不是很大且数据类型满足一定条件才能使用
//本例只考虑整数，且从小到大排序

class Counting
{
public:
	Counting() {};
	~Counting() {};

	static void Sort(vector<int>& vec);
};

inline void Counting::Sort(vector<int>& vec)
{
	int nMax = INT_MIN;
	int nMin = INT_MAX;
	//找到最大值和最小值确定新建数组长度
	for (auto it : vec)
	{
		if (it > nMax)
		{
			nMax = it;
		}
	}
	for (auto it : vec)
	{
		if (it < nMin)
		{
			nMin = it;
		}
	}

	int n = nMax - nMin + 1;
	int* countArr = new int[n];
	fill(countArr, countArr + n, 0);

	for (auto it : vec)
	{
		++countArr[it - nMin];
	}

	int it = 0;
	for (int i = 0; i < n; ++i)
	{
		while (countArr[i] > 0)
		{
			vec[it++] = i + nMin;
			--countArr[i];
		}
	}
}