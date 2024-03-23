#pragma once
#include <vector>
using namespace std;

//快速排序
template <class T>
class Quicksort
{
public:
	Quicksort() {};
	~Quicksort() {};

	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
private:
	static void recursion(vector<T>& vec, int low, int right, bool(*compare)(T, T));
	static int Partition(vector<T>& vec, int low, int right, bool(*compare)(T, T));
};

template<class T>
inline void Quicksort<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	recursion(vec, 0, vec.size() - 1, compare);
}

template<class T>
void Quicksort<T>::recursion(vector<T>& vec, int low, int right, bool(*compare)(T, T))
{
	if (low < right)
	{
		int pos = Partition(vec, low, right, compare);
		recursion(vec, low, pos - 1, compare);
		recursion(vec, low, pos, compare);
	}
}

template<class T>
int Quicksort<T>::Partition(vector<T>& vec, int low, int right, bool(*compare)(T, T))
{
	int pivot = vec.at(low);
	while (low < right)
	{
		while (low <right && !compare(pivot,vec.at(right)))
		{
			--right;
		}
		vec[low] = vec.at(right);
		while (low < right && compare(pivot, vec.at(low)))
		{
			++low;
		}
		vec[right] = vec.at(low);
	}
	vec[low] = pivot;
	return low;
}

//应对顺序数组排序算法优化：不使用第一个数作为基准使用中间或者收尾末尾中间的中值