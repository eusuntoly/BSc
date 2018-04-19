#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct nod{
    int grad, id;
} v[100];
vector< pair<int, int> > a;
struct cmp{
    bool operator()(const nod &a, const nod &b)const{
        if(a.grad > b.grad)
            return true;
        return false;
    }
};
bool solve(){
    for(int i = 1; i < n; ++i)
        if(v[i].grad){
            int j = i + v[i].grad, l = i + v[i].grad, d;
            if(j > n || !v[j].grad)
              return false;
            while(v[l].grad == v[l - 1].grad && l - 1  > i)
                --l;
            --l;
            d = j - l;
            while(v[j].grad == v[j + 1].grad)
                ++j;
            for(int k = 1; k <= d; ++k, --j){
                a.push_back( make_pair(v[i].id, v[j].id) );
                --v[j].grad;
            }
            j = l;
            for(int k = 1; k <= v[i].grad - d; ++k, --j){
                a.push_back( make_pair(v[i].id, v[j].id) );
                --v[j].grad;
            }
        }
    return true;
}
int main(){
    freopen("date.in", "r", stdin);
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d ", &v[i].grad);
        v[i].id = i;
    }
    sort(v + 1, v + n + 1, cmp());
    if(!solve())
        printf("Nu se poate.\n");
    else
        for(int i = 0; i < a.size(); ++i)
            printf("%d %d\n", a[i].first, a[i].second);
    return 0;
}
