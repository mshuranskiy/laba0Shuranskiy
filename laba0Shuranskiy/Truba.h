#pragma once
#include <string>
#include <iostream>
class Truba
{
	unsigned int id;//�������������
	std::string name;//���
	double dlina;//�����
	int diametr;//�������
	bool sostoyanie;//��������� � ������� ��� ���
public:
	static unsigned int IDt;
	friend std::istream& operator >> (std::istream& in, Truba& t);//�������� �����
	friend std::ostream& operator << (std::ostream& out,const Truba& t);//����� ���������� � �����
	void editTruba();//��������� ����� � ������
	void savefileTruba(std::ofstream& fout);//���������� ���������� � �����
	void inputfileTruba(std::ifstream& fin);//���������� ���������� � �����
	std::string getname();//����������� �����
	bool getsostoyanie();//���������� ���������
	unsigned int getid();//����������� id
};

