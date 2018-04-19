#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int v[100][100], dp[100][100], t[100][100],n, m;
int main(){
    f>>n>>m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f>>v[i][j];
    for(int i = n; i > 0; --i)
        for(int j = m; j > 0; --j)
            if(dp[i + 1][j] > dp[i][j + 1]){
                dp[i][j] = dp[i + 1][j] + v[i][j];
                t[i][j] = -1;
            }
            else{
                dp[i][j] = dp[i][j + 1] + v[i][j];
                t[i][j] = 1;
            }
    t[n][m] = 0;
    g<<dp[1][1]<<'\n';
    int i = 1, j = 1;
    while(t[i][j]){
        g<<i<<' '<<j<<'\n';
        if(t[i][j] == -1)
            ++i;
        else
            ++j;
    }
    g<<n<<' '<<m<<'\n';
    return 0;
}
