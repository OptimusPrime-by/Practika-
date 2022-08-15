#include "number_theory.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    int m = 112, p = 1553, g = 17, x = 14, k = 117, rk = 0, s = 0, r = 0;
    int y = DegreeRemainder1(g, x, p);
    r = DegreeRemainder1(g, k, p);
    if (NODEuclidean(k, p - 1) == 1) {
        rk = InverseBezu(k, p - 1);
    }
    else {
        cout << "Nod(k,p-1)≠1";
        return -1;
    }
    if (m - x * r < 0) {
        int H = m - x * r;
        int j = -H / (p - 1) + 1;
        int h = j * (p - 1) + H;
        s = (rk * h) % (p - 1);
    }
    else s = (rk * m - x * r) % (p - 1);
    cout << "Параметр y = " << y << endl << "Подпись (r,s) >> " << "(" << r << "," << s << ")" << endl;

    int remainderY = DegreeRemainder1(y, r, p);
    int remainderR = DegreeRemainder1(r, s, p);
    int remainderG = DegreeRemainder1(g, m, p);

    if (remainderG == (remainderY * remainderR) % p)cout << "Подпись действительна!";
    else cout << "Подпись недействительна!";
    return 0;
}