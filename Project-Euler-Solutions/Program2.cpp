#include <iostream>
using namespace std;
int main()
{
	int sum = 0, temp = 0, i = 1, j = 1, aux = 0;

	while(temp<4000000)
	{
		sum += temp;
		aux = temp;
		i = aux+j;
		j = aux+i;
		temp = i+j;
	}
	cout << sum << endl;
	return 0;
}