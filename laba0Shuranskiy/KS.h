#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	unsigned int id;//идентификатор
	int efect;//Эффективность
public:
	std::string name;//Имя
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	friend std::istream& operator >> (std::istream& in, KS& ks);//Создание компрессорной станции
	friend std::ostream& operator << (std::ostream& out, KS& ks);//Вывод информации о компрессорной станции
	void editKS();//Изменение цоехов в работе
	void savefileKS(std::ofstream& fout);//Сохранение информации о компрессорной станции
	void inputfileKS(std::ifstream& fin);//Считывание информации о компрессорной станции
};

