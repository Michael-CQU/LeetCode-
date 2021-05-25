//#include <stack>
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <iterator>
//using namespace std;
//int compareOperatorPriority(char op1, char op2);
//string getSuffixExpression(string str);
//int calculate(string str);
//bool isDigit(char c);
//bool isOperator(char c);
//int main(int argc, char const *argv[])
//{
//	/* code */
//	string input;
//	cout << "Please input a exoression: ";
//	cin >> input;
//	cout << "The input is : " << input << endl;
//	input = getSuffixExpression(input);
//	cout << "The suffix exoression is :" << input << endl;
//	int result = calculate(input);
//	cout << "The result is " << result << endl;
//	system("pause");
//	return 0;
//}
///*
//*比较两个操作符的优先级，op1比op2高返回1，一样返回0，低返回-1
//*/
//int compareOperatorPriority(char op1, char op2) {
//	switch (op1) {
//	case '+': case '-':
//		return (op2 == '*' || op2 == '/' ? -1 : 0);
//		break;
//	case '*': case '/':
//		return (op2 == '-' || op2 == '+' ? 1 : 0);
//	}
//	return -1;
//}
///*
//*得到后缀表达式
//*/
//string getSuffixExpression(string str) {
//	stack<char> numbersAndOperators;
//	stack<char> operators;
//	//开始遍历字符串
//	for (int i = 0; i<str.length(); i++) {
//		if (isDigit(str[i])) {
//			numbersAndOperators.push(str[i]);//如果是数字，则直接进入栈numbersAndOperators
//		}
//		else if (isOperator(str[i])) {//如果是操作符
//			if (operators.empty() || operators.top() == '(') {//若栈空或栈顶为(
//				operators.push(str[i]);
//			}
//			else if (compareOperatorPriority(str[i], operators.top())>0) {//若操作符比栈顶操作符优先级高
//				operators.push(str[i]);
//			}
//			else {
//				while (true) {
//					numbersAndOperators.push(operators.top());
//					operators.pop();
//					if (operators.empty() || operators.top() == '(') {
//						operators.push(str[i]);
//						break;
//					}
//					else if (compareOperatorPriority(str[i], operators.top())>0) {
//						operators.push(str[i]);
//						break;
//					}
//				}
//			}
//		}
//		else if (str[i] == '(') {
//			operators.push(str[i]);
//		}
//		else if (str[i] == ')') {
//			while (operators.top() != '(') {
//				numbersAndOperators.push(operators.top());
//				operators.pop();
//			}
//			operators.pop();//丢掉'('
//		}
//		else {
//			cout << "Bad Expression!" << endl;
//			exit(-1);
//		}
//	}
//
//	while (!operators.empty()) {
//		numbersAndOperators.push(operators.top());
//		operators.pop();
//	}
//
//	string suffix = string(numbersAndOperators.size(), 'a');
//	int i = 0;
//	while (!numbersAndOperators.empty()) {
//		suffix[i] = numbersAndOperators.top();
//		numbersAndOperators.pop();
//		i++;
//	}
//	reverse(begin(suffix), end(suffix));
//	return suffix;
//}
///*
//*根据后缀表达式计算
//*/
//int calculate(string str) {
//	stack<int> numbers;
//	for (int i = 0; i < str.length(); i++) {
//		if (isDigit(str[i])) {
//			numbers.push(str[i] - '0');
//		}
//		else if (isOperator(str[i])) {//遇到操作符，取出栈顶2个数字，并计算，计算结果压入栈
//
//			int a = numbers.top();
//			numbers.pop();
//			int b = numbers.top();
//			numbers.pop();
//			int tempResult;
//			if (str[i] == '+') {
//				tempResult = b + a;
//			}
//			else if (str[i] == '-') {
//				tempResult = b - a; //这里注意被减数和减数的顺序，不要弄反
//			}
//			else if (str[i] == '*') {
//				tempResult = b * a;
//			}
//			else if (str[i] == '/') {
//				tempResult = b / a;
//			}
//			numbers.push(tempResult);
//		}
//	}
//	return numbers.top();
//}
///*
//*判断是否为数字
//*/
//bool isDigit(char c) {
//	int a = c - '0';
//	if (a >= 0 && a <= 9) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
///*
//*判断是否为操作符
//*/
//bool isOperator(char c) {
//	if (c == '+' || c == '-' || c == '*' || c == '/') {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
