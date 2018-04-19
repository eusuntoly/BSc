#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{
    double x, y;
}A[5], B[5];
double a[3], b[3], c[3], d;
struct cmp1{
    bool operator()(const nod &a, const nod &b) const {
        if(a.x < b.x)
            return true;
        if(a.x == b.x)
            if(a.y < b.y)
                return true;
        return false;
    }
};
struct cmp2{
    bool operator()(const nod &a, const nod &b) const {
        if(a.y < b.y)
            return true;
        if(a.y == b.y)
            if(a.x < b.x)
                return true;
        return false;
    }
};
int main() {
    for(int i = 1; i <= 4; ++i){
        cin>>A[i].x>>A[i].y;
        B[i].x = A[i].x;
        B[i].y = B[i].y;
    }
    a[1] = A[1].y - A[2].y;
    b[1] = A[2].x - A[1].x;
    c[1] = A[2].x * A[1].y - A[1].x * A[2].y;
    a[2] = A[3].y - A[4].y;
    b[2] = A[4].x - A[3].x;
    c[2] = A[4].x * A[3].y - A[3].x * A[4].y;
    d = a[1] * b[2] - a[2] * b[1];
    if(d){
        double x, y;
        x = (c[1] * b[2] - c[2] * b[1]) / d;
        y = (a[1] * c[2] - a[2] * c[1]) / d;
        if( ( abs(x - A[1].x) + abs(x - A[2].x) == abs(A[1].x - A[2].x) ) && ( abs(y - A[1].y) + abs(y - A[2].y) == abs(A[1].y - A[2].y) ) && ( abs(x - A[3].x) + abs(x - A[4].x) == abs(A[3].x - A[4].x) ) && ( abs(y - A[3].y) + abs(y - A[4].y) == abs(A[3].y - A[4].y) ) )
            cout<<"Punctul de intersectie este: ("<<x<<", "<<y<<")\n";
        else
            cout<<"Intersectia este ultimea vida.\n";
    }
    else{
        if(a[1] * c[2] - a[2] * c[1])
            cout<<"Intersectia este ultimea vida.\n";
        else
            if(b[1] * c[2] - b[2] * c[2])
                cout<<"Intersectia este ultimea vida.\n";
            else{
                sort(A + 1, A + 3, cmp1());
                sort(A + 3, A + 5, cmp1());
                sort(B + 1, B + 3, cmp2());
                sort(B + 3, B + 5, cmp2());
                if(A[2].x < A[3].x || A[1].x > A[4].x)
                    cout<<"Intersectia este ultimea vida.\n";
                else
                    if(A[2].y < A[3].y || A[1].y > A[4].y)
                        cout<<"Intersectia este ultimea vida.\n";
                    else{
                        nod C[2];
                        if(A[2].x >= A[3].x){
                            C[1].x = A[2].x;
                            C[1].y = A[2].y;
                            C[2].x = A[3].x;
                            C[2].y = A[3].y;
                        }
                        else
                            if(A[1].x <= A[4].x){
                                C[1].x = A[1].x;
                                C[1].y = A[1].y;
                                C[2].x = A[4].x;
                                C[2].y = A[4].y;
                            }
                        cout<<"Intersectia este segmentul: ("<<C[1].x<<", "<<C[1].y<<") ("<<C[2].x<<", "<<C[2].y<<")\n";
                    }
            }
    }
    return 0;
}
