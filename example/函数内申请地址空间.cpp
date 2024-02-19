#include<bits/stdc++.h>
using namespace std;

//void getmemory(char* p,int n) {
//	p = (char*)malloc(n);
//}
//int main() {
//	char* str = nullptr;
//	getmemory(str, 100);
//	strcpy(str, "helloworld");
//	cout << str << endl;//程序崩溃，应该是访问无效内存
//	free(str);
//	system("pause");
//}



//int main(){
//	int c = 0;
//	char* p;
//	while (c <= 255) {
//		p = (char*)malloc(100);//p的地址每次不同，但是没有释放操作，因此导致内存泄漏
//		c++;
//	}
//	free(p);
//	p = nullptr;
//	system("pause");
//}