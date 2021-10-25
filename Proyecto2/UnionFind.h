
#include <vector>
#include <iostream>
using namespace std;


typedef struct{
	int rank=0;
    int parent;  
}Node;

class UnionFind{
	private:
		vector<Node> coleccion;
	public:
		UnionFind();
		~UnionFind();
		void MakeSet(int);
		int Find(int);
		void Union(int,int);
		
	
};
