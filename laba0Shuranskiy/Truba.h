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
	unsigned int inputks=0;//������������� ������� �� ������� ��� �����
	unsigned int outputks=0;//������������� ������� � ������� ��� �����
	int proizv;
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
	void setinputks(unsigned int value);//����������� id ������������� ������� �� ������� ��� �����
	void setoutputks(unsigned int value);//����������� id ������������� ������� � ������� ��� �����
	unsigned int getinputks();//���������� id ������������� ������� �� ������� ��� �����
	unsigned int getoutputks();//���������� id ������������� ������� � ������� ��� �����
	int getproizv();
};

