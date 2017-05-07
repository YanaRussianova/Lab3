#include <string>
#include <exception>
using namespace std;

class exception_1 : public exception
{
	string str;
public:
	exception_1() {};
	exception_1(string s) { str = s; cout << str << endl; str.clear(); };
	~exception_1() {};

};
