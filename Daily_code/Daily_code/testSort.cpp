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
//		std::cout << "---------------any֮���໥�ĸ�-----\n";
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
//// �ж��Ƿ�Ϊ����
//bool isPrime(int n) {
//    if (n < 2) return false;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//// �ݹ�ö�����п��ܵı��ʽ
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
//�º���
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
//bind()����
//auto addFunc2 = std::bind(&add, 15, std::placeholders::_1);
////�ȼ���
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
//        // ��ȡ������󱣴����������
//        virtual const std::type_info& type() { return typeid(T); }
//        // ��Ե�ǰ�Ķ���������¡��һ���µ��������
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
//    // ����������󱣴�����ݵ�ָ��
//    template<class T>
//    T* get() {
//        //��Ҫ��ȡ���������ͣ�����ͱ������������һ��
//        assert(typeid(T) == _content->type());
//        return &((placeholder<T>*)_content)->_val;
//    }
//    //��ֵ����������غ���
//    template<class T>
//    Any& operator=(const T& val) {
//        //Ϊval����һ����ʱ��ͨ��������Ȼ���뵱ǰ�����������ָ�뽻������ʱ�����ͷŵ�ʱ��ԭ�ȱ��������Ҳ�ͱ��ͷ�
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
//// �����ļ�������Ϊ������ģʽ
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
//    // 1. ���������׽��� (����ʡ����socket/bind/listen���̣�ʵ����Ҫ��ȫ)
//    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock_fd == -1) {
//        perror("socket");
//        return -1;
//    }
//
//    // 2. ����epollʵ��
//    efd = epoll_create1(0);  // ���Ƽ�ʹ��epoll_create1(0)���epoll_create
//    if (efd == -1) {
//        perror("epoll_create1");
//        close(sock_fd);
//        return -1;
//    }
//
//    // 3. ��Ӽ����׽��ֵ�epoll
//    ev.events = EPOLLIN;     // �����ɶ��¼��������ӣ�
//    ev.data.fd = sock_fd;
//    if (epoll_ctl(efd, EPOLL_CTL_ADD, sock_fd, &ev) == -1) {
//        perror("epoll_ctl(ADD)");
//        close(sock_fd);
//        close(efd);
//        return -1;
//    }
//
//    while (1) {
//        // 4. �ȴ��¼���������ʱ1000���룩
//        int nfds = epoll_wait(efd, events, MAX_EVENTS, 1000);
//        if (nfds == -1) {
//            if (errno == EINTR) continue;  // ���ź��ж�������
//            perror("epoll_wait");
//            break;
//        }
//        else if (nfds == 0) {
//            // printf("Timeout, no events\n"); // ����ӳ�ʱ�����߼�
//            continue;
//        }
//
//        for (int i = 0; i < nfds; i++) {
//            int fd = events[i].data.fd;
//
//            // 5. ��������׽����¼��������ӣ�
//            if (fd == sock_fd) {
//                new_fd = accept(sock_fd, (struct sockaddr*)&peer, &addrlen);
//                if (new_fd == -1) {
//                    if (errno != EAGAIN && errno != EWOULDBLOCK) {
//                        perror("accept");
//                    }
//                    continue;
//                }
//
//                setnonblocking(new_fd);  // ����Ϊ������ģʽ
//
//                // Ϊ������ע��EPOLLIN|EPOLLET�¼�����Ե����ģʽ��
//                ev.events = EPOLLIN | EPOLLET | EPOLLRDHUP;  // ���EPOLLRDHUP������ӹر�
//                ev.data.fd = new_fd;
//                if (epoll_ctl(efd, EPOLL_CTL_ADD, new_fd, &ev) == -1) {
//                    perror("epoll_ctl(ADD new_fd)");
//                    close(new_fd);
//                }
//            }
//            // 6. ����ҵ���׽����¼�
//            else {
//                // 6.1 �������ӹرջ�����¼�
//                if (events[i].events & (EPOLLERR | EPOLLHUP | EPOLLRDHUP)) {
//                    printf("Connection closed or error on fd %d\n", fd);
//                    epoll_ctl(efd, EPOLL_CTL_DEL, fd, NULL);
//                    close(fd);
//                    continue;
//                }
//
//                // 6.2 ����ɶ��¼�
//                if (events[i].events & EPOLLIN) {
//                    ssize_t count;
//                    // ��������ȡ����Ե����ģʽ����ѭ����ȡֱ��EAGAIN��
//                    while ((count = recv(fd, recv_buf, BUFFER_SIZE, 0)) > 0) {
//                        // ������յ������ݣ�ʾ����ԭ�����ԣ�
//                        send(fd, recv_buf, count, MSG_NOSIGNAL);
//                    }
//
//                    if (count == 0) {  // �Զ˹ر�����
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
//    // 7. ������Դ
//    close(sock_fd);
//    close(efd);
//    return 0;
//}
using TaskFunc = std::function<void()>;
using ReleaseFunc = std::function<void()>;
class TimerTask {
private:
    uint64_t _id;       // ��ʱ���������ID
    uint32_t _timeout;  //��ʱ����ĳ�ʱʱ��
    bool _canceled;     // false-��ʾû�б�ȡ���� true-��ʾ��ȡ��
    TaskFunc _task_cb;  //��ʱ������Ҫִ�еĶ�ʱ����
    ReleaseFunc _release; //����ɾ��TimerWheel�б���Ķ�ʱ��������Ϣ
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
