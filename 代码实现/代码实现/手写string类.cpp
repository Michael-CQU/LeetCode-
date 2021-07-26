#include <iostream>
using namespace std;
//构造、析构、拷贝构造、赋值运算符
class Mystring {
	friend ostream& operator<<(ostream& out, Mystring& str);
public:
	Mystring(const char* str = nullptr);
	~Mystring();
	Mystring(const Mystring& str);
	Mystring& operator=(const Mystring& str);
private:
	char* mydata;
};
Mystring::Mystring(const char* str) {
	if (str == nullptr) {
		mydata = new char[1];
		*mydata = '/0';
	}
	else {
		mydata = new char[strlen(str) + 1];
		strcpy(mydata, str);
	}
}
Mystring::~Mystring() {
	delete[] mydata;
	mydata = nullptr;
}
Mystring::Mystring(const Mystring& str) {
	mydata = new char[strlen(str.mydata) + 1];
	strcpy(mydata,str.mydata);
}
Mystring& Mystring::operator=(const Mystring& str) {
	if (this == &str)//避免自我复制（如果this指针指向了str的地址，那么就是自身）
		return *this;
	delete[] mydata;
	mydata = new char[strlen(str.mydata) + 1];
	strcpy(mydata, str.mydata);
	return *this;
}
ostream& operator<<(ostream& out, Mystring& str) {
	out << str.mydata;
	return out;
}
//strcpy：把src所指向的字符串复制到dest（当src<dest<src+n,n为字符串长度，不包含‘/0’时，内存重叠！！！）
char* mystrcpy(char* dest,char* src) {
	if (!dest || !src)
		return nullptr;
	char *d = dest;
	int size = strlen(src) + 1;
	if (d > src&&d < src + size) {
		d = d + size - 1;
		src = src + size - 1;
		while (size--) {
			*d-- = *src--;
		}
	}
	else {
		while (size--) {
			*d++ = *src++;
		}
	}
	return dest;
}
//strcmp比较两个字符串:正数就是str1大，负数就是str2大，0就是相等
int mystrcmp(const char* str1, const char* str2) {
	while (*str1 == *str2&&*str1 != '\0') {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
//int main() {
//	//Mystring a("abc");
//	//cout << a << endl;
//	//Mystring b(a);
//	//cout << b << endl;
//	//b = "efg";
//	//cout << b << endl;
//	char *src = "123";
//	char *dest = "123";
//	int res = mystrcmp(src, dest);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}