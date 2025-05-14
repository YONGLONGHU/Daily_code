#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//void removeSort(vector<int>& nums)
//{
//    if (nums.empty()) return;
//
//    sort(nums.begin(), nums.end());
//    int count = 1; // 从1开始，第一个元素默认保留
//
//    for (int i = 1; i < nums.size(); ++i)
//    {
//        if (nums[i] != nums[count - 1]) {
//            nums[count++] = nums[i]; // 保留唯一元素
//        }
//    }
//    nums.resize(count); // 最后统一 resize
//}
//
//int main()
//{
//    vector<int> nums{ 3, 3, 3, 34, 45, 45, 56, 56, 3, 2, 4, 5, 7 };
//    removeSort(nums);
//    for (auto& e : nums)
//        cout << e << " ";
//    return 0;
//}

void removeDuplicatesAndSortInPlace(std::vector<int>& nums) 
{
	if (nums.empty()) return;
	int count = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[count - 1] == nums[i])
			nums[count++] = nums[i];
	}
	nums.resize(count);
}
void ExpendCenter(string& s,int left,int right, int& start, int& maxlen)
{
	while (left >= 0 && right < s.size() && s[left] == s[right])
	{
		left--;
		right++;
	}
	int len = right - left;
	if (len > maxlen)
	{
		start = left + 1;
		maxlen = len;
	}
}
string LongString(string s)
{
	if (s.empty())
		return "";
	int start = 0,maxlen = 1;
	for (int i = 0; i < s.size(); i++)
	{
		ExpendCenter(s, i, i, start, maxlen);
		ExpendCenter(s, i, i+1, start, maxlen);
	}
	return s.substr(start, maxlen);
}
//int main()
//{
//	string s = "babad";
//	cout << LongString(s) << endl;
//	return 0;
//}
//void BubleSort(vector<int>& nums)
//{
//	int size = nums.size();
//	for (int i = 0; i < size-1; i++)
//	{
//		for (int j = 0; j < size - i - 1; j++)
//		{
//			if (nums[j] > nums[j + 1])
//				swap(nums[j], nums[j + 1]);
//		}
//	}
//	return;
//}
//int main()
//{
//	vector<int> nums{ 34,2,344,546,23,2,45 };
//	BubleSort(nums);
//	for (auto& e : nums)
//		cout << e << " ";
//	return 0;
//}

//void BubleSort(vector<int>& nums)
//{
//	for (int i = 0; i < nums.size()-1; i++)
//	{
//		bool flag = true;
//		for (int j = 0; j < nums.size() - i - 1; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				swap(nums[j], nums[j + 1]);
//				flag = !flag;
//			}
//			if (flag)
//				return;
//		}
//	}
//	return;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void removeSort(vector<int>& nums)
//{
//	if (nums.empty()) return;
//
//	sort(nums.begin(), nums.end());
//	int count = 1; // 从1开始，第一个元素默认保留
//
//	for (int i = 1; i < nums.size(); ++i)
//	{
//		if (nums[i] != nums[count - 1]) {
//			nums[count++] = nums[i]; // 保留唯一元素
//		}
//	}
//	nums.resize(count); // 最后统一 resize
//}
//
//int main()
//{
//	vector<int> nums{ 3, 3, 3, 34, 45, 45, 56, 56, 3, 2, 4, 5, 7 };
//	removeSort(nums);
//	for (auto& e : nums)
//		cout << e << " ";
//	return 0;
//}
#include<unordered_set>
#include<algorithm>
string LengthOfSubstring(string s)
{
	unordered_set<char> occ;
	int right = 0;
	int maxlen = 0;
	int size = s.size();
	int start = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
			occ.erase(s[i-1]);
		while (right < size && !occ.count(s[right]))
			occ.insert(s[right++]);
		if (maxlen < right - i)
		{
			maxlen = right - i;
			start = i;
		}
	}
	return s.substr(start, maxlen);
}

string LengthOfSubstring1(string s)
{
	int right = 0;
	unordered_set<char> st;
	int maxlen = 1;
	int start = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i != 0)
			st.erase(s[i - 1]);
		while (right < s.size() && !st.count(s[right]))
		{
			st.insert(s[right]);
			right++;
		}
		if (right - i > maxlen)
		{
			maxlen = right - i;
			start = i;
		}
	}
	return s.substr(start, maxlen);
}
#include<stack>
string ReaverseString(string ss)
{
	int n = ss.size();
	stack<string> st;
	string result;
	for (int i = 0; i < n;)
	{
		while (ss[i] == ' ')
			i++;
		int next = i;
		while (ss[next] != ' ')
			next++;
		string temp = ss.substr(i, next - i);
		st.push(temp);
		i = next;
	}
	while (!st.empty())
	{
		result += st.top();
		st.pop();
		if (!st.empty())
			result += ' ';
	}
	return result;
}

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
	volatile static Singleton instance;
};
Singleton Singleton::instance;

class Singleton1
{
public:
	static Singleton1* GetInstance()
	{
		if (instance == nullptr)
		{
			mtx.lock();
			if (instance == nullptr)
			{
				instance = new Singleton1();
			}
			mtx.unlock();
		}
		return instance;
	}
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
private:
	Singleton1();
	volatile static Singleton1* instance;
	static pthread_mutex_t mtx;
};
Singleton1* Singleton1::instance = nullptr;
pthread_mutex_t Singleton1::mtx;

