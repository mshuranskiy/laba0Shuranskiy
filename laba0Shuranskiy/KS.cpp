#include "KS.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>

unsigned int KS::IDks = 0;

KS creatKS()//Создание компрессорной станции
{
	KS ks;
	ks.id = ++KS::IDks;
	cout << "Введите имя компрессорной станции\n";
	cin.get();
	getline(cin, ks.name);
	ks.n = getint("Введите количество цехов", 1, 10000);
	ks.ninwork = getint("Введите количество цехов в работе", 0, ks.n);
	ks.efect = getint("Введите эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0, 10000);
	return ks;
}

void printKS(const KS& ks)//Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции: " << ks.name << endl;
	cout << "Количество цехов на компрессорной станции: " << ks.n << endl;
	cout << "Количество цехов в работе: " << ks.ninwork << endl;
	cout << "Эффективность компрессорной станции: " << ks.efect << endl;
}

void editKS(KS& ks)//Изменение цоехов в работе
{
	ks.ninwork = getint("Введите количество цехов в работе", 0, ks.n);
}

void savefileKS(ofstream& fout, const KS& ks)//Сохранение информации о компрессорной станции
{
	fout << ks.id << endl;
	fout << ks.name << endl;
	fout << ks.n << endl;
	fout << ks.ninwork << endl;
	fout << ks.efect << endl;
}

KS inputfileKS(ifstream& fin)//Считывание информации о компрессорной станции
{
	KS ks;
	fin >> ks.id;
	fin >> ks.name;
	fin >> ks.n;
	fin >> ks.ninwork;
	fin >> ks.efect;
	return ks;
}