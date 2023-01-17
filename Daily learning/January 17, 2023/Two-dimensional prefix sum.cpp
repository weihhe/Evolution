#include<iostream>
using namespace std;
const int N = 10010;
int a[N][N], S[N][N];
int n, w, e;
int main()
{
	cin >> n >> w >> e;
	for (int i = 1; i <= n; i++)
		for (int m = 1; m <= w; m++)
		{
			cin >> a[i][m];//载入数组
		}
	for (int i = 1; i <= n; i++)
		for (int m = 1; m <= w; m++)
		{
			S[i][m] = S[i - 1][m] + S[i][m - 1] - S[i - 1][m - 1] + a[i][m];//涉及容斥原理，最后减去的是一个元素
		}
	while (e--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}