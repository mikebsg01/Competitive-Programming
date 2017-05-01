#include <iostream>
using namespace std;
int main(){
    int n=0, sum=0;
    cin >> n >> sum;
    int max[n], min[n];
    int li=0, ls=0;

    for(int i=0;i<n;i++){
        cin >>min[i]>>max[i];
        li += min[i];
        ls += max[i];
    }

    if(sum<li || sum>ls)
        cout << "NO" << endl;
    else
    {
        int hours[n];
        for(int i=0;i<n;i++){
            hours[i] = min[i];
            max[i] -= min[i];
            sum -= min[i];
        }
        int index = 0;
        while(sum!=0){
            for(int i=1;i<=max[index];i++){
                hours[index] = hours[index] + 1;
                sum--;
                if(sum==0) break;
            }
            index++;
        }
        cout << "YES" << endl;
        for(int i=0;i<n;i++)
            cout << hours[i] << " ";
        cout << endl;
    }
    return 0;
}