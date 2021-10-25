#include "Random.h"

int random(int a, int b){
    if((a == 1 && b == 0) || (a==0 && b == 1)) return (int)rand()&1;
    int max = a;
    int min = b;
    if (max < b){
        max = b; 
        min = a;
    }
    int dif = max-min;
    int res=INT_MAX;
    while(res>dif){
        res = random(0,1);
        for(int i = 0; i < log2(dif) + 1 ; i++){
            res = res<<1;
            int x = random(0,1);
            res = res^x;
        }
    }    
    return res+min;
}



