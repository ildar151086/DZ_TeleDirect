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
■■ Возможность сохранения найденной информации
в файл.
■■ Сохранение базы в файл.
■■ Загрузка базы из файла.

*/

#include <iostream>
#include <string>
#include "TeleDirect.h"


using namespace std;

enum FILEMENU {
    ADD_ABONENT = 1,
    DELETE_ABONENT,
    EDIT_ABONENT,
    FIND_SURNAME,
    FIND_TELEPHON,
    PRINT,
    SAVE_IN_FILE,
    LOAD_IN_FILE,
    SAVE_IN_FILE_FIND,
    EXIT_IN_PROGRAM
};

void showMenu() {
    cout << endl;
    cout << "Выберите пункт меню:" << endl;
    cout << "\tДобавить абонента в базу " << ADD_ABONENT << endl;
    cout << "\tУдалить абонента из базы " << DELETE_ABONENT << endl;
    cout << "\tРедактировать абонента в базе " << EDIT_ABONENT << endl;
    cout << "\tПоиск абонента по фамилии " << FIND_SURNAME << endl;
    cout << "\tПоиск абонента по телефону " << FIND_TELEPHON << endl;
    cout << "\tВывод базы на печать " << PRINT << endl;
    cout << "\tСохранить базу " << SAVE_IN_FILE << endl;
    cout << "\tЗагрузить базу " << LOAD_IN_FILE << endl;
    cout << "\tСохранить найденного абонента в файл " << SAVE_IN_FILE_FIND << endl;
    cout << "\tВыход из программы " << EXIT_IN_PROGRAM << endl;
    cout << endl;
}



int main(){
    setlocale(LC_ALL, "RUS");
    
    TeleDirect tele;
    Abonent abonent;
    string str;
    int number = 0;

    bool work = true;
    while (work) {
        showMenu();
        int userCin;
        cin >> userCin;
        switch (userCin) {
            case ADD_ABONENT:
                abonent.pushAbonent();
                tele.pushAbonent(&abonent);
            break;
            case DELETE_ABONENT:
                abonent.pushAbonent();
                tele.deleteAbonent(abonent);
            break;
            case EDIT_ABONENT:
                abonent.pushAbonent();
                tele.editAbonent(abonent);
            break;
            case FIND_SURNAME:
                cout << "Введите Фамилию для поиска ";
                cin >> str;
                tele.findSurname(str);
            break;
            case FIND_TELEPHON:
                cout << "Введите Телефон для поиска ";
                cin >> number;
                tele.findTelephon(number);
            break;
            case PRINT:
                tele.printBaze();
            break;
            case SAVE_IN_FILE:
                tele.saveFile();
            break;
            case LOAD_IN_FILE:
                tele.loadFile();
            break;
            case SAVE_IN_FILE_FIND:
                cout << "Введите Фамилию для поиска ";
                cin >> str;
                tele.saveFindFile(tele.findSurname(str));
            break;
            case EXIT_IN_PROGRAM:
                work = false;
            break;
            default:
                 cout << "Такого пункта меню нет! Попробуйте еще раз" << endl;
            break;
        }
    }

}

