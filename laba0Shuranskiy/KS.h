#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	std::string name;//���
	unsigned int id;//�������������
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	int efect;//�������������
public:
	friend std::istream& operator >> (std::istream& in, KS& ks);//�������� ������������� �������
	friend std::ostream& operator << (std::ostream& out, KS& ks);//����� ���������� � ������������� �������
	void editKS();//��������� ������ � ������
	friend void savefileKS(std::ofstream& fout, const KS& ks);//���������� ���������� � ������������� �������
	KS inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
};

