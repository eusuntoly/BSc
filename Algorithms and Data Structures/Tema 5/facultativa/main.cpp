#include <cstdio>
using namespace std;
long long n, p = 1;
int main(){
    scanf("%lld", &n);
    while(p <= n) p <<= 1;
    printf("Numarul ultimei persoane ramase este: %lld\n", 2 * n + 1 - p);
    return 0;
}
