
#include <string>
using namespace std;


class sklad {//����� �� ����� �����������
protected:
	char *naimen;//������������ ������
	int kol;//��� ���-�� ������
	double cost;//���� �� ����
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
	int schitat();////��������� ������ �� �����
	void print();//����� ����������� � ������
	void del();//�������� ������
	void zapis();//���������� ����� � ��������
	int enter();//������ ����� �����
	void changeS();//�������� ������ ������
};

