#include <bits/stdc++.h>
using namespace std;
/*
segtree[1].num - arr[i].p
本题存在坑点，不同种类的树有相同的高度
将不同种类的树 放到相同高度的vector里面
枚举高度
存在一个前缀和
*/
typedef long long LL;
int n;
const int MAXN = 1e5 + 5;
struct Tree{
    LL h, c, p;
    friend bool operator< (const Tree &a, const Tree &b){
        return a.h < b.h;
    }
}arr[MAXN];
LL sum[MAXN];
vector<LL>vec, h_arr;
vector<int>vec_tree[MAXN];
struct Segtree{
    struct NODE{
        int l, r;
        LL sum, num;
    }tree[MAXN << 2];
    void Init(){
        for(int i = 0; i <= 4 * n; i ++){
            tree[i].l = tree[i].r = tree[i].sum = tree[i].num = 0;
        }
    }
    inline void push_up(int root){
        tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
        tree[root].num = tree[root << 1].num + tree[root << 1 | 1].num;
        return ;
    }
    void build(int root, int l, int r){
        tree[root].l = l, tree[root].r = r;
        if(l == r){
            tree[root].sum = tree[root].num = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(root << 1, l, mid);
        build(root << 1 | 1, mid + 1, r);
        return ;
    }
    void update(int root, int cnt, LL val){
        if(tree[root].l == cnt && tree[root].r == cnt){
            tree[root].sum += val * vec[cnt - 1];
            tree[root].num += val;
            return ;
        }
        int mid = (tree[root].l + tree[root].r) >> 1;
        if(cnt <= mid){
            update(root << 1, cnt, val);
        }
        else{
            update(root << 1 | 1, cnt, val);
        }
        push_up(root);
    }
    LL query(int root, LL cnt){
        if(tree[root].num == cnt){
            return tree[root].sum;
        }
        if(tree[root].l == tree[root].r){
            return vec[tree[root].l - 1] * cnt;
        }
        if(cnt > tree[root << 1].num){
            return query(root << 1, tree[root << 1].num) + query(root << 1 | 1, cnt - tree[root << 1].num);
        }
        else{
            return query(root << 1, cnt);
        }
    }
}seg;
int Get(LL x){
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
int Geth(LL x){
    return lower_bound(h_arr.begin(), h_arr.end(), x) - h_arr.begin() + 1;
}
int main(){
    while(~scanf("%d", &n)){
        memset(sum, 0, (n + 3) * sizeof(sum[0]));
        vec.clear(), h_arr.clear();
        for(int i = 0; i <= n; i ++){
            vec_tree[i].clear();
        }
        seg.Init();
        for(int i = 0; i < n; i ++){
            scanf("%lld%lld%lld", &arr[i].h, &arr[i].c, &arr[i].p);
            vec.push_back(arr[i].c), h_arr.push_back(arr[i].h);
        }
        sort(arr, arr + n);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        sort(h_arr.begin(), h_arr.end());
        h_arr.erase(unique(h_arr.begin(), h_arr.end()), h_arr.end());
        sum[0] = arr[0].p * arr[0].c;
        for(int i = 1; i < n; i ++){
            sum[i] = sum[i - 1] + arr[i].p * arr[i].c;
        }
        seg.build(1, 1, n);
        for(int i = 0; i < n; i ++){
            vec_tree[Geth(arr[i].h)].push_back(i);
        }
        LL ans = __LONG_LONG_MAX__;
        for(int i = 1; i <= h_arr.size(); i ++){
            LL sums = 0;
            for(int j = 0; j < vec_tree[i].size(); j ++){
                sums += arr[vec_tree[i][j]].p;
            }
            if(sums > seg.tree[1].num){
                ans = min(ans, sum[n - 1] - sum[vec_tree[i][vec_tree[i].size() - 1]]);
            }
            else{
                ans = min(ans, sum[n - 1] - sum[vec_tree[i][vec_tree[i].size() - 1]] + seg.query(1, seg.tree[1].num - sums + 1));
            }
            for(int j = 0; j < vec_tree[i].size(); j ++){
                seg.update(1, Get(arr[vec_tree[i][j]].c), arr[vec_tree[i][j]].p);
            }
        }
        printf("%lld\n", ans);
    } 
    return 0;
}