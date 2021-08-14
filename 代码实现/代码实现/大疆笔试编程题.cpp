//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
////d:10,a:3#d:5,a:2
//int main(){
//    string input;
//    cin>>input;
//    string C,U;
//    for(int i = 0;i<input.size();i++){
//        if(input[i] == '#'){
//            C = input.substr(0,i);
//            U = input.substr(i+1);
//        }
//    }
//    unordered_map<char,int> mp1,mp2;
//    for(int i = 0;i<C.size();i++){
//        if(C[i] == ':'){
//            int temp = 0;
//			char c = C[i - 1];
//            while(C[i+1]>='0'&&C[i+1]<='9'){
//                temp = temp*10+(C[i+1]-'0');
//                i++;
//            }
//            mp1[c] = temp;
//        }
//    }
//    for(int i = 0;i<U.size();i++){
//        if(U[i] == ':'){
//            int temp = 0;
//			char c = U[i - 1];
//            while(U[i+1]>='0'&&U[i+1]<='9'){
//                temp = temp*10+(U[i+1]-'0');
//                i++;
//            }
//            mp2[c] = temp;
//        }
//    }
//    string ans;
//    for(int i = 1;i<C.size();i++){
//        if(C[i] == ':'){
//			mp1[C[i-1]] -= mp2[C[i-1]];
//        }
//        if(mp1[C[i-1]]>0){
//			ans += C[i - 1];
//			ans += ':';
//			ans += to_string(mp1[C[i - 1]]);
//			ans += ',';
//        }
//    }
//    cout<< ans.substr(0,ans.size()-1) <<endl;
//    return 0;
//}