#include<graphics.h>
#include<Windows.h>
#include<MMSystem.h>
#include<stdio.h>
#pragma comment(lib,"winmm.lib")
#include<iostream>
#include<string>
#include<conio.h>//getch()��ʹ��
#include"hacker.h"



using namespace std;


#define WIDTH  40
#define HEIGH  20


//���뺯��
void inputPwd(char pwd[],int size) {
	char c;
	int i = 0;

	//����������:000123
	//���浽�ַ�����pwd:'0' '0' '0' '1' '2' '3' '\0'
	while (1) {
		//��������س���,����'\r'
		 c=_getch();//�������
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
		char pwd[32];//��������

		system("cls");

		cout << "�������˺�:";
		cin >> name;
		cout << "����������:";
		//cin >> pwd;
		//ʵ�����������
		inputPwd(pwd,sizeof(pwd));
		

		if (name == "54hk" && !strcmp(pwd,"000123")) {
			break;
		}
		else {
			cout << "�û������������,�����µ�¼" << endl;
			system("pause");
		}
	}
}

//���б���
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
	std::cout << "1.��վ404����" << std::endl;
	std::cout << "2.��վ�۸Ĺ���" << std::endl;
	std::cout << "3.��վ������¼" << std::endl;
	std::cout << "4.��վ�����޸�" << std::endl;
	std::cout << "5.�˳�" << std::endl;
	*/
	system("cls");
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ������¼",
		"4.��վ�����޸�",
		"5.�˳�"
	};

	//����˵�����󳤶�
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);//�ַ���������
	for (int i = 0; i < menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	//��ӡ����
	int menuLine = (HEIGH - (menuCount + 2)) / 2;
	for (int i = 0; i < menuLine; i++) {
		cout << endl;
	}

	//��ӡ����
	printfInMiddle("--�ڿ͹���--");


	//��ӡ�ո���
	int leftspace = (WIDTH - max) / 2;
	for (int i = 0; i < menuCount; i++) {
		for (int i = 0; i < leftspace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}

}

int menuChoise(void) {

	//���빦�ܱ��
	int n = 0;//�û�����ı��
	while (1) {
		cout << "���:";
		cin >> n;
		if (cin.fail()){
			cin.clear();
			cin.sync();
			cout << "��Ч����,����������." << endl;
			system("pause");
		}
		else {
			break;
		}
	}

	return n;
}

void attack404(void) {

	char id[64];//��վid
	char response[4096];//������,�ӷ��������صĽ��

	system("cls");
	//cout << "404����......" << endl;
	//int hk_404(char *id, char *response);
	printfInMiddle("--��վ404����--");

	cout << "������׼����������վID:";
	scanf_s("%s", id, sizeof(id));

	cout << "����ִ��404����....." << endl;

	//���𹥻�
	hk_404(id, response);
	//����ת��
	string retStr = UTF8ToGBK(response);

	cout << retStr << endl;

	system("pause");
}

void siteEdit(void) {
	
	//cout << "��վ�۸Ĺ���...." << endl;
	char id[64];
	char response[MAXSIZE];
	string  attackText;

	system("cls");

	printfInMiddle("--��վ�۸Ĺ���--");

	cout << "������׼����������վID:";
	scanf_s("%s", id, sizeof(id));

	cout << "������Ҫд�������:";
	cin >> attackText;

	cout << "����ִ������۸Ĺ���.......\n";
	GBKToUTF8(attackText);
	hk_tamper(id,(char *)attackText.c_str(),response);


	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(void) {
	
	//cout << "��վ������¼...." << endl;
	char id[64];
	char response[MAXSIZE];

	system("cls");

	printfInMiddle("--��վ������¼--");
	cout << "������鿴��������վID:";
	scanf_s("%s", id, sizeof(id));

	cout << "���ڲ鿴����վ������¼....." << endl;

	//���𹥻�
	hk_record(id, response);
	//����ת��
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
	printfInMiddle("---��վ�����޸�---");
	cout << "������׼����ѯ����վID��";
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
		cout << "��Ч����,����������" << endl;
		system("pause");
		break;
	}
}

//��ʼ������
void init(void) {
	//�����ն˴��ڵĴ�С
	//mode con cols=40 lines=5
	char cmd[128];

	sprintf_s(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGH);
	system(cmd);

}

int main(void) {

	init();//��ʼ���ն˴�С

	login();//ʵ�ֵ�¼

	system("cls");
	cout << "���ڼ�����Դ..........." << endl;
	Sleep(1000);

	mciSendString(_T("play ��ѩ��.mp3 repeat"), 0, 0, 0);

	while (1) {
		menuShow();//�˵���ʾ

		cout << "������Ҫʹ�õĲ˵����:" << endl;
		int n = menuChoise();//ʵ�ֲ˵�ѡ��

		menuGone(n);//�˵�����
	}
	
	system("pause");
		closegraph();
	return 0;
	
}