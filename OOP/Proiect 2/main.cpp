#include <iostream>
using namespace std;
class Polinom;
class Polinom_ireductibil;
class Monom{
    int grad;
    float coef;
    public:
        Monom(int g = 0, float c = 0){grad = g; coef = c;}
        Monom(const Monom &ob){grad = ob.grad; coef = ob.coef;}
        ~Monom(){grad = coef = 0;}
        friend class Polinom;
        friend class Polinom_ireductibil;
        friend istream &operator>>(istream &stream, Monom &ob){cin>>ob.grad>>ob.coef; return stream;}
        friend ostream &operator<<(ostream &stream, Monom ob){cout<<ob.coef<<"*X^"<<ob.grad; return stream;}
        void operator=(Monom &ob){grad = ob.grad; coef = ob.coef;}
};
class Polinom{
    int nr_monoame;
    Monom *m;
    protected:
        Monom* address(){return m;}
        int size(){return nr_monoame;}
    public:
        Polinom(){nr_monoame = 0;}
        Polinom(int a, float b){nr_monoame = 1; m = new Monom[1]; m[0].grad = a; m[0].coef = b;}
        Polinom(const Polinom &ob){
            nr_monoame = ob.nr_monoame;
            m = new Monom[nr_monoame];
            for(int i = 0; i < ob.nr_monoame; ++i)
                m[i] = ob.m[i];
        }
        ~Polinom(){delete[] m;};
        friend istream &operator>>(istream &stream, Polinom &ob){
            cin>>ob.nr_monoame;
            ob.m = new Monom[ob.nr_monoame];
            for(int i = 0; i < ob.nr_monoame; ++i)
                cin>>ob.m[i];
            return stream;
        }
        friend ostream &operator<<(ostream &stream, Polinom ob){
            cout<<ob.m[0];
            for(int i = 1; i < ob.nr_monoame; ++i)
                cout<<'+'<<ob.m[i];
            return stream;
        }
        void operator=(Polinom &ob){
            nr_monoame = ob.nr_monoame;
            m = new Monom[nr_monoame];
            for(int i = 0; i < ob.nr_monoame; ++i)
                m[i] = ob.m[i];
        }
        virtual bool is_ired(){};
};
class Polinom_ireductibil: public Polinom{
    bool red_ired;
    bool is_ired(){
        Monom *a;
        a = address();
        int l = size();
        bool prim[a[0].grad] = {0};
        if(a[0].grad)
            return true;
        for(int i = 2; i <= a[0].grad; ++i)
            if(!prim[i]){
                for(int j = 2 * i; j <= a[0].grad; j += i)
                    prim[j] = true;
            }
        for(int j = 2; j <= a[0].grad; ++j)
            if(!prim[j]){
                bool ok = true;
                for(int i = 0; i < l - 1; ++i)
                    if((int)a[i].coef % j)
                        ok = false;
                if(ok)
                    if((int)a[0].coef % (j * j) && (int)a[l].coef % j)
                        return true;
            }
        return false;
    }
    public:
        Polinom_ireductibil(): Polinom(){red_ired = false;}
        Polinom_ireductibil(int a, float b): Polinom(a, b){red_ired = false;}
        Polinom_ireductibil(const Polinom_ireductibil &ob): Polinom(ob){red_ired = ob.red_ired;}
        ~Polinom_ireductibil(){};
        void set_ired(){red_ired = is_ired();}
        //am considerat ca Polinom_ireductibil sa utilizeze >>, << si = de la Polinom, fiindca verificarea se face ulterior prin apel de functie
};
int main(){
    int n;
    cin>>n;
    Polinom *v;
    v = new Polinom[n];
    for(int i = 0; i < n; ++i)
        cin>>v[i];
    for(int i = 0; i < n; ++i)
        cout<<v[i]<<'\n';
    return 0;
}
