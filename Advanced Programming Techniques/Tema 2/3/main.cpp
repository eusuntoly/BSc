#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
vector<int> a;
vector<int> b;
double solve(vector<int>& a, vector<int>& b){
    int m = a.size(), n = b.size();
    if (m > n) { // to ensure m<=n
        vector<int> aux1 = a;
        a = b;
        b = aux1;
        int aux2 = m;
        m = n;
        n = aux2;
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if(i < iMax && b[j - 1] > a[i]){
            iMin = i + 1; // i is too small
        }
        else
            if(i > iMin && a[i - 1] > b[j])
                iMax = i - 1; // i is too big
            else{ // i is perfect
                int maxLeft = 0;
                if (!i)
                    maxLeft = b[j - 1];
                else
                    if(!j)
                        maxLeft = a[i - 1];
                    else
                        maxLeft = max(a[i - 1], b[j - 1]);
                if((m + n) % 2)
                    return maxLeft;
                int minRight = 0;
                if(i == m)
                    minRight = b[j];
                else
                    if(j == n)
                        minRight = a[i];
                    else
                        minRight = min(b[j], a[i]);
                return (maxLeft + minRight) / 2.0;
            }
    }
    return 0;
}
int main(){
    int n, m;
    f>>n;
    for(int i = 0; i < n; ++i){
        int x;
        f>>x;
        a.push_back(x);
    }
    f>>m;
    for(int i = 0; i < m; ++i){
        int x;
        f>>x;
        b.push_back(x);
    }
cout<<1;
    g<<solve(a, b)<<'\n';
    return 0;
}
