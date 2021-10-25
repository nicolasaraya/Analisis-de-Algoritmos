#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include "Random.h"
#include <vector>
#include <map>

using namespace std;

typedef struct{
    int peso;
    Nodo* nodo1;
    Nodo* nodo2;  
}Edge;

class Grafo{
    private:
        int n;
        int m;
        bool pesos;
        int a;
        int b;
        map<pair<Nodo*,Nodo*>, Edge> edges;
        vector<vector<Nodo*>> graph;
    public:
        Grafo(int, int, bool, int, int);
        ~Grafo();
        Nodo* getVertice(int, int);
        void setVertice(int, int, Nodo*);
        int getEdge(Nodo*, Nodo*);

        void setEdge(Nodo*, Nodo*, int);
        void print();
        int totalVertice();
        vector <Edge> totalEdges();
       
};

#endif
