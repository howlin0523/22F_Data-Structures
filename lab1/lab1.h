/**
 * @file lab1.h
 * @author howlinggggg (howlin0523@mail.ustc.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LAB
#define LAB

#include <iostream>
#include <vector>

using namespace std;

typedef struct LNode
{
    float coef;/**<coefficient*/
    float expn;/**<exponent*/
    struct LNode *next;
} LNode, *LinkList;


class Func
{
    
private:
    vector<LNode *> head;

public:
/**
 * @brief create linklist 0-5 to store poly
 * 
 */
    Func()
    {
        for (int i = 0; i < 6; i++)
        {
            LNode *headx = new (LNode);
            headx->coef = 0;
            headx->next = NULL;
            head.push_back(headx);
        }
    }
    /**
     * @brief initial poly
     * input poly a, poly b. then save in linklist[0] and linklist[1]  
     * @return true 
     * @return false 
     */
    bool init();
    /**
     * @brief insert node to nth linklist
     * 
     * @param node 
     * @param n 
     */
    void insert(LNode *node, int n);
    /**
     * @brief print nth linklist 
     * 
     * @param n 
     */
    void printPoly(int n);
    /**
     * @brief poly a plus poly b
     * 
     */
    void plus();
    /**
     * @brief poly a minus poly b
     * 
     */
    void minus();
    /**
     * @brief caculate the value of poly a in x
     * 
     * @param x 
     * @return a(x)
     */
    float calValue(float x);
    /**
     * @brief a'
     * 
     */
    void derive();
};

#endif