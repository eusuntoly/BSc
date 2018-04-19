#include <fstream>
#include <iostream>
#include <list>
using namespace std;
ifstream f("date.in");
list<int> v[100];
int n, m;
int binary_search(int val) {
    int i, cnt;
    for (cnt = 1; cnt < m; cnt <<= 1);
    for (i = m; cnt; cnt >>= 1)
        if (i - cnt >= 0 && v[i - cnt].back() >= val)
           i -= cnt;
    return i;
}
int main() {
    int x;
    f>>n>>x;
    v[0].push_back(x);
    m = 1;
    for(int i = 2; i <= n; ++i) {
        f>>x;
        int p = binary_search(x);
        if(p >= m && v[p].back() > x)
            v[m++].push_back(x);
        else
            v[p].push_back(x);
    }
    for(int i = 0; i <= m; ++i) {
        for (std::list<int>::iterator it = v[i].begin(); it != v[i].end(); ++it)
            cout<<*it<<' ';
        cout<<'\n';
    }
    return 0;
}
