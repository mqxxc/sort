#pragma once
#include <vector>
using namespace std;

//堆排序
template <class T>
class Heapsort
{
public:
	Heapsort() {};
	~Heapsort() {};

	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
private:
	static void Composting(vector<T>& vec, int left, int right, bool(*compare)(T, T));

};

template<class T>
inline void Heapsort<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	int n = vec.size();
	//创建一个(最大或者最小)堆
	for (int i = n / 2 - 1; i > -1; --i)
	{
		Composting(vec, i, n - 1, compare);
	}

	//开始整理数组，后半段为整完成数组，前半段一直维护堆
	for (int i = n - 1; i > 0; --i)
	{
		T temp = vec.at(0);
		vec[0] = vec.at(i);
		vec[i] = temp;
		Composting(vec, 0, i - 1, compare);
	}
}

template<class T>
inline void Heapsort<T>::Composting(vector<T>& vec, int left, int right, bool(*compare)(T, T))
{
	int son = left * 2 + 1;
	while (son < right + 1)
	{
		if (son + 1 <= right && !compare(vec.at(son), vec.at(son + 1)))
		{
			++son;
		}
		if (compare(vec.at(left), vec.at(son)))
		{
			return;
		}
		else
		{
			T temp = vec.at(left);
			vec[left] = vec.at(son);
			vec[son] = temp;
		}
	}
}