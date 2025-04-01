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
#include <iostream>
#include <string>
#include <any>
int main()
{
	{
		std::any a = 10;
		std::any b = 88.88;
		std::any c = std::string("bitejiuyeke");
		int* aa = std::any_cast<int>(&a);
		std::cout << *aa << std::endl;
		std::cout << *std::any_cast<double>(&b) << std::endl;
		std::cout << *std::any_cast<std::string>(&c) << std::endl;
	}
	{
		Test d("Leihou");
		std::any any_d = d;
		std::any any_e(d);
		std::any any_f(any_d);
		std::any any_g = any_d;
	}
	{
		std::cout << "---------------any֮���໥�ĸ�-----\n";
		std::any any_f;
		any_f = 33;
		std::cout << *std::any_cast<int>(&any_f) << std::endl;
		std::string c = "Hello World";
		any_f = c;
		std::cout << *std::any_cast<std::string>(&any_f) << std::endl;
		any_f = std::any(Test("test"));
		std::cout << std::any_cast<Test>(&any_f)->_data << std::endl;
	}
	return 0;
}