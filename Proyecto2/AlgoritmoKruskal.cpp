
#include "AlgoritmoKruskal.h"


bool OrdenarPeso(Edge a, Edge b){
    return a.peso < b.peso;
    
}
void AlgoritmoKruskal(Grafo* grafo){
    UnionFind UF;
    int v = grafo->totalVertice();
    vector <Edge> aristas = grafo->totalEdges();
    vector <Edge> not_ans;
    for (int i = 0; i < v; ++i){
        UF.MakeSet(i);
    }

    sort(aristas.begin(), aristas.end(), OrdenarPeso);
    int min_path = 0;
    for (int i = 0; i < aristas.size(); ++i){
        if(UF.Find(aristas[i].nodo1->getNum()) != UF.Find(aristas[i].nodo2->getNum())){
            min_path += aristas[i].peso;
            UF.Union(aristas[i].nodo1->getNum(),aristas[i].nodo2->getNum());
        }
        else not_ans.push_back(aristas[i]);
    }
    for (int i = 0; i <  not_ans.size(); ++i){
        grafo->setEdge(not_ans[i].nodo1, not_ans[i].nodo2, -1);
    }
    grafo->print();
    cout << "Valor total del camino: " << min_path << endl;
    cout << endl;
    return;
 }



