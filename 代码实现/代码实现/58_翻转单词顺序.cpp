#include <bits/stdc++.h>
using namespace std;
//�Ӻ���ǰ����Ч�ʸߣ�������ansƵ���ƶ���ߵ�Ԫ�ء����ַ�����ʱ�临�Ӷȶ���O��n����ֻ�еڶ��ַ����Ŀռ临�Ӷ���O��1��
//����һ��˫ָ��Ӻ���������ҵ��������ʣ��ٽ��������뵽ans�У�����ans�洢���յĴ𰸣���Ҫ������ַ����ռ�O��n��
//class Solution {
//public:
//	string reverseWords(string s) {
//		int i = s.size() - 1;
//		string ans = "";
//		while (i >= 0) {
//			int c = 0;
//			while (i >= 0 && s[i] == ' ')
//				i--;
//			while (i >= 0 && s[i] != ' ') {
//				i--;
//				c++;
//			}
//			if(c)//��ֹǰ���ո���ans�ظ�ִ�У��������Ŀո�
//			ans+=s.substr(i+1,c)+" ";
//		}
//		return ans.substr(0, ans.size() - 1);//ɾ�����һ������Ŀո�
//	}
//};
//��������˫ָ�루�ռ临�Ӷ�ΪO��n����
//˼·��1.�ȷ�ת�����ַ�����2.ȥ�������ַ�����ǰ���ո�3.�ҵ�ÿ�����ʲ���ת��4.ɾ��β������Ĳ���
//class Solution {
//public:
//	string reverseWords(string s) {
//		// ��ת�����ַ���
//		reverse(s.begin(), s.end());
//
//		int n = s.size();
//		int idx = 0;//����ȷ��s�ַ����е��ʵ������������Ҫȷ����λ�ã���Ҫ�����������������ĺ��壩
//		for (int start = 0; start < n; ++start) {
//			if (s[start] != ' ') {
//				// ��һ���հ��ַ�Ȼ��idx�ƶ�����һ�����ʵĿ�ͷλ��
//				if (idx != 0) s[idx++] = ' ';//һ�����������Ժ���������ʺ�����һ���ո񣬲�������idx����ƶ�һλ
//
//				// ѭ�����������ʵ�ĩβ
//				int end = start;//end��start����ָ���������ö����ʷ�Χ��
//				while (end < n && s[end] != ' ') s[idx++] = s[end++];
//
//				// ��ת��������
//				reverse(s.begin() + idx - (end - start), s.begin() + idx);
//
//				// ����start��ȥ����һ������
//				start = end;
//			}
//		}
//		s.erase(s.begin() + idx, s.end());//���ɾ��s�ж���Ĳ��֣�������ǰ�󵼻����м�����0���µĶ���λ��
//		return s;
//	}
//};
//��������˫�˶��У�C++�о�����deque��ʵ��ջ�Ĺ��ܣ���Ϊstack�Ѿ��������ˣ����Ƚ��ַ����е�����һ��һ���ҳ�����Ȼ�󽫵���ѹ����е�ͷ������Ϊ˫�˶����൱��ջ����˺��ҵ��ĵ��ʾ�ѹ���˶��е�ͷ�����൱�ڰѵ����Ƶ���ǰ�ߡ��������һ���µ��ַ��������մӶ���ͷ��������һ��һ�����ʼ���
//class Solution {
//public:
//	string reverseWords(string s) {
//		int left = 0, right = s.size() - 1;
//		// ȥ���ַ�����ͷ�Ŀհ��ַ�
//		while (left <= right && s[left] == ' ') ++left;
//
//		// ȥ���ַ���ĩβ�Ŀհ��ַ�
//		while (left <= right && s[right] == ' ') --right;
//
//		deque<string> d;
//		string word;
//
//		while (left <= right) {
//			char c = s[left];
//			if (word.size() && c == ' ') {
//				// ������ push �����е�ͷ��
//				d.push_front(move(word));
//				word = "";
//			}
//			else if (c != ' ') {
//				word += c;
//			}
//			++left;
//		}
//		d.push_front(move(word));
//
//		string ans;
//		while (!d.empty()) {
//			ans += d.front();
//			d.pop_front();
//			if (!d.empty()) ans += ' ';
//		}
//		return ans;
//	}
//};

//����ʵ��
//class Solution {
//public:
//    string reverseWords(string s) {
//        int n = s.size();
//        string ans = "";
//        for(int i = n-1;i>=0;i--){
//            int c = 0;
//            while(i>=0&&s[i]!=' '){
//                i--;
//                c++;
//            }
//            if(c)
//            ans+=s.substr(i+1,c)+" ";
//        }
//        return ans.substr(0,ans.size()-1);
//    }
//};

//int main() {
//	string test = "  hello world!  ";
//	Solution s;
//	string res = s.reverseWords(test);
//	cout << res << endl;
//	system("pause");
//	return 0;
//}