#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
ofstream g("date.out");
int n, k, dp[100][100];
void write(int i, int s){
    if(i == 0)
        return;
    write(i - 1, s - dp[i][s]);
    g<<dp[i][s]<<' ';
}
int main(){
    FILE *f = fopen("date.in", "r");
    fscanf(f, "%d %d\n", &n, &k);
    char s[200];
    int x, offset;
    fgets(s, 200, f);
    char *in = s;
    while(sscanf(in, " %d%n", &x, &offset) == 1){
        in += offset;
        dp[1][x] = x;
    }
    for(int i = 2; i <= n; ++i){
        char s[200];
        int x, offset;
        vector<int> v;
        fgets(s, 200, f);
        char *in = s;
        while(sscanf(in, "%d%n", &x, &offset) == 1){
            in += offset;
            v.push_back(x);
        }
        for(int j = 1; j <= k; ++j)
            if(dp[i - 1][j])
                for(int l = 0; l < v.size(); ++l)
                    dp[i][j + v[l]] = v[l];
    }
    if(!dp[n][k])
        g<<"0\n";
    else
        write(n, k);
    return 0;
}
