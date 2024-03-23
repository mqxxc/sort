#pragma once
#include <vector>
using namespace std;

//桶排序，根据计数排序以及快速排序优化而来，与计数排序一样有一定局限性
//本例仅考虑小于100的正整数,从小到大排序，由十位数组来确定桶的位置。分桶个数不同方法不同,

class Bucket
{
public:
	Bucket() {};
	~Bucket() {};

	static void Sort(vector<int>& vec);

private:
	class Node
	{
	public:
		Node* m_pNext = nullptr;
		int m_nValue = 0;

		Node() {};
		~Node() {};
	};

	static int BUCKET_MAX;
	static Node* Insert(Node* node, int value);
};

void Bucket::Sort(vector<int>& vec)
{
	//创建桶
	int nCount = vec.size();
	vector<Node*> buckets(BUCKET_MAX, nullptr);

	//将数组所有数据分配到对应的桶中
	for (auto it : vec)
	{
		int index = it / BUCKET_MAX;
		buckets[index] = Insert(buckets.at(index), it);
	}
	//顺序读桶完成排序
	int index = 0;
	for (auto it : buckets)
	{
		if (it != nullptr)
		{
			Node* node = it;
			while (node != nullptr)
			{
				vec[index++] = node->m_nValue;
				node = node->m_pNext;
			}
			delete it;
		}
	}
}

Bucket::Node* Bucket::Insert(Node* node, int value)
{
	Node temp;
	temp.m_pNext = node;
	Node* parent = &temp;
	Node* curNode = node;
	while (curNode != nullptr && value > curNode->m_nValue)
	{
		parent = curNode;
		curNode = curNode->m_pNext;
	}

	Node* newNode = new Node;
	newNode->m_nValue = value;
	newNode->m_pNext = curNode;
	parent->m_pNext = newNode;

	return temp.m_pNext;
}

int Bucket::BUCKET_MAX = 10;