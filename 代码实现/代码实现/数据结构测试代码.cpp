#include <iostream>
#include <queue>
#include <vector>
using namespace std;

////Hash��STL��
//template<>
//class hash<string>
//{
//public:
//	size_t operator()(const string theKey) const {
//		unsigned long hashValue = 0;
//		int length = (int)theKey.length();
//		for (int i = 0; i < length; i++)
//			hashValue = 5 * hashValue + theKey.at(i);
//
//		return size_t(hashValue);
//	}
//};
////ɢ�б��ַ���ת��Ϊ�������ִ洢
//int stringToint(string s)
//{
//	int length = (int)s.length();
//	int answer = 0;
//	if (length % 2 == 1) {
//		answer = s.at(length - 1);
//		length--;
//	}
//	for (int i = 0; i < length; i += 2) {
//		answer += s.at(i);
//		answer += ((int)s.at(i + 1)) << 8;
//	}
//	return (answer < 0) ? -answer : answer;
//}
//int main() {
//	//string s = "abcde";
//	//char a[]= "abcde";
//	//cout << sizeof(a) << endl;
//	////int result = stringToint(s);
//	////cout << result << endl;
//	//hash<string> h;
//	//size_t result = h.operator()(s);
//	//cout << result << endl;
//	system("pause");
//	return 0;
//}

////������
//template<class T>
//struct binaryTreeNode
//{
//	T element;
//	binaryTreeNode<T> *leftChild;
//	binaryTreeNode<T> *rightChild;
//	binaryTreeNode() { leftChild = rightChild = NULL; }
//	//binaryTreeNode(const &T theElement) {
//	//	element = theElement;
//	//	leftChild = rightChild = NULL;
//	//}
//
//	binaryTreeNode(const T& _val, binaryTreeNode* _leftchild = NULL, binaryTreeNode* _rightchild = NULL) :
//		element(_val), leftChild(_leftchild), rightChild(_rightchild) {}
//	//binaryTreeNode(const &T theElement, binaryTreeNode *theleftChild,
//	//binaryTreeNode *therightChild) {
//	//	this->element = theElement;
//	//	leftChild = theleftChild;
//	//	rightChild = therightChild;
//	//}
//};
//template<class T>
//void visit(binaryTreeNode<T> *x) {
//	//���ʽڵ�*x�������element��
//	cout << x->element << ' ';
//}
////ǰ�����
//template<class T>
//void preOrder(binaryTreeNode<T> *t) {
//	//ǰ�����������
//	if (t != NULL) {
//		visit(t);
//		preOrder(t->leftChild);
//		preOrder(t->rightChild);
//	}
//}
////�������
//template<class T>
//void inOrder(binaryTreeNode<T> *t) {
//	//�������������
//	if (t != NULL) {
//		inOrder(t->leftChild);
//		visit(t);
//		inOrder(t->rightChild);
//	}
//}
////�������
//template<class T>
//void postOrder(binaryTreeNode<T> *t) {
//	//�������������
//	if (t != NULL) {
//		postOrder(t->leftChild);
//		postOrder(t->rightChild);
//		visit(t);
//	}
//}
//
//int main(){
//	binaryTreeNode<char>* A = new binaryTreeNode<char>('a');
//	binaryTreeNode<char>* B = new binaryTreeNode<char>('b');
//	binaryTreeNode<char>* C = new binaryTreeNode<char>('+');
//	binaryTreeNode<char>* D = new binaryTreeNode<char>('c');
//	binaryTreeNode<char>* E = new binaryTreeNode<char>('d');
//	binaryTreeNode<char>* F = new binaryTreeNode<char>('-');
//	binaryTreeNode<char>* G = new binaryTreeNode<char>('e');
//	binaryTreeNode<char>* H = new binaryTreeNode<char>('f');
//	A->leftChild = B;
//	A->rightChild = E;
//	B->leftChild = C;
//	C->rightChild = D;
//	E->leftChild = F;
//	E->rightChild = G;
//	G->leftChild = H;
//	std::cout << "Pre order traversal:" << std::endl;
//	preOrder(A);
//	std::cout << std::endl << "In order traversal:" << std::endl;
//	inOrder(A);
//	std::cout << std::endl << "Post order traversal:" << std::endl;
//	postOrder(A);
//	queue<int> q;
//	system("pause");
//	return 0;
//}

////huffman��
//#include <iostream>   
//#include <queue>   
//#include <string.h>   
//#include <vector>   
//#include <algorithm>   
//using namespace std;
//
//char Table[26];
//
//struct Node
//{
//	int     freq;
//	char    val;
//	Node    * left;
//	Node    * right;
//	Node() :left(NULL), right(NULL), freq(0), val('0') {}
//};
//
//class Cmp
//{
//public:
//	bool operator() (const Node * a, const Node * b) const
//	{
//		return  a->freq > b->freq;  // ��С���� ��freq С�� ���ȼ����    
//	}
//};
//
//priority_queue<Node*, vector<Node*>, Cmp> myQueue;
//
//void BuildTree()
//{
//	for (int i = 0; i < 26; ++i)
//	{
//		if (Table[i] > 0)
//		{
//			Node * node = new Node();
//			node->freq = Table[i];
//			node->val = (char)(i + 'A');
//			myQueue.push(node);
//		}
//	}
//
//	while (myQueue.size() > 1)
//	{
//		Node * f = myQueue.top();
//		myQueue.pop();
//		Node * s = myQueue.top();
//		myQueue.pop();
//		Node * tmp = new Node();
//		tmp->freq = f->freq + s->freq;
//		tmp->left = f;
//		tmp->right = s;
//		myQueue.push(tmp);
//	}
//	//cout << myQueue.top()->freq<<endl;   
//}
//
//struct PrintNode
//{
//	int freq;
//	char val;
//	string code;
//};
//
//vector<PrintNode> vpn;
//bool cmp(const PrintNode & a, const PrintNode & b)
//{
//	return a.freq > b.freq;
//}
//
//void Print(Node * node, string res)
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	if (node->val != '0')
//	{
//		PrintNode pn;
//		pn.val = node->val;
//		pn.freq = node->freq;
//		pn.code = res;
//		vpn.push_back(pn);
//		//cout <<node->val <<" | " << node->freq <<" | "<< res <<endl;   
//		return;
//	}
//	Print(node->left, res + "0");
//	Print(node->right, res + "1");
//	delete node->left;
//	delete node->right;
//}
//
//int main()
//{
//	int N;
//	memset(Table, 0, sizeof(Table));
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		char ch;
//		cin >> ch;
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			++Table[ch - 'A'];
//		}
//	}
//	BuildTree();
//	Node * root = myQueue.top();
//	myQueue.pop();
//	Print(root, "");
//
//	sort(vpn.begin(), vpn.end(), cmp);
//
//	for (int i = 0; i < vpn.size(); ++i)
//	{
//		cout << vpn[i].val << " " << vpn[i].freq << " "  << endl;
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//
//using namespace std;
//const int increment = 3;
//void shellSort(int a[], int len)
//{
//	int temp = 0;
//	unsigned gap = len / increment; // ������ʼ��
//	while (gap) // while gap>=1
//	{
//		for (unsigned i = gap; i < len; ++i) // ���飬��ÿ���������н��в�������
//		{
//			temp = a[i];//����ǰ��Ԫ��ֵ�ȴ���������������
//			unsigned j = i;
//			while (j >= gap && temp < a[j - gap])//Ѱ�Ҳ���λ��
//			{
//				a[j] = a[j - gap];
//				j -= gap;
//			}
//			a[j] = temp;
//		}
//		gap = gap / increment;
//	}
//}
//int main()
//{
//	int array[10] = { 4,2,3,1,7,8,6,9,5,10 };
//	cout << "����ǰ��Ԫ�أ�" << endl;
//	for (int num = 0; num < 10; num++)
//	{
//		cout << array[num] << " ";
//	}
//	cout << endl;
//	shellSort(array, 10);
//	cout << "������Ԫ�أ�" << endl;
//	for (int num = 0; num < 10; num++)
//	{
//		cout << array[num] << " ";
//	}
//	system("pause");
//	return 0;
//}