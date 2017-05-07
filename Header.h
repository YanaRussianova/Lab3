
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // для setw
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
	int getLength();//длинна списка
	void add(const T&);//добавить объект
	T& at(int);//получить данные объекта
	void change(const T&, int);//изменить объект
	void deleteN();//удалить склад
	void deleteD();//удалить поставщика
	void delal();//удалить весь склад
	void display();//отобразить
};


