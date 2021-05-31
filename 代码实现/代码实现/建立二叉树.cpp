//根据数组创建完全二叉树
#include<iostream>
#include <queue>
using namespace std;
//优先使用方法三
//方法一：
////二叉树结构
//typedef struct BiTNode {
//	char data;
//	struct BiTNode *lchild, *rchild;//左右孩子指针
//} BiTNode, *BiTree;
//
////前序法创建二叉树
//void CreateBiTree(BiTree &T, char* &str) {
//	if (*str++ == '#')
//		T = NULL;
//	else {
//		T = (BiTNode*)malloc(sizeof(BiTNode));
//		if (!T) exit(1);
//		T->data = *(str - 1);
//		CreateBiTree(T->lchild, str);//构造左子树
//		CreateBiTree(T->rchild, str);//构造右子树
//	}
//}
//
////前序遍历
//void PreOrderTraverse(BiTree T) {
//	if (T) {
//		printf("%c ", T->data);
//		PreOrderTraverse(T->lchild);
//		PreOrderTraverse(T->rchild);
//	}
//}
//
////中序遍历
//void InOrderTraverse(BiTree T) {
//	if (T) {
//		InOrderTraverse(T->lchild);
//		printf("%c ", T->data);
//		InOrderTraverse(T->rchild);
//	}
//}
//
////后序遍历
//void PostOrderTraverse(BiTree T) {
//	if (T) {
//		PostOrderTraverse(T->lchild);
//		PostOrderTraverse(T->rchild);
//		printf("%c ", T->data);
//	}
//}
//
//int main()
//{
//	BiTree T;
//	char* ch;
//	char case1[] = { "ABC##DE#G##F###" };//用于创建二叉树的字符数组
//
//	ch = case1;
//	CreateBiTree(T, ch);
//
//	PreOrderTraverse(T);
//	printf("\n");
//	InOrderTraverse(T);
//	printf("\n");
//	PostOrderTraverse(T);
//	system("pause");
//	return 0;
//}
//方法二：
//typedef struct Tree
//{
//	int value;
//	struct Tree*left;
//	struct Tree*right;
//
//}BinaryTree;
//BinaryTree* create(int a[], int n)
//{
//	//BinaryTree *ptree = (BinaryTree*)malloc(sizeof(BinaryTree)*n);
//	BinaryTree *ptree = new BinaryTree[n];
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		ptree[i].value = a[i];//数组a只起到一个赋值的作用
//		ptree[i].left = NULL;
//		ptree[i].right = NULL;
//	}
//	for (i = 0; i <= n / 2 - 1; i++)//原来的父亲节点范围为1~n/2,现在0~n/2-1,所以注意n/2要取到等
//	{
//		if (2 * i + 1 <= n - 1)
//			ptree[i].left = &ptree[2 * i + 1];//把第2*i+1个结点的地址赋给左孩子
//		if (2 * i + 2 <= n - 1)
//			ptree[i].right = &ptree[2 * i + 2];
//	}
//	return ptree;
//}
//void preorder(BinaryTree* t)
//{
//	if (t == NULL) return;
//	if (t->value != -1)
//		printf("%d\n", t->value);
//	else
//		printf("%s\n", "null");
//	preorder(t->left);
//	preorder(t->right);
//}
//int main()
//{
//	int a[] = { 3,4,5,8,-1,9,10 };
//	BinaryTree *root = NULL;
//	root = create(a, sizeof(a) / sizeof(a[0]));
//
//	preorder(root);
//	system("pause");
//	return 0;
//}
////方法三：
typedef struct BSTreeNode {
	int m_nValue;
	struct BSTreeNode * m_pLeft;
	struct BSTreeNode * m_pRight;
}BSTreeNode;

BSTreeNode * creatBTree(int data[], int index, int n)
{
	BSTreeNode * pNode = NULL;

	if (index < n && data[index] != -1)//数组中-1 表示该节点为空
	{
		//pNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		pNode = new BSTreeNode;
		if (pNode == NULL)
			return NULL;
		pNode->m_nValue = data[index];
		pNode->m_pLeft = creatBTree(data, 2 * index + 1, n);//将二叉树按照层序遍历, 依次标序号, 从0开始
		pNode->m_pRight = creatBTree(data, 2 * index + 2, n);
	}

	return pNode;
}
void levelordertraver(BSTreeNode* result) {
	queue<BSTreeNode*> que;
	BSTreeNode* tem;
	if (result) {
		que.push(result);
		while (!que.empty()) {
			tem = que.front();
			que.pop();
			if (tem->m_nValue != '#')
				cout << tem->m_nValue << " ";
			else
				cout << "null" << " ";
			if (tem->m_pLeft) {
				que.push(tem->m_pLeft);
			}
			if (tem->m_pRight) {
				que.push(tem->m_pRight);
			}
		}
		cout << endl;
	}
}
//int main()
//{
//	int a[] = { 3,4,5,8,-1,9,10 };
//	BSTreeNode *root = NULL;
//	root = creatBTree(a, 0,sizeof(a) / sizeof(a[0]));
//
//	levelordertraver(root);
//	system("pause");
//	return 0;
//}
