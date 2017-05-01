#include <iostream>

int main(){
    long long int n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ((m+a-1)/a)*((n+a-1)/a) << "\n"; 
    return 0;
}