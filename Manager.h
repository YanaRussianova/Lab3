
#include <string>
#include "Provider.h"
#include "Store.h"
using namespace std;

class manager : virtual public sklad, virtual public dostavka
{
private:
	char* kod;//код товара
	char* otpravka;//дата отгрузки
	manager *head,  *prev;
public:
	manager() :sklad(), dostavka() {
		head = NULL;
		kod = nullptr;
		otpravka = nullptr;
	}
	manager(const manager&ob);
	~manager();
};
