
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>

#include "Header.h"

#pragma warning (disable:4996)
using namespace std;
#include <time.h>
#include <ctime>

void gotoxy(int xpos, int ypos);
int pozicionirovanie(int n);
int menuad(sklad &, dostavka &, password &);

void gotoxy(int xpos, int ypos) { //�������� ������ ���������� ������ � ����� � ������������ �,�
	COORD koord_simv; //���������, ������� �������� ���������� ���������� ������ � �������
	HANDLE diskriptor = GetStdHandle(STD_OUTPUT_HANDLE); //�������� ������ �������. ��������� ���������� ���������� ������������ ������
	koord_simv.X = xpos; koord_simv.Y = ypos; //�������� ��������� ���������� 
	SetConsoleCursorPosition(diskriptor, koord_simv); // ������������� ������� ������� � �������� �������� ������ �������
}

int pozicionirovanie(int n) { //������� ��������� ������ �� ������� � ������� ������� ����� � ����
	char c = ' ';
	int state = 0;
	gotoxy(40, 5); //������������� ������ �� ������ ������� ������ ����
	printf(">");
	while (c != 13) { //���� �� ������ Enter
		gotoxy(50, 20); //������������� ������ �� ����
		c = getch(); //���������, ����� ������� ������
		gotoxy(40, 5 + state);
		printf(" "); // ���� ������� ������ >

		if (c == 72) state--; //���� �� ������ ������� ����� �� ����-�
		if (c == 80) state++; //���� �� ������ ������� ���� �� ����-�

		if (state < 0) state = n; // ���� ���������� �� ����� � ����
		if (state > n) state = 0;

		gotoxy(40, 5 + state);
		printf(">");
		gotoxy(50, 20);
	}
	system("cls");
	return state;
}
sklad a;
dostavka b;
password ob;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gotoxy(0, 0);
	int ad = 0;
	ob.proverka();
	int trigger;
	trigger = a.schitat();
	if (trigger == 0) { a.enter();	a.zapis(); }
	b.schitat();
	while (true) {
		system("cls");
		gotoxy(50, 4); printf("����:");
		gotoxy(42, 5); printf("����.");
		gotoxy(42, 6); printf("�����.\n");
		switch (pozicionirovanie(1)) {
		case 0:ob.proverka(); if (ob.admin() == 2) menuad(a, b, ob); break;
		case 1:ob.~password();b.~dostavka();a.~sklad(); return 0;
		}
	}
	return 0;
}
int in = 0;
int menuad(sklad &a, dostavka &b, password &ob) {
	manager m, m1;

	while (true) {
		system("cls");
		gotoxy(42, 5); printf("�������� �������");
		gotoxy(42, 6); printf("������� �����");
		gotoxy(42, 7); printf("�������� �����");
		gotoxy(42, 8); printf("�������� �����������");
		gotoxy(42, 9); printf("������� ����������");
		gotoxy(42, 10); printf("�������� ����������");
		gotoxy(42, 11); printf("������� ����� � ������");
		gotoxy(42, 12); printf("�������� ������ ������");
		gotoxy(42, 13); printf("�����.\n");
		switch (pozicionirovanie(8)) {
		case 0: a.print(); system("pause"); break;
		case 1: a.del(); a.zapis();break;
		case 2: a.enter(); a.zapis(); break;
		case 3: b.schitat(1); system("pause"); break;
		case 4: b.del(); b.zapis(); break;
		case 5: b.enter(); b.zapis(); break;
		case 6: ob.smena(); break;
		case 7: a.changeS(); a.zapis(); break;
		case 8:m.~manager();m1.~manager(); return 0;
		}
	}
}

