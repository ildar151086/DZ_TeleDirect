/*
* Класс абонент в котором описываем такие поля как:
	Фамилия
	Имя
	Отчество
	Дата рождения
	Номер телефона
*/
#include <string>
using namespace std;

struct AbonentField {
	///Фамилия
	string surname;
	///Имя
	string name;
	///Отчество
	string middleName;
	///Дата рождения
	string dateOFbirth;
	///Номер телефона
	int phoneNumber;
};

class Abonent{
	
	///Заполненый абонент
	AbonentField abonent;

public:
	Abonent();
	Abonent(AbonentField);
	void print();
	string getSurname();
	string getName();
	string getMiddleName();
	string getDateOFbirth();
	int getPhoneNumber();

	void setSurname(string);
	void setName(string);
	void setMiddleName(string);
	void setDateOFbirth(string);
	void setPhoneNumber(int);
	void pushAbonent();
	Abonent(Abonent&);

	bool operator==(Abonent&);
};

