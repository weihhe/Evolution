#include<iostream>
using namespace std;

const int N = 100010;


int main()
{
	int qrr[N], n=0, m=0;
	qrr[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin>> qrr[i];//ǰ׺�͵ĳ�ʼ��
	}
	for (int i = 1; i <= n; i++)
	{
		qrr[i] = qrr[i - 1] + qrr[i];//ǰ׺�ͼ��㲿�֣�ע��������û�б����ʼ��������
	}
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << qrr[b] - qrr[a - 1]<<endl;
	}
	return 0;
}