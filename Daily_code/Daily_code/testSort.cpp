//#include <iostream>
//#include <vector>
//
//// ð��������
//void bubbleSort(std::vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; ++i) { // ���ѭ��������������
//        for (int j = 0; j < n - 1 - i; ++j) { // �ڲ�ѭ���Ƚ�����Ԫ��
//            if (arr[j] > arr[j + 1]) { // ���ǰһ��Ԫ�ش��ں�һ��������
//                std::swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//
//// ��ӡ����ĸ�������
//void printArray(const std::vector<int>& arr) {
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
//    std::cout << "ԭʼ����: ";
//    printArray(arr);
//
//    bubbleSort(arr);
//
//    std::cout << "ð�������: ";
//    printArray(arr);
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//// ����������
//void insertionSort(std::vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 1; i < n; ++i) { // �ӵڶ���Ԫ�ؿ�ʼ
//        int key = arr[i]; // ��ǰ�������Ԫ��
//        int j = i - 1; // �����򲿷ֵ����һ��Ԫ�ص�����
//        // ������ key ��Ԫ������ƶ�
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            --j;
//        }
//        arr[j + 1] = key; // �� key ���뵽��ȷλ��
//    }
//}
//
//// ��ӡ����ĸ�������
//void printArray(const std::vector<int>& arr) {
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
//    std::cout << "ԭʼ����: ";
//    printArray(arr);
//
//    insertionSort(arr);
//
//    std::cout << "���������: ";
//    printArray(arr);
//
//    return 0;
//}