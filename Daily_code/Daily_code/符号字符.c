
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

//using TaskFunc = std::function<void()>;
//using ReleaseFunc = std::function<void()>;
//class TimerTask {
//private:
//    uint64_t _id;       // ��ʱ���������ID
//    uint32_t _timeout;  //��ʱ����ĳ�ʱʱ��
//    bool _canceled;     // false-��ʾû�б�ȡ���� true-��ʾ��ȡ��
//    TaskFunc _task_cb;  //��ʱ������Ҫִ�еĶ�ʱ����
//    ReleaseFunc _release; //����ɾ��TimerWheel�б���Ķ�ʱ��������Ϣ
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
//    /*����ʵ��_loop��ȡ��ͬ����ϵ�������̴߳����ˣ�����_loop��û��ʵ����֮ǰȥ��ȡ_loop*/
//    std::mutex _mutex;          // ������
//    std::condition_variable _cond;   // ��������
//    EventLoop* _loop;       // EventLoopָ����������������Ҫ���߳���ʵ����
//    std::thread _thread;    // EventLoop��Ӧ���߳�
//private:
//    /*ʵ���� EventLoop ���󣬻���_cond���п����������̣߳����ҿ�ʼ����EventLoopģ��Ĺ���*/
//    void ThreadEntry() {
//        EventLoop loop;
//        {
//            std::unique_lock<std::mutex> lock(_mutex);//����
//            _loop = &loop;
//            _cond.notify_all();
//        }
//        loop.Start();
//    }
//public:
//    /*�����̣߳��趨�߳���ں���*/
//    LoopThread() :_loop(NULL), _thread(std::thread(&LoopThread::ThreadEntry, this)) {}
//    /*���ص�ǰ�̹߳�����EventLoop����ָ��*/
//    EventLoop* GetLoop() {
//        EventLoop* loop = NULL;
//        {
//            std::unique_lock<std::mutex> lock(_mutex);//����
//            _cond.wait(lock, [&]() { return _loop != NULL; });//loopΪNULL��һֱ����
//            loop = _loop;
//        }
//        return loop;
//    }
//};

//struct epoll_event {
//    uint32_t events;    // Epoll �¼�
//    epoll_data_t data;  // �û�����
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
//    // ���������׽���
//    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (listen_sock == -1) {
//        perror("socket");
//        exit(EXIT_FAILURE);
//    }
//
//    // ���õ�ַ����
//    int opt = 1;
//    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
//
//    // �󶨵�ַ
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
//    // ����
//    if (listen(listen_sock, SOMAXCONN) == -1) {
//        perror("listen");
//        exit(EXIT_FAILURE);
//    }
//
//    // ���� epoll ʵ��
//    epollfd = epoll_create1(0);
//    if (epollfd == -1) {
//        perror("epoll_create1");
//        exit(EXIT_FAILURE);
//    }
//
//    // ��Ӽ����׽��ֵ� epoll
//    ev.events = EPOLLIN;
//    ev.data.fd = listen_sock;
//    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
//        perror("epoll_ctl: listen_sock");
//        exit(EXIT_FAILURE);
//    }
//
//    // �¼�ѭ��
//    for (;;) {
//        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
//        if (nfds == -1) {
//            perror("epoll_wait");
//            exit(EXIT_FAILURE);
//        }
//
//        for (int n = 0; n < nfds; ++n) {
//            if (events[n].data.fd == listen_sock) {
//                // ������
//                conn_sock = accept(listen_sock,
//                    (struct sockaddr*)&client_addr,
//                    &client_len);
//                if (conn_sock == -1) {
//                    perror("accept");
//                    continue;
//                }
//
//                setnonblocking(conn_sock);
//                ev.events = EPOLLIN | EPOLLET;  // ��Ե����ģʽ
//                ev.data.fd = conn_sock;
//                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
//                    perror("epoll_ctl: conn_sock");
//                    close(conn_sock);
//                }
//            }
//            else {
//                // �������׽��������ݿɶ�
//                int fd = events[n].data.fd;
//                ssize_t count;
//
//                while ((count = read(fd, buffer, sizeof(buffer))) > 0) {
//                    // ��������
//                    write(STDOUT_FILENO, buffer, count);
//
//                    // �򵥻���
//                    write(fd, buffer, count);
//                }
//
//                if (count == 0 || (count == -1 && errno != EAGAIN)) {
//                    // ���ӹرջ����
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
//    uint64_t _next_id;      //����һ���Զ�����������ID
//    int _port;
//    int _timeout;           //���Ƿǻ�Ծ���ӵ�ͳ��ʱ��---�೤ʱ����ͨ�ž��Ƿǻ�Ծ����
//    bool _enable_inactive_release;//�Ƿ������˷ǻ�Ծ���ӳ�ʱ���ٵ��жϱ�־
//    EventLoop _baseloop;    //�������̵߳�EventLoop���󣬸�������¼��Ĵ���
//    Acceptor _acceptor;    //���Ǽ����׽��ֵĹ������
//    LoopThreadPool _pool;   //���Ǵ���EventLoop�̳߳�
//    std::unordered_map<uint64_t, PtrConnection> _conns;//��������������Ӷ�Ӧ��shared_ptr����
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
//    //Ϊ�����ӹ���һ��Connection���й���
//    void NewConnection(int fd) {
//        _next_id++;
//        PtrConnection conn(new Connection(_pool.NextLoop(), _next_id, fd));
//        conn->SetMessageCallback(_message_callback);
//        conn->SetClosedCallback(_closed_callback);
//        conn->SetConnectedCallback(_connected_callback);
//        conn->SetAnyEventCallback(_event_callback);
//        conn->SetSrvClosedCallback(std::bind(&TcpServer::RemoveConnection, this, std::placeholders::_1));
//        if (_enable_inactive_release) conn->EnableInactiveRelease(_timeout);//�����ǻ�Ծ��ʱ����
//        conn->Established();//������ʼ��
//        _conns.insert(std::make_pair(_next_id, conn));
//    }
//    void RemoveConnectionInLoop(const PtrConnection& conn) {
//        int id = conn->Id();
//        auto it = _conns.find(id);
//        if (it != _conns.end()) {
//            _conns.erase(it);
//        }
//    }
//    //�ӹ���Connection��_conns���Ƴ�������Ϣ
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
//        _acceptor.Listen();//�������׽��ֹҵ�baseloop��
//    }
//    void SetThreadCount(int count) { return _pool.SetThreadCount(count); }
//    void SetConnectedCallback(const ConnectedCallback& cb) { _connected_callback = cb; }
//    void SetMessageCallback(const MessageCallback& cb) { _message_callback = cb; }
//    void SetClosedCallback(const ClosedCallback& cb) { _closed_callback = cb; }
//    void SetAnyEventCallback(const AnyEventCallback& cb) { _event_callback = cb; }
//    void EnableInactiveRelease(int timeout) { _timeout = timeout; _enable_inactive_release = true; }
//    //�������һ����ʱ����
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
        for (const string& str : strs)  // ʹ�� const string&
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& pair : mp)  // ʹ�÷�Χ-based for ѭ��
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};