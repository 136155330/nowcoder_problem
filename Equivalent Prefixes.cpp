#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN], brr[MAXN];
deque<int>que1;
deque<int>que2;
/*维护当前值为最小值对应的区间 */
void Init(){
    memset(arr, 0, sizeof(arr));
    memset(brr, 0, sizeof(brr));
    while(!que1.empty()) que1.pop_back();
    while(!que2.empty()) que2.pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        Init();
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i ++){
            cin >> brr[i];
        }
        int flag = 0;
        for(int i = 0; i < n; i ++){
            if(que1.empty() && que2.empty()){
                que1.push_back(i);
                que2.push_back(i);
            }
            else{
                while(!que1.empty() && arr[i] < arr[que1.back()]){
                    que1.pop_back();
                }
                while(!que2.empty() && brr[i] < brr[que2.back()]){
                    que2.pop_back();
                }
                while(!que1.empty() && arr[i] < arr[que1.front()]){
                    que1.pop_front();
                }
                while(!que2.empty() && brr[i] < brr[que2.front()]){
                    que2.pop_front();
                }
                que1.push_back(i);
                que2.push_back(i);
                if(que1.size() != que2.size()){
                    cout << i << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag){
            cout << n << endl;
        }
    }
    return 0;
}