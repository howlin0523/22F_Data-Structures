/**
 * @file main.cpp
 * @author howlinggggg (howlin0523@mail.ustc.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include "stdlib.h"
#include "lab1.h"
#include "func.cpp"

using namespace std;
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
    Func F;
    bool flag = F.init();
    if (flag)
    {

        cout << "a+b=";
        F.plus();
        cout << "a-b=";
        F.minus();
        cout << "a\'(x)=";
        F.derive();
        cout << "input x:";
        cin.clear();
        cin.ignore();
        float x = 0;
        cin >> x;
        cout << "a(" << x << ")=" << F.calValue(x) << endl;
    }
    cin.get();
    return 0;
}
