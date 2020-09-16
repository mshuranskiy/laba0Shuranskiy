#include <iostream>
#include <fstream>
using namespace std;
struct Truba//Труба
{
	string id;//Идентификатор
	float dlina;//Длина
	int diametr;//Диаметр
	bool sostoyanie;//Состояние в ремонте или нет

};
struct KS//Компрессорная станция
{
	string name;//Имя
	string id;//идентификатор
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	int efect;//Эффективность
};
Truba creatTruba()//Создание трубы
{
	Truba t;
	cout << "Введите длину трубы\n";
	cin >> t.dlina;
	cout << "Введите диаметр трубы\n";
	cin >> t.diametr;
	t.sostoyanie = false;
	return t;
}
KS creatKS()//Создание компрессорной станции
{
	KS ks;
	cout << "Введите имя компрессорной станции\n";
	cin >> ks.name;
	cout << "Введите количество цехов\n";
	cin >> ks.n;
	cout << "Введите количество цехов в работе\n";
	cin >> ks.ninwork;
	cout << "Введите эффективность компрессорной станцции\n";
	cin >> ks.efect;
	return ks;
}
void printTruba(Truba t)//Вывод информации о трубе
{
	cout << "Данные о трубе:\n";
	cout << "Длина трубы: " << t.dlina<< endl;
	cout << "Диаметр турбы: " << t.diametr << endl;
	cout << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
}
void printKS(KS ks)//Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции: " << ks.name << endl;
	cout << "Количество цехов на компрессорной станции: " << ks.n << endl;
	cout << "Количество цехов в работе: " << ks.ninwork << endl;
	cout << "Эффективность компрессорной станции: " << ks.efect << endl;
}
void editTruba(Truba &t)//Отправить трубу в ремонт
{
	t.sostoyanie = !t.sostoyanie;
}
void editKS(KS &ks)//Изменение цоехов в работе
{
	cout << "Введите количесвто цехов в работе\n";
	int i;
	cin >> i;
	ks.ninwork = i;

}
void savefileTruba(Truba t)//Сохранение информации о трубе
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << t.dlina << endl;
		fout << t.diametr << endl;
		fout << t.sostoyanie << endl;
		fout.close();
	}
}
Truba inputfileTruba()//Считывание информации о трубе
{
	Truba t;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin >> t.dlina;
		fin >> t.diametr;
		fin >> t.sostoyanie;
		fin.close();
	}
	return t;
}
void savefileKS(KS ks)//Сохранение информации о компрессорной станции
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << ks.name<<endl;
		fout  << ks.n << endl;
		fout  << ks.ninwork << endl;
		fout << ks.efect << endl;
		fout.close();
	}
}
KS inputfileKS()//Считывание информации о компрессорной станции
{
	KS ks;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin>> ks.name;
		fin >> ks.n;
		fin >> ks.ninwork;
		fin >> ks.efect;
		fin.close();
	}
	return ks;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks = creatKS();
	editKS(infoks);
	printKS(infoks);
	savefileKS(infoks);
	/*Truba infoTruba=inputfileTruba();
	editTruba(infoTruba);
	printTruba(infoTruba);
	savefileTruba(infoTruba);*/
}