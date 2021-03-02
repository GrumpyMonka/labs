#include "Func.h"
#include <iostream>
#include <windows.h>

vector<patient> list;

void record(int id, patient& object) {
	cout << endl;
	cout << "������ �\t" << id + 1 << endl;
	cout << "�������:\t" << object.get_last_name() << endl;
	cout << "���:\t\t" << object.get_name() << endl;
	cout << "��������:\t" << object.get_papich() << endl;
	cout << "������:\t\t" << object.get_address() << endl;
	cout << "���. ����� �\t" << object.get_number() << endl;
	cout << "�������:\t" << object.get_shiza() << endl;
}

void vivod() {
	if (list.size()) {
		for (int i = 0; i < list.size(); i++) {
			record(i, list[i]);
		}
	}
	else {
		cout << "��� �����..." << endl;
	}
	cout << endl;
	cout << endl;
	mainmenu();
}

void add_record() {
	string tempstr;
	patient temp;

	cout << "������� ������: " << endl;
	cout << "�������:\t";
	cin >> tempstr;
	temp.set_last_name(tempstr);

	cout << "���:\t\t";
	cin >> tempstr;
	temp.set_name(tempstr);

	cout << "��������:\t";
	cin >> tempstr;
	temp.set_papich(tempstr);

	cout << "������:\t\t";
	cin >> tempstr;
	temp.set_address(tempstr);

	cout << "���. ����� �\t";
	int tempint;
    cin >> tempint;
	temp.set_number(tempint);

	cout << "�������:\t";
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
	cout << "������� ����� ������ ��� ��������: ";
	int a;
	cin >> a;

	if (a < list.empty()) {
		list.erase(list.begin() + a - 1);
		cout << "������ ����� " << a << " ��������!";
	}
	cout << endl;
	cout << endl;
	mainmenu();
}

void seach_shiza_record() {
	cout << "������� ������� �� �������� ������ ����������� �����: ";
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
		cout << "������ �� �������!" << endl;
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
	cout << "������� �������� �� �������� ������ ����������� �����:" << endl;
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
		cout << "������ �� �������!" << endl;
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
		cout << "���������� ������, �� �����" << endl;
	}
	else {
		cout << "������� ������ ������� ��� ���������: ";
		int x, y;
		cin >> x >> y;

		if (x <= list.size() && y <= list.size()) {
			patient temp_x = list[x - 1];  // ������������
			patient temp_y = list[y - 1];
			if (temp_x == temp_y) {			// ���������
				cout << "������ ���������" << endl;
			}
			if (temp_x != temp_y) {        //��������� � ����������
				cout << "������ �� ���������" << endl;
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
		cout << "�������� ������, �� �����" << endl;
	}
	else {
		cout << "������� ������ ������ ��� ������: ";
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

	cout << "����� ���������� � ���� ��!" << endl;
	cout << "1 - ���������� ��" << endl;
	cout << "2 - �������� ������ � ��" << endl;
	cout << "3 - ������� ������ � ��" << endl;
	cout << "4 - (��1)����� �� ��������" << endl;
	cout << "5 - (��1)����� �� ���. �����" << endl;
	cout << "6 - (��2)�������� ������" << endl;
	cout << "7 - (��2)������� ������ � �������" << endl;

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