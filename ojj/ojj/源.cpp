#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	double d1, c, d2, di[7], p[7], d[7], cost = 0, cleft = 0, dz = 0;//costΪ�ܸ����ͼ�
	int n, i, i1 = 0, i2 = 1, m;
	cin >> d1 >> c >> d2 >> p[0] >> n;
	m = n;
	i = 1;//��������
	double cd2 = c * d2;
	if (n == 0)
	{
		if (cd2 < d1)
		{
			cout << "No Solution" << endl;
		}
		else
		{
			cost = p[0] * d1 / d2;
			cost *= 100;
			cost = round(cost);
			cost /= 100;
			cout << setprecision(2) << fixed << cost << endl;
		}
		return 0;
	}
	while (cin >> di[i1] >> p[i])
	{
		i++, i1++;
	}
	p[n + 1] = 0;
	di[n] = d1;
	//������d[]��Ÿ���վ��֮��ľ���,��di[]���ų���ʼվ�����վ�㵽��ʼվ�ľ���
	d[0] = di[0];
	while (i2 < n)
	{
		d[i2] = di[i2] - di[i2 - 1];
		i2++;
	}
	d[n] = d1 - di[i2 - 1];
	//�ж��Ƿ��޽⣬���޽⣬��ֹ������
	for (i2 = 0; i2 <= n; i2++)
	{
		if (d[i2] > cd2)
		{
			cout << "No Solution" << endl;
			return 0;
		}
	}
	int stop = 0, cmax = 0;//stopΪ����������վ��,cmaxΪǰվ���������ɿ���վ
	i = 0;
	while (stop <= n)//��ѭ�������㳵������վ�����ڵ����յ�վʱֹͣѭ��
	{
		if (p[i] < p[i + 1])//�ж�ǰվ���վ���ͼ�˭������վ��ִ���������
		{
			if (cd2 >= d[i] + d[i + 1])//�ж�ǰվ�����Ϳɷ�����վ����һվ�����ɣ�ִ���������
			{
				double cd = cd2;
				int itwin = i;
				while (cd > 0 && itwin <= 6 && cmax <= (n + 1 - i))//��cmax
				{
					cd = cd - d[itwin];
					itwin++, cmax++;
				}
				//cmax--;
				itwin = i;
				int judge = i;
				while (cmax > 0)//�жϿɿ�����վ���Ƿ��б�ǰվ���˵�վ
				{
					itwin++, cmax--;
					if (p[i] > p[itwin])
					{
						stop = itwin;
						dz = 0;
						while (i < stop)
						{
							dz += d[i]; //�����ʱ���ѵ��ͼ�
							i++;//��i����stop�Ĵ�С
						}
						cost = cost + p[judge] * (dz - cleft * d2) / d2;
						cleft = 0;// cout << cost << i;
						break;
					}
				}
				if (i == judge)//ǰվ�����
				{
					stop = i + cmax;
					dz = 0;
					while (i < stop)
					{
						dz = dz + d[i];
						i++;
					}
					cost = cost + p[judge] * (c - cleft);//��������
					cleft = c - dz / d2;//�㿪��Ŀ�ĵغ��ʣ������
				}
				continue;
			}
			else//ǰվ�����Ͳ��ɿ�����վ����һվ
			{
				stop += 1;
				cost = cost + p[i] * (c - cleft);
				cleft = c - d[i] / d2;
				i = stop;
				continue;
			}
		}
		else//ǰվ�Ⱥ�վ��
		{
			stop += 1;
			cost = cost + p[i] * (d[i] / d2 - cleft);
			cleft = 0;
			i = stop;
			continue;
		}
	}
	cost *= 100;
	cost = round(cost);
	cost /= 100;
	cout << setprecision(2) << fixed << cost << endl;
	return 0;
}