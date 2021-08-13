/*

#define N 100
typedef int semaphore;
semaphore mutex = 1;
semaphore empty = N;//当empty为0时生产者不可以写
semaphore full = 0;//当full不为0时消费者可以读

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
//注意实现互斥的P操作一定要在实现同步的P操作之后，否则会导致“死锁”。（V操作不会导致进程阻塞，因此两个V的顺序可以随意交换）