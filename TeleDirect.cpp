#include "TeleDirect.h"
#include <string>
#include <fstream>
#include <iostream>


TeleDirect::TeleDirect() {
	listAbonent = nullptr;
	sizeAbonent = 0;
}

bool TeleDirect::inEmpty() {
	if (sizeAbonent = !0) {
		return 1;
	}
	return 0;
}

void TeleDirect::pushAbonent(Abonent *value) {
	if (listAbonent == nullptr) {
		listAbonent = new Abonent[++sizeAbonent];
		*listAbonent = *value;
	}
	else {
		Abonent *temp = listAbonent;
		Abonent* newlistAbonent = new Abonent[++sizeAbonent];
		for (int i = 0; i < sizeAbonent - 1; i++) {
			*(newlistAbonent + i) = *(temp + i);
		};
		*(newlistAbonent + sizeAbonent - 1) = *value;
		delete[] temp;
		listAbonent = newlistAbonent;
	}
}

void TeleDirect::deleteAbonent(Abonent& findValue) {
	int newSizeAbonenet = sizeAbonent - 1;

	for (int i = 0; i < sizeAbonent; i++) {
		if (*(listAbonent + i) == findValue) {
			std::cout << " ����� �������� �������� " << endl;			

			// ������� ���
			Abonent* temp = listAbonent;
			Abonent* newlistAbonent = new Abonent[newSizeAbonenet];

			// �������� �� ������ ��� �������
			for (int j = 0; j < i; j++) {
				*(newlistAbonent + j) = *(temp + j);
			};
			// ���������� ���������� � ��������� ��������� �������� i 
			for (int j = i + 1; j < sizeAbonent; j++) {
				*(newlistAbonent + j - 1) = *(temp + j);
			};
			delete[] temp;
			listAbonent = newlistAbonent;
			sizeAbonent = newSizeAbonenet;

			std::cout << " ���������� �� �������� ���� ������� " << endl;
			std::cout << endl;
			return;
		}
	}
	// �� ����� �������� ��������
	std::cout << " ������ �������� ��� " << endl;
	std::cout << endl;
}

TeleDirect::~TeleDirect() {
	if (listAbonent != nullptr) {
		delete[] listAbonent;
	}
}

/// ����� ������������ ��� ��������� ���������� �������� � �����������
enum EDIT_ABONENT {
	EDIT_SURNAME = 1,
	EDIT_NAME,
	EDIT_MIDDLENAME,
	EDIT_PHONENUMBER,
	EDIT_DATEOFBIRTH
};

int menuEdit() {
	int useUser = 0;
	std::cout << " �������� ����������� ����� ����  " << endl;
	std::cout << " 1 - �������� ������� " << endl;
	std::cout << " 2 - �������� ��� " << endl;
	std::cout << " 3 - �������� �������� " << endl;
	std::cout << " 4 - �������� ����� �������� " << endl;
	std::cout << " 5 - �������� ���� �������� " << endl;
	std::cout << " 6 - ����� �� ���� " << endl;
	cin >> useUser;
	return useUser;
}

template <typename T>
T editFieldAbonent(T str) {
	T valueUserEdit;
	cout << "�������� �� ��� �������� ��������� ���� ";
	cin >> valueUserEdit;
	cout << " ���� ���� ������� �������� " << endl;
	return valueUserEdit;
}

void TeleDirect::editAbonent(Abonent& findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if (*(listAbonent + i) == findValue){
			std::cout << " ����� �������� �������� " << endl;

			bool timeEdit = true;
			string typeStr;
			int typeInt = 0;
			while (timeEdit) {
				switch (menuEdit()) {
				case EDIT_SURNAME:
					(listAbonent + i)->setSurname(editFieldAbonent(typeStr));
					break;
				case EDIT_NAME:
					(listAbonent + i)->setName(editFieldAbonent(typeStr));
					break;
				case EDIT_MIDDLENAME:
					(listAbonent + i)->setMiddleName(editFieldAbonent(typeStr));
					break;
				case EDIT_PHONENUMBER:
					(listAbonent + i)->setPhoneNumber(editFieldAbonent(typeInt));
					break;
				case EDIT_DATEOFBIRTH:
					(listAbonent + i)->setDateOFbirth(editFieldAbonent(typeStr));
					break;
				default:
					timeEdit = false;
					break;
				}
			}

			// �������� ���
			std::cout << " ���������� �� �������� ���� �������� " << endl;
			std::cout << endl;
			return;
		}
	}
	// �� ����� �������� ��������
	std::cout << " ������ �������� ��� " << endl;
	std::cout << endl;
}

Abonent *TeleDirect::findTelephon(int findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if ((listAbonent + i)->getPhoneNumber() == findValue) {
			cout << " ����� ������� ������� � ����� �������� " << endl;
			(listAbonent + i)->print();
			return (listAbonent + i);
		}
	}
	cout << " �� ����� �������� � ������ ������� " << endl;
	std::cout << endl;
	return nullptr;
}

Abonent* TeleDirect::findSurname(string findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if ((listAbonent + i)->getSurname() == findValue) {
			cout << " ����� ������� ������� � ����� �������� " << endl;
			(listAbonent + i)->print();
			return (listAbonent + i);
		}
	}
	cout << " �� ����� �������� � ������ �������� " << endl;
	return nullptr;
}

void TeleDirect::printBaze() {
	if (listAbonent != 0) {
		for (int i = 0; i < sizeAbonent; i++) {
			(listAbonent + i)->print();
		}
	}
}

void TeleDirect::saveFile() {
	if (listAbonent == nullptr) {
		// ���� ������ ���� �� �� ����� ��� ���������� � ����
		cout << "��������� ���������� ����! ���� �� ��� �������� " << endl;
		return;
	}

	fstream fileSave;
	fileSave.open("Baze.dat", ios::trunc, ios::out);
	
	if (!fileSave.is_open()) {
		// ���� ���� ������ ���� �� �������
		ofstream file;
		file.open("Baze.dat",ios::out);

		for (int i = 0; i < sizeAbonent; i++) {
			file.write((char*)&listAbonent[i], sizeof(Abonent));
		}
		
		file.close();
	}
	else {
		// ���� ������ ���� ���������� �� �������������� ���
			for (int i = 0; i < sizeAbonent; i++) {
				fileSave.write((char*)&listAbonent[i], sizeof(Abonent));
			}
	}
	cout << "���� ����������� ������� �������� �� ����" << endl;
	cout << "����� ������� " << sizeAbonent << endl;
}

void TeleDirect::loadFile() {
	int countObject = 0;

	fstream fileLoad;
	fileLoad.open("Baze.dat", ios::in);

	if (!fileLoad.is_open()) {
		// ���� ���� ������ �����
		cout << "���������� ������������ ���" << endl;
		fileLoad.close();
		return;
	}
	else {
		 //���� ������ ���� ���������� �� ��������� ������� ��� ��������
		cout << "���� ����������� ������ ���������" << endl;
		
		Abonent tempRead;
		// ���� ���� � ��������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		while (fileLoad.read((char*) &tempRead, sizeof(Abonent))) {
			countObject++;
		}
		cout << "���������� ������� " << countObject << endl;
	}
	fileLoad.close();


	// �� ������� ������� ����� ��������� ������ ��� ������ � ������� �� ����� ����������
	if (listAbonent != nullptr) {
		delete[] listAbonent;
	}
	fileLoad.open("Baze.dat", ios::in);
	sizeAbonent = countObject;
	Abonent temp;

	Abonent *tempCopy = new Abonent[sizeAbonent];
	listAbonent = tempCopy;

	while (fileLoad.read((char*)&temp, sizeof(Abonent))) {
		*tempCopy = temp;
		tempCopy++;
	}

	fileLoad.close();
}

void TeleDirect::saveFindFile(Abonent *findAbonent) {
	if (findAbonent != nullptr) {
		ofstream fileSave;
		fileSave.open("SaveFindAbonent.txt", ios::out);
		fileSave << "������� ";
		fileSave << findAbonent->getSurname() << endl;
		fileSave << "��� ";
		fileSave << findAbonent->getName() << endl;
		fileSave << "�������� ";
		fileSave << findAbonent->getMiddleName() << endl;
		fileSave << "���� �������� ";
		fileSave << findAbonent->getDateOFbirth() << endl;
		fileSave << "������� ";
		fileSave << findAbonent->getPhoneNumber() << endl;
		fileSave.close();
	}
}