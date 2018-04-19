#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue<int> a;
queue< pair<int, int> > b;
vector< pair<int, int> > sol;
int n;
bool solve(){
    while(!a.empty()){
        if(!b.empty()){
            sol.push_back( make_pair(a.front(), b.front().second));
            --b.front().first;
            a.pop();
            if(b.front().first == 1){
                a.push(b.front().second);
                b.pop();
            }
        }
        else{
            if(a.size() % 2)
                return false;
            while(!a.empty()){
                int x = a.front();
                a.pop();
                int y = a.front();
                a.pop();
                sol.push_back( make_pair(x, y) );
            }
        }
     }
     return true;
}
int main(){
    freopen("date.in", "r", stdin);
    scanf("%d ", &n);
    int s = 0;
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d ", &x);
        s += x;
        if(x == 1)
            a.push(i);
        else
            b.push( make_pair(x, i) );
    }
    if(s != 2 * (n - 1))
        printf("Imposibil.\n");
    else
        if(solve())
            for(int i = 0; i < sol.size(); ++i)
                printf("%d %d\n", sol[i].first, sol[i].second);
        else
            printf("Imposibil.\n");
    return 0;
}
