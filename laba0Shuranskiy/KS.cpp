#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>

unsigned int KS::IDks = 0;

istream& operator >> (istream& in, KS& ks)//Создание компрессорной станции
{
	ks.id = ++KS::IDks;
	cout << "Введите имя компрессорной станции\n";
	cin.get();
	getline(cin, ks.name);
	ks.n = getint("Введите количество цехов", 1, 10000);
	ks.ninwork = getint("Введите количество цехов в работе", 0, ks.n);
	ks.efect = getint("Введите эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0, 10000);
	return in;

}

ostream& operator << (ostream& out, KS& ks)//Вывод информации о компрессорной станции
{
	out << "Данные о компрессорной станции:\n";
	out << "Имя компрессорной станции: " << ks.name << endl;
	out << "Количество цехов на компрессорной станции: " << ks.n << endl;
	out << "Количество цехов в работе: " << ks.ninwork << endl;
	out << "Эффективность компрессорной станции: " << ks.efect << endl;
	return out;
}

void KS::editKS()//Изменение цоехов в работе
{
	ninwork = getint("Введите количество цехов в работе", 0, n);
}

void savefileKS(std::ofstream& fout, const KS& ks)//Сохранение информации о компрессорной станции
{
	fout << ks.id << endl;
	fout << ks.name << endl;
	fout << ks.n << endl;
	fout << ks.ninwork << endl;
	fout << ks.efect << endl;
}

KS KS::inputfileKS(std::ifstream& fin)//Считывание информации о компрессорной станции
{
	KS ks;
	fin >> ks.id;
	fin >> ks.name;
	fin >> ks.n;
	fin >> ks.ninwork;
	fin >> ks.efect;
	return ks;
}

