# Calculator_easy
【MFC，C++】——简单计算器

关键代码在 MFCApplication2Dlg.cpp 文件中


程序思路
按钮部分主要是往编辑框里增加内容，关键是自己创建的eval函数，这个函数运用栈来实现对编辑框里面内容直接运算


2.0(2021.5.6）
```
// MFCApplication2Dlg.cpp: 实现文件
/*版本区别：1.增加了三角函数的计算
		        2.完善了小数
*/
```

1.0（2021.5.5）
在 MFCApplication2Dlg.cpp 里面
总结：
1. 获取编辑框内容和设置编辑框内容
```
CString text;
GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
text += "1";
GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
```
2.信息框
```
MessageBox(TEXT("格式错误！！！"), TEXT("注意注意"), MB_YESNO);
```
3.栈算法
```
int eval(string s) {
	stack<int> nums;
	int num = 0;
	char sign = '+';
	s += '+';
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) num = num * 10 + (s[i] - '0');		//判断是否是数字
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {		//出现符号
			if (sign == '+') {
				nums.push(num);
			}
			else if (sign == '-') {
				nums.push(-num);
			}
			else if (sign == '*') {
				int n = nums.top();
				nums.pop();
				nums.push(n * num);
			}
			else if (sign == '/') {
				int n = nums.top();
				nums.pop();
				nums.push(n / num);
			}
			num = 0;
			sign = s[i];
		}
	}

	int res = 0;
	while (nums.size()) {
		res += nums.top();
		nums.pop();
	}
	return res;
}

```
