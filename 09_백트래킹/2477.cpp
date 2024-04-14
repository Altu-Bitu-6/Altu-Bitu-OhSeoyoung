#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int k, n, a;
    vector<pair<int, int> >v;
    cin >> k;
    int EW = 0;
    int NS = 0;      
    for (int i = 0; i < 6; i++) {
        cin >> n >> a;
        v.push_back(make_pair(n, a));
        if (n >= 3) NS += a;
        else EW += a;
    }
    NS /= 2;   
    EW /= 2;   
    int index = -1;
    for (int i = 0; i < 6; i++) {
       
        if (v[i].second == NS || v[i].second == EW) {
            int k = i + 1;
            if (k > 5) k = 0;
            if (v[k].second == NS || v[k].second == EW) {
                index = k;
                break;
            }
        }
    }
    int x = index + 2;
    int y = index + 3;
    if (x > 5)x -= 6;
    if (y > 5)y -= 6;
    cout << ((NS * EW) - (v[x].second * v[y].second)) * k << "\n";
}
