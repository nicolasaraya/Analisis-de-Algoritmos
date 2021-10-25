
#include "UnionFind.h"
#include <iostream>
#include <vector>

using namespace std;

UnionFind::UnionFind(){
}

UnionFind::~UnionFind(){
}

void UnionFind::MakeSet(int x){
	Node inicio;
	inicio.parent = x;
	coleccion.push_back(inicio); 
}

int UnionFind::Find(int x){
	if (coleccion[x].parent != x){
		coleccion[x].parent = Find(coleccion[x].parent);
	}

	return coleccion[x].parent;
}

void UnionFind::Union(int x,int y){
	int parent_x = Find(x);
	int parent_y = Find(y);

	if(coleccion[parent_x].rank > coleccion[parent_y].rank) coleccion[parent_y].parent = parent_x;
	else coleccion[parent_x].parent = parent_y;
 	
 	if(coleccion[parent_x].rank == coleccion[parent_y].rank) coleccion[parent_y].rank++;
}
