#include <bits/stdc++.h>
using namespace std;
/*
the math know that the sum is 3's
sum(n) % 3 == 1 or 2 or 0
if(arr[i] == 0 && arr[i + 1] == 0){
    re += s[arr[i]];
}
 */
const int MAXN = 1e5 + 5;
char arr[MAXN];
int sum[MAXN];
int vids[4];
int main() {
    cout << log2 (1e6) << endl;
    scanf("%s", arr + 1);
    int len = strlen(arr + 1);
    for (int i = 1; i <= len; i++) {
        sum[i] = sum[i - 1] + arr[i] - '0';
        sum[i] %= 3;
    }
    vids[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= len; i++) {
        if (i + 1 < len + 1 && arr[i] == '0' && arr[i + 1] == '0') {
            ans += vids[sum[i]];
        }
        vids[sum[i]]++;
    }
    for (int i = 1; i <= len; i++) {
        if (arr[i] == '0') {
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}