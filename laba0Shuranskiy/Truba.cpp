#include "Truba.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

unsigned int Truba::IDt = 0;
istream& operator >> (istream& in, Truba& t)//Создание трубы
{
	t.id = ++Truba::IDt;
	cout << "Введите имя трубы\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("Введите длину трубы (Еденица измерения: м)", 1.0, 10000.0);
	t.diametr = getint("Введите диаметр трубы(Еденица измерения : мм)", 1, 10000);
	t.sostoyanie = false;
	return in;
}

ostream& operator << (ostream& out,const Truba& t)//Вывод информации о трубе
{
	out << "Данные о трубе:\n";
	out << "Имя трубы: " << t.name << endl;
	out << "Длина трубы: " << t.dlina << " (м)" << endl;
	out << "Диаметр турбы: " << t.diametr << " (мм)" << endl;
	out << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
	return out;
}


void Truba::editTruba()//Отправить трубу в ремонт
{
	sostoyanie = !sostoyanie;
}

void Truba::savefileTruba(std::ofstream& fout)//Сохранение информации о трубе
{
	fout << id << endl;
	fout << name << endl;
	fout << dlina << endl;
	fout << diametr << endl;
	fout << sostoyanie << endl;
}

void Truba::inputfileTruba(std::ifstream& fin)//Считывание информации о трубе
{
	fin >> id;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;
}