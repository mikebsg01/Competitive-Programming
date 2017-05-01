#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int isNumber(char x){
    if((x-'0')>0 && (x-'0')<=9)
        return 1;
    
    return 0;
}

int ofAlphabet(char x){
    if((x-'A'+1)>0 && (x-'A'+1)<=26)
        return 1;
    
    return 0;
}

int isOfFirstSystem(char coords[]){
    if(coords[0] == 'R' && isNumber(coords[1]))
        return 1;
    
    return 0;
}
int main(){

char coords[1000001], answer[1000001];
int p = 0;
int N, i, j, k;
int F=0, C=0, aux = 0, long_string=0;
int power = 0, repeat = 0;

    cin >> N;
    for(i=0; i<N; ++i){
        C=0; F=0;
        cin >> coords;
        long_string = strlen(coords);

        if(isOfFirstSystem(coords)){
            j=1;

            while(isNumber(coords[j]))
                ++j;

            power = (long_string-(j+2));
            
            while(power){
                F += (pow(10, power)) * (coords[j + 1] - '0');
                --power; ++j;
            }


            F += (coords[j+1]-'0');
            
            while(F>9){
                power = 1;
                aux = pow(26, power);
                while(aux <= F){
                    ++power;
                    aux = pow(26, power);
                }
                --power;

                repeat = 1;
                aux = pow(26, power);

                while(aux <= F){
                    ++repeat;
                    aux *= repeat;
                }
                --repeat;

                aux = repeat * (pow(26, power));
                cout << "R: " << repeat << endl;
                printf("%c\n",repeat+('A'-1));
                answer[p++] = (char) (repeat+('A'-1));

                F -= aux;

            }
            --F;
            printf("%c\n",F+('A'-1));
            answer[p++] = (char) ((int)(F+('A'-1)));
            answer[p] = '\0';

            cout << answer;

            for(k=1; k < j - 1; ++k)
                cout << coords[k];
            cout << "\n";

        }else{
            
            j=0;
            while(ofAlphabet(coords[j]))
                ++j;

            aux = j;

            for(k=0; k < j - 1; ++k){
                C += ((long long) pow(26, j - 1)) * (((long long)coords[k]-'A')+1);
                --j;
            }   

            C += (((long long) coords[k]-'A')+1);
            
            cout << "R";
            for(k=aux; k<long_string; ++k)
                cout << coords[k];

            cout << "C" << C << "\n";
            
        }
    }    
    return 0;
}