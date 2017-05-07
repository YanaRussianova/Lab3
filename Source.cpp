#include "Header.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include<cassert>
#include <iomanip> // для setw
#pragma warning (disable:4996)
FILE *f;
FILE *d;
FILE *p;
using namespace std;

char *stroka() {  ////ввод строки со **
	char *s = new char[20];
	char c;
	int i = 0, k = 0;
	i = 0;
	fflush(stdin);
	while ((c = getch()) != 13 && i<19) {
		if (c == 8 && i > 0) {
			printf("\b \b");
			i--;
		}
		else {
			cout << "*";
			s[i] = c;
			i++;
		}
	}
	s[i] = '\0';
	return s;
}

char *stroka1() {
	string buff;
	getline(cin, buff);
	if (buff.length() == 0) { getline(cin, buff); }
	char * a = new char[buff.length()];
	strcpy(a, buff.c_str());
	buff.clear();
	return a;
}

int chislo() {
	string s;
	int n = 0, k = 0;
	regex str("([0-9])+");
	try {
		getline(cin, s);
		if (s.length() == 0) { getline(cin, s); }
		if (s.empty()) cerr << "Ничего не ввели" << endl;  //---------------------------------------------------------
		if (!regex_match(s, str)) throw exception_1("введите целое число ");
		n = atoi(s.c_str());
		s.clear();
		return n;
	}
	catch (exception_1) {
		//cout << e << endl;
		s.clear();
		return -1;
	}
}




double dobl() {
	string s;
	int  k = 0;
	double n = 0;
	regex str("([0-9\.])+");
	try {
		getline(cin, s);
		if (s.length() == 0) { getline(cin, s); }
		if (!regex_match(s, str)) throw exception_1("неверно,пример 3.4");
		n = atoi(s.c_str());
		s.clear();
		return n;
	}
	catch (exception_1) {
		//cout << a << endl;
		s.clear();
		return 0;
	}
}
////////////////////////////////////////////////////////////////////
typedef List<sklad> L;
L l;
typedef List<dostavka> D;
D dos;

template<class T>
List<T>::List() {
	head = NULL;
	length = 0;
}
template<class T>
List<T>::~List() {
	while (head != NULL) {
		Node *tmp = head->prev;
		delete head;
		head = tmp;
	}
}
template<class T>
int List<T>::getLength() {
	return length;
}

template <class T>
void List<T>::add(const T& data)
{
	Node *n = new Node(data);		// создаем отдельный узел
									// Если список пуст, то
	//n->prev = NULL;
	if (head == NULL) {
		// связываем последний узел с новым;
		head = n;
		n->prev = NULL;

	}
	else {
		n->prev = head;
		head = n;
	}
	length++;
}

template <class T>
T& List<T>::at(int index) {
	Node *current = head;
	for (int i = 0; i < index; i++) {
		current = current->prev;
	}
	return current->data;
}


template<class T>
void List<T>::display() {
	for (int i = 0; i < getLength(); i++) {
		//cout <<"№ "<< i + 1 << endl;
		cout << at(i) << endl << endl;
	}
}
template<class T>
void List<T>::deleteN() {
	Node *cur = head, *pred;
	int len = l.getLength();
	if (len==0) { cout << "Больше нечего удалять "; system("pause"); }
	else {
		if (len > 1 ) {    //если эл-т не последний
			head = head->prev;
		}
		else if (len == 1) {      //если эл-т последний
			head = NULL;
		}		
		delete cur, pred;/////
		length--;
	}
}


template<class T>
void List<T>::change(const T& data, int a) {/////////////////////////////
	Node *n = new Node(data);
	Node *cur = head, *pred;
	int b = l.getLength();
	for (int i = 0; i < a; i++) {
		cur = cur->prev;
	}
	if (a == 0) {
		head = n;
		head->prev = NULL;
	}
	else if (a == b - 1) {
		pred = cur->prev;
		head = n;
		head->prev = pred;
	}
	else {
		pred = head;
		for (int i = 0; i < a - 1; i++) {
			pred = pred->prev;
		}
		pred->prev = n;
		n->prev = cur->prev;
	}
	delete cur, pred;
}


template<class T>
void List<T>::deleteD() {
	Node *cur = head, *pred;
	int len = l.getLength();
	if (len == 0) { cout << "Больше нечего удалять "; system("pause"); }
	else {
		if (len > 1) {    //если эл-т не последний
			head = head->prev;
		}
		else if (len == 1) {      //если эл-т последний
			head = NULL;
		}
		delete cur, pred;/////
		length--;
	}	
}

template<class T>
void List<T>::delal() {
	Node *cur = head;
	int a = l.getLength();
	for (int i = 0; i < a - 1; i++) {
		cur = head;
		head = head->prev;
		delete cur;
		length--;
	}
	head = NULL;
	length = 0;
}


//////////////////////////////////////////////////////////////////////////////////
sklad s;

sklad::sklad() {
	head = NULL;
	naimen = nullptr;
	kol = 0;
	cost = 0;
}
sklad::sklad(const sklad&ob) {
	naimen = new char[strlen(ob.naimen) + 1];
	strcpy(naimen, ob.naimen);
	kol = ob.kol;
	cost = ob.cost;
}
sklad::~sklad() {
	delete[] naimen;
	kol = 0;
	cost = 0;
	while (head != NULL) {
		sklad *tmp = head->prev;
		delete head;
		head = tmp;
		cout << "Work" << endl;
	}
}
void sklad::del() {
	cout << "Удаление товара  ";
	system("pause");
	l.deleteN();
}
void sklad::changeS() {//изменение товара
	int a = l.getLength(), num = 0, i;
	int  KOL = 0, k = 0;
	cout << "Какой товар изменить" << endl;
	char *na = stroka1();
	for (i = 0; i < a; i++) {
		if (strcmp(l.at(i).getnaimen(), na) == 0) {
			num = i;cout <<"num "<< num; k++; break;

		}
	}
	if (k == 0) cout << "Нет такого товара " << endl;
	else {
		k = 0;
		while (k == 0) {
			cout << "Введите новое количество   ";
			a = chislo();
			if (a >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			else system("cls");
		}
		KOL = a;
		s.setnaimen(l.at(num).getnaimen());
		s.setkol(KOL);
		k = 0;
		double d;
		while (k == 0) {
			cout << "Введите новую цену ";
			d = dobl();
			if (d != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			else { system("pause"); system("cls"); }
		}
		s.setcost(d);
		l.change(s, num);
	}
	system("pause");
}

ostream& operator << (ostream& os, const sklad &l) {           //перегрузка оператора вывода
	printf("%10s  |%8d|  %3.2f  \n", l.naimen, l.kol, l.cost);
	return os;
}
void sklad::setnaimen(char *a) {
	naimen = a;
}
void sklad::setkol(int &a) {
	kol = a;
}
void sklad::setcost(double &a) {
	cost = a;
}

int sklad::enter() {
	int  i = 0, k = 0, length;
	length = l.getLength();
	cout << "Введите товар  ";
	char string_for_file[20];
	string buf_string;
	stringstream string_st;
	cin >> buf_string;
	string_st << buf_string;
	while (string_st.str().size() >= 11) {
		cout << "Слишком большое название.Попробуйте заново" << endl;  //--------------------------------------------
		buf_string.clear();
		string_st.str(string());
		cin >> buf_string;
		string_st << buf_string;
	}
	if (string_st.good()) {
		string_st >> string_for_file;
		//char *na = stroka1();
		while (i < length && k == 0) {
			if (strcmp(l.at(i).getnaimen(), string_for_file) == 0)
				k++;
			else i++;
		}
		if (k != 0) {
			cout << "такой товар уже есть " << endl;
			system("pause");
		}
		else {
			s.setnaimen(string_for_file);
			k = 0;
			while (k == 0) {
				cout << "Введите количество товара ";
				length = chislo();
				if (length >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			}
			s.setkol(length);
			k = 0;
			double b;
			while (k == 0) {
				cout << "Введите новую цену ";
				b = dobl();
				if (b != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				else { system("pause"); system("cls"); }
			}
			s.setcost(b);
			l.add(s);
		}
	}
	else { cout << "Что-то пошло не так";system("pause"); }
	return 0;
}
int sklad::schitat() {
	l.delal();
	fopen_s(&f, "sklad.txt", "r");
	try {                              ////????????????????????????????????????????????????????????????
		if (f == NULL) throw exception_1("Создайте список склада");
		while (feof(f) == 0) {
			char *na = new char[50];
			char *k = new char[20];
			char *c = new char[20];
			fscanf(f, "%s\n%s\n%s\n", na, k, c);
			s.setnaimen(na);
			int a = atoi(k);
			s.setkol(a);
			double b = atof(c);
			s.setcost(b);
			l.add(s);
			s.~sklad();       /////****
		}
		fclose(f);
		return 1;
	}
	catch (exception_1) {
		//cout << a;
		system("pause");
		return 0;
	}                                   ////????????????????????????????????????????????????????????????

}
void sklad::print() {
	cout << "   Товар    | Кол-во | Цена за 1 ящик" << endl;
	cout << "_____________________________________" << endl;
	l.display();
}
void sklad::zapis() {
	ofstream f("sklad.txt", ios_base::out);
	int a = l.getLength();
	for (int i = 0; i < a; i++) {
		if (i == a - 1) {
			f << l.at(i).getnaimen() << endl;
			f << l.at(i).getkol() << endl;
			f << l.at(i).getcost() << endl;
		}
		else {
			f << l.at(i).getnaimen() << endl;
			f << l.at(i).getkol() << endl;
			f << l.at(i).getcost() << endl;
			f << "\n";
		}
	}
	f.close();
}

char *sklad::getnaimen() {
	return naimen;
}
int sklad::getkol() {
	return kol;
}
double sklad::getcost() {
	return cost;
}
//////////////////////////////////////////////////////////////////////
dostavka::dostavka() {
	head = NULL;
	firma = nullptr;
	Kcar = 0;
	proc = 0.0;
	x = 0.0;
	y = 0.0;
}
dostavka::dostavka(const dostavka&ob) {
	firma = new char[strlen(ob.firma) + 1];
	strcpy(firma, ob.firma);
	Kcar = ob.Kcar;
	proc = ob.proc;
	x = ob.x;
	y = ob.y;
}
dostavka::~dostavka() {
	delete[] firma;
	Kcar = 0;
	proc = 0;
	x = 0;
	y = 0;
	while (head != NULL) {
		dostavka *tmp = head->prev;
		delete head;
		head = tmp;
	}
}
ostream& operator << (ostream& os, const dostavka &l) {
	printf("%15s |%13d | %3.2f | %3.1f  %3.1f\n", l.firma, l.Kcar, l.proc, l.x, l.y);
	return os;
}
char *dostavka::getfirma() {
	return firma;
}
int dostavka::getKcar() {
	return Kcar;
}
double dostavka::getproc() {
	return proc;
}
double dostavka::getx() {
	return x;
}
double dostavka::gety() {
	return y;
}

void dostavka::setfirma(char *a) {
	firma = a;
}
void dostavka::setKcar(int &a) {
	Kcar = a;
}
void dostavka::setcorrd(double &a, double &b, double &c) {
	proc = a;
	x = b;
	y = c;
}
dostavka dost;
void dostavka::schitat() {
	int state;
	ifstream file("dost.txt", ios_base::in);
	state = file.rdstate();
	if (state&ios::eofbit) {
		cout << "В файле нет данных" << endl;
		system("pause");
	}
	else if (state&ios::failbit) { cout << "ошибка открытия файла поставщиков" << endl;	system("pause");}	//------------------------------
	else {
		while (file.eof() == 0) {
			char *fi = new char[50];
			char *k = new char[10];
			char *c = new char[10];
			char *x = new char[10];
			char *y = new char[10];
			char *nu = new char[1];
			file.getline(fi, 50);
			file.getline(k, 10);
			file.getline(c, 10);
			file.getline(x, 10);
			file.getline(y, 10);
			file.getline(nu, 1);
			dost.setfirma(fi);
			int m = atoi(k);
			dost.setKcar(m);
			double p = atof(c);
			double x1 = atof(x);
			double y1 = atof(y);
			dost.setcorrd(p, x1, y1);
			dos.add(dost);
			dost.~dostavka();       /////****
		}
		file.close();
	}
}
void dostavka::schitat(int a) {
	cout << "  Организация   | Кол-во машин |  %   | Координаты" << endl;
	cout << "__________________________________________________" << endl;
	dos.display();
}
int dostavka::enter() {
	cout << "Введите поставщика  ";
	char *na = stroka1();
	dost.setfirma(na);
	int k = 0, a = 0;
	while (k == 0) {
		cout << "Введите количество машин ";
		a = chislo();
		if (a >= 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	}
	dost.setKcar(a);
	k = 0;
	double p, x1, y1;
	while (k == 0) {
		cout << "Введите процент ";
		p = dobl();
		if (p != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		else { system("pause"); system("cls"); }
	}
	k = 0;
	while (k == 0) {
		cout << "Введите координаты х и у";
		x1 = dobl();
		y1 = dobl();
		if (x1 != 0 && y1 != 0) k++;   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		else { system("pause"); system("cls"); }
	}
	dost.setcorrd(p, x1, y1);
	dos.add(dost);
	return 0;
}
void dostavka::zapis() {
	//ofstream f("dost.txt", ios_base::trunc);
	std::fstream f;
	f.exceptions(ios::badbit | ios::failbit);
	try                                         ///////////////////????????????????????????????????
	{
		f.open("dost.txt", ios::out);  //------------------------------------------------
		int a = dos.getLength();
		for (int i = 0; i < a; i++) {
			if (i == a - 1) {
				f << dos.at(i).getfirma() << endl;
				f << dos.at(i).getKcar() << endl;
				f << dos.at(i).getproc() << endl;
				f << dos.at(i).getx() << endl;
				f << dos.at(i).gety() << endl;
			}
			else {
				f << dos.at(i).getfirma() << endl;
				f << dos.at(i).getKcar() << endl;
				f << dos.at(i).getproc() << endl;
				f << dos.at(i).getx() << endl;
				f << dos.at(i).gety() << endl;
				f << "\n";
			}
		}
		f.close();
	}
	catch (ios::failure &e)
	{
		cout << "File opening error: " << e.what() << endl;
		system("pause");
	}
}

void dostavka::del() {
	cout << "Удаление...  ";
	system("pause");
	dos.deleteD();
}
/////////////////////////////////////////////////////////////////////

manager::manager(const manager&ob) :sklad(ob), dostavka(ob) {
	kod = new char[strlen(ob.kod) + 1];
	strcpy(kod, ob.kod);
	otpravka = new char[strlen(ob.otpravka) + 1];
	strcpy(otpravka, ob.otpravka);
}
manager::~manager() {
	delete[] kod;
	delete[] otpravka;
	while (head != NULL) {
		manager *tmp = head->prev;
		delete head;
		head = tmp;
	}
	cout << "mm";
}

///////////////////////////////////////////////////////////////


password::~password() {
	delete[]log;
	delete[] par;
	while (head != NULL) {
		password *tmp = head->prev;
		delete head;
		head = tmp;
	}
}

void password::proverka() {
	head = NULL;
	fopen_s(&p, "admin.txt", "r");
	while (feof(p) == 0) {
		password *s = new password;
		char *lo = new char[30];
		char *pa = new char[30];
		fscanf(p, "%s\n%s\n", lo, pa);
		decript(lo);
		s->log = new char[strlen(lo) + 1];
		s->log = lo;
		decript(pa);
		s->par = new char[strlen(pa) + 1];
		s->par = pa;
		s->prev = NULL;
		if (head == NULL) {
			head = s;
			head->prev = NULL;
		}
	}
	fclose(p);
}
char  *password::decript(char *a) {    ////расшифровка
	int i, j = 0, dl;
	char zam;
	int k = strlen(a);
	if (k % 2 == 1) dl = k / 2 + 1;
	else dl = k / 2;
	for (i = 0; i < k; ) {
		j = i;
		zam = a[j];
		a[j] = a[j + 2];
		a[j + 2] = zam;
		zam = a[j + 1];
		a[j + 1] = a[j + 2];
		a[j + 2] = zam;
		i = i + 3;
	}
	for (i = 0; i < k / 2; i++)
	{
		zam = a[i];
		a[i] = a[i + dl];
		a[i + dl] = zam;
	}
	try {
		if (a[strlen(a) - 1] == 'A') throw 1;
		else if (a[strlen(a) - 1] == 'F') a[strlen(a) - 1] = '\0';
	}
	catch (int i) {
		a[strlen(a) - 2] = '\0';
	}
	return a;
}

char *password::encript(char *a) {       ////зашифровка
	int k = strlen(a), i, j, dl;
	char zam;
	if (k % 3 == 1)  strcat(a, "FA");
	else if (k % 3 == 2)  strcat(a, "F");
	k = strlen(a);
	if (k % 2 == 1) dl = k / 2 + 1;
	else dl = k / 2;
	for (i = 0; i < k / 2; i++)
	{
		zam = a[i];
		a[i] = a[i + dl];
		a[i + dl] = zam;
	}
	for (i = 0; i < k; ) {
		j = i;
		zam = a[j + 1];
		a[j + 1] = a[j];
		a[j] = zam;
		zam = a[j + 1];
		a[j + 1] = a[j + 2];
		a[j + 2] = zam;
		i = i + 3;
	}
	return a;
}

void password::smena() {
	cout << "Введите новый логин" << endl;
	char * temp1 = stroka();
	encript(temp1);
	cout << endl;
	cout << "Введите новый пароль" << endl;
	char * temp2 = stroka();
	cout << endl;
	encript(temp2);
	ofstream file("admin.txt", ios_base::out);
	file << temp1 << endl;
	file << temp2;
	file.close();
}

int password::admin() {
	int a = 1;
	char b;
	string buff;
	do {
		password *p = head;
		cout << "Введите свой логин" << endl;
		char * temp1 = stroka();
		cout << endl;
		cout << "Введите свой пароль" << endl;
		char * temp2 = stroka();
		cout << endl;
		while (p != NULL) {
			if (strcmp(temp1, p->log) == 0 && strcmp(temp2, p->par) == 0) {
				a = 2;
			}
			p = p->prev;
			buff.clear();
		}
		if (a == 1) {
			cout << "Неверно, повторите еще.Если хотите выйти нажмите 0" << endl;
			//cout << "" << endl;
			cin >> b;
			if (b == '0') a = 3;
			else a = 1;
			system("cls");
		}
	} while (a == 1);
	return a;
}

