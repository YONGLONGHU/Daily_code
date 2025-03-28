
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
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello,World!How,Are,You";
    const char delimiters[] = ",!";
    char* context = NULL;

    // 首次调用
    char* token = strtok_s(str, delimiters, &context);

    while (token != NULL) {
        printf("%s\n", token);
        // 后续调用
        token = strtok_s(NULL, delimiters, &context);
    }

    return 0;
}