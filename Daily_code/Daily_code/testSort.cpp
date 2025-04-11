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
//#include <iostream>
//#include <string>
//#include <any>
//int main()
//{
//	{
//		std::any a = 10;
//		std::any b = 88.88;
//		std::any c = std::string("bitejiuyeke");
//		int* aa = std::any_cast<int>(&a);
//		std::cout << *aa << std::endl;
//		std::cout << *std::any_cast<double>(&b) << std::endl;
//		std::cout << *std::any_cast<std::string>(&c) << std::endl;
//	}
//	{
//		Test d("Leihou");
//		std::any any_d = d;
//		std::any any_e(d);
//		std::any any_f(any_d);
//		std::any any_g = any_d;
//	}
//	{
//		std::cout << "---------------any之间相互的赋-----\n";
//		std::any any_f;
//		any_f = 33;
//		std::cout << *std::any_cast<int>(&any_f) << std::endl;
//		std::string c = "Hello World";
//		any_f = c;
//		std::cout << *std::any_cast<std::string>(&any_f) << std::endl;
//		any_f = std::any(Test("test"));
//		std::cout << std::any_cast<Test>(&any_f)->_data << std::endl;
//	}
//	return 0;
//}
//#include <iostream>
//#include <unordered_set>
//#include <string>
//using namespace std;
//
//// 判断是否为质数
//bool isPrime(int n) {
//    if (n < 2) return false;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//// 递归枚举所有可能的表达式
//void dfs(const string& s, int index, int currentSum, unordered_set<int>& primes) {
//    if (index == s.length()) {
//        if (isPrime(currentSum)) {
//            primes.insert(currentSum);
//        }
//        return;
//    }
//
//    int num = 0;
//    for (int i = index; i < s.length(); i++) {
//        num = num * 10 + (s[i] - '0');
//        if (index == 0) {
//            dfs(s, i + 1, num, primes);
//        }
//        else {
//            dfs(s, i + 1, currentSum + num, primes);
//        }
//    }
//}
//
//int countPrimeExpressions(string s) {
//    unordered_set<int> primes;
//    dfs(s, 0, 0, primes);
//    return primes.size();
//}
//
//int main() {
//    string s;
//    cin >> s;
//    cout << countPrimeExpressions(s) << endl;
//    return 0;
//}

#include<iostream>
//typedef int(*FunType)(int, int);
//int add(int v1, int v2) {
//	return v1 + v2;
//}
//void testFuncPointer(FunType func1, int val1, int val2)
//{
//	if (func1 != nullptr)
//	{
//		int result = func1(val1, val2);
//		std::cout << "TestFuncpointer: " << result << std::endl;
//	}
//	FunType func2 = add;
//	testFuncPointer(func2, 10, 20);
//}


//auto Add = [](int a, int b)
//{
//	std::cout << "sum = " << a + b;
//}
//Add(100, 200);
//仿函数
//class Functor1 {
//public:
//    void operator()(const std::string& str) {
//        mStr += str;
//        printf("Functor1::operator() >> %s\n", str.c_str());
//    }
//    std::string mStr;
//};
//
//Functor1 f;
//f("hello functor");
//f(" test ");
//bind()函数
//auto addFunc2 = std::bind(&add, 15, std::placeholders::_1);
////等价于
//// std::function<int(int)> addFunc2 = std::bind(&add, 15, std::placeholders::_1);
//printf("addFunc2 >> %d\n", addFunc2(5));

//std::function<void(int)>f_printnum = print_num;
//print_num(-100);

//class Any {
//private:
//    class holder {
//    public:
//        virtual ~holder() {}
//        virtual const std::type_info& type() = 0;
//        virtual holder* clone() = 0;
//    };
//    template<class T>
//    class placeholder : public holder {
//    public:
//        placeholder(const T& val) : _val(val) {}
//        // 获取子类对象保存的数据类型
//        virtual const std::type_info& type() { return typeid(T); }
//        // 针对当前的对象自身，克隆出一个新的子类对象
//        virtual holder* clone() { return new placeholder(_val); }
//    public:
//        T _val;
//    };
//    holder* _content;
//public:
//    Any() :_content(NULL) {}
//    template<class T>
//    Any(const T& val) : _content(new placeholder<T>(val)) {}
//    Any(const Any& other) :_content(other._content ? other._content->clone() : NULL) {}
//    ~Any() { delete _content; }
//
//    Any& swap(Any& other) {
//        std::swap(_content, other._content);
//        return *this;
//    }
//
//    // 返回子类对象保存的数据的指针
//    template<class T>
//    T* get() {
//        //想要获取的数据类型，必须和保存的数据类型一致
//        assert(typeid(T) == _content->type());
//        return &((placeholder<T>*)_content)->_val;
//    }
//    //赋值运算符的重载函数
//    template<class T>
//    Any& operator=(const T& val) {
//        //为val构造一个临时的通用容器，然后与当前容器自身进行指针交换，临时对象释放的时候，原先保存的数据也就被释放
//        Any(val).swap(*this);
//        return *this;
//    }
//    Any& operator=(const Any& other) {
//        Any(other).swap(*this);
//        return *this;
//    }
//};

//#include <sys/epoll.h>
//#include <sys/socket.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//
//#define MAX_EVENTS 1024
//#define BUFFER_SIZE 4096
//
//// 设置文件描述符为非阻塞模式
//static void setnonblocking(int fd) {
//    int flags = fcntl(fd, F_GETFL, 0);
//    if (flags == -1) {
//        perror("fcntl(F_GETFL)");
//        return;
//    }
//    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
//        perror("fcntl(F_SETFL)");
//    }
//}
//
//int main(int argc, char* argv[]) {
//    struct epoll_event ev, events[MAX_EVENTS];
//    int sock_fd, new_fd, efd, ret;
//    struct sockaddr_in peer;
//    socklen_t addrlen = sizeof(peer);
//    char recv_buf[BUFFER_SIZE];
//
//    // 1. 创建监听套接字 (这里省略了socket/bind/listen过程，实际需要补全)
//    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock_fd == -1) {
//        perror("socket");
//        return -1;
//    }
//
//    // 2. 创建epoll实例
//    efd = epoll_create1(0);  // 更推荐使用epoll_create1(0)替代epoll_create
//    if (efd == -1) {
//        perror("epoll_create1");
//        close(sock_fd);
//        return -1;
//    }
//
//    // 3. 添加监听套接字到epoll
//    ev.events = EPOLLIN;     // 监听可读事件（新连接）
//    ev.data.fd = sock_fd;
//    if (epoll_ctl(efd, EPOLL_CTL_ADD, sock_fd, &ev) == -1) {
//        perror("epoll_ctl(ADD)");
//        close(sock_fd);
//        close(efd);
//        return -1;
//    }
//
//    while (1) {
//        // 4. 等待事件发生（超时1000毫秒）
//        int nfds = epoll_wait(efd, events, MAX_EVENTS, 1000);
//        if (nfds == -1) {
//            if (errno == EINTR) continue;  // 被信号中断则重试
//            perror("epoll_wait");
//            break;
//        }
//        else if (nfds == 0) {
//            // printf("Timeout, no events\n"); // 可添加超时处理逻辑
//            continue;
//        }
//
//        for (int i = 0; i < nfds; i++) {
//            int fd = events[i].data.fd;
//
//            // 5. 处理监听套接字事件（新连接）
//            if (fd == sock_fd) {
//                new_fd = accept(sock_fd, (struct sockaddr*)&peer, &addrlen);
//                if (new_fd == -1) {
//                    if (errno != EAGAIN && errno != EWOULDBLOCK) {
//                        perror("accept");
//                    }
//                    continue;
//                }
//
//                setnonblocking(new_fd);  // 设置为非阻塞模式
//
//                // 为新连接注册EPOLLIN|EPOLLET事件（边缘触发模式）
//                ev.events = EPOLLIN | EPOLLET | EPOLLRDHUP;  // 添加EPOLLRDHUP检测连接关闭
//                ev.data.fd = new_fd;
//                if (epoll_ctl(efd, EPOLL_CTL_ADD, new_fd, &ev) == -1) {
//                    perror("epoll_ctl(ADD new_fd)");
//                    close(new_fd);
//                }
//            }
//            // 6. 处理业务套接字事件
//            else {
//                // 6.1 处理连接关闭或错误事件
//                if (events[i].events & (EPOLLERR | EPOLLHUP | EPOLLRDHUP)) {
//                    printf("Connection closed or error on fd %d\n", fd);
//                    epoll_ctl(efd, EPOLL_CTL_DEL, fd, NULL);
//                    close(fd);
//                    continue;
//                }
//
//                // 6.2 处理可读事件
//                if (events[i].events & EPOLLIN) {
//                    ssize_t count;
//                    // 非阻塞读取（边缘触发模式必须循环读取直到EAGAIN）
//                    while ((count = recv(fd, recv_buf, BUFFER_SIZE, 0)) > 0) {
//                        // 处理接收到的数据（示例：原样回显）
//                        send(fd, recv_buf, count, MSG_NOSIGNAL);
//                    }
//
//                    if (count == 0) {  // 对端关闭连接
//                        printf("Connection closed by peer on fd %d\n", fd);
//                        epoll_ctl(efd, EPOLL_CTL_DEL, fd, NULL);
//                        close(fd);
//                    }
//                    else if (count == -1 && errno != EAGAIN) {
//                        perror("recv");
//                        epoll_ctl(efd, EPOLL_CTL_DEL, fd, NULL);
//                        close(fd);
//                    }
//                }
//            }
//        }
//    }
//
//    // 7. 清理资源
//    close(sock_fd);
//    close(efd);
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
