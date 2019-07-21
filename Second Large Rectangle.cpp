#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int arr[MAXN][MAXN];
int dp[MAXN][MAXN];
struct MYINT {
    int w, h;
};
struct MYINTS {
    int area, w, h;
    bool friend operator < (const MYINTS &a, const MYINTS &b){
        return a.area < b.area;
    }
};
stack<MYINT> stk;
priority_queue<MYINTS> que;
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < a.length(); j++) {
            arr[i][j + 1] = a[j] - '0';
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[j][i] == 1) {
                dp[j][i] = dp[j - 1][i] + 1;
            }
        }
    }
    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= m; j ++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int w = 0;
            while (!stk.empty() && stk.top().h > dp[i][j]) {
                w += stk.top().w;
                MYINTS ans;
                ans.h = stk.top().h;
                ans.w = w;
                ans.area = w * stk.top().h;
                que.push(ans);
                stk.pop();
            }
            MYINT temp;
            temp.h = dp[i][j], temp.w = w + 1;
            stk.push(temp);
        }
        int w = 0;
        while (!stk.empty()) {
            w += stk.top().w;
            MYINTS ans;
            ans.h = stk.top().h;
            ans.w = w;
            ans.area = w * stk.top().h;
            que.push(ans);
            stk.pop();
        }
    }
    if(que.size() == 1){
        if(que.top().area - min(que.top().h, que.top().w) > 0){
            cout << que.top().area - min(que.top().h, que.top().w) << endl;
        }
        else{
            cout << "0\n";
        }
    }
    else{
        MYINTS a = que.top(); que.pop();
        MYINTS b = que.top(); que.pop();
        if(a.area == b.area){
            cout << a.area << endl;
        }
        else{
            cout << max(a.area - min(a.h, a.w), b.area) << endl;
        }
    }
    return 0;
}