#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int m = 1;
	string str, bbb;
	//str = "�� bbl�Ϻ�ss��r�й�abc";
	while (getline(cin, str))
	{
		bbb.resize(str.size()); //
		for (int i = str.size() - 1, j = 0, c = 0; i >= 0; i--) {
			if (str[i] < 0) {
				bbb[j + (++c % 2)] = str[i]; //c%2˫�ֽڼ�����
				j += c % 2 ? 0 : 2;              //˫�ֽ���ɲ���2
			}
			else bbb[j++] = str[i];
		}
		cout << "Case " << m++ << ": \"";
		cout << bbb << "\"" << endl;
	}
	return 0;
}