#include <iostream>
#include <vector>
#include <math.h>
#include "lab1.h"

using namespace std;

bool Func::init()
{
    // input poly a
    cout << "input poly a:";
    float t;
    vector<float> temp_a;
    while (cin >> t)
    {
        temp_a.push_back(t);
    }
    if (temp_a.size() % 2 != 0)
    {
        cout << "error" << endl;
        return false;
    }
    for (size_t i = 0; i < temp_a.size(); i += 2)
    {
        LNode *node = new (LNode);
        node->coef = temp_a[i];
        node->expn = temp_a[i + 1];
        insert(node, 1);
    }
    cin.clear();
    cin.ignore();

    // input poly b
    cout << "input poly b:";
    vector<float> temp_b;
    while (cin >> t)
    {
        temp_b.push_back(t);
    }
    if (temp_b.size() % 2 != 0)
    {
        cout << "input error" << endl;
        return false;
    }
    for (size_t i = 0; i < temp_b.size(); i += 2)
    {
        LNode *node = new (LNode);
        node->coef = temp_b[i];
        node->expn = temp_b[i + 1];
        insert(node, 2);
    }
    printPoly(1);
    printPoly(2);
    return true;
}

void Func::insert(LNode *node, int n)
{
    LNode *t = head[n - 1];
    while (t->next)
    {
        if (node->expn > t->next->expn)
        {
            node->next = t->next;
            t->next = node;
            ++head[n - 1]->coef;
            return;
        }
        else if (node->expn == t->next->expn)
        {
            t->next->coef += node->coef;
            return;
        }
        t = t->next;
    }
    if (!t->next)
    {
        node->next = t->next;
        t->next = node;
    }
    ++head[n - 1]->coef;
}

void Func::printPoly(int n)
{
    LNode *t = head[n - 1];
    LNode *t1 = head[n - 1];
    cout << head[n - 1]->coef;
    while (t->next)
    {
        cout << "," << t->next->coef << "," << t->next->expn;
        t = t->next;
    }
    cout << endl;

    int temp = 0;

    cout << head[n - 1]->coef << ":";
    while (t1->next)
    {
        if (temp != 0 && t1->next->coef > 0)
            cout << "+";
        if (t1->next->coef == -1)
            cout << "-";
        if (t1->next->coef != 1 && t1->next->coef != -1)
            cout << t1->next->coef;
        else if ((t1->next->coef == 1 || t1->next->coef == -1) && t1->next->expn == 0)
            cout << 1;
        if (t1->next->expn != 0 && t1->next->expn != 1)
            cout << "x^" << t1->next->expn;
        else if (t1->next->expn == 1)
            cout << "x";
        t1 = t1->next;
        ++temp;
    }
    cout << endl;
}

void Func::add()
{
    LNode *t1 = head[0];
    LNode *t2 = head[1];
    while (t1->next && t2->next)
    {
        if (t1->next->expn == t2->next->expn)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef + t2->next->coef;
            node->expn = t1->next->expn;
            if (node->coef != 0)
                insert(node, 3);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->next->expn > t2->next->expn)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef;
            node->expn = t1->next->expn;
            insert(node, 3);
            t1 = t1->next;
        }
        else
        {
            LNode *node = new (LNode);
            node->coef = t2->next->coef;
            node->expn = t2->next->expn;
            insert(node, 3);
            t2 = t2->next;
        }
    }
    if (!t1->next)
    {
        while (t2->next)
        {
            LNode *node = new (LNode);
            node->coef = t2->next->coef;
            node->expn = t2->next->expn;
            insert(node, 3);
            t2 = t2->next;
        }
    }
    else if (!t2->next)
    {
        while (t1->next)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef;
            node->expn = t1->next->expn;
            insert(node, 3);
            t1 = t1->next;
        }
    }
    printPoly(3);
}
void Func::minus()
{
    LNode *t1 = head[0];
    LNode *t2 = head[1];
    while (t1->next && t2->next)
    {
        if (t1->next->expn == t2->next->expn)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef - t2->next->coef;
            node->expn = t1->next->expn;
            if (node->coef != 0)
                insert(node, 4);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->next->expn > t2->next->expn)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef;
            node->expn = t1->next->expn;
            insert(node, 4);
            t1 = t1->next;
        }
        else
        {
            LNode *node = new (LNode);
            node->coef = -1 * t2->next->coef;
            node->expn = t2->next->expn;
            insert(node, 4);
            t2 = t2->next;
        }
    }
    if (!t1->next)
    {
        while (t2->next)
        {
            LNode *node = new (LNode);
            node->coef = -1 * t2->next->coef;
            node->expn = t2->next->expn;
            insert(node, 4);
            t2 = t2->next;
        }
    }
    else if (!t2->next)
    {
        while (t1->next)
        {
            LNode *node = new (LNode);
            node->coef = t1->next->coef;
            node->expn = t1->next->expn;
            insert(node, 4);
            t1 = t1->next;
        }
    }
    printPoly(4);
}
float Func::calValue(float x)
{
    float sum = 0;
    LNode *t = head[0];
    while (t->next)
    {
        if ((x == 0 && t->next->expn == -1) || (x < 0 && t->next->expn > 0 && t->next->expn < 1))
        {
            cout << "Calculation error!" << endl;
            return INT_MIN;
        }
        sum += t->next->coef * pow(x, t->next->expn);
        t = t->next;
    }
    return sum;
}
void Func::derive()
{
    LNode *t = head[0];

    while (t->next)
    {
        LNode *t2 = new (LNode);
        if (t->next->expn != 0)
        {
            t2->coef = t->next->coef * t->next->expn;
            t2->expn = t->next->expn - 1;
            insert(t2, 5);
        }
        t = t->next;
    }
    printPoly(5);
}
