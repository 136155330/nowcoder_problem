#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, k;
const int MAXN = 1e3 + 5;
int head[MAXN];
struct NODE {
    int u, v, w, next;
} arr[MAXN << 1];
int tot = 0;
void add(int u, int v, int w) {
    arr[tot].u = u, arr[tot].v = v, arr[tot].w = w;
    arr[tot].next = head[u];
    head[u] = tot++;
}
long long dist[MAXN];
struct edge {
    int num, knum;
    long long sum;
    friend bool operator< (const edge &x, const edge &y) {
        return x.sum > y.sum;
    }
};
int vids[MAXN];
void bfs() {
    edge be;
    be.num = s, be.knum = 0, be.sum = 0;
    priority_queue<edge> que;
    que.push(be);
    while (!que.empty()) {
        edge x = que.top();
        que.pop();
        dist[x.num] = min(dist[x.num], x.sum);
        vids[x.num] = 1;
        for (int i = head[x.num]; ~i; i = arr[i].next) {
            edge y1 = x, y2 = x;
            if (!vids[arr[i].v]) {
                if (y1.knum < k) {
                    y1.knum++;
                    y1.num = arr[i].v;
                    que.push(y1);
                }
                y2.num = arr[i].v;
                y2.sum += arr[i].w;
                que.push(y2);
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    for (int i = 0; i <= n; i++) {
        head[i] = -1;
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = __LONG_LONG_MAX__;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    bfs();
    printf("%lld\n", dist[t]);
    return 0;
}