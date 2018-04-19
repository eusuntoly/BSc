#include <iostream>
#include <cstring>
using namespace std;
class Locuinta{
    protected:
        char *nume;
        int suprafata, discount;
    public:
        Locuinta(){suprafata = 0; discount = 0;};
        Locuinta(char *a, int b, int c){
            try{
                nume = new char[strlen(a) + 1];
                strcpy(nume, a);
                suprafata = b;
                discount = c;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        Locuinta(const Locuinta &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        ~Locuinta(){delete[] nume;};
        friend istream &operator>>(istream &stream, Locuinta &ob){
            char s[30];
            cin>>s;
            try{
                ob.nume = new char[strlen(s) + 1];
                strcpy(ob.nume, s);
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            cin>>ob.suprafata>>ob.discount;
            return stream;
        }
        virtual ostream &operator<<(ostream &stream){
            cout<<nume<<' '<<suprafata<<' '<<discount<<"%\n";
            return stream;
        };
        void operator=(Locuinta &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
};
class Apartament: public Locuinta{
    int etaj;
    static int nr;
    public:
        Apartament(): Locuinta(){etaj = 0; ++nr;}
        Apartament(char *a, int b, int c, int d): Locuinta(a, b, c), etaj(d){++nr;}
        Apartament(const Apartament &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
                etaj = ob.etaj;
                ++nr;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        ~Apartament(){--nr;};
        friend istream &operator>>(istream &stream, Apartament &ob){
            char s[30];
            cin>>s;
            try{
                ob.nume = new char[strlen(s) + 1];
                strcpy(ob.nume, s);
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            cin>>ob.suprafata>>ob.discount>>ob.etaj;
            ++nr;
            return stream;
        }
        friend ostream &operator<<(ostream &stream, Apartament ob){
            cout<<ob.nume<<' '<<ob.suprafata<<' '<<ob.etaj<<' '<<ob.discount<<"%\n";
            return stream;
        }
        void operator=(Apartament &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
                etaj = ob.etaj;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        static int nr_Apartamente(){return nr;}
        float chirie(){return suprafata * 5 *(100 - discount)/100;}
};
int Apartament::nr = 0;
class Casa: public Locuinta{
    int curte, etaje, *v;
    static int nr;
    public:
        Casa(): Locuinta(){curte = 0; etaje = 1; ++nr;};
        Casa(char *a, int b, int c, int d, int e, int *w): Locuinta(a, b, c), curte(d), etaje(e){
            try{
                v = new int[etaje];
                for(int i = 0; i < etaje; ++i)
                    v[i] = w[i];
                ++nr;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        Casa(const Casa &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
                etaje = ob.etaje;
                curte = ob.curte;
                v = new int[etaje];
                for(int i = 0; i < etaje; ++i)
                    v[i] = ob.v[i];
                ++nr;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        ~Casa(){delete[] v; --nr;};
        friend istream &operator>>(istream &stream, Casa &ob){
            char s[30];
            cin>>s;
            try{
                ob.nume = new char[strlen(s) + 1];
                strcpy(ob.nume, s);
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            cin>>ob.suprafata>>ob.discount>>ob.curte>>ob.etaje;
            try{
                ob.v = new int[ob.etaje];
                for(int i = 0; i < ob.etaje; ++i)
                    cin>>ob.v[i];
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            ++nr;
            return stream;
        }
        friend ostream &operator<<(ostream &stream, Casa ob){
            cout<<ob.nume<<' '<<ob.suprafata<<' '<<ob.etaje<<' ';
            for(int i = 0; i < ob.etaje; ++i)
                cout<<ob.v[i]<<' ';
            cout<<ob.discount<<"%\n";
            return stream;
        }
        void operator=(Casa &ob){
            try{
                nume = new char[strlen(ob.nume) + 1];
                strcpy(nume, ob.nume);
                suprafata = ob.suprafata;
                discount = ob.discount;
                etaje = ob.etaje;
                curte = ob.curte;
                v = new int[etaje];
                for(int i = 0; i < etaje; ++i)
                    v[i] = ob.v[i];
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
        }
        static int nr_Case(){return nr;}
        float chirie(){
            float sum = suprafata;
            for(int i = 0; i < etaje; ++i)
                sum += v[i] * 4;
            sum = sum * (100 - discount) / 100;
            sum += curte * 6;
            return sum;
        }
};
int Casa::nr = 0;
template <class T> class Gestiune{
    Locuinta *v[100];
    static int nr;
    float *chirie[100];
    public:
        Gestiune(){nr  = 0;}
        ~Gestiune(){delete[] *v; delete[] *chirie;}
        Gestiune &operator+=(const T &ob){
            try{
                v[nr] = new T;
                v[nr] = ob;
                chirie[nr] = new float;
                chirie[nr] = ob.chirie();
                ++nr;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            return *this;
        }
};
template<class T> int Gestiune<T>::nr = 0;
template <> class Gestiune <char*>{
    char *v[100];
    int nr;
    public:
        Gestiune(){nr = 0;}
        ~Gestiune(){delete[] *v;}
        Gestiune &operator+=(const char *s){
            try{
                v[nr] = new char[strlen(s) + 1];
                strcpy(v[nr], s);
                ++nr;
            }
            catch (std::bad_alloc &ba){
                std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
            }
            return *this;
        }
};
int main(){
    Locuinta *b1 = new Apartament;
    Apartament *d = dynamic_cast<Apartament*>(b1);
    Locuinta *b2 = static_cast<Locuinta*>(d);
    int n1, n2;
    cin>>n1;
    cin>>n2;
    Locuinta *v[100];
    for(int i = 0; i < n1; ++i){
        try{
            v[i] = new Apartament;
        }
        catch(std::bad_alloc &ba){
            std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
        }
        cin>>*(Apartament*)v[i];
    }
    for(int i = n1; i < n1 + n2; ++i){
        try{
            v[i] = new Casa;
        }
        catch(std::bad_alloc &ba){
            std::cerr<<"bad_alloc caught: "<<ba.what()<<'\n';
        }
        cin>>*(Casa*)v[i];
    }
    for(int i = 0; i < n1; ++i)
        *v[i]<<cout;
    for(int i = n1; i < n1 + n2; ++i)
        cout<<*(Casa*)v[i];
    return 0;
}
