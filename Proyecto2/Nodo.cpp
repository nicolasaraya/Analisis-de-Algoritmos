#include "Nodo.h"

using namespace std;

Nodo::Nodo(int i){
    num = i;
    up = NULL;
    down = NULL;
    right = NULL;
    left = NULL;
}
Nodo::~Nodo(){
}
Nodo* Nodo::getUp(){
    return up;
}
Nodo* Nodo::getDown(){    
    return down;
}
Nodo* Nodo::getRight(){
    return right;
}
Nodo* Nodo::getLeft(){
    return left;
}
void Nodo::setRight(Nodo* n){
    right=n;
}
void Nodo::setLeft(Nodo* n){
    left=n;
}
void Nodo::setUp(Nodo* n){
    up=n;
}
void Nodo::setDown(Nodo* n){
    down=n;
}
int Nodo::getNum(){
    return num;
}
void Nodo::setNum(int n){
    num = n;
}

