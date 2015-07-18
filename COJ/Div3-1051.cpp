#include <iostream>

using namespace std;

int main(){

    long long int n = 0, res = 0;

    cin >> n;
    if(n>=1&&n<=2147483647){
        res = (n-1)-((n-1)/3);
        cout << res;
    }

    return 0;
}