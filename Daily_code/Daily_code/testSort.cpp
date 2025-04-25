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

//#include<iostream>
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

//#include<iostream>
//#include<unordered_map>
//#include<vector>
//#include<string>
//class Solution
//{
//	vector<vector<string>> groupAnagrams(vector<string>& strs)
//	{
//		unorder<string, vector<string>> hash_temp;
//		for (auto& str : strs)
//		{
//			string tem_str = str;
//			sort(tem_str.begin(), tem_str.end());
//			hash_temp[tem_str].push_back(str);
//		}
//		vector<vector<string>> reval;
//		for (auto& ht : hash_temp)
//		{
//			reval.push_back(ht.second);
//		}
//		return reval;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//// ɾ��ָ�����Ӵ���O(n)ʱ�䣬O(1)�ռ�
//void removeSubstrings(string& s, const vector<string>& removeList) {
//    int n = s.size();
//    int slow = 0, fast = 0;
//
//    while (fast < n) {
//        bool matched = false;
//        for (const string& word : removeList) {
//            int len = word.size();
//            if (fast + len <= n && s.substr(fast, len) == word) {
//                fast += len; // ƥ�䵽ĳ���Ӵ���ֱ������
//                matched = true;
//                break;
//            }
//        }
//        if (!matched) {
//            s[slow++] = s[fast++];
//        }
//    }
//    s.resize(slow); // �ض��ַ���
//}
//
//int main() {
//    string s;
//    cin >> s;
//    vector<string> removeList = { "abc", "de", "f" }; // Ҫɾ�����Ӵ�����
//
//    removeSubstrings(s, removeList);
//
//    cout << s << endl;
//    return 0;
//}
//#include <iostream>
//#include <fstream>
//#include <unordered_map>
//#include <queue>
//#include <vector>
//#include <string>
//using namespace std;
//
//const int BUCKETS = 100; // �ֳ�100��СͰ
//const string BUCKET_PREFIX = "bucket_"; // Ͱ�ļ���ǰ׺
//
//// С����Ԫ��
//struct IpCount {
//    string ip;
//    int count;
//    bool operator<(const IpCount& other) const {
//        return count > other.count; // ע�⣺countС���ڶѶ���С���ѣ�
//    }
//};
//
//// ��һ������IP����ϣ��Ͱ
//void splitIntoBuckets(const string& inputFile) {
//    ifstream fin(inputFile);
//    if (!fin.is_open()) {
//        cerr << "�޷����ļ�" << endl;
//        return;
//    }
//
//    ofstream buckets[BUCKETS];
//    for (int i = 0; i < BUCKETS; ++i) {
//        buckets[i].open(BUCKET_PREFIX + to_string(i) + ".txt");
//    }
//
//    string ip;
//    while (fin >> ip) {
//        int hashVal = hash<string>{}(ip) % BUCKETS;
//        buckets[hashVal] << ip << '\n';
//    }
//
//    fin.close();
//    for (int i = 0; i < BUCKETS; ++i) {
//        buckets[i].close();
//    }
//}
//
//// �ڶ�������ÿ��Ͱ����Top10
//vector<IpCount> processBucket(const string& bucketFile) {
//    ifstream fin(bucketFile);
//    unordered_map<string, int> freq;
//    string ip;
//    while (fin >> ip) {
//        freq[ip]++;
//    }
//    fin.close();
//
//    priority_queue<IpCount> minHeap;
//    for (auto& [ip, count] : freq) {
//        minHeap.push({ ip, count });
//        if (minHeap.size() > 10) {
//            minHeap.pop();
//        }
//    }
//
//    vector<IpCount> top10;
//    while (!minHeap.empty()) {
//        top10.push_back(minHeap.top());
//        minHeap.pop();
//    }
//    return top10;
//}
//
//// ���������ϲ�����Ͱ��Top10
//vector<IpCount> mergeAllTop10(const vector<vector<IpCount>>& allTop10) {
//    priority_queue<IpCount> minHeap;
//    for (const auto& bucketTop : allTop10) {
//        for (const auto& ipcount : bucketTop) {
//            minHeap.push(ipcount);
//            if (minHeap.size() > 10) {
//                minHeap.pop();
//            }
//        }
//    }
//
//    vector<IpCount> finalTop10;
//    while (!minHeap.empty()) {
//        finalTop10.push_back(minHeap.top());
//        minHeap.pop();
//    }
//    return finalTop10;
//}
//
//int main() {
//    string inputFile = "ip.txt"; // ��������IP������ļ���
//
//    // ��һ������Ͱ
//    splitIntoBuckets(inputFile);
//
//    // �ڶ�����ÿ��Ͱ�ڲ�Top10
//    vector<vector<IpCount>> allTop10;
//    for (int i = 0; i < BUCKETS; ++i) {
//        string bucketFile = BUCKET_PREFIX + to_string(i) + ".txt";
//        allTop10.push_back(processBucket(bucketFile));
//    }
//
//    // ��������ȫ�ֺϲ�Top10
//    vector<IpCount> finalTop10 = mergeAllTop10(allTop10);
//
//    // �������Top10
//    cout << "���ִ�������10��IP�ǣ�" << endl;
//    for (auto it = finalTop10.rbegin(); it != finalTop10.rend(); ++it) {
//        cout << it->ip << " ������ " << it->count << " ��" << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//// ����С�������£��³���
//void heapifyDown(vector<int>& heap, int idx, int heapSize) {
//    int smallest = idx;
//    int left = 2 * idx + 1;
//    int right = 2 * idx + 2;
//
//    if (left < heapSize && heap[left] < heap[smallest]) {
//        smallest = left;
//    }
//    if (right < heapSize && heap[right] < heap[smallest]) {
//        smallest = right;
//    }
//    if (smallest != idx) {
//        swap(heap[idx], heap[smallest]);
//        heapifyDown(heap, smallest, heapSize);
//    }
//}
//
//// ����С�������ϣ��ϸ���
//void heapifyUp(vector<int>& heap, int idx) {
//    if (idx == 0) return;
//    int parent = (idx - 1) / 2;
//    if (heap[parent] > heap[idx]) {
//        swap(heap[parent], heap[idx]);
//        heapifyUp(heap, parent);
//    }
//}
//
//// ����������Top10���Ԫ��
//void findTop10Largest(const vector<int>& nums) {
//    vector<int> heap; // С����
//
//    for (int num : nums) {
//        if (heap.size() < 10) {
//            heap.push_back(num);
//            heapifyUp(heap, heap.size() - 1); // ������ϸ�
//        }
//        else {
//            if (num > heap[0]) {
//                heap[0] = num; // �滻�Ѷ�
//                heapifyDown(heap, 0, heap.size()); // �滻���³�
//            }
//        }
//    }
//
//    // ������Top10������ģ�
//    cout << "����10�����ǣ�����:" << endl;
//    for (int num : heap) {
//        cout << num << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    // ʾ������
//    vector<int> nums = {
//        12, 3, 55, 7, 89, 100, 2, 45, 67, 34, 88, 91, 25, 76, 54, 99, 1, 23, 66, 78, 85
//    };
//
//    findTop10Largest(nums);
//
//    return 0;
//}
//using namespace std;
//#include<queue>
//#include<vector>
//typedef struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//}TreeNode;
//vector<int> LevelOrder(TreeNode* root)
//{
//	vector<int>rval;
//	queue<TreeNode*>q;
//	q.push(root);
//	if (!root) return;
//	while (!q.empty())
//	{
//		TreeNode* node = q.front();
//		rval.push_back(node->val);
//		q.pop();
//		if (node->left)
//			q.push(node->left);
//		if (node->right)
//			q.push(node->right);
//	}
//	return rval;
//}
//void Order(TreeNode* root, vector<int>&rval)
//{
//	if (!root) return;
//	Order(root->left,rval);
//	rval.push_back(root->val);
//	Order(root->right, rval);
//}
//vector<int> InOrder(TreeNode* root)
//{
//	vector<int> rval;
//	Order(root, rval);
//	return rval;
//}
//struct ListNode {
//	int val;
//	struct ListNode* next;
// ListNode(int x):val(x),next(nullptr){}
//};
//ListNode* GetInterNode(ListNode* A, ListNode* B)
//{
//	if (A == nullptr || B == nullptr) return nullptr;
//	ListNode* pA = A, * pB = B;
//	while (pA != pB)
//	{
//		pA = pA == nullptr ? pB : pA->next;
//		pB = pB == nullptr ? pA : pB->next;
//	}
//	return pA;
//}

//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//	ListNode(int x):val(x),next(nullptr){}
//};
//ListNode* ReverseList(ListNode* head)
//{
//	ListNode* pre = nullptr;
//	ListNode* cur = head;
//	while (cur)
//	{
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		pre = cur;
//		cur = temp;
//	}
//	return pre;
//}
//void PrintList(ListNode* head)
//{
//	while (head)
//	{
//		cout << head->val << " " << endl;
//		head = head->next;
//	}
//	return;
//}
//int main()
//{
//	ListNode* root=new ListNode(1);
//	ListNode* head = root;
//	for (int i = 2; i < 8; ++i)
//	{
//		root->next = new ListNode(1);
//		root = root->next;
//	}
//	PrintList(head);
//	root = ReverseList(head);
//	PrintList(root);
//	return  0;
//}
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//typedef struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
//}TreeNode;
//void Level(TreeNode* root, vector<int> &result)
//{
//	queue<TreeNode*> q;
//	q.push(root);
//	int count = 0;
//	while (!q.empty())
//	{
//		count++;
//		int size = q.size();
//		vector<int> temp_result;
//		for (int i = 0; i < size; i++)
//		{
//			TreeNode* temp = q.front();
//			q.pop();
//			temp_result.push_back(temp->val);
//			if (temp->left != nullptr)
//				q.push(temp->left);
//			if (temp->right != nullptr)
//				q.push(temp->right);
//		}
//		if (count % 2 == 1)
//			for (int i = 0; i < size; ++i)
//				result.push_back(temp_result[i]);
//		else
//			for (int i = size-1; i >=0; --i)
//				result.push_back(temp_result[i]);
//	}
//}
//int main()
//{
//	vector<int> result;
//	TreeNode* root = new TreeNode(1);
//	root->left= new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(7);
//	Level(root,result);
//	for (auto& e : result)
//		cout << e << " ";
//	delete root->right->right;
//	delete root->right->left;
//	delete root->left->right;
//	delete root->left->left;
//	delete root->right;
//	delete root->left;
//	delete root;
//	return 0;
//}

//TOPK���� ������Ϊ��
//#include<iostream>
//#include<vector>
//using namespace std;
//void UpHeap(vector<int>& tempheap, int i)
//{
//	while (i > 0)
//	{
//		int parent = i / 2;
//		if (tempheap[i] < tempheap[parent])
//		{
//			swap(tempheap[i], tempheap[parent]);
//			UpHeap(tempheap, parent);
//		}
//		else
//			break;
//	}
//}
//void DownHeap(vector<int>& tempheap,int i,int K)
//{
//	while (i < K)
//	{
//		int leftson = 2 * i + 1;
//		int rightson = 2 * i + 2;
//		int smallest = i;
//		if (leftson<K && tempheap[smallest] > tempheap[leftson])
//			smallest = leftson;
//		if (rightson<K && tempheap[smallest] > tempheap[rightson])
//			smallest = rightson;
//		if (smallest != i)
//		{
//			swap(tempheap[smallest], tempheap[i]);
//			DownHeap(tempheap, smallest, K);
//		}
//		else
//			break;
//	}
//}
//void Heap_Sort(vector<int >&  nums, int K)
//{
//	vector<int> heapnums;
//	int size = nums.size();
//	for (int i = 0; i < size; i++)
//	{
//		if (i < K)
//		{
//			heapnums.push_back(nums[i]);
//			UpHeap(heapnums, i);
//		}
//		else
//		{
//			if (nums[i] <= heapnums[0])
//				continue;
//			else
//			{
//				heapnums[0]=nums[i];
//				DownHeap(heapnums,0, K);
//			}
//		}
//	}
//	for (auto& e : heapnums)
//		cout << e << " ";
//}
//int main()
//{
//	vector<int> test_nums{ 2,3,45,6,21,3,5,12,546 };
//	int K = 5;
//	Heap_Sort(test_nums, K);
//	return 0;
//}

//������
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
//void HeapSort(vector<int>& nums)
//{
//	//1�����ϵ����ɴ����
//	int size = nums.size();
//	int i = (size - 1) / 2;
//	while (i >= 0)
//	{
//		int left = i * 2 + 1;
//		int right = i * 2 + 2;
//		int largest = i;
//		if (left < size - 1 && nums[largest] < nums[left])
//			largest = left;
//		if (right < size - 1 && nums[largest] < nums[right])
//			largest = right;
//		if (largest != i)
//			swap(nums[largest], nums[i]);
//		--i;
//	}
//	//2���������ڵ��ĩβ�ڵ㣬���µ���
//	for (int j=size-1;j>0;j--)
//	{
//		swap(nums[0], nums[j]);
//		//���µ���
//		int k = 0;
//		while (k < j)
//		{
//			int largest = k;
//			int leftson = k * 2 + 1;
//			int rightson = k * 2 + 2;
//			if (leftson < j && nums[leftson] < nums[largest])
//				largest = leftson;
//			if (leftson < j && nums[rightson] < nums[largest])
//				largest = rightson;
//			if (largest != k)
//				swap(nums[largest], nums[k--]);
//			else break;
//
//		}
//	}
//
//}
//void UpHeapAdjust(vector<int>& nums, int i,int length)
//{
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	if (left < length && nums[largest] < nums[left])
//		largest = left;
//	if (right < length && nums[largest] < nums[right])
//		largest = right;
//	if (i != largest)
//	{
//		swap(nums[largest], nums[i]);
//		UpHeapAdjust(nums, largest,length);
//	}
//}
//void HeapSort(vector<int> &nums)
//{
//	//1.���ϵ����γɴ����
//	int numbers = nums.size();
//	for (int i = numbers / 2 - 1; i >= 0; i--)
//		UpHeapAdjust(nums, i,numbers);
//	//2.�������ڵ� ���µ���
//	for (int i = numbers - 1; i--; i > 1)
//		UpHeapAdjust(nums, 0, i); 
//}
//int main()
//{
//	vector<int> test_nums{ 1,5,7,3,23,4,234,12,45,66,23,45 };
//	HeapSort(test_nums);
//	for (auto& e : test_nums)
//		cout << e << " ";
//	return 0;

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
}TreeNode;
void PreOrder(TreeNode* root,vector<int>& result)
{
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* temp = s.top();
		s.pop();
		result.push_back(temp->val);
		if (temp->right)
			s.push(temp->right);
		if (temp->left)
			s.push(temp->left);
	}
}
int main1()
{
	vector<int> result;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(4);
	root->left->left = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->left->right = new TreeNode(7);
	root->right->right = new TreeNode(6);
	PreOrder(root, result);
	for (auto& e : result)
		cout << e << " ";
	return 0;
}

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
}ListNode;
ListNode* TwoMeet(ListNode* head1, ListNode* head2)
{
	ListNode* cur1 = head1;
	ListNode* cur2 = head2;
	while (head1!= head2)
	{
		head1 = head1 == nullptr ? cur2 : head1->next;
		head2 = head2 == nullptr ? cur1 : head2->next;
	}
	return head1;
}
int main2()
{
	ListNode* temp = nullptr;
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	temp = head1->next;
	head1->next->next = new ListNode(20);
	ListNode* head2 = new ListNode(10);
	head2->next = new ListNode(22);
	head2->next->next = temp;
	//���������Ľڵ�ĵ�ַ
	ListNode* meet= TwoMeet(head1, head2);
	cout << meet->val<<endl;
	return 0;
}
ListNode* PostVal(ListNode* head,int k)
{
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i <= k; i++)
		fast = fast->next;
	while (fast != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->next;
}
int main()
{
	ListNode* head = new ListNode(1);
	ListNode* h = head;
	int k = 4;
	for (int i = 0; i < 10; i++)
	{
		head->next = new ListNode(i + 2);
		head = head->next;
	}
	ListNode* result = PostVal(h, k);
	cout << result->val<<endl;
	return 0;
}