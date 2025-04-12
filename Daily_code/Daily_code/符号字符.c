
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

using TaskFunc = std::function<void()>;
using ReleaseFunc = std::function<void()>;
class TimerTask {
private:
    uint64_t _id;       // 定时器任务对象ID
    uint32_t _timeout;  //定时任务的超时时间
    bool _canceled;     // false-表示没有被取消， true-表示被取消
    TaskFunc _task_cb;  //定时器对象要执行的定时任务
    ReleaseFunc _release; //用于删除TimerWheel中保存的定时器对象信息
public:
    TimerTask(uint64_t id, uint32_t delay, const TaskFunc& cb) :
        _id(id), _timeout(delay), _task_cb(cb), _canceled(false) {}
    ~TimerTask() {
        if (_canceled == false) _task_cb();
        _release();
    }
    void Cancel() { _canceled = true; }
    void SetRelease(const ReleaseFunc& cb) { _release = cb; }
    uint32_t DelayTime() { return _timeout; }
};