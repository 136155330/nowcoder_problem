#include <bits/stdc++.h>
using namespace std;
int arr[30][30];
int n;
long long re = 0;
vector<int> vec1, vec2;
void dfs(int step, long long sum) {
    if(vec1.size() > n || vec2.size() > n || step > 2 * n) return ;
    if (step == 2 * n && vec1.size() == n && vec2.size() == n) {
        re = max(re, sum);
        return;
    }
    if (vec1.size() < n) {
        vec1.push_back(step);
        long long ans = 0;
        for (int i = 0; i < vec2.size(); i++) {
            ans += arr[step][vec2[i]];
        }
        dfs(step + 1, sum + ans);
        vec1.pop_back();
    }
    if (vec2.size() < n) {
        vec2.push_back(step);
        long long ans = 0;
        for (int i = 0; i < vec1.size(); i++) {
            ans += arr[step][vec1[i]];
        }
        dfs(step + 1, sum + ans);
        vec2.pop_back();
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);
    cout << re << endl;
    return 0;
}