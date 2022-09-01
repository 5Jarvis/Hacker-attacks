#include<graphics.h>
#include<Windows.h>
#include<MMSystem.h>
#include<stdio.h>
#pragma comment(lib,"winmm.lib")
#include<iostream>
#include<string>
#include<conio.h>//getch()的使用
#include"hacker.h"



using namespace std;


#define WIDTH  40
#define HEIGH  20


//密码函数
void inputPwd(char pwd[],int size) {
	char c;
	int i = 0;

	//请输入密码:000123
	//保存到字符数组pwd:'0' '0' '0' '1' '2' '3' '\0'
	while (1) {
		//如果读到回车符,返回'\r'
		 c=_getch();//不会回显
		if (c == '\r') {
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		cout << '*';
	}
	cout << endl;
}

void login(void) {
	while (1) {

		//string pwd;
		string name;
		char pwd[32];//定义密码

		system("cls");

		cout << "请输入账号:";
		cin >> name;
		cout << "请输入密码:";
		//cin >> pwd;
		//实现密码的输入
		inputPwd(pwd,sizeof(pwd));
		

		if (name == "54hk" && !strcmp(pwd,"000123")) {
			break;
		}
		else {
			cout << "用户名或密码错误,请重新登录" << endl;
			system("pause");
		}
	}
}

//居中标题
void printfInMiddle(string msg) {
	int leftspace = (WIDTH - msg.length()) / 2;
	
		for (int i = 0; i < leftspace; i++) {
			cout << " ";
		}
		cout << msg << endl;
	
}

void menuShow(void) {
	/*
	system("cls");
	std::cout << "1.网站404攻击" << std::endl;
	std::cout << "2.网站篡改攻击" << std::endl;
	std::cout << "3.网站攻击记录" << std::endl;
	std::cout << "4.网站攻击修复" << std::endl;
	std::cout << "5.退出" << std::endl;
	*/
	system("cls");
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击记录",
		"4.网站攻击修复",
		"5.退出"
	};

	//计算菜单项最大长度
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);//字符串的数量
	for (int i = 0; i < menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	//打印换行
	int menuLine = (HEIGH - (menuCount + 2)) / 2;
	for (int i = 0; i < menuLine; i++) {
		cout << endl;
	}

	//打印标题
	printfInMiddle("--黑客攻击--");


	//打印空格数
	int leftspace = (WIDTH - max) / 2;
	for (int i = 0; i < menuCount; i++) {
		for (int i = 0; i < leftspace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}

}

int menuChoise(void) {

	//输入功能标号
	int n = 0;//用户输入的标号
	while (1) {
		cout << "编号:";
		cin >> n;
		if (cin.fail()){
			cin.clear();
			cin.sync();
			cout << "无效输入,请重新输入." << endl;
			system("pause");
		}
		else {
			break;
		}
	}

	return n;
}

void attack404(void) {

	char id[64];//网站id
	char response[4096];//攻击后,从服务器返回的结果

	system("cls");
	//cout << "404攻击......" << endl;
	//int hk_404(char *id, char *response);
	printfInMiddle("--网站404攻击--");

	cout << "请输入准备攻击的网站ID:";
	scanf_s("%s", id, sizeof(id));

	cout << "正在执行404攻击....." << endl;

	//发起攻击
	hk_404(id, response);
	//编码转换
	string retStr = UTF8ToGBK(response);

	cout << retStr << endl;

	system("pause");
}

void siteEdit(void) {
	
	//cout << "网站篡改攻击...." << endl;
	char id[64];
	char response[MAXSIZE];
	string  attackText;

	system("cls");

	printfInMiddle("--网站篡改攻击--");

	cout << "请输入准备攻击的网站ID:";
	scanf_s("%s", id, sizeof(id));

	cout << "请输入要写入的内容:";
	cin >> attackText;

	cout << "正在执行网络篡改攻击.......\n";
	GBKToUTF8(attackText);
	hk_tamper(id,(char *)attackText.c_str(),response);


	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(void) {
	
	//cout << "网站攻击记录...." << endl;
	char id[64];
	char response[MAXSIZE];

	system("cls");

	printfInMiddle("--网站攻击记录--");
	cout << "请输入查看攻击的网站ID:";
	scanf_s("%s", id, sizeof(id));

	cout << "正在查看此网站攻击记录....." << endl;

	//发起攻击
	hk_record(id, response);
	//编码转换
	string retStr = UTF8ToGBK(response);

	cout << retStr << endl;
	system("pause");
}

void attackRepair(void) {

	system("cls");
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printfInMiddle("---网站攻击修复---");
	cout << "请输入准备查询的网站ID：";
	scanf_s("%s", id, sizeof(id));

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");

}

int menuGone(int n) {

	switch (n) {
	case 1:attack404(); break;
	case 2:siteEdit(); break;
	case 3:attackRecord(); break;
	case 4:attackRepair(); break;
	case 5:return 0;
	default:
		cout << "无效输入,请重新输入" << endl;
		system("pause");
		break;
	}
}

//初始化函数
void init(void) {
	//设置终端窗口的大小
	//mode con cols=40 lines=5
	char cmd[128];

	sprintf_s(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGH);
	system(cmd);

}

int main(void) {

	init();//初始化终端大小

	login();//实现登录

	system("cls");
	cout << "正在加载资源..........." << endl;
	Sleep(1000);

	mciSendString(_T("play 飞雪玉花.mp3 repeat"), 0, 0, 0);

	while (1) {
		menuShow();//菜单显示

		cout << "请输入要使用的菜单编号:" << endl;
		int n = menuChoise();//实现菜单选择

		menuGone(n);//菜单功能
	}
	
	system("pause");
		closegraph();
	return 0;
	
}