#pragma once
#include <string>
#include <vector>
class KS
{
	unsigned int id;//�������������
	std::string name;//���
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	int efect;//�������������
public:
	static unsigned int IDks;
	friend std::istream& operator >> (std::istream& in, KS& ks);//�������� ������������� �������
	friend std::ostream& operator << (std::ostream& out,const KS& ks);//����� ���������� � ������������� �������
	void editKS();//��������� ������ � ������
	void savefileKS(std::ofstream& fout);//���������� ���������� � ������������� �������
	void inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
	std::string getname();//����������� ���
	int getn();//����������� ���������� �����
	int getninwork();//����������� ���������� ����� � ������
	unsigned int getid();//����������� id
};

