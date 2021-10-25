#include "Maze.h"

bool Ciclo(Grafo* grafo){
    UnionFind UF;
    int v = grafo->totalVertice();
    vector <Edge> aristas = grafo->totalEdges();
    for (int i = 0; i < v; ++i){
        UF.MakeSet(i);
    }   
    vector <Edge> aristas_nuevas;
    for (int i = 0; i < aristas.size(); ++i){
    	if(aristas[i].peso==1) aristas_nuevas.push_back(aristas[i]);
    }
	
	aristas = aristas_nuevas;
    for (int i = 0; i < aristas.size(); ++i) {
        if (UF.Find(aristas[i].nodo1->getNum()) == UF.Find(aristas[i].nodo2->getNum())){
            return true;
        } 	
        UF.Union(UF.Find(aristas[i].nodo1->getNum()),UF.Find(aristas[i].nodo2->getNum()));
    }
    return false;
}
     

void CreacionLaberinto(Grafo* grafo,int n, int m){

    int v = grafo->totalVertice();
    vector <Edge> aristas = grafo->totalEdges();   
    vector <pair<int,int>> esta, no_esta;
   
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if(grafo->getVertice(i,j)->getLeft() ==NULL){   			
    			esta.push_back(make_pair(i,j));
    		}
    		else if(grafo->getVertice(i,j)->getRight() ==NULL){ 			
    			esta.push_back(make_pair(i,j));
    		}
    		else if(grafo->getVertice(i,j)->getUp() ==NULL ){   		
    			esta.push_back(make_pair(i,j));
    		}
    		else if(grafo->getVertice(i,j)->getDown() ==NULL){   		
    			esta.push_back(make_pair(i,j));
    		}
    		else {    			
    			no_esta.push_back(make_pair(i,j));
    		}
    	}
    }
    for (int i = 0; i < no_esta.size(); ++i){
    	Nodo* n = grafo->getVertice(no_esta[i].first,no_esta[i].second);
   	 	Nodo* m = n->getRight();
    	if(m!=NULL && n!=NULL)grafo->setEdge(n,m,-1);
    	m = n->getDown();
    	if(m!=NULL && n!=NULL)grafo->setEdge(n,m,-1);
    	m = n->getUp();
    	if(m!=NULL && n!=NULL)grafo->setEdge(n,m,-1);
    	m = n-> getLeft();
    	if(m!=NULL && n!=NULL)grafo->setEdge(n,m,-1);

    }

     
    grafo->setEdge(grafo->getVertice(0,0),grafo->getVertice(0,0)->getDown(),-1);
 
	while(true){
		if(esta.size() ==v)break;
   		int i = rand()%esta.size();
   		int j = rand()%no_esta.size();
   		
   		Nodo* n = grafo->getVertice(esta[i].first,esta[i].second);
   	 	Nodo* m = grafo->getVertice(no_esta[j].first,no_esta[j].second);

    	if(grafo->getEdge(n,m) !=-2 && grafo->getEdge(n,m) !=1)grafo->setEdge(n,m,1);
    	else continue;
    	
    	if(Ciclo(grafo)){
    		//grafo->print();
    		grafo->setEdge(n,m,-1);
    		//grafo->print();    		
    	}
    	else{    	
    		esta.push_back(make_pair(no_esta[j].first,no_esta[j].second));
    		no_esta.erase(no_esta.begin()+j);    		
    	}
    }
    grafo->setEdge(grafo->getVertice(n-1,m-1),grafo->getVertice(n-1,m-1)->getUp(),-1);
    grafo->print();
   
}