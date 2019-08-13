#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 0; i < 1000; i ++){
        system("C:/Users/user/Desktop/nowcoder/rand.exe");
        double be = clock();
        system("C:/Users/user/Desktop/nowcoder/sol.exe");
        double en = clock();
        system("C:/Users/user/Desktop/nowcoder/dat.exe");
        if(system("fc C:\\Users\\user\\Desktop\\nowcoder\\1.out C:\\Users\\user\\Desktop\\nowcoder\\1.ans")){
            puts("wrong answer");
            return 0;
        }
        else{
            cout << "Accept in the test " << i + 1 << ", the test cost the" << " " << en - be << "ms\n";
        }
    }
    return 0;
}