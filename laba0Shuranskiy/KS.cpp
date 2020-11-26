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

ostream& operator << (ostream& out,const KS& ks)//Вывод информации о компрессорной станции
{
	out << "Данные о компрессорной станции:\n";
	out << "id компрессорной станции: " << ks.id << endl;
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

void KS::savefileKS(std::ofstream& fout)//Сохранение информации о компрессорной станции
{
	fout << id << endl;
	fout << name << endl;
	fout << n << endl;
	fout << ninwork << endl;
	fout << efect << endl;
}

void KS::inputfileKS(std::ifstream& fin)//Считывание информации о компрессорной станции
{
	fin >> id;
	fin >> name;
	fin >> n;
	fin >> ninwork;
	fin >> efect;
}

std::string KS::getname()
{
	return name;
}

int KS::getn()
{
	return n;
}

int KS::getninwork()
{
	return ninwork;
}

unsigned int KS::getid()
{
	return id;
}
