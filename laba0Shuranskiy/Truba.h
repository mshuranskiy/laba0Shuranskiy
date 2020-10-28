#pragma once
#include <string>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//�������������
	std::string name;//���
	double dlina;//�����
	int diametr;//�������
	bool sostoyanie;//��������� � ������� ��� ���
public:
	static Truba creatTruba();//�������� �����
	friend void printTruba(const Truba& t);//����� ���������� � �����
	friend void editTruba(Truba& t);//��������� ����� � ������
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//���������� ���������� � �����
	static Truba inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
	friend Truba& selectTruba(vector<Truba>& Truboprovod);//�������� ������ �����
	friend void deleteTruba(vector<Truba>& Truboprovod);//�������� �����
	friend bool SearchTrubaByName(const Truba& t, std::string parametr);//����� �� �����
	friend bool SearchTrubaBySostoyanie(const Truba& t, bool parametr);//����� �� ����������
};

