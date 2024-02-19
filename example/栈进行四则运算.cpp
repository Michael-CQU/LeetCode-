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
//*�Ƚ����������������ȼ���op1��op2�߷���1��һ������0���ͷ���-1
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
//*�õ���׺���ʽ
//*/
//string getSuffixExpression(string str) {
//	stack<char> numbersAndOperators;
//	stack<char> operators;
//	//��ʼ�����ַ���
//	for (int i = 0; i<str.length(); i++) {
//		if (isDigit(str[i])) {
//			numbersAndOperators.push(str[i]);//��������֣���ֱ�ӽ���ջnumbersAndOperators
//		}
//		else if (isOperator(str[i])) {//����ǲ�����
//			if (operators.empty() || operators.top() == '(') {//��ջ�ջ�ջ��Ϊ(
//				operators.push(str[i]);
//			}
//			else if (compareOperatorPriority(str[i], operators.top())>0) {//����������ջ�����������ȼ���
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
//			operators.pop();//����'('
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
//*���ݺ�׺���ʽ����
//*/
//int calculate(string str) {
//	stack<int> numbers;
//	for (int i = 0; i < str.length(); i++) {
//		if (isDigit(str[i])) {
//			numbers.push(str[i] - '0');
//		}
//		else if (isOperator(str[i])) {//������������ȡ��ջ��2�����֣������㣬������ѹ��ջ
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
//				tempResult = b - a; //����ע�ⱻ�����ͼ�����˳�򣬲�ҪŪ��
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
//*�ж��Ƿ�Ϊ����
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
//*�ж��Ƿ�Ϊ������
//*/
//bool isOperator(char c) {
//	if (c == '+' || c == '-' || c == '*' || c == '/') {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
