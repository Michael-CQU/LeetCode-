////ʮ������תʮ����
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//int main() {
//	char a[100];
//	cin >> a;
//	int l = strlen(a);
//	long long num = 0;
//	for (int i = 0; i < l; i++) {
//		if (a[i] >= '0'&&a[i] <= '9')
//			num += (a[i] - '0')*pow(16, l - 1 - i);
//		else
//			num += (a[i] - 'A' + 10)*pow(16, l - 1 - i);
//	}
//	cout << num;
//	return 0;
//}
//
////ʮ����תʮ������
//#include<iostream>
//using namespace std;
//
//int main() {
//	long long n;
//	int m;
//	int k = 0;
//	char str[100];
//	cin >> n;
//	if (n == 0) {
//		cout << '0';
//	}
//	while (n > 0) {
//		m = n % 16;
//		n / 16;
//		if (m > 9)
//			str[k++] = 'A' + m - 10;
//		else
//			str[k++] = '0' + m;
//	}
//	for (int i = k - 1; i >= 0; i--) {//ע��˳��
//		cout << str[i];
//	}
//	return 0;
//}
////�ܽ᣺����ת��ʱ����Ҫ���ַ�������֮���ת�����ú�'A','0'�ͺ�