#include <iostream>
#include <vector>
#include <deque>
#include <graphics.h>
using namespace std;
int n;
struct vertex{
    double x, y;
};
bool orientationTest(vertex A, vertex B, vertex C){
    return (B.x * C.y) + (A.x * B.y) + (C.x * A.y) - (B.x * A.y) - (A.x * C.y) - (C.x * B.y) > 0;
}
int main(){
    cout<<"Introduceti numarul de varfuri ale poligonului.\n";
    cin>>n;
    vector<vertex> vertices(n + 1);
    cout<<"Introduceti in ordinea adiacentei coordonatele varfurilor poligonului.\n";
    for(int i = 0; i < n; ++i)
        cin>>vertices[i].x>>vertices[i].y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    setcolor(BLUE);
    for(int i = 0; i < n - 1; ++i)
        line(300 + vertices[i].x * 50, 300 + vertices[i].y * 50, 300 + vertices[i + 1].x * 50, 300 + vertices[i + 1].y * 50);
    line(300 + vertices[n - 1].x * 50, 300 + vertices[n - 1].y * 50, 300 + vertices[0].x * 50, 300 + vertices[0].y * 50);
    if(n < 2 || (n == 2 && (vertices[0].x != vertices[1].x || vertices[0].y != vertices[1].y) ) )
        cout<<"Date de intrare incorecte\n";
    else
        if(n == 2){
            cout<<"Acoperirea convexa este:\n";
            cout<<'('<<vertices[0].x<<", "<<vertices[0].y<<")\n";
        }
        else
            if(n == 3 && vertices[0].x == vertices[2].x && vertices[0].y == vertices[2].y){
                cout<<"Acoperirea convexa este:\n";
                for(int i = 0; i < 2; ++i)
                    cout<<'('<<vertices[i].x<<", "<<vertices[i].y<<")\n";
            }
            else{
                int pivot = 0;
                for(int i = 1; i < n; ++i)
                    if(vertices[i].x < vertices[pivot].x)
                        pivot = i;
                vector<vertex> tmp;
                for(int i = pivot; i < n; ++i)
                    tmp.push_back(vertices[i]);
                for(int i = 0; i < pivot; ++i)
                    tmp.push_back(vertices[i]);
                if(orientationTest(tmp[n - 1], tmp[0], tmp[1]))
                    for(int i = 0; i < n; ++i)
                        vertices[i] = tmp[i];
                else{
                    vertices.clear();
                    vertices.push_back(tmp[0]);
                    for(int i = n - 1; i > 0; --i)
                        vertices.push_back(tmp[i]);
                }
                cout<<"Acoperirea convexa este:\n";
                vertices[n].x = vertices[0].x;
                vertices[n].y = vertices[0].y;
                ++n;
                deque<vertex> convexCover;
                convexCover.push_back(vertices[0]);
                convexCover.push_back(vertices[1]);
                for(int i = 2; i < n; ++i){
                    while(convexCover.size() >= 2){
                        int sz = convexCover.size();
                        if(!orientationTest(convexCover[sz - 2], convexCover[sz - 1], vertices[i]))
                            convexCover.pop_back();
                        else
                            break;
                    }
                    convexCover.push_back(vertices[i]);
                }
                for(int i = 0; i < convexCover.size() - 1; ++i)
                    cout<<'('<<convexCover[i].x<<", "<<convexCover[i].y<<")\n";
                if(convexCover.size() == n)
                    cout<<"Poligonul este convex.\n";
                else
                    cout<<"Poligonul nu este convex.\n";
                setcolor(RED);
                delay(5000);
                for(int i = 0; i < convexCover.size() - 1; ++i){
                    line(300 + convexCover[i].x * 50, 300 + convexCover[i].y * 50, 300 + convexCover[i + 1].x * 50, 300 + convexCover[i + 1].y * 50);
                    delay(1000);
                }
                getch();
                closegraph();
            }
    return 0;
}
