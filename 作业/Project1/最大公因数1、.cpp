#include<iostream>

using namespace std;

//ȡС�ĺ���
int min(int a, int b)
{
	
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	//oj����
	int in1, in2, shua_oj;
	cin >> in1 >> in2;
	//�ų��������С�ڵ���0�����
	if (in1 > 0 && in2 > 0)
	{
		shua_oj = 0;
		//iֵС�������������������С���Ǹ����һ�뼴ֹͣѭ������������ʱ��
		for (int i = 1; i <= min(in1, in2) / 2; i++)
		{
			//�ó����Ĺ�Լ��
			if (in1 % i == 0 && in2 % i == 0)
			{
				shua_oj = i;
			}
		}
		//���
		cout << "���Լ���ǣ� " << shua_oj << endl;
	}
	return 0;
}