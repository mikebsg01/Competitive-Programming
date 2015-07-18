#include <iostream>

using namespace std;

int main(){

    int casos = 0;
    cin >> casos;
    int m[casos];
    int n[casos];

    for(int i=0;i<casos;i++){
        cin >> n[i] >> m[i];
    }
    for(int i=0;i<casos;i++){
       if(m[i]==n[i] && m[i]%2==0){
            cout << "L" << endl;
       }
       else if(m[i]==n[i] && m[i]%2!=0){
            cout << "R" << endl;
       }
       else if(m[i]>n[i] && n[i]%2!=0){
            cout << "R" << endl;
       }
       else if(m[i]>n[i] && n[i]%2==0){
            cout << "L" << endl;
       }
       else if(n[i]>m[i] && m[i]%2!=0){
            cout << "D" << endl;
       }
       else if(n[i]>m[i] && m[i]%2==0){
            cout << "U" << endl;
       }

    }


    return 0;
}

