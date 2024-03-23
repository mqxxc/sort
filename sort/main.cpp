#include <iostream>
using namespace std;
#include "Bubble.hpp"
#include "Select.hpp"
#include "Insert.hpp"
#include "Shell.hpp"
#include "Cases.h"
#include "Merge.hpp"
#include "Quicksort.hpp"
#include "Heapsort.hpp"
#include "Counting.hpp"
#include "Bucket.hpp"
#include "Radix.hpp"

int main() 
{
	//Heapsort<int>::Sort(Cases::shaping, &Cases::shapingMax);
	Radix::Sort(Cases::shaping);
	for (auto it : Cases::shaping)
	{
		cout << it << " ";
	}
	return 0;
}