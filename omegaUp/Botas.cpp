#include <cstdio>
#include <algorithm>
int main(){
    int array[100002], impares=0, n=0, i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);

    std::sort(array, array+n);

    for(i=0;i<n;i+=2)
        if(array[i]!=array[i+1]){
            impares++;
            i--;
        }
  
    printf("%d\n",impares);
    return 0;
}

