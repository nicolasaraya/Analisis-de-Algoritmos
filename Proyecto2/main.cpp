#include <time.h>
#include "Maze.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	srand(time(NULL));
    if(argc != 7) return 0;
    cout << "El largo del grafo ingresado fue: " << atoi(argv[1]) << endl;
    cout << "El ancho del grafo ingresado fue: " << atoi(argv[2]) << endl;
    
    Grafo* g = new Grafo(atoi(argv[1]),atoi(argv[2]), true, atoi(argv[3]), atoi(argv[4]));

    cout << "Con los datos ingresados se forma el siguiente gráfo de grilla: "<< endl;
    cout << endl;
    g->print();
 	cout << endl;

    cout << "Árbol de cobertura mínima del grafo de grilla es: "<< endl;
    AlgoritmoKruskal(g);
    cout << endl;

    cout << "El largo del laberinto ingresado fue: " << atoi(argv[3]) << endl;
    cout << "El ancho del laberinto ingresado fue: " << atoi(argv[4]) << endl;

    cout << "Creación laberinto aleatorio: "<< endl << endl;
	Grafo* h = new Grafo(atoi(argv[5]),atoi(argv[6]), false,1,1);
	CreacionLaberinto(h,atoi(argv[5]),atoi(argv[6]));
    cout << endl;
    return 0;
}
