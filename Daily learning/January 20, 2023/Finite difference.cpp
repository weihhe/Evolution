#include<iostream>

using namespace std;

const int N = 100010;
int sun[N], arr[N];


void insert(int l, int r, int s)//������
{
    arr[l] += s;
    arr[r + 1] =arr[r+1]- s;
    return;
}
int main()
{
    int n=0,m=0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> sun[i];
    }
    for (int i = 1; i <= n; i++)//��ԭ���鹹��Ϊ���!
    {
        insert(i, i, sun[i]);
    }
    while (m --)
    {
        int l=0, r=0, s=0;
        cin >> l,r, s;
        insert(l, r, s);
    }
    for (int i = 1; i <=n; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}