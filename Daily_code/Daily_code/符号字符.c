
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
//    // 首次调用
//    char* token = strtok_s(str, delimiters, &context);
//
//    while (token != NULL) {
//        printf("%s\n", token);
//        // 后续调用
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
//    // 前置++运算符重载（返回引用，提高效率）
//    Counter& operator++() {
//        ++value;
//        return *this;
//    }
//
//    // 后置++运算符重载（返回值，需要创建临时对象）
//    Counter operator++(int) {
//        Counter temp = *this; // 复制当前对象
//        ++value; // 自增
//        return temp; // 返回旧值
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
//    std::cout << "前置++：" << std::endl;
//    (++c1).display(); // 直接修改原对象
//
//    std::cout << "后置++：" << std::endl;
//    (c1++).display(); // 返回原对象的副本
//
//    return 0;
//}
#include <iostream>

//class Base {
//public:
//    Base() { std::cout << "Base 构造\n"; }
//    virtual ~Base() { std::cout << "Base 析构\n"; } 
//};
//
//class Derived : public Base {
//public:
//    Derived() { std::cout << "Derived 构造\n"; }
//    ~Derived() { std::cout << "Derived 析构\n"; } // 现在会被正确调用
//};
//
//int main() {
//    Base* obj = new Derived();
//    delete obj; // 现在会正确调用 Derived 的析构函数
//    return 0;
//}