#pragma once
#include <string>
#include <iostream>
class Truba
{
	static unsigned int IDt;
	unsigned int id;//�������������
	std::string name;//���
	double dlina;//�����
	int diametr;//�������
	bool sostoyanie;//��������� � ������� ��� ���
public:
	friend std::istream& operator >> (std::istream& in, Truba& t);//�������� �����
	friend std::ostream& operator << (std::ostream& out, Truba& t);//����� ���������� � �����
	void editTruba();//��������� ����� � ������
	friend void savefileTruba(std::ofstream& fout, const Truba& t);//���������� ���������� � �����
	Truba inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
};

