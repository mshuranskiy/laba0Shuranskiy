#pragma once
#include <string>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//�������������
	double dlina;//�����
	int diametr;//�������
	bool sostoyanie;//��������� � ������� ��� ���
public:
	friend Truba creatTruba();//�������� �����
	friend void printTruba(const Truba& t);//����� ���������� � �����
	friend void editTruba(Truba& t);//��������� ����� � ������
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//���������� ���������� � �����
	friend Truba inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
};

