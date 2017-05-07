
#include <string>
using namespace std;

class password {
private:
	char * log;
	char * par;
	password *head,  *prev;
public:
	password() {
		head = NULL;
		log = nullptr;
		par = nullptr;
	}
	password(const password&ob) {}
	~password();
	void proverka();//проверка на совпадение
	char *decript(char *);//шифровка
	char *encript(char *);//расшифровка
	void smena();//сменить пароль
	int admin();//считать из файла
};

