/*

#define N 100
typedef int semaphore;
semaphore mutex = 1;
semaphore empty = N;//��emptyΪ0ʱ�����߲�����д
semaphore full = 0;//��full��Ϊ0ʱ�����߿��Զ�

void producer() {
	while (TRUE) {
		int item = produce_item();
		down(&empty);
		down(&mutex);
		insert_item(item);
		up(&mutex);
		up(&full);
	}
}

void consumer() {
	while (TRUE) {
		down(&full);
		down(&mutex);
		int item = remove_item();
		consume_item(item);
		up(&mutex);
		up(&empty);
	}
}

*/
//ע��ʵ�ֻ����P����һ��Ҫ��ʵ��ͬ����P����֮�󣬷���ᵼ�¡�����������V�������ᵼ�½����������������V��˳��������⽻����