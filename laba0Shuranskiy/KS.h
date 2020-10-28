#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	std::string name;//Имя
	unsigned int id;//идентификатор
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	int efect;//Эффективность
public:
	friend std::istream& operator >> (std::istream& in, KS& ks);//Создание компрессорной станции
	friend std::ostream& operator << (std::ostream& out, KS& ks);//Вывод информации о компрессорной станции
	void editKS();//Изменение цоехов в работе
	friend void savefileKS(std::ofstream& fout, const KS& ks);//Сохранение информации о компрессорной станции
	KS inputfileKS(std::ifstream& fin);//Считывание информации о компрессорной станции
};

