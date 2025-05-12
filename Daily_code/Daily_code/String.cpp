#include<iostream>
using namespace std;
class String
{
	String(const char* str="")
	{
		if (str == nullptr)
			return;
		_str = new char[sizeof(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
	{
		_str = new char[sizeof(s._str) + 1];
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str =new char[sizeof(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	~String()
	{
		if (_str != nullptr)
			delete[] _str;
	}
private:
	char* _str;
};
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr=nullptrt)
	{
		_ptr = ptr;
	}
	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
#include<algorithm>
#include<iostream>
#include<vector>
void backtrack(vector<int> nums, int start,vector<vector<int>> result)
{
	if (nums.size() == start)
	{
		result.push_back(nums);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		swap(nums[start], nums[i]);
		backtrack(nums, i + 1, result);
		swap(nums[start], nums[i]);
	}
}
vector<vector<int>> permute(vector<int> nums)
{
	vector<vector<int>> result;
	backtrack(nums,0, result);
	return result;
}

void bubleSort(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - i; j++)
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
	}
}

void heapily(vector<int>& nums, int size, int i)
{
	int largest = i;
	int right = 2 * i+1;
	int left = 2 * i +2;
	if (left<size && nums[left]>nums[largest])
		largest = left;
	if (right<size && nums[right]>nums[largest])
		largest = right;
	if (largest != i)
	{
		swap(nums[largest], nums[i]);
		heapily(nums, size, largest);
	}
}
void HeapSort(vector<int>& nums)
{
	int size = nums.size();
	//调整形成堆
	for (int i = size / 2 - 1; i >= 0; i--)
		heapily(nums, size, i);
	//交换头节点和在最后一个节点
	for (int j = size - 1; j > 0; --j)
	{
		swap(nums[0], nums[j]);
		heapily(nums, size, 0);
	}
}

typedef struct Node
{
	int val;
	struct Node* next;
	Node(int x):val(x),next(nullptr){}
}Node;
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
}TreeNode;

Node* RemoveNthNode(Node* head,int n)
{
	Node* dummy = new Node(-1);
	dummy->next = head;
	Node* fast = dummy;
	Node* slow = dummy;
	for (int i = 0; i <= n; i++)
	{
		fast = fast->next;
	}
	while (fast != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = temp->next;
	delete temp;
	return dummy->next;
}

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

ListNode* SwapPair(ListNode* head)
{
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pre = dummy;
	while (pre->next && pre->next->next)
	{
		ListNode* first = pre->next;
		ListNode* second = pre->next->next;

		first->next = second->next;
		second->next = first;
		pre->next = pre;

		pre = first;

		return dummy->next;
	}
}

ListNode* Reverse(ListNode* head)
{
	ListNode* curr = head;
	ListNode* pre = nullptr;
	while (curr)
	{
		ListNode* temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}
	return pre;
}
#include<queue>
#include<algorithm>
vector<vector<int>> LevelOrder(TreeNode* root)
{
	if (!root)
		return;
	vector<vector<int>> result;
	queue<TreeNode*> q;
	q.push(root);
	bool flag = true;
	while (!q.empty())
	{
		vector<int> temp;
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* curr = q.front();
			q.pop();
			temp.push_back(curr->val);
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
		if (flag)
		{
			result.push_back(temp);
			flag = !flag;
		}
		else
		{
			reverse(temp.begin(), temp.end());
			result.push_back(temp);
			flag = !flag;
		}
	}
	return result;
}
#include<stack>
vector<int> PreOrder(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* curr = st.top();
		st.pop();
		result.push_back(curr->val);
		if (curr->right) st.push(curr->right);
		if (curr->left) st.push(curr->left);
	}
	return result;
}

vector<int> InOrder(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> st;
	TreeNode* curr = root;
	while (!st.empty() && curr)
	{
		while (curr)
		{
			st.push(curr);
			curr = curr->left;
		}
		TreeNode* temp = st.top();
		st.pop();
		result.push_back(temp->val);

		curr = curr->right;
	}
}

void PreOrder(TreeNode* root,vector<int>& result)
{
	result.push_back(root->val);
	PreOrder(root->left, result);
	PreOrder(root->right, result);
}
void Heapify(vector<int>& nums, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && nums[largest] < nums[left])
		largest = left;
	if (right < size && nums[largest] < nums[right])
		largest = right;
	if (largest != i)
	{
		swap(nums[largest], nums[i]);
		Heapify(nums, largest, size);
	}
}
void Heapsort(vector<int>& nums)
{
	int size = nums.size();
	for (int i = size / 2 - 1; i >= 0; --i)
		Heapify(nums, i, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(nums[i], nums[0]);
		Heapify(nums, 0, i);
	}
}
int main()
{
	vector<int> nums{2, 34567, 3, 23, 4356, 21, 56, 23, 456};
	Heapsort(nums);
	for (auto& e : nums)
		cout << e << " ";
	return 0;
}
void Upadjust(vector<int>& arr, int i)
{
	int parent = i / 2 - 1;
	if (arr[i] < arr[parent])
	{
		swap(arr[i], arr[parent]);
		Upadjust(arr, parent);
	}
}
void DownAdjust(vector<int>& arr, int i, int size)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && arr[left] < arr[smallest])
		smallest = left;
	if (right < size && arr[right] < arr[smallest])
		smallest = right;
	if (i != smallest)
	{
		swap(arr[i], arr[smallest]);
		DownAdjust(arr, smallest, size);
	}
}
vector<int> FindTop10(vector<int>& nums)
{
	int length = nums.size();
	vector<int> result;
	for (int i = 0; i < length; i++)
	{
		if (i < 10)
		{
			result.push_back(nums[i]);
			Upadjust(result, i);
		}
		else
		{
			if (nums[i] > result[0])
			{
				result[0] = nums[i];
				DownAdjust(result,0, 10);
			}
		}
	}
}
#include<map>
vector<int> TwoSum(vector<int>& num, int target)
{
	vector<int> result;
	map<int, int> mp;
	for (int i = 0; i < num.size(); i++)
	{
		if (mp.count(target - num[i]) > 0)
		{
			result.push_back(i);
			result.push_back(mp[i]);
			return result;
		}
		mp[num[i]] = i;
	}
	return;
}
#include<unordered_set>
bool hasCycle(ListNode* head)
{
	unordered_set<ListNode*> temp;
	while (head)
	{
		if (temp.count(head))
			return true;
		temp.insert(head);
		head = head->next;
	}
	return false;
}
class Solution {
public:
	bool hasCycle(ListNode* head)
	{
		unordered_set<ListNode*> temp;
		while (head != nullptr)
		{
			if (temp.count(head))
				return true;
			temp.insert(head);
			head = head->next;
		}
		return false;
	}
};

//class Singleton
//{
//public:
//	Singleton& GetInstance()
//	{
//		return ins;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton(){}
//	static Singleton ins;
//};
//Singleton Singleton::ins;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		if (instance != nullptr)
//		{
//			mtx.lock();
//			if (instance == nullptr)
//				instance = new Singleton();
//			mtx.unlock();
//		}
//		return instance;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton() {};
//	static Singleton* instance;
//	static pthread_t_mutex mtx;
//};
//Singleton* Singleton::instance = nullptr;
//pthread_t_mutex Singleton :: mtx;

class Singleton
{
public:
	static Singleton& Getinstance()
	{
		return instance;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton(){}
	static Singleton instance;
};
Singleton Singleton::instance;

class Singleton
{
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
		{
			mtx.lock();
			if (instance == nullptr)
				instance = new Singleton();
			mtx.unlock();
		}
		return instance;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton(){}
	static Singleton* instance;
	static pthread_mute_t mtx;
};
Singleton* Singleton::instance = nullptr;
pthread_mute_t Singleton::mtx;

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		return instance;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton();
	static Singleton instance;
};