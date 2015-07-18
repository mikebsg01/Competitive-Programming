#include <bits/stdc++.h>
using namespace std;

int main(){
char array[1002];
cin>>array;
int tam = strlen(array);
sort(array, array+tam);
cout<<array<<endl;
return 0;
}
