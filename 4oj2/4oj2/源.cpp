#include<iostream>
#include<algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int in[65536];

int main()
{
	int i, num = 1;
	int out[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//ԭʼ����
	while (cin >> in[0] && in[0] != EOF)
	{
		i = 1;
		while (cin >> in[i])//��ÿһ�еĸ���������һ������
		{
			if (cin.get() == '\n')
			{
				break;
			}
			i++; //cout << in[i - 1] << i;
		}
		cout << "Case " << num++ << ": ";
		for (int ii = 0; ii <= i; ii++)//��in����ĸ���Ԫ����out��������С�����Ƚ�
		{
			sort(out, out + 10, comp); //cout << out[9];//��������
			if (in[ii] > out[9])//�������������out��Сֵ����out��Сֵ�滻Ϊ�������
			{
				out[9] = in[ii];
			}//cout << in[ii]; cout << out[0];
		}
		sort(out, out + 10, comp);
		for (int iii = 0; iii <= 9; iii++)
		{
			if (iii != 9)
			{
				cout << out[iii] << ", " << flush;
			}
			else
			{
				cout << out[iii] << endl;
			}
		}
	}
	return 0;
}