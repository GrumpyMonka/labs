#include "Func.h"
#include <iostream>
#include <windows.h>

vector<patient> list;

void record(int id, patient& object) {
	cout << endl;
	cout << "Запись №\t" << id + 1 << endl;
	cout << "Фамилия:\t" << object.get_last_name() << endl;
	cout << "Имя:\t\t" << object.get_name() << endl;
	cout << "Отчество:\t" << object.get_papich() << endl;
	cout << "Адресс:\t\t" << object.get_address() << endl;
	cout << "Мед. карта №\t" << object.get_number() << endl;
	cout << "Диагноз:\t" << object.get_shiza() << endl;
}

void vivod() {
	if (list.size()) {
		for (int i = 0; i < list.size(); i++) {
			record(i, list[i]);
		}
	}
	else {
		cout << "БДэ пуста..." << endl;
	}
	cout << endl;
	cout << endl;
	mainmenu();
}

void add_record() {
	string tempstr;
	patient temp;

	cout << "Введите данные: " << endl;
	cout << "Фамилия:\t";
	cin >> tempstr;
	temp.set_last_name(tempstr);

	cout << "Имя:\t\t";
	cin >> tempstr;
	temp.set_name(tempstr);

	cout << "Отчество:\t";
	cin >> tempstr;
	temp.set_papich(tempstr);

	cout << "Адресс:\t\t";
	cin >> tempstr;
	temp.set_address(tempstr);

	cout << "Мед. карта №\t";
	int tempint;
    cin >> tempint;
	temp.set_number(tempint);

	cout << "Диагноз:\t";
	cin >> tempstr;
	temp.set_shiza(tempstr);

	//list.push_back(temp->get_last_name(),temp->get_name(),temp->get_papich(),temp->get_address(),temp->get_number(),temp->get_shiza());
	list.push_back(temp);

	cout << endl;
	cout << endl;
	mainmenu();
}

void delete_record() {
	cout << endl;
	cout << endl;
	cout << "Введите номер записи для удаления: ";
	int a;
	cin >> a;

	if (a < list.empty()) {
		list.erase(list.begin() + a - 1);
		cout << "Запись номер " << a << " удаление!";
	}
	cout << endl;
	cout << endl;
	mainmenu();
}

void seach_shiza_record() {
	cout << "Введите диагноз по которому хотите осуществить поиск: ";
	string tempstr;
	cin >> tempstr;
	vector<int> abc;
	if (!list.empty()) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i].get_shiza() == tempstr) {
				abc.push_back(i);
			}
		}
	}

	cout << endl;
	if (abc.empty()) {
		cout << "Записи не найдены!" << endl;
	}
	else {
		for (int i = 0; i < abc.size(); i++) {
			record(abc[i], list[abc[i]]);
		}
	}

	cout << endl;
	cout << endl;
	mainmenu();
}

void seach_number_record() {
	cout << "Введите диапазон по которому хотите осуществить поиск:" << endl;
	cout << "Min: ";
	long long int min, max;
	cin >> min;
	cout << "Max: ";
	cin >> max;

	vector<int> zxc;
	if (!list.empty()) {
		for (int i = 0; i < list.size(); i++) {
			if ((list[i].get_number() >= min) && (list[i].get_number() <= max)) {
				zxc.push_back(i);
			}
		}
	}

	cout << endl;
	if (zxc.empty()) {
		cout << "Записи не найдены!" << endl;
	}
	else {
		for (int i = 0; i < zxc.size(); i++) {
			record(zxc[i], list[zxc[i]]);
		}
	}

	cout << endl;
	cout << endl;
	mainmenu();
}

void sravnenie() {
	cout << endl;
	if (list.empty()) {
		cout << "Сравнивать нечего, БД пуста" << endl;
	}
	else {
		cout << "Введите номера записей для сравнения: ";
		int x, y;
		cin >> x >> y;

		if (x <= list.size() && y <= list.size()) {
			patient temp_x = list[x - 1];  // присваивание
			patient temp_y = list[y - 1];
			if (temp_x == temp_y) {			// сравнение
				cout << "Записи идентичны" << endl;
			}
			if (temp_x != temp_y) {        //сравнение с отрицанием
				cout << "Записи не идентичны" << endl;
			}
		}
	}

	cout << endl;
	cout << endl;
	mainmenu();
}

void vivod_str() {
	cout << endl;
	Observer temp;
	if (list.empty()) {
		cout << "Выводить нечего, БД пуста" << endl;
	}
	else {
		cout << "Введите номера записи для вывода: ";
		int x;
		cin >> x;
		
		cout << temp.GetInfo(list[x-1]);
	}

	cout << endl;
	cout << endl;
	mainmenu();
}

void mainmenu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Добро пажалавать в нашу БД!" << endl;
	cout << "1 - Отобразить БД" << endl;
	cout << "2 - Добавить запись в БД" << endl;
	cout << "3 - Удалить запись в БД" << endl;
	cout << "4 - (Лб1)Найти по диагнозу" << endl;
	cout << "5 - (Лб1)Найти по мед. карте" << endl;
	cout << "6 - (Лб2)Сравнить записи" << endl;
	cout << "7 - (Лб2)Вывести запись в строчку" << endl;

	int number;
	cin >> number;

	cout << endl;


	switch (number) {
	case 1:
		vivod();
		break;
	case 2:
		add_record();
		break;
	case 3:
		delete_record();
		break;
	case 4:
		seach_shiza_record();
		break;
	case 5:
		seach_number_record();
		break;
	case 6:
		sravnenie();
		break;
	case 7:
		vivod_str();
		break;
	}
}