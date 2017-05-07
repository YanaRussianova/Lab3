
#include <string>
using namespace std;


class sklad {//будет из файла считываться
protected:
	char *naimen;//наименование товара
	int kol;//его кол-во ящиков
	double cost;//цена за ящик
	sklad *head,*prev;
public:
	sklad();
	sklad(const sklad&ob);
	~sklad();
	friend ostream& operator << (ostream &, const sklad&);
	void setnaimen(char*);
	void setkol(int &);
	void setcost(double &);
	char *getnaimen();
	int getkol();
	double getcost();
	int schitat();////считываем список из файла
	void print();//вывод хранящегося в списке
	void del();//удаление товара
	void zapis();//перезапись файла с товарами
	int enter();//ввести новый товар
	void changeS();//изменить данные склада
};

