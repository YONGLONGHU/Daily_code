
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d",a,b,c);
//	return 0;
//}
//void test1(int arr[])
//{}
//void test2(int arr[10])
//{}
//void test3(int* arr)
//{}
//void test4(int* arr[20])
//{}
//void test5(int** arr)
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test3(arr);
//	test5(arr2);
//}
//#include <stdio.h>
//#include <string.h>

//int main() {
//    char str[] = "Hello,World!How,Are,You";
//    const char delimiters[] = ",!";
//    char* context = NULL;
//
//    // �״ε���
//    char* token = strtok_s(str, delimiters, &context);
//
//    while (token != NULL) {
//        printf("%s\n", token);
//        // ��������
//        token = strtok_s(NULL, delimiters, &context);
//    }
//
//    return 0;
//}
//#include <iostream>
//class Counter 
//{
//private:
//    int value;
//public:
//    Counter(int v = 0) : value(v) {}
//
//    // ǰ��++��������أ��������ã����Ч�ʣ�
//    Counter& operator++() {
//        ++value;
//        return *this;
//    }
//
//    // ����++��������أ�����ֵ����Ҫ������ʱ����
//    Counter operator++(int) {
//        Counter temp = *this; // ���Ƶ�ǰ����
//        ++value; // ����
//        return temp; // ���ؾ�ֵ
//    }
//
//    void display() const {
//        std::cout << "Value: " << value << std::endl;
//    }
//};
//
//int main() {
//    Counter c1(10);
//
//    std::cout << "ǰ��++��" << std::endl;
//    (++c1).display(); // ֱ���޸�ԭ����
//
//    std::cout << "����++��" << std::endl;
//    (c1++).display(); // ����ԭ����ĸ���
//
//    return 0;
//}
#include <iostream>

//class Base {
//public:
//    Base() { std::cout << "Base ����\n"; }
//    virtual ~Base() { std::cout << "Base ����\n"; } 
//};
//
//class Derived : public Base {
//public:
//    Derived() { std::cout << "Derived ����\n"; }
//    ~Derived() { std::cout << "Derived ����\n"; } // ���ڻᱻ��ȷ����
//};
//
//int main() {
//    Base* obj = new Derived();
//    delete obj; // ���ڻ���ȷ���� Derived ����������
//    return 0;
//}