/*
* ����� ������� � ������� ��������� ����� ���� ���:
	�������
	���
	��������
	���� ��������
	����� ��������
*/
#include <string>
using namespace std;

struct AbonentField {
	///�������
	string surname;
	///���
	string name;
	///��������
	string middleName;
	///���� ��������
	string dateOFbirth;
	///����� ��������
	int phoneNumber;
};

class Abonent{
	
	///���������� �������
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

