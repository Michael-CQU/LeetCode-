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
////��������ö�����ͽ��е�
////��vs2017������ʶ��plus��minus���ʻ���bool������+Ϊ0��-Ϊ1
//
//class illegal_Parameter_Value
//{//�쳣�࣬���벻��ȷ��Ϣʱ�����׳�
//public:
//	illegal_Parameter_Value() :message("Illegal parameter value") {}
//	//���캯��
//	illegal_Parameter_Value(const char* theMessage) { message = theMessage; }
//	//���ƹ��캯������ͬ���ù��캯���ĳ�ʼ���ġ�������Ϊconst char*���ͣ�������Ϊ����ʽ��const������
//	void outputMessage() { cout << message << endl; }
//private:
//	string message;
//};
////������
//
//class currency
//{//������
//public:
//	currency(bool the_Sign = 0, unsigned long the_Dollars = 0, unsigned int the_Cents = 0);
//	//���캯���������룬���ޱ������й���͸�ֵΪ0,0,0����ֵΪȱʡֵ
//	//����ʼֵ���ڲ����������в������룩���Ͱ�˳���ʼ����ʣ�µİ���ȱʡֵ���г�ʼ��
//	~currency() {};
//	//��������
//	void setValue(bool, unsigned long, unsigned int);
//	void setValue(double);
//
//	bool getSign()const { return sign; }
//	unsigned int getdollar()const { return dollars; }
//	unsigned long getcent()const { return cents; }
//	//const�ؼ���ָ�� �Ϸ���Ա��������ı���ö����ֵ�����ֳƳ�������
//	currency add(const currency&)const;
//	//�˴��ļӷ���������ı���ö����ֵ��������Ϊһ��currency���͵�ֵ�����ڻ����У�Ҳ����ı���øú����Ĳ�����ֵ����Ϊ��������
//	//add���ض����ֵ
//	currency&increment(const currency&);
//	//�˴��ļӷ�������ı���ö����ֵ���ʷǳ�������������ʹ�����ã����Լ��ٺ�������󷵻ض���Ľ��ʱ�ĸ��Ƶ�ʱ��
//	//increment���ض��������
//	void output()const;
//
//	//�����㷨
//	void input();//�ӱ�׼���ж�ȡcurrency��ֵ��Ȼ�󸳸����ö���
//	//currency subtract(const currency&x)const;//�ӵ��ö����м�ȥ��������x��ֵ�����ؽ������ʵ�֣�
//	//δʵ��������������
//	currency percent(const double&x)const;//����һ��currency��Ķ�������ֵ�ǵ��ö����x%��xΪdouble��
//	currency multiply(const double&x)const;//����һ��currency��Ķ�������ֵ�ǵ��ö����x�ĳ˻���xΪdouble��
//	currency divide(const double&x)const;//����һ��currency��Ķ�������ֵ�ǵ��ö������x�Ľ����xΪdouble��
//private:
//	bool sign;
//	unsigned long dollars;
//	unsigned int cents;
//};
///*
//class new_currency
//{//�µ����С����ǰ���ֵ��������double�洢��
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
//	void output(ostream&out)const;//����ȫ�ַ�Χ�ĺ���ostream&operator<<(ostream&out,const new_currency&)����ʹ��<<
//	friend ostream&operator<<(ostream&output,const new_currency&x);
//private:
//	double amount;
//};
////һ���µ�currency�࣬��dollar��cent��amountһ�����洢������amountΪ����
//*/
//
//currency::currency(bool the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
//{
//	setValue(the_Sign, the_Dollars, the_Cents);
//}
////���ó�Ա������ʼ��
//void currency::setValue(bool the_Sign, unsigned long the_Dollars, unsigned int the_Cents)
//{//�����ö�������ݳ�Ա��ֵ
//	if (the_Cents > 99)throw illegal_Parameter_Value("cents should be<100");//���������ʱ�׳��Ƿ���Ϣ
//	sign = the_Sign;
//	dollars = the_Dollars;
//	cents = the_Cents;
//}
//void currency::setValue(double the_Amount)
////double��float�ɴ�����
//{
//	if (the_Amount < 0)//�ж�������������������ȡǰ�߷���
//	{
//		sign = 1;
//		the_Amount = -the_Amount;
//	}
//	else sign = 0;
//	dollars = (unsigned long)the_Amount;//ǿ��ת��Ϊ�޷��ţ�ȥ���������⣬����unsigned long�Ӳ���int��һ��
//	cents = (unsigned int)((the_Amount + 0.001 - dollars) * 100);//0.01�ֲ�������洢�����ܻ�ƫС����ǿ��ת����������
//}//longռ���ֽڣ�int��16λϵͳ��ռ2�ֽڣ���32λϵͳ��ռ4�ֽڣ���һ�������һ���ģ�����unsigned int��unsigned long
//currency currency::add(const currency& x)const
//{
//	double a1, a2, a3;
//	currency result;//����һ���������ı����Ͳ���ı����������ֵ��
//	a1 = dollars * 100 + cents;
//	if (sign == 1)a1 = -a1;//��ʱa1Ϊ�����ŵ�double��
//	a2 = x.dollars * 100 + x.cents;
//	if (x.sign == 1) a2 = -a2;
//	a3 = a1 + a2;//a3�������������
//	if (a3 < 0)//����a3�ķ��ź���ֵ
//	{
//		result.sign = 1;//��result�������Ÿ�ֵ
//		a3 = -a3;//a3Ϊ��ֵ����������
//	}
//	else result.sign = 0;
//	result.dollars = a3 / 100;
//	result.cents = a3 - result.dollars * 100;
//	return result;//����result���ı���õĲ���ֵ
//}
//currency& currency::increment(const currency& x)
//{//�Ѳ�������Ļ���ֵ�ӵ����ö����ϣ���������ı��˵��ö����ֵ,���ı����õ�x��ֵ������xǰ��const����
//	*this = add(x);
//	return *this;//���ص�x�У��ı����ֵ
//}
//void currency::output()const
//{
//	if (sign == 1)cout << "-";
//	cout << "$" << dollars << ".";
//	if (cents < 10)cout << "0";
//	cout << cents << endl;
//}
////currency currency::subtract(const currency&x)const
////{//�κ���
////	currency result;
////	double y1, y2;
////	if (sign == 1)
////	{
////		y1 = -(dollars * 100 + cents);
////		//cout << "y1һ��ʼΪ������ʱӦ��Ϊ����" << y1 << endl;
////	}
////	y1 = dollars * 100 + cents;
////	//cout << "��y1����֮��y1ӦΪһ������" << y1 << endl;
////	if (x.sign == 1)
////		y2 = -(dollars * 100 + cents);
////	y2 = x.dollars * 100 + x.cents;
////	//cout << "��y2����֮��y2ӦΪһ������" << y2 << endl;
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
//{//��û���·�������Ķ��壬�˴�����������error
//	double Amount;
//	//��ƽʱʹ�õ�cout��Ϊ�����������
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
//{//��ʽ��ostream&operator<<(ostream&,�Զ�����&)
//	//̷��ǿc++�̳���p314̸��������������ܶ���Ϊ��Ա������ֻ�ܶ���Ϊ��Ԫ�������˴����ǳ�Ա����
//	x.output(out);
//	//��Ҫ�ȶ���һ����������������ʹ��������в��������һ�Ҫ��ostream��������Ϊ��������
//	return out;
//	//����һ����������ú������Զ�ͬһ����������������������ض���ֻ�Ƿ���һ�������������޷����к�������
//	//��cout<<a<<b<<endl;
//	//�˴�cout��<<�������صľ������ã�����ʹ������������÷��ŵ�Ч��
//}
////�˴�Ϊȫ�ַ�Χ�ĺ���
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
//	cout << "g��ֵΪ��" << endl;
//	g.output();
//	//cout << "g.add(h)��ֵΪ��" << endl;
//	//g.add(h).output();
//	////cout << "g.abstract(h)��ֵΪ��" << endl;
//	////g.subtract(h).output();
//	//cout << "h��ֵΪ��" << endl;
//	//h.output();
//	//cout << "g.increment(h)��ֵΪ��" << endl;
//	//g.increment(h).output();
//	//cout << "h��ֵΪ��" << endl;
//	//h.output();
//	//cout << "g��ֵΪ��" << endl;
//	//g.output();
//	//cout << "h��ֵΪ��" << endl;
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
//	cout <<"d=a+b+c�� "<< a << "+" << b << "+" << c << "=" << d << endl;
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
