

#include <string>
using namespace std;

class dostavka {//�� ����� �����������
protected:
	char *firma;//�������� �����
	int Kcar;//����� ��������� �����
	double proc;//% �� ��������
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
	void schitat();//������� ����������� �� �����
	void schitat(int);//���������� �����������
	int enter();//������ ������
	void zapis();//������������ ���� � ����
	void del();//�������
};

