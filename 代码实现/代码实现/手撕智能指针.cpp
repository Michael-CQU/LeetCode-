#include<bits/stdc++.h>
using namespace std;

//����ָ��ʵ����һ��������Ϊ����ȴ��һ��ָ��
//��Ҫ����ֻ��ָ����Թ���ʱ��ʼ��������ʱ�ͷ���Դ
//����ָ����һ���࣬���������������ʱ������Զ����������������Զ��ͷ���Դ

//���졢��������������ֵ��*��->
template<class T>
class smartptr {
public:
	smartptr(T* ptr = nullptr) {//����ָ��
		_ptr = ptr;
		_count = new int[1];
		cout << "����" << endl;
	}
	~smartptr() {
		if (_count != nullptr){//�����ж��ƶ�����
			--(*_count);
			if ((*_count) == 0) {
				delete _ptr;
				_ptr = nullptr;
				delete _count;
				_count = nullptr;
			}
			cout << "����" << endl;
		}
	}
	smartptr(const smartptr& s) {//�������
		_ptr = s._ptr;
		_count = s._count;
		++(*_count);
		cout << "����" << endl;

	}
	smartptr<T>& operator=(const smartptr& s) {//�������,���÷�ʽ���ر���
		if (this != &s) {
			if (--(*_count) == 0) {
				delete _ptr;
				delete _count;
			}
			_ptr = s._ptr;
			_count = s._count;
			++(*_count);
		}
		cout << "��ֵ" << endl;
		return *this;
	}
	smartptr(smartptr&& s) {//�ƶ�����
		_ptr = s._ptr;
		_count = s._count;
		s._ptr = nullptr;
		s._count = nullptr;
		cout << "�ƶ�" << endl;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {//Ϊ��ʹһ���������ֵ���һ�����͵�ָ��һ��
		return _ptr;
	}
public:
	T* _ptr;
	int* _count;
};

//int main() {
//	{
//		smartptr<int> p1(new int[10]);
//		smartptr<int> p2(p1);
//		smartptr<int> p3;
//		p3 = p1;
//		smartptr<int> p4(move(p3));
//	}
//	system("pause");
//	return 0;
//}