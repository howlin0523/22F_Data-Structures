#include <iostream>
#include <vector>
#include <cstdlib>
#include "stdlib.h"
#include "lab1.h"
#include "func.cpp"

using namespace std;

int main()
{
    Func F;
    bool flag = F.init();
    if (flag)
    {
        cout << "a+b=";
        F.add();
        cout << "a-b=";
        F.minus();
        cout << "a\'(x)=";
        F.derive();
        cout << "input x:";
        float x=0;
        cin >> x;
        cout << "a(" << x << ")=" << F.calValue(x) << endl;
    }
    cin.get();
    return 0;
}
