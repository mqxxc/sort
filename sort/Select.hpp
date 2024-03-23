#include <vector>
using namespace std;

//选择排序
template<class T>
class Select
{
public:
	Select() {};
	~Select() {};

	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
};

template<class T>
void Select<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	if (compare == nullptr)
	{
		return;
	}
	
	int n = vec.size();
	int k = 0;
	T temp;
	for (int i = 0; i < n; ++i)
	{
		temp = vec.at(i);
		k = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (!compare(temp, vec.at(j)))
			{
				temp = vec.at(j);
				k = j;
			}
		}
		if (k != i)
		{
			vec[k] = vec.at(i);
			vec[i] = temp;
		}
	}
}