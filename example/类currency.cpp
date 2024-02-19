////#include<iostream>
////using namespace std;
////
////class currency {
////public:
////	enum signType {plus,minus};
////	currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
////	~currency() {}
////
////
////
////
////
////	currency add (const currency&) const;
////	currency& increment(const currency&);
////	void output() const;
////private:
////	signType sign;
////	unsigned long dollars;
////	unsigned int cents;
////};
////currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
////{
////
////}
////currency currency::add(const currency& x) const
////{
////
////}
////
////int main() {
////
////	system("pause");
////	return 0;
////}
//
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//enum signType{plus,minus};
////本打算用枚举类型进行的
////但vs2017并不能识别plus和minus，故换成bool，其中+为0，-为1
//
//class illegal_Parameter_Value
//{//异常类，输入不正确信息时用来抛出
//public:
//	illegal_Parameter_Value() :message("Illegal parameter value") {}
//	//构造函数
//	illegal_Parameter_Value(const char* theMessage) { message = theMessage; }
//	//复制构造函数，如同调用构造函数的初始化的“”内容为const char*类型，故声明为该形式，const不可少
//	void outputMessage() { cout << message << endl; }
//private:
//	string message;
//};
////报错类
//
//class currency
//{//类声明
//public:
//	currency(bool the_Sign = 0, unsigned long the_Dollars = 0, unsigned int the_Cents = 0);
//	//构造函数，三输入，若无变量进行构造就赋值为0,0,0，该值为缺省值
//	//若初始值少于参数个数（有参数输入），就按顺序初始化，剩下的按照缺省值进行初始化
//	~currency() {};
//	//析构函数
//	void setValue(bool, unsigned long, unsigned int);
//	void setValue(double);
//
//	bool getSign()const { return sign; }
//	unsigned int getdollar()const { return dollars; }
//	unsigned long getcent()const { return cents; }
//	//const关键字指明 上方成员函数不会改变调用对象的值，故又称常量函数
//	currency add(const currency&)const;
//	//此处的加法函数不会改变调用对象的值，而是作为一个currency类型的值存在于环境中，也不会改变调用该函数的参数的值，故为常量函数
//	//add返回对象的值
//	currency&increment(const currency&);
//	//此处的加法函数会改变调用对象的值，故非常量函数，并且使用引用，可以减少函数在最后返回对象的结果时的复制的时间
//	//increment返回对象的引用
//	void output()const;
//
//	//附加算法
//	void input();//从标准流中读取currency的值，然后赋给调用对象
//	//currency subtract(const currency&x)const;//从调用对象中减去参数对象x的值，返回结果（已实现）
//	//未实现下列三个函数
//	currency percent(const double&x)const;//返回一个currency类的对象，它的值是调用对象的x%。x为double型
//	currency multiply(const double&x)const;//返回一个currency类的对象，它的值是调用对象和x的乘积。x为double型
//	currency divide(const double&x)const;//返回一个currency类的对象，它的值是调用对象除以x的结果。x为double型
//private:
//	bool sign;
//	unsigned long dollars;
//	unsigned int cents;
//};
///*
//class new_currency
//{//新的类把小数点前后的值合起来用double存储了
//public:
//	new_currency(bool the_sign = 0, unsigned long the_dollars = 0, unsigned int the_cents = 0);
//	~new_currency() {}
//	void set_value(bool, unsigned long, unsigned int);
//	void set_value(double);
//
//	bool getsign()const { if (amount < 0)return 1; else return 0; }
//	unsigned long get_dollars()const { if (amount < 0)return (-amount) / 100; else return amount / 100; }
//	unsigned int get_cents()const { if (amount < 0)return (-amount) - get_dollars(); else return amount - get_dollars(); }
//
//	new_currency add(const new_currency&x)const;
//	new_currency &increment(const new_currency&x) { amount += x.amount; return *this; }
//
//	new_currency operator +(const new_currency&)const;
//	new_currency& operator+=(const new_currency&x) { amount += x.amount; return *this; }
//
//	void output(ostream&out)const;//调用全局范围的函数ostream&operator<<(ostream&out,const new_currency&)即可使用<<
//	friend ostream&operator<<(ostream&output,const new_currency&x);
//private:
//	double amount;
//};
////一个新的currency类，把dollar和cent用amount一个数存储，并且amount为整数
//*/
//
//currency::currency(bool the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
//{
//	setValue(the_Sign, the_Dollars, the_Cents);
//}
////调用成员函数初始化
//void currency::setValue(bool the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
//{//给调用对象的数据成员赋值
//	if (the_Cents > 99)throw illegal_Parameter_Value("cents should be<100");//当输入过大时抛出非法信息
//	sign = the_Sign;
//	dollars = the_Dollars;
//	cents = the_Cents;
//}
//void currency::setValue(double the_Amount)
////double和float可带符号
//{
//	if (the_Amount < 0)//判断输入数的正负，并提取前边符号
//	{
//		sign = 1;
//		the_Amount = -the_Amount;
//	}
//	else sign = 0;
//	dollars = (unsigned long)the_Amount;//强制转换为无符号，去除符号问题，其中unsigned long加不加int都一样
//	cents = (unsigned int)((the_Amount + 0.001 - dollars) * 100);//0.01弥补计算机存储数据总会偏小的误差，强制转换数据类型
//}//long占四字节，int在16位系统中占2字节，在32位系统中占4字节，故一般情况是一样的，包括unsigned int和unsigned long
//currency currency::add(const currency& x)const
//{
//	double a1, a2, a3;
//	currency result;//返回一个新声明的变量就不会改变输入参量的值了
//	a1 = dollars * 100 + cents;
//	if (sign == 1)a1 = -a1;//此时a1为带符号的double型
//	a2 = x.dollars * 100 + x.cents;
//	if (x.sign == 1) a2 = -a2;
//	a3 = a1 + a2;//a3符号由运算得来
//	if (a3 < 0)//分离a3的符号和数值
//	{
//		result.sign = 1;//给result变量符号赋值
//		a3 = -a3;//a3为数值，不带符号
//	}
//	else result.sign = 0;
//	result.dollars = a3 / 100;
//	result.cents = a3 - result.dollars * 100;
//	return result;//返回result不改变调用的参数值
//}
//currency& currency::increment(const currency& x)
//{//把参数对象的货币值加到调用对象上，这个函数改变了调用对象的值,不改变引用的x的值，并且x前有const声明
//	*this = add(x);
//	return *this;//返回到x中，改变参数值
//}
//void currency::output()const
//{
//	if (sign == 1)cout << "-";
//	cout << "$" << dollars << ".";
//	if (cents < 10)cout << "0";
//	cout << cents << endl;
//}
////currency currency::subtract(const currency&x)const
////{//课后题
////	currency result;
////	double y1, y2;
////	if (sign == 1)
////	{
////		y1 = -(dollars * 100 + cents);
////		//cout << "y1一开始为负，此时应当为正：" << y1 << endl;
////	}
////	y1 = dollars * 100 + cents;
////	//cout << "对y1操作之后y1应为一正数：" << y1 << endl;
////	if (x.sign == 1)
////		y2 = -(dollars * 100 + cents);
////	y2 = x.dollars * 100 + x.cents;
////	//cout << "对y2操作之后y2应为一正数：" << y2 << endl;
////	double y3 = y1 - y2;
////	//cout << "y1-y2=" << y3 << endl;
////	if (y3 < 0)
////	{
////		y3 = -y3;
////		result.sign = 1;
////	}
////	else
////		result.sign = 0;
////	result.dollars = y3 / 100;
////	//cout << "result.dollars=";
////	//cout << result.dollars << endl;
////	result.cents = y3 - result.dollars * 100;
////	//cout << "result.cents=" << result.cents << endl;
////	return result;
////}
///*
//new_currency::new_currency(bool the_sign, unsigned long the_dollars, unsigned int the_cents)
//{
//	set_value(the_sign, the_dollars, the_cents);
//}
//void new_currency::set_value(bool the_sign, unsigned long the_dollars, unsigned int the_cents)
//{
//	if (the_cents > 99)
//		throw illegal_Parameter_Value("too much cents,the cents should below 100");
//	if (the_sign == 1)
//	{
//		double the_numbers = the_dollars * 100 + the_cents;
//		amount = -the_numbers;
//	}
//	else
//		amount = the_dollars * 100 + the_cents;
//}
//void new_currency::set_value(double Amount)
//{
//	if (Amount < 0)
//		amount = (Amount - 0.001) * 100;
//	else
//		amount = (Amount + 0.001) * 100;
//}
//new_currency new_currency::add(const new_currency&x)const
//{
//	new_currency y;
//	y.amount = x.amount + amount;
//	return y;
//}
////********************************************************************************************
////********************************************************************************************
//void new_currency::output(ostream &out)const
//{//若没有下方输出流的定义，此处的输出流会出error
//	double Amount;
//	//将平时使用的cout换为输入参数即可
//	if (amount < 0)
//	{
//		out << "-";
//		Amount = -amount;
//	}
//	else
//		Amount = amount;
//	unsigned long dollars = Amount / 100;
//	out << "$" << dollars << ".";
//	unsigned int cents = Amount - dollars * 100;
//	if (cents < 10)
//		out << "00";
//	out << cents;
//}
//
//ostream&operator<<(ostream&out, const new_currency&x)
//{//格式即ostream&operator<<(ostream&,自定义类&)
//	//谭浩强c++教程中p314谈及输入输出流不能定义为成员函数，只能定义为友元函数，此处即非成员函数
//	x.output(out);
//	//需要先定义一个类的输出函数，并使输出函数有参数，并且还要是ostream的引用作为参数输入
//	return out;
//	//返回一个对象的引用后续可以对同一个对象进行其他操作，返回对象只是返回一个拷贝副本，无法进行后续操作
//	//如cout<<a<<b<<endl;
//	//此处cout的<<函数返回的就是引用，连续使用输出流即引用符号的效果
//}
////此处为全局范围的函数
////********************************************************************************************
////********************************************************************************************
//new_currency new_currency::operator+(const new_currency&x)const
//{
//	new_currency y;
//	y.amount = amount + x.amount;
//	return y;
//}
//ostream&operator<<(ostream&output,const new_currency&x)
//{
//	double the_amount;
//	if (x.amount < 0)
//	{
//		output << "-";
//		the_amount = -x.amount;
//	}
//	else
//		the_amount = x.amount;
//	unsigned long dollar = the_amount / 100;
//	unsigned int cent = the_amount - dollar * 100;
//	output << "$" << dollar << ".";
//	if (cent < 10)
//		output << "0";
//	output << cent;
//	return output;
//}
//*/
//int main()
//{
//	currency g, h(0, 3, 50), i, j;
//	g.setValue(1, 2, 25);
//	cout << "g的值为：" << endl;
//	g.output();
//	//cout << "g.add(h)的值为：" << endl;
//	//g.add(h).output();
//	////cout << "g.abstract(h)的值为：" << endl;
//	////g.subtract(h).output();
//	//cout << "h的值为：" << endl;
//	//h.output();
//	//cout << "g.increment(h)的值为：" << endl;
//	//g.increment(h).output();
//	//cout << "h的值为：" << endl;
//	//h.output();
//	//cout << "g的值为：" << endl;
//	//g.output();
//	//cout << "h的值为：" << endl;
//	//h.output();
//	i.setValue(-6.45);
//	//j = h.add(g);
//	//h.output();
//	//cout << "+";
//	//g.output();
//	//cout << "=";
//	//j.output();
//	//cout << endl;
//	j = i.add(g).add(h);
//	j.output();
//	j = i.increment(g).add(h);
//	j.output();
//	cout << "Attempting to initialize with cents = 152" << endl;
//	try { i.setValue(0, 3, 152); }
//	catch (illegal_Parameter_Value e)
//	{
//		cout << "Caught thrown exception" << endl;
//		e.outputMessage();
//	}
//	/*
//	new_currency a, b(0, 3, 50), c, d;
//	a.set_value(1, 2, 25);
//	c.set_value(-6.25);
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//	cout << "d= " << d << endl;
//	d = b + a;
//	cout <<"  d=b+a:  "<< b << "+" << a << "=" << d << endl<<endl;
//	d = a + b + c;
//	cout <<"d=a+b+c： "<< a << "+" << b << "+" << c << "=" << d << endl;
//	cout << "increment of new_currency: " << c << "by: " << a << endl << "and then add:" << b << endl;
//	d = (c += a) + b;
//	cout << "the result is : " << d << endl;
//	cout << "incremented object is: " << c << endl;
//	//error testing
//	cout << "attempting to initialize with cents=152" << endl;
//	try { c.set_value(0, 3, 152); }
//	catch (illegal_Parameter_Value e)
//	{
//		cout << "caught thrown exception" << endl;
//		e.outputMessage();
//	}*/
//	system("pause");
//	return 0;
//}
