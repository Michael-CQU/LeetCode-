//#include <iostream>
//using namespace std;
//
//class testone
//{
//	
//	public:
//		int age = 30;
//
//		testone()
//		{}
//		~testone()
//		{}
//	void Show(int age)
//	{
//		this->age = age;
//		cout << age << " " << this->age<< endl;
//	}
//};
//int main()
//{
//	testone one;
//	int age = 32;
//	one.Show(age);
//	system("pause");
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//class Box
//{
//public:
//	// 构造函数定义
//	//Box(double l = 2.0, double b = 2.0, double h = 2.0)
//	Box(double l, double b, double h)
//	{
//		cout << "Constructor called." << endl;
//		length = l;
//		breadth = b;
//		height = h;
//		//cout << l << b << h << endl;
//		cout << length << breadth << height << endl;
//	}
//	double Volume()
//	{
//		return length * breadth * height;
//	}
//	int compare(Box box)
//	{
//		return this->Volume() > box.Volume();
//	}
//private:
//	double length;     // Length of a box
//	double breadth;    // Breadth of a box
//	double height;     // Height of a box
//};
//
//int main(void)
//{
//	Box Box1(3.3, 1.2, 1.5);    // Declare box1
//	Box Box2(8.5, 6.0, 2.0);    // Declare box2
//
//	if (Box1.compare(Box2))
//	{
//		cout << "Box2 is smaller than Box1" << endl;
//	}
//	else
//	{
//		cout << "Box2 is equal to or larger than Box1" << endl;
//	}
//	system("pause");
//	return 0;
//}