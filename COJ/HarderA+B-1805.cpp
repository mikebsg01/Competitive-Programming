#include <iostream>
using namespace std;
int main(){
	long long int A, B;
	cin >> A >> B;
	cout << (A+B) + (A-B) + (B+A) + (B-A) << endl;
	return 0;
}