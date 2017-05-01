
 #include <iostream>
#include <string>
#include <map>

int N;
std::map<std::string, int> db;
std::string s;

int main(){
    
    std::cin >> N;
    while(N--){
        std::cin >> s;
        if(!db[s]){
            std::cout << "OK\n";
            ++db[s];
        }else{
            std::cout << s << db[s] << "\n";
            ++db[s]; 
        }
    }
    return 0;
}