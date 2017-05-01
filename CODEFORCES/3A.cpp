#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 9

typedef struct cola
{
    char move[3];

} Cola;

Cola cola[50];
int p = 0;

char coord[3];
char coordDestino[3];
int x = 0, y = 0;
int xDestino = 0, yDestino = 0;
int i,j;

int xChar(char c){
    if(c == 'a')
        return 1;
    else if(c == 'b')
        return 2;
    else if(c == 'c')
        return 3;
    else if(c == 'd')
        return 4;
    else if(c == 'e')
        return 5;
    else if(c == 'f')
        return 6;
    else if(c == 'g')
        return 7;
    else if(c == 'h')
        return 8;

    return -1;
}

int toNumber(char c){
    return ((int)(c-'0'));
}

int main(){
    scanf("%s",coord);

    x = xChar(coord[0]);
    y = toNumber(coord[1]);

    scanf("%s",coordDestino);

    xDestino = xChar(coordDestino[0]);
    yDestino = toNumber(coordDestino[1]);
    

    while(x != xDestino || y != yDestino){

        if(x < xDestino && y == yDestino ){
            ++x;
            strcpy(cola[p].move,"R");;
            ++p;
        }
        else if( x > xDestino && y == yDestino ){
            --x;
            strcpy(cola[p].move,"L");;
            ++p;

        }
        else if( y < yDestino && x == xDestino ){
            ++y;
            strcpy(cola[p].move,"U");;
            ++p; 
        }
        else if( y > yDestino && x == xDestino ){
            --y;
            strcpy(cola[p].move,"D");;
            ++p;

        }
        else if(x < xDestino && y < yDestino ){
            ++x;
            ++y;
            strcpy(cola[p].move,"RU");
            ++p;;

        }
        else if( x < xDestino && y > yDestino ){
            ++x;
            --y;            
            strcpy(cola[p].move,"RD");
            ++p;;
        }
        else if( x > xDestino && y < yDestino ){
            --x;
            ++y;
            strcpy(cola[p].move,"LU");
            ++p;;

        }
        else if( x > xDestino && y > yDestino ){
            --x;
            --y;
            strcpy(cola[p].move,"LD");
            ++p;;

        }

    }

    printf("%d\n",p);

    for(i=0; i<p; ++i){
        printf("%s\n",cola[i].move);
    }
    return 0;
}