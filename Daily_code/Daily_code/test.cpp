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
//void removeSort(vector<int>& nums)
//{
//	if (nums.empty())
//		return;
//	sort(nums.begin(), nums.end());
//	int count = 1;
//	for (int i = 1; i < nums.size(); ++i)
//	{
//		if (nums[i] != nums[count - 1])
//			nums[count++] = nums[i];
//	}
//	nums.resize(count);
//}
//int main()
//{
//    vector<int> nums{ 3, 3, 3, 34, 45, 45, 56, 56, 3, 2, 4, 5, 7 };
//    removeSort(nums);
//    for (auto& e : nums)
//        cout << e << " ";
//    return 0;
//}

//void removeDuplicatesAndSortInPlace(std::vector<int>& nums) 
//{
//	if (nums.empty()) return;
//	int count = 1;
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if (nums[count - 1] == nums[i])
//			nums[count++] = nums[i];
//	}
//	nums.resize(count);
//}
//void ExpendCenter(string& s,int left,int right, int& start, int& maxlen)
//{
//	while (left >= 0 && right < s.size() && s[left] == s[right])
//	{
//		left--;
//		right++;
//	}
//	int len = right - left;
//	if (len > maxlen)
//	{
//		start = left + 1;
//		maxlen = len;
//	}
//}
//string LongString(string s)
//{
//	if (s.empty())
//		return "";
//	int start = 0,maxlen = 1;
//	for (int i = 0; i < s.size(); i++)
//	{
//		ExpendCenter(s, i, i, start, maxlen);
//		ExpendCenter(s, i, i+1, start, maxlen);
//	}
//	return s.substr(start, maxlen);
//}
//int main()
//{
//	string s = "babad";
//	cout << LongString(s) << endl;
//	return 0;
//}
//void Expan(string& s,int left,int right,int& start,int& maxlen)
//{
//	while (left >= 0 && right <= s.size() && s[left] == s[right])
//	{
//		left--;
//		right++;
//	}
//	int len = right - left;
//	if (len > maxlen)
//	{
//		maxlen = len;
//		start = left + 1;
//	}
//}
//string Huiwen(string s)
//{
//	if (s.empty())
//		return "";
//	int start = 0; int maxlen = 1;
//	for (int i = 0; i < s.size(); i++)
//	{
//		Expan(s, i, i, start, maxlen);
//		Expan(s, i, i+1, start, maxlen);
//	}
//	return s.substr(start, maxlen);
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
//#include<unordered_set>
//#include<algorithm>
//string LengthOfSubstring(string s)
//{
//	unordered_set<char> occ;
//	int right = 0;
//	int maxlen = 0;
//	int size = s.size();
//	int start = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (i != 0)
//			occ.erase(s[i-1]);
//		while (right < size && !occ.count(s[right]))
//			occ.insert(s[right++]);
//		if (maxlen < right - i)
//		{
//			maxlen = right - i;
//			start = i;
//		}
//	}
//	return s.substr(start, maxlen);
//}
//
//string LengthOfSubstring1(string s)
//{
//	int right = 0;
//	unordered_set<char> st;
//	int maxlen = 1;
//	int start = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (i != 0)
//			st.erase(s[i - 1]);
//		while (right < s.size() && !st.count(s[right]))
//		{
//			st.insert(s[right]);
//			right++;
//		}
//		if (right - i > maxlen)
//		{
//			maxlen = right - i;
//			start = i;
//		}
//	}
//	return s.substr(start, maxlen);
//}
//#include<stack>
//string ReaverseString(string ss)
//{
//	int n = ss.size();
//	stack<string> st;
//	string result;
//	for (int i = 0; i < n;)
//	{
//		while (ss[i] == ' ')
//			i++;
//		int next = i;
//		while (ss[next] != ' ')
//			next++;
//		string temp = ss.substr(i, next - i);
//		st.push(temp);
//		i = next;
//	}
//	while (!st.empty())
//	{
//		result += st.top();
//		st.pop();
//		if (!st.empty())
//			result += ' ';
//	}
//	return result;
//}
//
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return instance;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton();
//	volatile static Singleton instance;
//};
//Singleton Singleton::instance;
//
//class Singleton1
//{
//public:
//	static Singleton1* GetInstance()
//	{
//		if (instance == nullptr)
//		{
//			mtx.lock();
//			if (instance == nullptr)
//			{
//				instance = new Singleton1();
//			}
//			mtx.unlock();
//		}
//		return instance;
//	}
//	Singleton1(const Singleton1&) = delete;
//	Singleton1& operator=(const Singleton1&) = delete;
//private:
//	Singleton1();
//	volatile static Singleton1* instance;
//	static pthread_mutex_t mtx;
//};
//Singleton1* Singleton1::instance = nullptr;
//pthread_mutex_t Singleton1::mtx;
//

//int searchInsert(vector<int>& nums, int target)
//{
//	int left = 0, right = nums.size() - 1;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (target > nums[mid])
//			left = mid + 1;
//		else if (target == nums[mid])
//			return mid;
//		else
//			right = mid - 1;
//	}
//	return left;
//}

//bool searchMatrix(vector<vector<int>>& matrix, int target)
//{
//	int top = 0, bottom = matrix.size();
//	while (top <= bottom)
//	{
//		int mid = (top + bottom) / 2;
//		if (target == matrix[mid][0])
//			return true;
//		else if (target > matrix[mid][0])
//			top = mid + 1;
//		else
//			bottom = mid - 1;
//	}
//	int left = 0, right = matrix[bottom].size() - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (target == matrix[bottom][mid])
//			return true;
//		else if (target > matrix[bottom][mid])
//			left = mid + 1;
//		else
//			right = mid - 1;
//	}
//	return false;
//}
//#include<unordered_map>
//vector<int> topKFrenquent(vector<int>& nums, int k)
//{
//	unordered_map<int, int> freqMap;
//	for (auto e : nums)
//		freqMap[e]++;
//	vector<pair<int, int>>freqVec(freqMap.begin(), freqMap.end());
//	sort(freqVec.begin(), freqVec.end(),
//		[](const pair<int, int>& a, const pair<int, int>& b) {
//			return a.second > b.second;
//		});
//	vector<int> result;
//	for (int i = 0; i < k; ++i)
//	{
//		result.push_back(freqVec[i].first);
//	}
//	return result;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}
//struct compare
//{
//	bool operator()(const node& node1, const node& node2)
//	{
//		return node1.aa > node2.aa;
//	}
//};
//struct node
//{
//	string ss;
//	int aa;
//	node(const char* sss,int a):ss(sss),aa(a){}
//};
//int main()
//{
//	vector<node> nums{ {"sdfg",21},{"sfg",23},{"sdfdg",28},{"sdsg",28} };
//	sort(nums.begin(), nums.end(), compare);
//}

//template<class T>
//class unique_ptr
//{
//	unique_ptr(T* ptr=nullptr):_ptr(ptr){}
//	~unique_ptr()
//	{
//		if (_ptr)
//			delete ptr;
//	}
//	unique_ptr(const unique_ptr<T>& p1) = delete;
//	unique_ptr<T>& operator*(const unique_ptr<int>& p1) = delete;
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main1()
//{
//	//static_cast
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	//reinterpret_cast
//	int* p = reinterpret_cast<int*>(a);
//
//	//const_cast
//	const int b = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	return 0;
//}
//class A
//{
//public:
//	virtual void f() {}
//};
//class B : public A
//{};
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}

//class String
//{
//public:
//	String(const char* ptr = " ")
//	{
//		_ptr = new char[strlen(ptr)+1];
//		strcpy(_ptr, ptr);
//	}
//	String(const String& s)
//	{
//		_ptr = new char[strlen(s._ptr) + 1];
//		strcpy(_ptr, s._ptr);
//	}
//	String& operator=(const String&s)
//	{
//		if (s._ptr != _ptr)
//		{
//			delete[]_ptr;
//			_ptr = nullptr;
//			_ptr = new char[strlen(s._ptr) + 1];
//			strcpy(_ptr, s._ptr);
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_ptr)
//		{
//			delete[] _ptr;
//			_ptr = nullptr;
//		}
//	}
//private:
//	char* _ptr;
//};

//int main()
//{
//	int a = 1;
//	char* c = (char*)&a;
//	if (*c == 1)
//		cout << "小端" << endl;
//	else
//		cout << "大端" << endl;
//	return 0;
//}
//int SecondNum(vector<int>& nums)
//{
//	int largest = nums[0];
//	int size = nums.size();
//	int second = INT_MIN;
//	for (int i = 0; i < size; ++i)
//	{
//		if (nums[i] > largest)
//			largest = nums[i];
//		else if (nums[i] > second)
//		{
//			int temp = second;
//			second = nums[i];
//			if (second == largest)
//				second = temp;
//		}
//		return second;
//	}
//}
//int main()
//{
//	vector<int> nums{ 2,4,5,5,6,3,2,1 };
//	if (nums.size() < 2)
//		cout << "没有第二大整数" << endl;
//
//	int result = SecondNum(nums);
//	cout << "第二大整数为" << result << endl;
//	return 0;
//}
//int MaxTemp(vector<int>& nums)
//{
//	int hismax = nums[0]; 
//	int size = nums.size();
//	int maxtemp = 0;
//	for (int cur = 0; cur < size; cur++)
//	{
//		int curmax = 0;
//		if(hismax< nums[cur])
//			hismax = nums[cur];
//		curmax = hismax - nums[cur];
//		maxtemp = curmax > maxtemp ? curmax : maxtemp;
//	}
//	return maxtemp;
//}
//int main()
//{
//	vector<int> nums{ 5,2,1,4,6 };
//	int result = MaxTemp(nums);
//	cout << result << endl;
//	return 0;
//}
//int FindSecondMax(const vector<int>& nums)
//{
//	int max1 = INT_MIN;
//	int max2 = INT_MIN;
//	for (auto& e : nums)
//	{
//		if (e > max1)
//		{
//			max2 = max1;
//			max1 = e;
//		}
//		else if (e > max2 && e < max1)
//		{
//			max2 = e;
//		}
//	}
//	if (max2 == INT_MIN)
//		return -1;
//	return max2;
//}
//int FindSecond(vector<int> nums)
//{
//	int size = nums.size();
//	int largest = INT_MIN;
//	int second = INT_MIN;
//	for (int i = 0; i < size; i++)
//	{
//		if (nums[i] > largest)
//		{
//			second = largest;
//			largest = nums[i];
//		}
//		else if (nums[i] > second && nums[i] != largest)
//			second = nums[i];
//	}
//	if (second == INT_MIN)
//		return -1;
//	return second;
//}
//int main()
//{
//	vector<int> nums{ 23,43,44,33,23,345,23 };
//	int second = FindSecond(nums);
//	cout << second << endl;
//	return 0;
//}
//int MaxTemp(vector<int> nums)
//{
//	int largest = INT_MIN;
//	int temp = 0;
//	for (auto& e : nums)
//	{
//		if (e > largest)
//			largest = e;
//		temp = largest - e > temp ? largest - e : temp;
//	}
//	return temp;
//}

//1、最长回文子串
//2、最长字串
//3、排序去重
//void Nosort(vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	int count = 1;
//	int size = nums.size();
//	for (int i = 1; i < size; ++i)
//	{
//		if (nums[count - 1] != nums[i])
//		{
//			nums[count] = nums[i];
//			count++;
//		}
//	}
//	nums.resize(count);
//}
//#include<unordered_set>
//string LongestStr(string str)
//{
//	unordered_set<char> set;
//	int size = str.size();
//	int left = 0, right = 0;
//	int maxlen = 0;
//	int start = 0;
//	while (right < size)
//	{
//		if(left!=0)
//			str.erase(str[left-1]);
//		while (set.count(str[right]) == 0 && right < size)
//		{
//			set.insert(str[left]);
//			left++;
//		}
//		int len = left - right;
//		if (len > maxlen)
//		{
//			maxlen = len;
//			start = left;
//		}
//	}
//	left++;
//	return str.substr(start, maxlen);
//}
void Center_Expend(string& str, int& start, int& maxlen, int left, int right)
{
	while (left >= 0 && right < str.size() && str[left] == str[right])
	{
		left--; right++;
	}
	maxlen = right - left - 1 > maxlen ? right - left - 1 : maxlen,
	start = left + 1;
}
string HWStr(string str)
{
	int size = str.size();
	int start = 0;
	int maxlen = 0;
	for (int i = 0; i < size; ++i)
	{
		Center_Expend(str, start, maxlen, i, i);
		Center_Expend(str, start, maxlen, i, i+1);
	}
	return str.substr(start,maxlen);
}
#include<unordered_set>
string lengthoflongeststring(string s)
{
	unordered_set<char> occ;
	int start = 0;
	int size = s.size();
	int maxlen = 1;
	int right = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i != 0)
			occ.erase(s[i]);
		while (right < size && !occ.count(s[right]))
		{
			occ.insert(s[right]);
			right++;
		}
		int len = right - i;
		if (len > maxlen)
		{
			maxlen = len;
			start = i;
		}
		return s.substr(start, maxlen);
	}
}
//bool isValidBST(TreeNode* root) {
//	stack<TreeNode*> stack;
//	long long inorder = (long long)INT_MIN - 1;
//
//	while (!stack.empty() || root != nullptr) {
//		while (root != nullptr) {
//			stack.push(root);
//			root = root->left;
//		}
//		root = stack.top();
//		stack.pop();
//		if (root->val <= inorder) {
//			return false;
//		}
//		inorder = root->val;
//		root = root->right;
//	}
//	return true;
//}
//#include<stack>
//typedef struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
//}TreeNode;
//
//bool IsValidBST(TreeNode* root)
//{
//	stack<TreeNode*> st;
//	int prenode = INT_MIN;
//	while (root || !st.empty())
//	{
//		while (root)
//		{
//			st.push(root);
//			root = root->left;
//		}
//		root = st.top();
//		st.pop();
//		if (root->val < prenode)
//			return false;
//		prenode = root->val;
//		root = root->right;
//	}
//	return true;
//}
//
//class Solution {
//public:
//	string addBinary(string a, string b)
//	{
//		int i = a.size() - 1;
//		int j = b.size() - 1;
//		int carry = 0;
//		string result = "";
//		while (i >= 0 || j >= 0 || carry > 0)
//		{
//			int sum = carry;
//			if (i >= 0)
//			{
//				sum += a[i] - '0';
//				i--;
//			}
//			if (j >= 0)
//			{
//				sum += b[j] - '0';
//				j--;
//			}
//			result = to_string(sum % 2) + result;
//			carry = sum / 2;
//		}
//		return result;
//	}
//};
//
//class Solution {
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		int result = 0;
//		for (int num : nums)
//			result ^= num;
//		return result;
//	}
//};

//#include <vector>
//
//class Solution {
//public:
//	int singleNumber(std::vector<int>& nums) {
//		int result = 0;
//
//		// 遍历每一位（假设是32位整数）
//		for (int i = 0; i < 32; ++i) {
//			int sum = 0;
//
//			// 统计所有数字在第i位上的1的个数
//			for (int num : nums) {
//				sum += (num >> i) & 1;
//			}
//
//			// 如果模3不为0，说明只出现一次的数字在该位上是1
//			if (sum % 3 != 0) {
//				result |= (1 << i);
//			}
//		}
//
//		return result;
//	}
//};

//#include <iostream>
//#include <string>
//using namespace std;
//
//int firstUniqueChar(const string& s) {
//	const int SIZE = 52;  // 26 uppercase + 26 lowercase
//	int count[SIZE] = { 0 };
//
//	// 统计每个字符出现的次数
//	for (char c : s) {
//		int index;
//		if (c >= 'A' && c <= 'Z') {
//			index = c - 'A';           // A-Z -> 0~25
//		}
//		else {
//			index = 26 + (c - 'a');    // a-z -> 26~51
//		}
//		count[index]++;
//	}
//
//	// 再次遍历，找出第一个只出现一次的字符
//	for (int i = 0; i < s.length(); i++) {
//		int index;
//		char c = s[i];
//		if (c >= 'A' && c <= 'Z') {
//			index = c - 'A';
//		}
//		else {
//			index = 26 + (c - 'a');
//		}
//		if (count[index] == 1) {
//			return i;
//		}
//	}
//
//	return -1;  // 没有只出现一次的字符
//}
//
//int main() {
//	string str;
//	cout << "请输入字符串：";
//	cin >> str;
//
//	int index = firstUniqueChar(str);
//	if (index != -1) {
//		cout << "第一个只出现一次的字符是：" << str[index] << endl;
//		cout << "位置是：" << index << endl;
//	}
//	else {
//		cout << "没有只出现一次的字符。" << endl;
//	}
//
//	return 0;
//}
//void BubleSort(vector<int>& nums)
//{
//	int size = nums.size();
//	for (int i = 0; i < size-1; ++i)
//	{
//		bool flag = false;
//		for (int j = 0; i < size - i - 1; ++j)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				swap(nums[j], nums[j + 1]);
//				flag = !flag;
//			}
//		}
//		if (!flag)
//			return;
//	}
//}