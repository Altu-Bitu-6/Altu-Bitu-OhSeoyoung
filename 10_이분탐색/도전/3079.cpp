#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    unsigned long long n, m;
    unsigned long long t[100001];
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> t[i];
    }
    sort(t, t + n);
    unsigned long long high = m * t[0]; 

    unsigned long long low = 1;
    unsigned long long mid;
    unsigned long long ans = 0;
    unsigned long long people;
    while(high >= low){ 
        people = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < n;i++){
            people += mid / t[i]; 
        }
        if(people >= m){ 
            if(ans > mid || ans ==0){ 
                ans = mid;
            }
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
