#include <vector>
using namespace std;

//归并排序
template<class T>
class Merge
{
public:
	Merge() {};
	~Merge() {};

	//迭代
	static void Sort_iter(vector<T>& vec, bool(*compare)(T, T) = nullptr);
	//递归
	static void Sort_recursion(vector<T>& vec, bool(*compare)(T, T) = nullptr);
private:
	static void Recursion_auxiliary(vector<T>& arr, vector<T>& temp,
		int start, int end, bool(*compare)(T, T));
};

template<class T>
void Merge<T>::Sort_iter(vector<T>& vec, bool(*compare)(T, T))
{//自下而上
	if (compare == nullptr)
	{
		return;
	}
	
	int n = vec.size();
	auto index = vec.begin();
	vector<T> temparr(n);
	auto arr = temparr.begin();

	for (int step = 1; step < n; step += step)
	{
		for (int start = 0; start < n; start += step * 2)
		{
			int it, left1, right1, left2, right2;
			it = left1 = start;
			right1 = left2 = min(n, start + step);
			right2 = min(n, start + step * 2);
			while (left1 < right1 && left2 < right2)
			{
				*(arr + it++) = compare(*(index + left1), *(index + left2)) ? *(index + left1++) : *(index + left2++);
			}
			while (left1 < right1)
			{
				*(arr + it++) = *(index + left1++);
			}
			while (left2 < right2)
			{
				*(arr + it++) = *(index + left2++);
			}
		}
		auto temp = index;
		index = arr;
		arr = temp;
	}
	if (index != vec.begin())
	{
		vec.swap(temparr);
	}
	temparr.clear();
}

template<class T>
void Merge<T>::Sort_recursion(vector<T>& vec, bool(*compare)(T, T))
{//自上而下
	int n = vec.size();
	vector<T> temp(n,0);
	Recursion_auxiliary(vec, temp, 0, n, compare);
}

template<class T>
inline void Merge<T>::Recursion_auxiliary(vector<T>& arr, vector<T>& temp, int start, int end, bool(*compare)(T, T))
{
	if (start < end)
	{
		return;
	}
	int start2, end1;
	int it = start;
	start2 = end1 = (end - start) / 2;
	Recursion_auxiliary(arr, temp, start, end1, compare);
	Recursion_auxiliary(arr, temp, start2, end, compare);

	while (start < end1 && start2 < end)
	{
		temp[it++] = !compare(arr[start], arr[start2]) ? arr[start++] : arr[start2++];
	}
	while (start < end1)
	{
		temp[it++] = arr[start++];
	}
	while (start2 < end)
	{
		temp[it++] = arr[start2++];
	}
	arr.swap(temp);
}