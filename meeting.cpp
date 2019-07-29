#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAXN = int(1e5 + 5);
int tot = 0;
int head[MAXN];
void Init() {
    for (int i = 0; i <= n; i++) {
        head[i] = -1;
    }
    tot = 0;
}
struct NODE {
    int u, v, next;
} arr[MAXN << 1];
void add(int u, int v) {
    arr[tot].u = u, arr[tot].v = v;
    arr[tot].next = head[u];
    head[u] = tot;
    tot ++;
}
map<int, int>M;
int vids[MAXN];
struct MYINT {
    int key, value;
    friend bool operator<(const MYINT &a, const MYINT &b) {
        return a.key > b.key;
    }
};
vector<int> vec;
void bfs(int num) {
    M.clear();
    memset(vids, 0, sizeof(vids));
    priority_queue<MYINT> que;
    MYINT be;
    be.key = num;
    be.value = 0;
    M[be.key] = 0;
    vids[be.key] = 1;
    que.push(be);
    while (!que.empty()) {
        MYINT te = que.top();
        que.pop();
        for (int i = head[te.key]; ~i; i = arr[i].next) {
            if (!vids[arr[i].v]) {
                vids[arr[i].v] = 1;
                MYINT be = te;
                be.key = arr[i].v;
                be.value += 1;
                M[be.key] = be.value;
                que.push(be);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    Init();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    bfs(vec[0]);
    int re = 0, num = 0;
    for (int i = 0; i < k; i++) {
        if (re < M[vec[i]]) {
            re = M[vec[i]];
            num = vec[i];
        }
    }
    bfs(num);
    re = 0;
    for (int i = 0; i < k; i++) {
        re = max(re, M[vec[i]]);
    }
    cout << (re + 1) / 2 << endl;
    return 0;
}