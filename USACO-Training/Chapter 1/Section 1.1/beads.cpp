/*
ID: program43
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX_SIZE 100005
using namespace std;

int main(){
	
	freopen("beads.in","rt",stdin);
	freopen("beads.out","wt",stdout);
	int N;
	int i=0, MAYOR = 0, prev=0, next=0, TEMP = 0;
	int count_prev=0, count_next=0;
	char collar[100005], t_prev, t_next;
	int num_p=0;
	bool equal = true;
	cin >> N;
	scanf("%s",collar);

	for(i=1; i<N; i++){
		num_p++;
		if(collar[i]!=collar[i-1]){
			equal = false;
		}
	}
	if(equal){
		cout << num_p+1 << endl;
	}else{

		for(i=0; i<=N; i++){
			count_prev = count_next = 0;
			prev = i;
			--prev;
			if(prev<0){
				prev = N-1;
			}
			t_prev = collar[prev];
			if(t_prev!='w'){
				while(collar[prev] == t_prev || collar[prev] == 'w'){
					count_prev++;
					prev--;
					if(prev<0){
						prev = N-1;
					}
				}	
			}else{
				while(collar[prev] == 'w'){
					count_prev++;
					prev--;
					if(prev<0){
						prev = N-1;
					}
				}	
				char t_aux = collar[prev];
				while(collar[prev] == t_aux || collar[prev] == 'w'){
					count_prev++;
					prev--;
					if(prev<0){
						prev = N-1;
					}
				}	
			}
			//cout << count_prev << " - " << i << endl;
			next = i;
			if(next>=N){
				next = 0;
			}	
			t_next = collar[next];

			if(t_next!='w'){
				while((collar[next] == t_next || collar[next] == 'w') && next != prev){
					count_next++;
					next++;
					if(next>=N){
						next = 0;
					}
				}	
			}else{
				while(collar[next] == 'w' && next != prev){
					count_next++;
					next++;
					if(next>=N){
						next = 0;
					}
				}	
				char t_aux = collar[next];
				while(collar[next] == t_aux || collar[next] == 'w'){
					count_next++;
					next++;
					if(next>=N){
						next = 0;
					}
				}	
			}
			//cout << count_next << " - " << i << endl;
			TEMP = count_next + count_prev;

			if(TEMP>MAYOR){
				MAYOR = TEMP;
			}
		}		
		cout << MAYOR << endl;
	}
	return 0;
}
