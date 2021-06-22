
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"


int sign = 0;		//用来避免结果出现后再按数字会继续向后加

//利用栈来实现字符串表达式的计算
//（将+和-移到数值里面，最终就只需要*和/）
double eval(string s) {
	stack<double> nums;
	double num = 0;
	string tmp = "";
	char sign = '+';
	s += '+';
	//处理乘法和除法
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]) || s[i] == '.' )  tmp += s[i];		//判断是否是数字或者小数
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {		//出现符号
			//将string转为double类型（这里用了istringstream流）
			istringstream iss(tmp);
			iss >> num;

			if (sign == '+') {
				nums.push(num);
			}
			else if (sign == '-') {
				nums.push(-num);
			}
			else if (sign == '*') {
				double n = nums.top();
				nums.pop();
				nums.push(n * num);
			}
			else if (sign == '/') {
				int n = nums.top();
				nums.pop();
				nums.push((double)n / (double)num);
			}
			tmp = "";
			num = 0;
			sign = s[i];
		}
	}
	//计算出全部
	double res = 0;
	while (nums.size()) {
		res += nums.top();
		nums.pop();
	}
	return res;
}


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication2Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication2Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication2Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication2Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCApplication2Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication2Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication2Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication2Dlg::OnBnClickedButton17)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}

	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "1";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "2";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "3";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "4";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "5";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}



void CMFCApplication2Dlg::OnBnClickedButton8()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "6";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}

void CMFCApplication2Dlg::OnBnClickedButton9()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "7";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}




void CMFCApplication2Dlg::OnBnClickedButton10()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "8";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton12()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "9";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}




void CMFCApplication2Dlg::OnBnClickedButton13()
{
	if (sign == 1) {			//说明现在输出的是结果，再按得清空为0
		CString text3;
		text3 = "";
		GetDlgItem(IDC_EDIT1)->SetWindowText(text3);	//设置编辑框内容
		sign = 0;
	}
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "0";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	sign = 0;
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "+";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}




void CMFCApplication2Dlg::OnBnClickedButton7()
{
	sign = 0;
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "-";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton11()
{
	sign = 0;
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "*";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton15()
{
	sign = 0;
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	text += "/";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton16()		//qingkong
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	text = "";
	GetDlgItem(IDC_EDIT1)->SetWindowText(text);	//设置编辑框内容
}


void CMFCApplication2Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	

	CString text;
	GetDlgItemText(IDC_EDIT1, text);			//获取编辑框内容
	//转化为特定格式
	for (int i = 0; i < text.GetLength(); i++) {
		//分析异常情况
		if (text[i] == '/' && text[i + 1] == '0') {			//分母为0的情况
			MessageBox(TEXT("除数不能为零！！！"), TEXT("注意注意"), MB_YESNO);
			return;
		}
		//符号相邻
		if (i < text.GetLength() - 1 && (text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/') && (text[i + 1] == '+' || text[i + 1] == '-' || text[i + 1] == '*' || text[i + 1] == '/')) {
			MessageBox(TEXT("格式错误！！！"), TEXT("注意注意"), MB_YESNO);
			return;
		}
	}
	//CString转为string https://blog.csdn.net/monk1992/article/details/82849822
	string res = CT2A(text.GetBuffer());		//CString转为string
	double num = eval(res);
	

	//判断单选框是否被选中
	CButton* pB;
	pB = (CButton*)GetDlgItem(IDC_RADIO1);		//sin
	if (pB->GetCheck() == BST_CHECKED ) {		
		num = sin(num);
	}
	pB = (CButton*)GetDlgItem(IDC_RADIO3);
	if (pB->GetCheck() == BST_CHECKED) {		//cos--3
		num = cos(num);
	}
	pB = (CButton*)GetDlgItem(IDC_RADIO2);
	if (pB->GetCheck() == BST_CHECKED) {		//tan--2
		num = tan(num);
	}
	pB = (CButton*)GetDlgItem(IDC_RADIO4);
	if (pB->GetCheck() == BST_CHECKED) {		//log10--4
		num = log10(num);
	}
	
	CString text2;
	if (num == (int)num)	//如果是整数 
	{
		text2.Format(_T("%d"),(int)num);			//将int类型转为CString
	}
	else {
		text2.Format(_T("%f"), num);			//将double类型转为CString
	}
	
	GetDlgItem(IDC_EDIT1)->SetWindowText(text2);	//设置编辑框内容
	sign = 1;						//结果出现后再按数字就清空为0
}


void CMFCApplication2Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CMFCApplication2Dlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	//取消全部单选框的选中状态
	CButton* pB;
	pB = (CButton*)GetDlgItem(IDC_RADIO1);		//sin
	pB->SetCheck(FALSE);
	pB = (CButton*)GetDlgItem(IDC_RADIO2);		//sin
	pB->SetCheck(FALSE);
	pB = (CButton*)GetDlgItem(IDC_RADIO3);		//sin
	pB->SetCheck(FALSE);
	pB = (CButton*)GetDlgItem(IDC_RADIO4);		//sin
	pB->SetCheck(FALSE);
}
