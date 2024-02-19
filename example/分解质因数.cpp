#include <cstdio>  
#include <iostream>  
#define max 10000  
  
int prime[max];  
  
int isPrime(int n)  
{  
    int flag = 1;  
    for(int i = 2; i*i <= n; i++)  
        if(n%i == 0)  
            flag = 0;  
    return flag;  
}  
  
int getPrime(int m)  
{  
    int cnt = 0;  
    int flag = 1;  
      
    for(int i = 2; i <= m; i++){  
        flag = 1;  
        for(int j = 2; j*j <= i; j++)  
            if(i%j == 0)  
                flag = 0;  
        if(flag)  
            prime[cnt++] = i;  
    }  
      
    return cnt;  
}  
void split(int m)  
{  
    int i = 0;  
    int t = 0;  
    while(m != 1){  
        t = m/prime[i];  
        if(t*prime[i] == m){  
            m /= prime[i];  
            if(m != 1)  
               printf("%d*",prime[i]);  
            else  
                printf("%d",prime[i]);  
        }  
        else  
            i++;  
    }  
    printf("\n");  
}  
//int main()  
//{  
//    int st,end;  
//    int cnt = getPrime(10000);  
//    scanf("%d%d",&st,&end);  
//  
//    for(int i = st; i <= end; i++)  
//    {  
//        if(isPrime(i))  
//            printf("%d=%d\n",i,i);  
//        else  
//        {  
//            printf("%d=",i);  
//            split(i);  
//        }  
//    }  
//  
//  
//    return 0;  
//}  