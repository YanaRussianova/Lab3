
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // ��� setw
#include <regex> 
#include <cstdlib>
#include <fstream> 
#include <time.h>
#include "Password.h"
#include "Manager.h"
#include "exept.h"
#include <sstream>
#pragma warning (disable:4996)
using namespace std;

template  <typename T>
class List {
	class Node {
		Node *prev;
		T data;
		friend class List <T>;
	public:
		Node() :  prev(nullptr) {}
		~Node() {}
		Node(const T& d) :data(d), prev(NULL) {}
		T* getData() {
			return &data;
		}
	};
	Node *head;
	int length;
	List(const List&) { }
public:
	List();
	~List();
	int getLength();//������ ������
	void add(const T&);//�������� ������
	T& at(int);//�������� ������ �������
	void change(const T&, int);//�������� ������
	void deleteN();//������� �����
	void deleteD();//������� ����������
	void delal();//������� ���� �����
	void display();//����������
};


