#pragma once
#include <string>
#include <vector>
class KS
{
	unsigned int id;//�������������
	int efect;//�������������
public:
	static unsigned int IDks;
	std::string name;//���
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	friend std::istream& operator >> (std::istream& in, KS& ks);//�������� ������������� �������
	friend std::ostream& operator << (std::ostream& out,const KS& ks);//����� ���������� � ������������� �������
	void editKS();//��������� ������ � ������
	void savefileKS(std::ofstream& fout);//���������� ���������� � ������������� �������
	void inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
};

