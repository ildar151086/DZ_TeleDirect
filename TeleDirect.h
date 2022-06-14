/*
1.	Создать телефонный справочник для осуществления
следующих операций:
■■ Добавление абонентов в базу.
■■ Удаление абонентов из базы.
■■ Модификация данных абонента.
■■ Поиск абонентов по телефонному номеру или фа-
милии.
■■ Распечатка в алфавитном порядке абонентов из за-
данного диапазона номеров или фамилий; например,
для номеров диапазон может быть: 222222–333333,
а для фамилий: Иванаускас — Иванов (то есть Ива-
нова в диапазон не входит).

■■ Сохранение базы в файл.
■■ Загрузка базы из файла.
■■ Возможность сохранения найденной информации
в файл.
*/

#include "Abonent.h"
#include <string>
#include <iostream>

class TeleDirect{
	
	///Массив из абонентов
	Abonent* listAbonent;

	/// Размер справочника
	int sizeAbonent;

public:
	TeleDirect();
	bool inEmpty();

	void pushAbonent(Abonent*);
	Abonent* findTelephon(int);
	Abonent* findSurname(string);
	void printBaze();
	void editAbonent(Abonent&);
	void deleteAbonent(Abonent&);
	void saveFile();
	void saveFindFile(Abonent*);
	
	void loadFile();


	~TeleDirect();
};

