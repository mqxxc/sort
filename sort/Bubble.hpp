#pragma once
#include <vector>
using namespace std;

//冒泡排序
template<class T>
class Bubble
{
public:
	Bubble() {};
	~Bubble() {};

	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
};

template<class T>
inline void Bubble<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	if (compare == nullptr)
	{
		return;
	}
	int n = vec.size();
	T temp;
	bool flag = true;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (!compare(vec.at(j), vec.at(j + 1)))
			{
				flag = false;
				temp = vec.at(j);
				vec[j] = vec.at(j + 1);
				vec[j + 1] = temp;
			}
		}
		if(flag)
		{
			break;
		}
		else
		{
			flag = true;
		}
	}
}
