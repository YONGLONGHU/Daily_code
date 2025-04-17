
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

//using TaskFunc = std::function<void()>;
//using ReleaseFunc = std::function<void()>;
//class TimerTask {
//private:
//    uint64_t _id;       // 定时器任务对象ID
//    uint32_t _timeout;  //定时任务的超时时间
//    bool _canceled;     // false-表示没有被取消， true-表示被取消
//    TaskFunc _task_cb;  //定时器对象要执行的定时任务
//    ReleaseFunc _release; //用于删除TimerWheel中保存的定时器对象信息
//public:
//    TimerTask(uint64_t id, uint32_t delay, const TaskFunc& cb) :
//        _id(id), _timeout(delay), _task_cb(cb), _canceled(false) {}
//    ~TimerTask() {
//        if (_canceled == false) _task_cb();
//        _release();
//    }
//    void Cancel() { _canceled = true; }
//    void SetRelease(const ReleaseFunc& cb) { _release = cb; }
//    uint32_t DelayTime() { return _timeout; }
//};
//class LoopThread {
//private:
//    /*用于实现_loop获取的同步关系，避免线程创建了，但是_loop还没有实例化之前去获取_loop*/
//    std::mutex _mutex;          // 互斥锁
//    std::condition_variable _cond;   // 条件变量
//    EventLoop* _loop;       // EventLoop指针变量，这个对象需要在线程内实例化
//    std::thread _thread;    // EventLoop对应的线程
//private:
//    /*实例化 EventLoop 对象，唤醒_cond上有可能阻塞的线程，并且开始运行EventLoop模块的功能*/
//    void ThreadEntry() {
//        EventLoop loop;
//        {
//            std::unique_lock<std::mutex> lock(_mutex);//加锁
//            _loop = &loop;
//            _cond.notify_all();
//        }
//        loop.Start();
//    }
//public:
//    /*创建线程，设定线程入口函数*/
//    LoopThread() :_loop(NULL), _thread(std::thread(&LoopThread::ThreadEntry, this)) {}
//    /*返回当前线程关联的EventLoop对象指针*/
//    EventLoop* GetLoop() {
//        EventLoop* loop = NULL;
//        {
//            std::unique_lock<std::mutex> lock(_mutex);//加锁
//            _cond.wait(lock, [&]() { return _loop != NULL; });//loop为NULL就一直阻塞
//            loop = _loop;
//        }
//        return loop;
//    }
//};

//struct epoll_event {
//    uint32_t events;    // Epoll 事件
//    epoll_data_t data;  // 用户数据
//};
//
//typedef union epoll_data {
//    void* ptr;
//    int fd;
//    uint32_t u32;
//    uint64_t u64;
//} epoll_data_t;

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <sys/epoll.h>
//#include <fcntl.h>
//
//#define MAX_EVENTS 10
//#define PORT 8080
//
//void setnonblocking(int sockfd) {
//    int flags = fcntl(sockfd, F_GETFL, 0);
//    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
//}
//
//int main() {
//    int listen_sock, conn_sock, nfds, epollfd;
//    struct sockaddr_in server_addr, client_addr;
//    socklen_t client_len = sizeof(client_addr);
//    struct epoll_event ev, events[MAX_EVENTS];
//    char buffer[1024];
//
//    // 创建监听套接字
//    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (listen_sock == -1) {
//        perror("socket");
//        exit(EXIT_FAILURE);
//    }
//
//    // 设置地址重用
//    int opt = 1;
//    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
//
//    // 绑定地址
//    memset(&server_addr, 0, sizeof(server_addr));
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_addr.s_addr = INADDR_ANY;
//    server_addr.sin_port = htons(PORT);
//
//    if (bind(listen_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
//        perror("bind");
//        exit(EXIT_FAILURE);
//    }
//
//    // 监听
//    if (listen(listen_sock, SOMAXCONN) == -1) {
//        perror("listen");
//        exit(EXIT_FAILURE);
//    }
//
//    // 创建 epoll 实例
//    epollfd = epoll_create1(0);
//    if (epollfd == -1) {
//        perror("epoll_create1");
//        exit(EXIT_FAILURE);
//    }
//
//    // 添加监听套接字到 epoll
//    ev.events = EPOLLIN;
//    ev.data.fd = listen_sock;
//    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
//        perror("epoll_ctl: listen_sock");
//        exit(EXIT_FAILURE);
//    }
//
//    // 事件循环
//    for (;;) {
//        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
//        if (nfds == -1) {
//            perror("epoll_wait");
//            exit(EXIT_FAILURE);
//        }
//
//        for (int n = 0; n < nfds; ++n) {
//            if (events[n].data.fd == listen_sock) {
//                // 新连接
//                conn_sock = accept(listen_sock,
//                    (struct sockaddr*)&client_addr,
//                    &client_len);
//                if (conn_sock == -1) {
//                    perror("accept");
//                    continue;
//                }
//
//                setnonblocking(conn_sock);
//                ev.events = EPOLLIN | EPOLLET;  // 边缘触发模式
//                ev.data.fd = conn_sock;
//                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
//                    perror("epoll_ctl: conn_sock");
//                    close(conn_sock);
//                }
//            }
//            else {
//                // 已连接套接字有数据可读
//                int fd = events[n].data.fd;
//                ssize_t count;
//
//                while ((count = read(fd, buffer, sizeof(buffer))) > 0) {
//                    // 处理数据
//                    write(STDOUT_FILENO, buffer, count);
//
//                    // 简单回显
//                    write(fd, buffer, count);
//                }
//
//                if (count == 0 || (count == -1 && errno != EAGAIN)) {
//                    // 连接关闭或出错
//                    close(fd);
//                }
//            }
//        }
//    }
//
//    close(listen_sock);
//    return 0;
//}

//class TcpServer {
//private:
//    uint64_t _next_id;      //这是一个自动增长的连接ID
//    int _port;
//    int _timeout;           //这是非活跃连接的统计时间---多长时间无通信就是非活跃连接
//    bool _enable_inactive_release;//是否启动了非活跃连接超时销毁的判断标志
//    EventLoop _baseloop;    //这是主线程的EventLoop对象，负责监听事件的处理
//    Acceptor _acceptor;    //这是监听套接字的管理对象
//    LoopThreadPool _pool;   //这是从属EventLoop线程池
//    std::unordered_map<uint64_t, PtrConnection> _conns;//保存管理所有连接对应的shared_ptr对象
//
//    using ConnectedCallback = std::function<void(const PtrConnection&)>;
//    using MessageCallback = std::function<void(const PtrConnection&, Buffer*)>;
//    using ClosedCallback = std::function<void(const PtrConnection&)>;
//    using AnyEventCallback = std::function<void(const PtrConnection&)>;
//    using Functor = std::function<void()>;
//    ConnectedCallback _connected_callback;
//    MessageCallback _message_callback;
//    ClosedCallback _closed_callback;
//    AnyEventCallback _event_callback;
//private:
//    void RunAfterInLoop(const Functor& task, int delay) {
//        _next_id++;
//        _baseloop.TimerAdd(_next_id, delay, task);
//    }
//    //为新连接构造一个Connection进行管理
//    void NewConnection(int fd) {
//        _next_id++;
//        PtrConnection conn(new Connection(_pool.NextLoop(), _next_id, fd));
//        conn->SetMessageCallback(_message_callback);
//        conn->SetClosedCallback(_closed_callback);
//        conn->SetConnectedCallback(_connected_callback);
//        conn->SetAnyEventCallback(_event_callback);
//        conn->SetSrvClosedCallback(std::bind(&TcpServer::RemoveConnection, this, std::placeholders::_1));
//        if (_enable_inactive_release) conn->EnableInactiveRelease(_timeout);//启动非活跃超时销毁
//        conn->Established();//就绪初始化
//        _conns.insert(std::make_pair(_next_id, conn));
//    }
//    void RemoveConnectionInLoop(const PtrConnection& conn) {
//        int id = conn->Id();
//        auto it = _conns.find(id);
//        if (it != _conns.end()) {
//            _conns.erase(it);
//        }
//    }
//    //从管理Connection的_conns中移除连接信息
//    void RemoveConnection(const PtrConnection& conn) {
//        _baseloop.RunInLoop(std::bind(&TcpServer::RemoveConnectionInLoop, this, conn));
//    }
//public:
//    TcpServer(int port) :
//        _port(port),
//        _next_id(0),
//        _enable_inactive_release(false),
//        _acceptor(&_baseloop, port),
//        _pool(&_baseloop) {
//        _acceptor.SetAcceptCallback(std::bind(&TcpServer::NewConnection, this, std::placeholders::_1));
//        _acceptor.Listen();//将监听套接字挂到baseloop上
//    }
//    void SetThreadCount(int count) { return _pool.SetThreadCount(count); }
//    void SetConnectedCallback(const ConnectedCallback& cb) { _connected_callback = cb; }
//    void SetMessageCallback(const MessageCallback& cb) { _message_callback = cb; }
//    void SetClosedCallback(const ClosedCallback& cb) { _closed_callback = cb; }
//    void SetAnyEventCallback(const AnyEventCallback& cb) { _event_callback = cb; }
//    void EnableInactiveRelease(int timeout) { _timeout = timeout; _enable_inactive_release = true; }
//    //用于添加一个定时任务
//    void RunAfter(const Functor& task, int delay) {
//        _baseloop.RunInLoop(std::bind(&TcpServer::RunAfterInLoop, this, task, delay));
//    }
//    void Start() { _pool.Create();  _baseloop.Start(); }
//};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for (const string& str : strs)  // 使用 const string&
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& pair : mp)  // 使用范围-based for 循环
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};