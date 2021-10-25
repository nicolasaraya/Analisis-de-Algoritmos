#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int max(int a, int b){
	if(a<b) return b;
	else return a; 
}

vector<int> generador(int n, int a, int b){
	vector<int> graph;
	int max = a;
	int min = b;
	if(a<b){ 
		max = b;
		min = a;
	}
	for(int i = 0; i < n; i++){
		graph.push_back((rand()%(max-min+1))+min);
	} 
	return graph;
}


void print(vector<int>* graph){
	for(auto it : *graph) cout<<it<<" ";
	cout<<endl;
}

int topDown2(vector<int>* graph, int pos, vector<int>* mem){
	if(mem->at(pos) != -1) return mem->at(pos); 

	if(pos == graph->size()-1){
		mem->at(pos) = graph->at(pos);
		return graph->at(graph->size()-1);
	}
	if(pos == graph->size()-2){
		mem->at(pos) = graph->at(pos);
		return graph->at(graph->size()-2);
	}

	int a = 0, b = 0;
	if(pos+2 < graph->size()) a = topDown2(graph, pos+2, mem) + graph->at(pos);
	if(pos+3 < graph->size()) b = topDown2(graph, pos+3, mem) + graph->at(pos);	
	mem->at(pos) = max(a,b);
	return mem->at(pos);
}

	
int topDown(vector<int>* graph){
	if(graph->empty()) return -1; 
	if(graph->size() == 2) return max(graph->at(0), graph->at(1));
	if(graph->size() == 1) return graph->at(0);
	vector<int> mem;
	mem.assign(graph->size(), -1);
	return max(topDown2(graph, 0, &mem), topDown2(graph, 1, &mem));
}

int bottomUp(vector<int>* graph){
	vector<int> sub;
	if(graph->empty()) return -1;
	if(graph->size()>0) sub.push_back(graph->at(0));
	if(graph->size()>1) sub.push_back(max(sub.at(0), graph->at(1)));
	for(int i = 2; i < graph->size(); i++){ 
		if(graph->at(i) + sub.at(i-2) > sub.at(i-1)) sub.push_back(graph->at(i) + sub.at(i-2) );
		else sub.push_back(sub.at(i-1));
	}
	return *sub.rbegin();
}



int main(int argc, char const *argv[]){
	vector<int> graph;
	srand(time(NULL));
	if(argc==4) graph = generador(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]) );
	else graph = {6,1,2,11,5,4};
	
	
	print(&graph);
	cout<<"Solucion con TopDown "<<topDown(&graph)<<endl;
	cout<<"Solucion con BottomUp "<<bottomUp(&graph)<<endl;


	return 0;
}

