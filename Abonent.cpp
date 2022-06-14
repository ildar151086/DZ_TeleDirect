#include "Abonent.h"
#include <string>
#include <iostream>

using namespace std;

Abonent::Abonent() {
	abonent.surname = "";
	abonent.name = "";
	abonent.middleName = "";
	abonent.dateOFbirth = "";
	abonent.phoneNumber = 0;
}

Abonent::Abonent(AbonentField temp){
	abonent = temp;
}

void Abonent::print() {
	cout << endl;
	cout << " ������� " << abonent.surname << endl;
	cout << " ��� " << abonent.name << endl;
	cout << " �������� " << abonent.middleName << endl;
	cout << " ���� �������� " << abonent.dateOFbirth << endl;
	cout << " ������� " << abonent.phoneNumber << endl;
	cout << endl;
}

string Abonent::getSurname() {
	return abonent.surname;
}

string Abonent::getName() {
	return abonent.name;
}

string Abonent::getMiddleName() {
	return abonent.middleName;
}

string Abonent::getDateOFbirth() {
	return abonent.dateOFbirth;
}

int Abonent::getPhoneNumber() {
	return abonent.phoneNumber;
}

void Abonent::setSurname(string value) {
	abonent.surname = value;
}

void Abonent::setName(string value) {
	abonent.name = value;
}

void Abonent::setMiddleName(string value) {
	abonent.middleName = value;
}

void Abonent::setDateOFbirth(string value) {
	abonent.dateOFbirth = value;
}

void Abonent::setPhoneNumber(int value) {
	abonent.phoneNumber = value;
}

bool Abonent::operator==(Abonent& value) {
	if (abonent.dateOFbirth == value.getDateOFbirth() &&
		abonent.middleName	== value.getMiddleName() &&
		abonent.name		== value.getName() &&
		abonent.phoneNumber == value.getPhoneNumber() &&
		abonent.surname		== value.getSurname()) {
		// �������� ������ ����������
		return 1;
	}
	return 0;
}

void Abonent::pushAbonent() {
	string str;
	int number = 0;
	
	cout << endl;
	cout << "������� ������� ";
	cin >> str;
	abonent.surname = str;
	
	cout << "������� ��� ";
	cin >> str;
	abonent.name = str;

	cout << "������� �������� ";
	cin >> str;
	abonent.middleName = str;

	cout << "������� ���� �������� ";
	cin >> str;
	abonent.dateOFbirth = str;

	cout << "������� ����� �������� ";
	cin >> number;
	abonent.phoneNumber = number;
	cout << endl;
}


Abonent::Abonent(Abonent& copyValue) {
	this->abonent = copyValue.abonent;
}