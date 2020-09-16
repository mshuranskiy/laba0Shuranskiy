#include <iostream>
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
	cout << "Длина трубы " << t.dlina<< endl;
	cout << "Диаметр турбы " << t.diametr << endl;
	cout << "Состояние трубы " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
}
void printKS(KS ks)//Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции " << ks.name;
	cout << "Количество цехов на компрессорной станции " << ks.n;
	cout << "Количество цехов в работе " << ks.ninwork;
	cout << "Эффективность компрессорной станции " << ks.efect;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Truba infoTruba=creatTruba();
	printTruba(infoTruba);
}