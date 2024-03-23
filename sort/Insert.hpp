#include <vector>
using namespace std;

//插入排序


template<class T>
class Insert
{
public:
	Insert() {};
	~Insert() {};
	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
};

template<class T>
inline void Insert<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	if (compare == nullptr)
	{
		return;
	}

	int n = vec.size();
	T temp;
	bool flag = true;

	for (int i = 1; i < n; ++i)
	{
		temp = vec.at(i);
		flag = true;
		for (int j = i - 1; j > -1; --j)
		{
			if (!compare(temp, vec.at(j)))
			{
				vec[j + 1] = temp;
				flag = false;
				break;
			}
			else
			{
				vec[j + 1] = vec.at(j);
			}
		}
		if (flag)
		{
			vec[0] = temp;
		}
	}
}