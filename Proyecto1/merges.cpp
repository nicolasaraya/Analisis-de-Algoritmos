
#include <iostream>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <time.h>
using namespace std;

void merge_2(vector<int>* arr, long long int l, long long int m, long long int r){
    long long int n1 = m - l + 1;
    long long int n2 = r - m;
    vector<int> L;
    vector<int> R;
    /*
	Se separan los elementos del arreglo desde el elemento 'l' 
	hasta el 'r', en dos vectores distintos,
	para luego ir comparando el extremo izquierdo de cada uno
	y asignarlos en la posicion correspodiente del vector 
	original 'arr'
    */
    for (long long int i = 0; i < n1; i++)L.push_back(arr->at(l + i));
    for (long long int j = 0; j < n2; j++)R.push_back(arr->at(m + 1 + j));

    long long int i = 0;
    long long int j = 0;
    long long int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr->at(k) = L[i];
            i++;
        }
        else {
            arr->at(k) = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        arr->at(k) = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr->at(k) = R[j];
        j++;
        k++;
    }
}

void merge_3(vector<int>* arr,long long int l,long long int m1, long long int m2, long long int r){
       
    long long int n1 = m1 - l + 1;
    long long int n2 = m2 - m1;
    long long int n3 = r - m2;
    vector<int> L;
    vector<int> M;
    vector<int> R;
    
    /*
	Se crean tres vectores, 'L' contendra los elementos desde 'l' hasta 'm1'
	El vector 'M', contendra los elementos desde 'm1+1' hasta 'm2'
	y el vector 'R' desde 'm2+1' hasta 'r'
	Luego se va comparando los extremos izquierdos de los tres vectores y al menor
	de ellos se ubica en la posicion correspondiente del arreglo 'arr' original
    */


    for (long long int i = 0; i < n1; i++)L.push_back(arr->at(l + i));
    for (long long int j = 0; j < n2; j++)M.push_back(arr->at(m1 + 1 + j));    
    for (long long int j = 0; j < n3; j++)R.push_back(arr->at(m2 + 1 + j));

    
   
    long long int i = 0;
    long long int j = 0;    
    long long int z = 0;
   
    long long int k = l;
 
    while (i < n1 && j < n2 && z <n3) {
        if (L[i] <= M[j]) {
            if(L[i] <= R[z]){
                arr->at(k) = L[i];
                i++;
            }
            else{
                arr->at(k) = R[z];
                z++;
            }
        }
        else if (M[j]<= R[z]) {
            arr->at(k) = M[j];
            j++;
        }
        else{
            arr->at(k) = R[z];
            z++;
        }
        k++;
    }
    
   
    while ((i < n1) && (j < n2)){     
        if (L[i] <= M[j]) {
            arr->at(k) = L[i];
            i++;
            k++;
        }else{
            arr->at(k) = M[j];
            j++;
            k++;
        }     
    } 
    
    
    while ((j < n2) && (z < n3)){ 
        if (M[j] <= R[z]) {
            arr->at(k) = M[j];
            j++;
            k++;
        }else{
            arr->at(k) = R[z];
            z++;
            k++;
        }        
    } 
    
    while ((i < n1) && (z < n3)){  
        if (L[i] <= R[z]) {
            arr->at(k) = L[i];
            i++;
            k++;
        }else{
            arr->at(k) = R[z];
            z++;
            k++;
        }
    } 
    

    while (i < n1) {
        arr->at(k) = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr->at(k) = M[j];
        j++;
        k++;
    }
    while (z < n3) {
        arr->at(k) = R[z];
        z++;
        k++;
    }
}

void merge_4(vector<int>* arr, long long int l, long long int m1, long long int m2, long long int m3, long long int r){
	/*
	Se aprovecha la funcion "merge_2" definida anteriormente,  en ella se hace merge_2 primero con los elementos 
	desde 'l' hasta 'm2'. Luego se hace merge_2 desde 'm2+1' hasta 'r'
	y finalmente a lo obtenido de los dos anteriores se hace merge_2, es decir desde 'l' hasta 'r'
	*/
	merge_2(arr,l, m1, m2);
    merge_2(arr,m2+1, m3, r);
    merge_2(arr,l, m2, r);
    
}
  

void mergeSort_3(vector<int>* arr,long long int l,long long int r){
	/*
	Algoritmo base de MergeSort 3, hace una division de 3 equidistante entre 'l' y 'r', para luego 
	llamar recursivamente al metodo, cuando l>=r deja de llamarse recursivamente y empiza a llamarse 
	el metodo merge_3 para unir el arreglo ordenado.
	*/


    if(l>=r){
        return;
    }

    long long int m1 =l+ (r-l)/3;
    long long int m2 =l+ 2*((r-l)/3) +1;

    mergeSort_3(arr,l,m1);
    mergeSort_3(arr,m1+1,m2);
    mergeSort_3(arr,m2+1,r);
    merge_3(arr,l,m1,m2,r);   
}

 

void mergeSort_4(vector<int>* arr,long long int l,long long int r){
	/*
	Algoritmo base de MergeSort 4, hace una division de 4 equidistante entre 'l' y 'r', para luego 
	llamar recursivamente al metodo, cuando l>=r deja de llamarse recursivamente y empiza a llamarse 
	el metodo merge_4 para unir el arreglo ordenado.

	la condicion del if ((r-l)%4) cumple la funcion de no excederse en los limites de los indices del arreglo
	*/




    if(l>=r){
        return;
    }

    long long int m1 =l+ (r-l)/4;
    long long int m2 =l+ 2*((r-l)/4) +1;
    long long int m3 =l+ 3*((r-l)/4) +2;
    if(((r-l)%4) != 0){
    	m2--;
    	m3--;
    	m1--;
    }
    
    mergeSort_4(arr,l,m1);
    mergeSort_4(arr,m1+1,m2);
    mergeSort_4(arr,m2+1,m3);
    mergeSort_4(arr,m3+1,r); 
    merge_2(arr,l, m1, m2);
    merge_2(arr,m2+1, m3, r);
    merge_2(arr,l, m2, r);
    //merge_4(arr,l,m1,m2,m3,r);   
}
 
void mergeSort_2(vector<int>* arr,long long int l,long long int r){

	/*
	Algoritmo base de MergeSort 2, hace una division equidistante entre 'l' y 'r', para luego 
	llamar recursivamente al metodo, cuando l>=r deja de llamarse recursivamente y empiza a llamarse 
	el metodo merge_2 para unir el arreglo ordenado.
	*/
    if(l>=r){
        return;
    }
    long long int m =l+ (r-l)/2;
    mergeSort_2(arr,l,m);
    mergeSort_2(arr,m+1,r);
    merge_2(arr,l,m,r);
}

void print(vector<int>* arr){
    cout<<endl;
    for(int i = 0; i<arr->size(); i++) cout<<arr->at(i)<<" ";
    cout<<endl;
    cout<<endl;
}

int main(){
    srand(time(NULL));
    int num = 10000000;
    
    for(int i = 0; i<10; i++){ //para hacer 10 test con distintas cantidades
    	vector<int> arr;  //declaramos el arreglo
    	for (long long int i = 0; i < num; i++) arr.push_back(rand() % num); //lo rellenamos como peor caso, de mayor a menor
    	auto start = chrono::high_resolution_clock::now();
		mergeSort_4(&arr, 0, arr.size() - 1);  //lanzamos el algoritmo entre las pos 0 y la final del arreglo
    	auto finish = chrono::high_resolution_clock::now();    
		auto d = chrono::duration_cast<chrono::milliseconds> (finish - start).count();
		cout<<"merge_4,"<<num<<" elementos"<<endl;
		cout<<"Test: "<<i+1 <<" total time "<< d << " [ns]" << " \n";
		num+=10000000;  //incrementamos el tamaño en 10millones
    }
    num = 10000000;
    for(int i = 0; i<10; i++){
    	vector<int> arr;
    	for (long long int i = 0; i < num; i++) arr.push_back(num-i);
    	auto start = chrono::high_resolution_clock::now();
		mergeSort_3(&arr, 0, arr.size() - 1);
    	auto finish = chrono::high_resolution_clock::now();    
		auto d = chrono::duration_cast<chrono::milliseconds> (finish - start).count();
		cout<<"merge_3 ,"<<num<<" elementos"<<endl;
		cout<<"Test: "<<i+1 <<" total time "<< d << " [ns]" << " \n";
		num+=10000000;
    }
    num = 10000000;
    for(int i = 0; i<10; i++){
    	vector<int> arr;
    	for (long long int i = 0; i < num; i++) arr.push_back(num-i);
    	auto start = chrono::high_resolution_clock::now();
		mergeSort_2(&arr, 0, arr.size() - 1);
    	auto finish = chrono::high_resolution_clock::now();    
		auto d = chrono::duration_cast<chrono::milliseconds> (finish - start).count();
		cout<<"merge_2 ,"<<num<<" elementos"<<endl;
		cout<<"Test: "<<i+1 <<" total time "<< d << " [ns]" << " \n";
		num+=10000000;
    }
    
   
    
    return 0;
}  
