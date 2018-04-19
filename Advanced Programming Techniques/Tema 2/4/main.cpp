#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream f("cmap.in");
ofstream g("cmap.out");
const long long INF = 9e18;
vector< pair<long long, long long> > V(100005), X, Y;
long long dist(const pair <long long, long long>& a, const pair <long long, long long>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
long long solve(int left, int right, vector < pair <long long, long long> >& X, vector < pair <long long, long long> >& Y) {
    if(left >= right - 1)
        return INF;
    else
        if(right - left == 2) {
            if(Y[left] > Y[left + 1])
            swap(Y[left], Y[left + 1]);
            return dist(X[left], X[left + 1]);
        }
    int middle = (left + right) / 2;
    long long best = min(solve(left, middle, X, Y), solve(middle, right, X, Y));
    merge(Y.begin() + left, Y.begin() + middle, Y.begin() + middle, Y.begin() + right, V.begin());
    copy(V.begin(), V.begin() + (right - left), Y.begin() + left);
    int sz = 0;
    for(int i = left; i < right; ++i)
        if(abs(Y[i].second - X[middle].first) <= best)
            V[sz++] = Y[i];
    for(int i = 0; i < sz - 1; ++ i) {
        for(int j = i + 1; j < sz && j - i < 8; ++ j)
            best = min(best, dist(V[i], V[j]));
    }
    return best;
}
int main(){
    int n;
    f>>n;
    X.resize(n), Y.resize(n);
    for(int i = 0; i < n; ++i){
        f>>X[i].first>>X[i].second;
    }
    sort(X.begin(), X.end());
    for(int i = 0; i < (int) X.size(); ++i)
        Y[i] = make_pair(X[i].second, X[i].first);
    g<<std::fixed<<std::setprecision(6)<<sqrt(solve(0, X.size(), X, Y))<<'\n';
    f.close();
    g.close();
    return 0;
}
