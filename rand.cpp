#include <bits/stdc++.h>
using namespace std;
long long random(long long n) {
    long long a = (long long)rand() * rand() % n;
    return a == 0 ? a + 1 : a;
}
const long long inf = 1e9;
const long long x = 1e5;
int main() {
    freopen("C:/Users/user/Desktop/nowcoder/1.in", "w", stdout);
    srand(time(0));
    for (int hzb = 0; hzb < 10; hzb++) {
        int n = random(x) % 10000 + 1;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << random(inf) << " " << random(200LL) << " " << random(inf)
                 << endl;
        }
    }
    return 0;
}