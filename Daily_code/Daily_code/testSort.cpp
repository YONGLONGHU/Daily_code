//#include <iostream>
//#include <vector>
//
//// 冒泡排序函数
//void bubbleSort(std::vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; ++i) { // 外层循环控制排序轮数
//        for (int j = 0; j < n - 1 - i; ++j) { // 内层循环比较相邻元素
//            if (arr[j] > arr[j + 1]) { // 如果前一个元素大于后一个，交换
//                std::swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//
//// 打印数组的辅助函数
//void printArray(const std::vector<int>& arr) {
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
//    std::cout << "原始数组: ";
//    printArray(arr);
//
//    bubbleSort(arr);
//
//    std::cout << "冒泡排序后: ";
//    printArray(arr);
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//// 插入排序函数
//void insertionSort(std::vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 1; i < n; ++i) { // 从第二个元素开始
//        int key = arr[i]; // 当前待插入的元素
//        int j = i - 1; // 已排序部分的最后一个元素的索引
//        // 将大于 key 的元素向后移动
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            --j;
//        }
//        arr[j + 1] = key; // 将 key 插入到正确位置
//    }
//}
//
//// 打印数组的辅助函数
//void printArray(const std::vector<int>& arr) {
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
//    std::cout << "原始数组: ";
//    printArray(arr);
//
//    insertionSort(arr);
//
//    std::cout << "插入排序后: ";
//    printArray(arr);
//
//    return 0;
//}