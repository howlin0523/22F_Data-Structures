#ifndef LAB
#define LAB

#include <iostream>
#include <vector>

using namespace std;

typedef struct LNode
{
    float coef;
    float expn;
    struct LNode *next;
} LNode, *LinkList;

class Func
{
private:
    vector<LNode *> head;

public:
    Func()
    {
        for (int i = 0; i < 6; ++i)
        {
            LNode *headx = new (LNode);
            headx->coef = 0;
            headx->next = NULL;
            head.push_back(headx);
        }
    }
    bool init();
    void insert(LNode *node, int n);
    void printPoly(int n);
    void add();
    void minus();
    float calValue(float x);
    void derive();
};

#endif