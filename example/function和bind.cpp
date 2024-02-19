/*#include <iostream>  
#include <functional>  
using namespace std;  
template <class T>  
T g_Minus(T i, T j){  
    return i - j;  
}  
int main(){  
    function<int(int, int)> f = g_Minus<int>;  
    cout << f(1, 2) << endl;  
	system("pause");
    return 0;  
}  


#include <iostream>  
#include <functional>  
using namespace std;  
class Func{  
public:  
    static void func6(int numa, int numb, int numc){  
        cout << numa << " " << numb << " " << numc << endl;  
    }  
    void func2(int numa, int numb, int numc,string namc){  
        cout << numa << " " << numb << " " << numc<<" " << namc << endl;  
    }  
};  
void callFunc(function<void(int a,int b)> call){  
    call(1,2);  
}  
void func1(int numa, int numb, int numc){  
    std::cout << numa << " " << numb << " " << numc << endl;  
}  
int main(){  
    callFunc(bind(func1, placeholders::_1, placeholders::_2, 3));  
    callFunc(bind(func1, placeholders::_2, placeholders::_1, 3));  
    callFunc(bind(func1, placeholders::_2, 3, placeholders::_1));  
    callFunc(bind(Func::func6, placeholders::_1, placeholders::_2, 3));  
}*/  