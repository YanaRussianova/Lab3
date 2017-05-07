

#include <string>
using namespace std;

class dostavka {//из файла считывается
protected:
	char *firma;//название фирмы
	int Kcar;//число доступных машин
	double proc;//% за доставку
	double x;
	double y;
	dostavka *head, *prev;
public:
	dostavka();
	dostavka(const dostavka&ob);
	~dostavka();
	friend ostream& operator << (ostream &, const dostavka&);
	void setfirma(char*);
	void setKcar(int &);
	void setcorrd(double &, double &, double &);
	char *getfirma();
	int getKcar();
	double getproc();
	double getx();
	double gety();
	void schitat();//считаем поставщиков из файла
	void schitat(int);//напичатать поставщиков
	int enter();//ввести нового
	void zapis();//перезаписать файл с ними
	void del();//удалить
};

