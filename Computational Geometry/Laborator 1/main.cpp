#include <iostream>
using namespace std;
struct punct{
    double x, y, z;
}A1, A2, A3;
int main(){
    cin>>A1.x>>A1.y>>A1.z;
    cin>>A2.x>>A2.y>>A2.z;
    cin>>A3.x>>A3.y>>A3.z;
    if(A1.x == A2.x && A1.y == A2.y && A1.z == A2.z)
        cout<<"Punctele sunt coliniare: A1 = 1 * A2 + 0 * A3"<<endl;
    else{
        bool ok = true;
        if(A2.x - A1.x){
            double a = (A3.x - A1.x) / (A2.x - A1.x);
            if( (A3.y - A1.y == a * (A2.y - A1.y)) && (A3.z - A1.z == a * (A2.z - A1.z)) )
                ok = false,
                cout<<"Punctele sunt coliniare: A3 = "<<(1 - a)<<" * A1 + "<<a<<" * A2"<<endl;
        }
        if(A2.y - A1.y && ok){
            double a = (A3.y - A1.y) / (A2.y - A1.y);
            if( (A3.x - A1.x == a * (A2.x - A1.x)) && (A3.z - A1.z == a * (A2.z - A1.z)) )
                ok = false,
                cout<<"Punctele sunt coliniare: A3 = "<<(1 - a)<<" * A1 + "<<a<<" * A2"<<endl;
        }
        if(A2.z - A1.z && ok){
            double a = (A3.z - A1.z) / (A2.z - A1.z);
            if( (A3.y - A1.y == a * (A2.y - A1.y)) && (A3.x - A1.x == a * (A2.x - A1.x)) )
                ok = false,
                cout<<"Punctele sunt coliniare: A3 = "<<(1 - a)<<" * A1 + "<<a<<" * A2"<<endl;
        }
        if(ok)
            cout<<"Punctele nu sunt coliniare."<<endl;
    }
    return 0;
}
