#pragma once
#include <string>
#include <iostream>
class Truba
{
	unsigned int id;//�������������
	double dlina;//�����
	int diametr;//�������
public:
	static unsigned int IDt;
	std::string name;//���
	bool sostoyanie;//��������� � ������� ��� ���
	friend std::istream& operator >> (std::istream& in, Truba& t);//�������� �����
	friend std::ostream& operator << (std::ostream& out,const Truba& t);//����� ���������� � �����
	void editTruba();//��������� ����� � ������
	void savefileTruba(std::ofstream& fout);//���������� ���������� � �����
	void inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
};

