#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//void removeSort(vector<int>& nums)
//{
//    if (nums.empty()) return;
//
//    sort(nums.begin(), nums.end());
//    int count = 1; // ��1��ʼ����һ��Ԫ��Ĭ�ϱ���
//
//    for (int i = 1; i < nums.size(); ++i)
//    {
//        if (nums[i] != nums[count - 1]) {
//            nums[count++] = nums[i]; // ����ΨһԪ��
//        }
//    }
//    nums.resize(count); // ���ͳһ resize
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
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[count - 1] == nums[i])
			nums[count++] = nums[i];
	}
	nums.resize(count);
}