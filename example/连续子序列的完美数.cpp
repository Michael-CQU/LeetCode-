//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//    int m;
//    cin>>m;
//    while(m--){
//        int n;
//        cin>>n;
//        vector<int> a(n);
//        for(int i =0;i<n;i++){
//            cin>>a[i];
//        }
//        vector<int>b(n);
//        int sum =0;
//        for(int i =0;i<n;i++){
//            sum += a[i];
//            b[i] = sum;//b[i]包括第i位的前缀和
//        }
//        int len = 1,ans = 1,begin = 1;
//		if (a[1] > a[0])len++;
//        for(int i = 2;i<n;i++){
//            if(a[i]>=(b[i-1]-b[begin-1])){
//                len++;
//            }
//            else{
//                if(len>ans){
//                    ans = len;
//                }
//                len = 1;
//                begin = i;
//            }
//        }
//        if(len>ans){
//           ans = len;
//                }
//        cout << ans <<endl;
//		return 0;
//    }
//}