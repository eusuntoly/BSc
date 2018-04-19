#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char a[100], b[100];
int del, inser, repl, n, m, p[100][100], dp[100][100];
void write(int i, int j){
    if(i < 1)
        return;
    if(p[i][j] == 1){
        write(i - 1, j);
        g<<"stergem "<<a[i]<<'\n';
        return;
    }
    if(j < 1)
        return;
    if(p[i][j] == 2){
        write(i, j - 1);
        g<<"inseram "<<b[j]<<'\n';
        return;
    }
    if(p[i][j] == 3){
        write(i - 1, j - 1);
        g<<"inlocuim "<<a[i]<<'-'<<b[j]<<'\n';
        return;
    }
    write(i - 1, j - 1);
    g<<"pastram "<<a[i]<<'\n';
}
int main(){
    f>>(a + 1)>>(b + 1)>>inser>>del>>repl;
    n = strlen(a + 1);
    m = strlen(b + 1);
    for(int i = 1; i <= n; ++i)
        dp[i][0] = i,
        p[i][0] = 1;
    for(int i = 1; i <= m; ++i)
        dp[0][i] = i,
        p[0][i] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            int cost  = repl;
            if(a[i] == b[j])
                cost = 0;
            if(dp[i - 1][j] + del < dp[i][j - 1] + inser && dp[i - 1][j] + del < dp[i - 1][j - 1] + cost){
                dp[i][j] = dp[i - 1][j] + del;
                p[i][j] = 1;
            }
            else
                if(dp[i][j - 1] + inser < dp[i - 1][j] + del && dp[i][j - 1] + inser < dp[i - 1][j - 1] + cost){
                    dp[i][j] = dp[i][j - 1] + inser;
                    p[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i - 1][j - 1] + cost;
                    if(cost)
                        p[i][j] = 3;
                    else
                        p[i][j] = 4;
                }
        }
    g<<dp[n][m]<<'\n';
    write(n, m);
    return 0;
}
