#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
long long arr[MAXN][MAXN];
long long st[MAXN][1010][20]; //st表
long long value[MAXN];
long long sums[MAXN];
int n, m;
void Init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            st[i][j][0] = arr[i][j];
        }
    }
    for (int z = 0; z < n; z++)
    {
        for (int j = 1; (1 << j) <= m; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < m; i++)
                st[z][i][j] = min(st[z][i][j - 1], st[z][i + (1 << (j - 1))][j - 1]);
        }
    }
}
long long search(int step, int l, int r)
{
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    return min(st[step][l][k], st[step][r - (1 << k) + 1][k]);
}
int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //cin >> arr[i][j];
                scanf("%lld", &arr[i][j]);
                if(j > 0){
                    arr[i][j] = arr[i][j - 1] + arr[i][j];
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
           scanf("%lld", &value[i]);
            if (i > 0)
            {
                value[i] = value[i] + value[i - 1];
            }
        }
        Init();
        long long res = 0;
        for(int i = 0; i < n; i ++){
            res += min(search(i, 0, m - 1), 0LL);
        }
        for (int i = 0; i < m; i++)
        {
            long long ans = 0;
            for (int j = 0; j < n; j++)
            {
                ans += search(j, i, m - 1);
            }
            sums[i] = ans;
        }
        long long re = 0;
        for (int i = 0; i < n; i++)
        {
            long long ans = 0;
            for (int j = 0; j < m; j++)
            {
                ans = sums[j] - search(i, j, m - 1) + arr[i][j];
                re = max(re, value[j] - ans);
            }
        }
        for (int i = 0; i < n; i++)
        {
            long long ans = res - min(search(i, 0, m - 1), 0LL) + 0LL;
            re = max(-ans, re);
        }
        printf("Case #%d: %lld\n", ++cnt, re);
    }
    return 0;
}