//template<class T>
//chain<T>::chain(const chain<T>& theList) {
//	//���ƹ��캯��
//	listsize = theList.listsize;
//
//	if (listsize == 0)
//	{
//		firstNode = NULL;
//		return;
//	}
//	
//	//����theListΪ�ǿ�
//	chainNode<T>* soureNode = theList.firstNode;//��������theList�Ľڵ�
//	firstNode = new chainNode<T>(soureceNode->element);//��������theList����Ԫ��
//	soureNode = sourseNode->next;
//	chain<T> targetNode = firstNode;//��ǰ����*this�����һ���ڵ�
//
//	while (soureNode != NULL) {
//		targetNode->next = new chainNode<T>(soureNode->element);
//		targetNode = targetNode->next;
//		soureNode = soureNode->next;
//	}
//	targetNode->next = NULL;
//}