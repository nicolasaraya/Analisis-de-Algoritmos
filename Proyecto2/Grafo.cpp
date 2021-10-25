#include "Grafo.h"

using namespace std;

Grafo::Grafo(int n, int m, bool pesos, int a, int b){
    this->n = n;
    this->m = m;
    this->pesos =pesos;
    int id = 0;
    for(int i = 0; i < n; i++){
        vector<Nodo*> r;
        for(int j = 0; j < m; j++){
            Nodo* a = new Nodo(id);
            id++;
            r.push_back(a);
        }
        graph.push_back(r);
    }

    if(pesos){
    //pesos horizontal y ptr horiz
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m-1; j++){
                int p = random(a, b);
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].peso=p;
         //   edges[make_pair(graph.at(i).at(j+1), graph.at(i).at(j))].peso=p;
                graph.at(i).at(j)->setRight(graph.at(i).at(j+1));
                graph.at(i).at(j+1)->setLeft(graph.at(i).at(j));
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].nodo1 = graph.at(i).at(j) ;
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].nodo2 =graph.at(i).at(j+1);
            }
        }

    
        //pesos vertical y ptr vert 
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n-1; i++){
                int p = random(a,b);
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].peso=p;
          //  edges[make_pair(graph.at(i+1).at(j), graph.at(i).at(j))].peso=p;
                graph.at(i).at(j)->setDown(graph.at(i+1).at(j));
                graph.at(i+1).at(j)->setUp(graph.at(i).at(j));
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].nodo1 = graph.at(i+1).at(j) ;
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].nodo2 =graph.at(i).at(j);
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m-1; j++){
                int p = 1;
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].peso=p;
         //   edges[make_pair(graph.at(i).at(j+1), graph.at(i).at(j))].peso=p;
                graph.at(i).at(j)->setRight(graph.at(i).at(j+1));
                graph.at(i).at(j+1)->setLeft(graph.at(i).at(j));
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].nodo1 = graph.at(i).at(j) ;
                edges[make_pair(graph.at(i).at(j), graph.at(i).at(j+1))].nodo2 =graph.at(i).at(j+1);
            }
        }

    
        //pesos vertical y ptr vert 
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n-1; i++){
                int p = 1;
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].peso=p;
          //  edges[make_pair(graph.at(i+1).at(j), graph.at(i).at(j))].peso=p;
                graph.at(i).at(j)->setDown(graph.at(i+1).at(j));
                graph.at(i+1).at(j)->setUp(graph.at(i).at(j));
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].nodo1 = graph.at(i+1).at(j) ;
                edges[make_pair(graph.at(i).at(j), graph.at(i+1).at(j))].nodo2 =graph.at(i).at(j);
            }
        }

    }

}
Grafo::~Grafo(){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            Nodo* temp = graph.at(i).at(j);
            graph.at(i).at(j) = NULL;
            delete[] temp;
        }
    }
}


Nodo* Grafo::getVertice(int x, int y){
    return graph.at(x).at(y);
}
void Grafo::setVertice(int x, int y, Nodo* n){
    graph.at(x).at(y) = n;
}
int Grafo::getEdge(Nodo* u, Nodo* v){

    if(edges.count(make_pair(u, v))>0) return edges[make_pair(u, v)].peso;
    else if (edges.count(make_pair(v, u))>0) return edges[make_pair(v, u)].peso ;
    return -2;
}
void Grafo::setEdge(Nodo* u, Nodo* v, int n){
    if(edges.count(make_pair(u, v))>0)edges[make_pair(u, v)].peso = n;
    else if (edges.count(make_pair(v, u))>0) edges[make_pair(v, u)].peso = n;

}
void Grafo::print(){
    cout<<"******************************************************"<<endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; ++j){

        	if(pesos){
        		if(graph.at(i).at(j)->getNum()<10) cout<<"|0"<<graph.at(i).at(j)->getNum()<<"|";
        		else cout<<"|"<<graph.at(i).at(j)->getNum()<<"|";
        		if(j!=m-1){
        			if(getEdge(graph.at(i).at(j), graph.at(i).at(j+1)) <= -1) cout<<"      ";
        			else {
        				cout<<"<-";
        				if(getEdge(graph.at(i).at(j), graph.at(i).at(j+1))<10) cout<<"0"<<getEdge(graph.at(i).at(j), graph.at(i).at(j+1))<<"->";
        				else cout<<getEdge(graph.at(i).at(j), graph.at(i).at(j+1))<<"->";
        			}
        		}
        	}
        	else{
        		if(graph.at(i).at(j)->getNum()<10) cout<<"|0"<<graph.at(i).at(j)->getNum()<<"|";
        		else cout<<"|"<<graph.at(i).at(j)->getNum()<<"|";
        		if(j!=m-1){
        			if(getEdge(graph.at(i).at(j), graph.at(i).at(j+1)) <= -1) cout<<"     ";
        			else cout<<"-----";
        		}

        	}
        }
        cout<<endl<<" ";


        if(i!=n-1){
        	for(int j=0; j < m ; j++){
        		if(getEdge(graph.at(i).at(j), graph.at(i+1).at(j)) <= -1) cout<<"         ";
                else {
                	if(pesos) cout<<"^         ";
                	else cout<<"|        ";
                }
            }
            cout<<endl<<" ";
            for(int j=0; j < m ; j++){
        		if(getEdge(graph.at(i).at(j), graph.at(i+1).at(j)) <= -1) cout<<"         ";
                else{
                	if(pesos){ 
                		if(getEdge(graph.at(i).at(j), graph.at(i+1).at(j))<10) cout<<getEdge(graph.at(i).at(j), graph.at(i+1).at(j))<<"         ";
                		else cout<<getEdge(graph.at(i).at(j), graph.at(i+1).at(j))<<"        ";
                	}
                	else{
                		cout<<"|        ";
                	}
            	}
            }
            cout<<endl<<" ";
            for(int j=0; j < m ; j++){
        		if(getEdge(graph.at(i).at(j), graph.at(i+1).at(j)) <= -1) cout<<"         ";
                else {
                	if(pesos) cout<<"v         ";
                	else cout<<"|        ";
                }
            }
            cout<<endl;
        }
    }
    cout<<endl<<"******************************************************"<<endl;
}

int Grafo::totalVertice(){
    return n*m;
}

vector <Edge> Grafo::totalEdges (){
    vector <Edge> aristas;

   for(auto it : edges){
       
        aristas.push_back(it.second);
    }

    return aristas;
}
