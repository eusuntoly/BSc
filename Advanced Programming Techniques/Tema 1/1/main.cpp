#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream f("acoperire.in");
ofstream g("acoperire.out");
struct interval {
    int a, b;
}I, v[1005];
struct cmp {
    bool operator()(const interval &x, const interval &y)const{
        if(x.a < y.a)
            return true;
        if(x.a == y.a)
            if(x.b < y.b)
                return true;
        return false;
    }
};
int n;
int main(){
    f>>I.a>>I.b;
    f>>n;
    for (int i = 1; i <= n; ++i)
        f>>v[i].a>>v[i].b;
    sort(v + 1, v + n + 1, cmp());
    if(v[1].a > I.a){
        g<<-1<<'\n';
        return 0;
    }
    vector< pair<int, int> > sol;
    int pivot = I.a, j = 1;
    for (int i = 2; i <= n; ++i) {
        if(v[i].a <= pivot){
            if(v[j].b < v[i].b)
                j = i;
        }
        else{
            if(v[j].b < pivot){
                g<<-1<<'\n';
                return 0;
            }
            sol.push_back( make_pair(v[j].a, v[j].b) );
            pivot = v[j].b;
            j = i;
            if(v[i].a > pivot && pivot != I.b){
                g<<-1<<'\n';
                return 0;
            }
        }
        if(pivot >= I.b)
            break;
    }
    if((sol.size() && sol[sol.size() - 1].second < I.b) || !sol.size()){
        if(v[n].a <= pivot && v[n].b >= I.b)
            sol.push_back( make_pair(v[n].a, v[n].b) );
        else{
            g<<-1<<'\n';
            return 0;
        }
    }
    for (std::vector< pair<int, int> >::iterator it = sol.begin() ; it != sol.end(); ++it)
        g<<(*it).first<<' '<<(*it).second<<'\n';
    if(sol.size())
        g<<sol.size();
    else
        g<<-1;
    return 0;
}
