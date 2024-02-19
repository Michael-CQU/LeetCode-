//vector<vector<int>>num1;
//vector<int> num2;
//vector<int> num3;
//vector<int> num4;
//{
//	num2.push_back(1);
//	num2.push_back(1);
//	num2.push_back(1);
//	num2.push_back(1);
//}
//num1.push_back(num2);
//{
//	num3.push_back(2);
//	num3.push_back(2);
//	num3.push_back(2);
//	num3.push_back(2);
//}
//num1.push_back(num3);
//{
//	num4.push_back(3);
//	num4.push_back(3);
//	num4.push_back(3);
//	num4.push_back(3);
//}
//num1.push_back(num4);
//
//for (vector<vector<int>>::iterator row = num1.begin(); row != num1.end(); row++) {
//	for (vector<int>::iterator it = (*row).begin(); it != (*row).end(); it++) {
//		//for (vector<int>::iterator it = num2.begin(); it != num2.end(); it++) {
//		cout << *it << " ";
//		// (*row_it).erase(it); （删除）
//	}
//	cout << endl;
//}

////访问一维数组num2的值：
//for (int i = 0; i < num2.size(); i++)
//{
//	cout << num2[i] << endl;
//}
////访问二维数组num1的值：
//for (int i = 0; i < num1.size(); i++) {
//	for (int j = 0; j < num2.size(); j++)
//	{
//		cout << num1[i][j];
//		//cout << num2[j];
//	}
//	cout << endl;
//}


//vector<vector<int>> arr1;
//vector<int> arr2;
//arr2.assign(10, 1);
//for (int i = 0; i < 5; i++) {
//	arr1.push_back(arr2);
//}
//for (vector<vector<int>>::iterator row = arr1.begin(); row != arr1.end(); row++) {
//	for (vector<int>::iterator it = (*row).begin(); it != (*row).end(); it++){
//	//for (vector<int>::iterator it = arr2.begin(); it != arr2.end(); it++) {
//		cout << *it << " ";
//		// (*row_it).erase(it); （删除）
//	}
//	cout << endl;
//}