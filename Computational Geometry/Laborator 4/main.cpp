#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct nod{
    double x, y;
}v[5];
const double PI = 3.14159265;
const double eps = 0.000001;
int main(){
    for(int i = 1; i <= 4; ++i)
        cin>>v[i].x>>v[i].y;
    double A2 = acos( ( (v[1].x - v[2].x) * (v[3].x - v[2].x) + (v[1].y - v[2].y) * (v[3].y - v[2].y) ) / sqrt( ((v[1].x - v[2].x) * (v[1].x - v[2].x) + (v[1].y - v[2].y) * (v[1].y - v[2].y)) * ((v[3].x - v[2].x) * (v[3].x - v[2].x) + (v[3].y - v[2].y) * (v[3].y - v[2].y)) ) ) * 180.0 / PI;
    double A4 = acos( ( (v[1].x - v[4].x) * (v[3].x - v[4].x) + (v[1].y - v[4].y) * (v[3].y - v[4].y) ) / sqrt( ((v[1].x - v[4].x) * (v[1].x - v[4].x) + (v[1].y - v[4].y) * (v[1].y - v[4].y)) * ((v[3].x - v[4].x) * (v[3].x - v[4].x) + (v[3].y - v[4].y) * (v[3].y - v[4].y)) ) ) * 180.0 / PI;
    if( abs(A2 + A4 - 180) < eps )
        cout<<"A4 se afla pe cercul circumscris trigunghiului A1A2A3.\n";
    else
        if(A2 + A4 - 180 > 0)
            cout<<"A4 se afla in interiorul cercului circumscris triunghiului A1A2A3.\n";
        else
            cout<<"A4 se afla in exteriorul cercului circumscris triunghiului A1A2A3.\n";
    double s1 = sqrt( (v[2].x - v[1].x) * (v[2].x - v[1].x) + (v[2].y - v[1].y) * (v[2].y - v[1].y) ) + sqrt( (v[4].x - v[3].x) * (v[4].x - v[3].x) + (v[4].y - v[3].y) * (v[4].y - v[3].y) );
    double s2 = sqrt( (v[4].x - v[1].x) * (v[4].x - v[1].x) + (v[4].y - v[1].y) * (v[4].y - v[1].y) ) + sqrt( (v[3].x - v[2].x) * (v[3].x - v[2].x) + (v[3].y - v[2].y) * (v[3].y - v[2].y) );
    if( abs(s1 - s2) < eps )
        cout<<"Patrulaterul A1A2A3A4 este circumscriptibil.\n";
    else
        cout<<"Patrulaterul A1A2A3A4 nu este circumscriptibil.\n";
    return 0;
}
