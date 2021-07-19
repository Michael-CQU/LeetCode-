//单调栈和单调队列思想:先用暴力朴素算法，然后看看哪些元素没有用就删掉，然后就有了单调性。根据单调性进行优化。
//先想暴力怎么做，然后从中挖掘一些，把没用的元素删掉就有单调性了，有单调性就可以求极值，将时间复杂度降为O（1）
//队列里存的是下标
//#include<iostream>
//using namespace std;
//
//const int N = 1000010;
//	int n, k;
//	int a[N],q[N];//q数组就是单调队列，存的是k大小的框内最小的值的下标（重要）
//int main(){
//	cin >> n >> k;
//    for(int i = 0;i<n;i++){
//		cin >> a[i];
//    }
//    //最小值
//    int hh = 0,tt = -1;
//    for(int i = 0;i<n;i++){
//		//判断队头是否已经滑出窗口，注意q里存的是下标
//        if(hh<=tt&&i-k+1>q[hh])
//			hh++;
//        while(hh<=tt&&a[q[tt]]>=a[i])//注意每次循环到这里时tt的值和i的值相等，因此要tt-1来找到i前边的值。核心是思想就是如果i的值比i-1及其之前大的话，就直接放入q队列里，如果小的话，就要先把前边比它大的值用tt删掉，然后再存入i的值。
//			tt--;
//        q[++tt] = i;
//        if(i>=k-1)printf("%d ",a[q[hh]]);//只要输出在窗口内的值，前k个值不需要管
//    }
//    puts("");
//    //最大值
//    hh = 0,tt = -1;
//    for(int i = 0;i<n;i++){
//        if(hh<=tt&&i-k+1>q[hh])hh++;
//        while(hh<=tt&&a[q[tt]]<=a[i])tt--;
//        q[++tt] = i;
//        if(i>=k-1)printf("%d ",a[q[hh]]);
//    }
//    puts("");
//	system("pause");
//    return 0;
//}