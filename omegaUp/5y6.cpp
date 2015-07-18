#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;

void digitos(int num, int* d){
    if(num>=10){
        *d += 1;
        digitos(num/10,d);
    }
}

int minNumber(int* array, int index){
    int base = 1, minNum = 0;
    for(int i=0;i<index;++i){
        if(array[i]==6)
            array[i] = 5;
    }
    int in = 0;
    while(index!=0){
        base = 1;
            for(int i=1;i<index;++i){
                base *= 10;
            }
        minNum += array[in]*base;
        --index;
        ++in;
    }
    return minNum;

}

int maxNumber(int* array, int index){
    int base = 1, maxNum = 0;
    for(int i=0;i<index;++i){
        if(array[i]==5)
            array[i] = 6;
    }
    int in = 0;
    while(index!=0){
        base = 1;
            for(int i=1;i<index;++i){
                base *= 10;
            }
        maxNum += array[in]*base;
        --index;
        ++in;
    }
    return maxNum;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char numeros[SIZE];
    cin.getline(numeros,SIZE,'\n');
    int index = 0;
    while(numeros[index] != ' '){
        ++index;
    }
    int array1[index];
    int tam = (strlen(numeros)-1)-index;
    int array2[tam];
    for(int i=0;i<index;++i){
        array1[i] = numeros[i] - '0';
    }
    int a = 0;
    for(int i=(index+1);i<=(strlen(numeros)-1);++i){
        array2[a] = numeros[i] - '0';
        ++a;
    }
    cout << minNumber(array1,index) + minNumber(array2,a) << " " << maxNumber(array1,index) + maxNumber(array2,a) << endl;
    return 0;
}
