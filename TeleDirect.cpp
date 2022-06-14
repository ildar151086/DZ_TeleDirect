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
			std::cout << " Нашли искомого абонента " << endl;			

			// Удаляем его
			Abonent* temp = listAbonent;
			Abonent* newlistAbonent = new Abonent[newSizeAbonenet];

			// Копируем до нужной нам позиции
			for (int j = 0; j < i; j++) {
				*(newlistAbonent + j) = *(temp + j);
			};
			// Продолжаем копировать с пропуском ненужного элемента i 
			for (int j = i + 1; j < sizeAbonent; j++) {
				*(newlistAbonent + j - 1) = *(temp + j);
			};
			delete[] temp;
			listAbonent = newlistAbonent;
			sizeAbonent = newSizeAbonenet;

			std::cout << " Информация об абоненте была удалена " << endl;
			std::cout << endl;
			return;
		}
	}
	// Не нашли искомого абонента
	std::cout << " Такого абонента нет " << endl;
	std::cout << endl;
}

TeleDirect::~TeleDirect() {
	if (listAbonent != nullptr) {
		delete[] listAbonent;
	}
}

/// Выбор пользователя для изменения параметров абонента в справочнике
enum EDIT_ABONENT {
	EDIT_SURNAME = 1,
	EDIT_NAME,
	EDIT_MIDDLENAME,
	EDIT_PHONENUMBER,
	EDIT_DATEOFBIRTH
};

int menuEdit() {
	int useUser = 0;
	std::cout << " Выберите необходимый пункт меню  " << endl;
	std::cout << " 1 - Изменить Фамилию " << endl;
	std::cout << " 2 - Изменить Имя " << endl;
	std::cout << " 3 - Изменить Отчетсво " << endl;
	std::cout << " 4 - Изменить номер телефона " << endl;
	std::cout << " 5 - Изменить дату рождения " << endl;
	std::cout << " 6 - Выход из меню " << endl;
	cin >> useUser;
	return useUser;
}

template <typename T>
T editFieldAbonent(T str) {
	T valueUserEdit;
	cout << "Напишите на что поменять выбранное поле ";
	cin >> valueUserEdit;
	cout << " Поле было успешно изменено " << endl;
	return valueUserEdit;
}

void TeleDirect::editAbonent(Abonent& findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if (*(listAbonent + i) == findValue){
			std::cout << " Нашли искомого абонента " << endl;

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

			// Изменяем его
			std::cout << " Информация об абоненте была изменена " << endl;
			std::cout << endl;
			return;
		}
	}
	// Не нашли искомого абонента
	std::cout << " Такого абонента нет " << endl;
	std::cout << endl;
}

Abonent *TeleDirect::findTelephon(int findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if ((listAbonent + i)->getPhoneNumber() == findValue) {
			cout << " Нашли искомый телефон у этого абонента " << endl;
			(listAbonent + i)->print();
			return (listAbonent + i);
		}
	}
	cout << " Не нашли абонента с данным номером " << endl;
	std::cout << endl;
	return nullptr;
}

Abonent* TeleDirect::findSurname(string findValue) {
	for (int i = 0; i < sizeAbonent; i++) {
		if ((listAbonent + i)->getSurname() == findValue) {
			cout << " Нашли искомую фамилию у этого абонента " << endl;
			(listAbonent + i)->print();
			return (listAbonent + i);
		}
	}
	cout << " Не нашли абонента с данной фамилией " << endl;
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
		// Если список пуст то не зачем его записывать в файл
		cout << "Телефоный справочник пуст! Файл не был сохранен " << endl;
		return;
	}

	fstream fileSave;
	fileSave.open("Baze.dat", ios::trunc, ios::out);
	
	if (!fileSave.is_open()) {
		// Если нету такого фала то создаем
		ofstream file;
		file.open("Baze.dat",ios::out);

		for (int i = 0; i < sizeAbonent; i++) {
			file.write((char*)&listAbonent[i], sizeof(Abonent));
		}
		
		file.close();
	}
	else {
		// Если данный файл существует то перезаписываем его
			for (int i = 0; i < sizeAbonent; i++) {
				fileSave.write((char*)&listAbonent[i], sizeof(Abonent));
			}
	}
	cout << "База справочника успешно записана на диск" << endl;
	cout << "Всего записей " << sizeAbonent << endl;
}

void TeleDirect::loadFile() {
	int countObject = 0;

	fstream fileLoad;
	fileLoad.open("Baze.dat", ios::in);

	if (!fileLoad.is_open()) {
		// Если нету такого файла
		cout << "Телефоного спраавочника нет" << endl;
		fileLoad.close();
		return;
	}
	else {
		 //Если данный файл существует то посчитаем сколько там объектов
		cout << "База справочника упешно загружена" << endl;
		
		Abonent tempRead;
		// Тута сбой в программе !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		while (fileLoad.read((char*) &tempRead, sizeof(Abonent))) {
			countObject++;
		}
		cout << "Количество записей " << countObject << endl;
	}
	fileLoad.close();


	// Но сначало ощищаем ранее выделеную память под объект в который мы будем записывать
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
		fileSave << "Фамилия ";
		fileSave << findAbonent->getSurname() << endl;
		fileSave << "Имя ";
		fileSave << findAbonent->getName() << endl;
		fileSave << "Отчество ";
		fileSave << findAbonent->getMiddleName() << endl;
		fileSave << "Дата рождения ";
		fileSave << findAbonent->getDateOFbirth() << endl;
		fileSave << "Телефон ";
		fileSave << findAbonent->getPhoneNumber() << endl;
		fileSave.close();
	}
}