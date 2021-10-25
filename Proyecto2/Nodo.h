#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo{
    private:
        int num;
        Nodo* up;
        Nodo* down;
        Nodo* right;
        Nodo* left;
 
    public:
        Nodo(int);
        ~Nodo();
        Nodo* getLeft();
        Nodo* getRight();
        Nodo* getUp();
        Nodo* getDown();
        void setLeft(Nodo*);
        void setRight(Nodo*);
        void setUp(Nodo*);
        void setDown(Nodo*);
        int getNum();
        void setNum(int);
};

#endif