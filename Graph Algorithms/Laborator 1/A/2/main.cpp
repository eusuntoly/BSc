#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> v[100];
void read(){
    freopen("graf.in", "r", stdin);
    scanf("%d %d\n", &n, &m);
    int x, y;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void write(){
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < v[i].size(); ++j)
            printf("%d ", v[i][j]);
        printf("\n");
    }
}
int main(){
    read();
    write();
    return 0;
}
