#include <vector>
using namespace std;

//希尔排序
template<class T>
class Shell
{
public:
	Shell() {};
	~Shell() {};
	static void Sort(vector<T>& vec, bool(*compare)(T, T) = nullptr);
private:
	static vector<int> getHibbardStepArr(int n);
};

template<class T>
inline void Shell<T>::Sort(vector<T>& vec, bool(*compare)(T, T))
{
	if (compare == nullptr)
	{
		return;
	}
	int n = vec.size();
	T temp;
	int j;
	vector<int> vecStep = getHibbardStepArr(n);
	for (auto step = vecStep.rbegin(); step != vecStep.rend(); ++step)
	{
		for (int i = 0; i < n; ++i)
		{
			temp = vec.at(i);
			for (j = i; j < n - *step && !compare(temp, vec.at(j + *step));j += *step)
			{
					vec[j] = vec.at(j + *step);
			}
			vec[j] = temp;
		}
	}
}

template<class T>
inline vector<int> Shell<T>::getHibbardStepArr(int n)
{
	vector<int> res(n, 1);
	int temp = 1;
	for (int i = 1; temp < n; ++i)
	{
		res[i] = temp;
		temp = 9 * ((1 << 2 * i) - (1 << i)) + 1;
	}
	return res;
}