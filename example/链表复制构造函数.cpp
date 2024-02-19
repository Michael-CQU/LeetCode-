//template<class T>
//chain<T>::chain(const chain<T>& theList) {
//	//复制构造函数
//	listsize = theList.listsize;
//
//	if (listsize == 0)
//	{
//		firstNode = NULL;
//		return;
//	}
//	
//	//链表theList为非空
//	chainNode<T>* soureNode = theList.firstNode;//复制链表theList的节点
//	firstNode = new chainNode<T>(soureceNode->element);//复制链表theList的首元素
//	soureNode = sourseNode->next;
//	chain<T> targetNode = firstNode;//当前链表*this的最后一个节点
//
//	while (soureNode != NULL) {
//		targetNode->next = new chainNode<T>(soureNode->element);
//		targetNode = targetNode->next;
//		soureNode = soureNode->next;
//	}
//	targetNode->next = NULL;
//}