#pragma once
#include <string>
#include <iostream>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//�������������
	double dlina;//�����
	int diametr;//�������
public:
	std::string name;//���
	bool sostoyanie;//��������� � ������� ��� ���
	friend std::istream& operator >> (std::istream& in, Truba& t);//�������� �����
	friend std::ostream& operator << (std::ostream& out,const Truba& t);//����� ���������� � �����
	void editTruba();//��������� ����� � ������
	void savefileTruba(std::ofstream& fout);//���������� ���������� � �����
	void inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
};

