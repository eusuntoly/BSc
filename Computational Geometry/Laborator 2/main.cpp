#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct point {
    int x, y;
}v[5];
int n = 4;
struct cmp{
    bool operator()(const point &a, const point &b) const {
        if(a.x < b.x)
            return true;
        if(a.x == b.x)
            if(a.y < b.y)
                return true;
        return false;
    }
};
float det(point a, point b, point c){
    return (b.x * c.y) + (a.x * b.y) + (a.y * c.x) - (a.y * b.x) - (a.x * c.y) - (b.y * c.x);
}
int main() {
    for(int i = 1; i <= n; ++i)
        cin>>v[i].x>>v[i].y;
    sort(v + 1, v + n + 1, cmp());
    for(int i = 1; i <= n; ++i)
        cout<<v[i].x<< ' '<<v[i].y<<'\n';
    queue<point> L1;
    queue<point> L2;
    if(det(v[1], v[2], v[3]) <= 0){
        if(det(v[1], v[3], v[4]) > 0){
            L1.push(v[1]);
            L1.push(v[4]);
            L2.push(v[2]);
            L2.push(v[3]);
        }
        else{
            L1.push(v[1]);
            L1.push(v[2]);
            L1.push(v[4]);
            L2.push(v[3]);
        }
    }
    else
        if(det(v[3], v[4], v[1]) > 0){
            if(det(v[3], v[1], v[2]) <= 0){
                L1.push(v[3]);
                L1.push(v[2]);
                L2.push(v[1]);
                L2.push(v[4]);
            }
            else{
                L1.push(v[1]);
                L1.push(v[3]);
                L1.push(v[2]);
                L2.push(v[4]);
            }
    }
    else{
        L1.push(v[1]);
        L1.push(v[3]);
        L2.push(v[2]);
        L2.push(v[4]);
    }
    cout<<"L1:\n";
    while(!L1.empty()){
        point p = L1.front();
        L1.pop();
        cout<<"("<<p.x<<", "<<p.y<<")\n";
    }
    cout<<"L2:\n";
    while(!L2.empty()){
        point p = L2.front();
        L2.pop();
        cout<<"("<<p.x<<", "<<p.y<<")\n";
    }
    return 0;
}
