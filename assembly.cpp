#include <iostream>
using namespace std;


int Fastest_Way(int a[][4], int t[][4], int e[2], int x[2], int n)
{
    int f1[4], f2[4], f;
    string w1 = "e1 -> a11",  w2 = "e2 -> a21";
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];
    for (int j = 1; j < n; j++){
        if ((f1[j - 1] + a[0][j]) <= (f2[j - 1] + t[1][j - 1] + a[0][j])){
            f1[j] = f1[j - 1] + a[0][j];
            w1 = w1 + " -> a1" + to_string(j+1);
        }
        else{
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
            w1 = w2 + " -> a1" + to_string(j+1);
        }
        if ((f2[j - 1] + a[1][j]) <= (f1[j - 1] + t[0][j - 1] + a[1][j])){
            f2[j] = f2[j - 1] + a[1][j];
            w2 = w2 + " -> a2" + to_string(j+1);
        }
        else{
            f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
            w2 = w1 + " -> a2" + to_string(j+1);
        }  
    }
    if ((f1[n-1] + x[0]) <= (f2[n-1] + x[1])){
        f = f1[n-1] + x[0];
        cout <<"Ruta: " << w1 + " -> x1"<< endl;
    }
    else{
        f = f2[n-1] + x[1];
        cout << "Ruta: " << w2 + " -> x2"<< endl;
    }
    cout << "Cantidad pasos: ";
    return f;
}

int main(int argc, char const *argv[])
{
    int a[][4] = {{4,5,3,2}, {2,10,1,4}};
    int t[][4] = {{0, 7,4,5}, {0 , 9, 2 , 8}};                
    int e[2] = {10, 12};
    int x[2] = {18, 7};

    cout << Fastest_Way(a, t, e, x, 4) << endl;

    return 0;
}