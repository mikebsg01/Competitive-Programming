#include <iostream>
using namespace std;
int main(){
	int n, p1 = 0, p2 = 0, iterate=0;
	cin >> n;
	p1 = p2 = iterate = n/2;
	if((p1%2)==0 && (p1+p2)==n){
		cout << "YES" << endl;
	}
	else
	{
		bool is_solution = false;
		for(int i=0;i<iterate;i++){
			
			if(p1%2==0 && p2%2==0 && (p1+p2)==n){
				is_solution = true;
				break;
			}
			p1--;
			p2++;
			
		}
		if(is_solution){
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}