#include <bits/stdc++.h>
using namespace std;
long long dp[3005][3005];
const long long mod = 1e9 + 7;
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= n + m; i ++){
            for(int j = 0; j <= n + m; j ++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 0; i <= n + m; i ++){
            for(int j = 0; j <= n + m; j ++){
                if(i < n + j){
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                }
                if(j < m + i){
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
                }
            }
        }
        printf("%lld\n", dp[n + m][n + m]);
    }
    return 0;
}