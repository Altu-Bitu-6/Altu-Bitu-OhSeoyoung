#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {

    int n, m = 0;

    cin >> n >> m;

    set<string> s;
    vector<string> arr1(n);
    vector<string> arr2(m);
    int ans = 0;

    for (int i = 0; i < n; i++) {
		cin >> arr1[i];
        s.insert(arr1[i]);
	}

    for (int i = 0; i < m; i++) {
		cin >> arr2[i];
        if(s.find(arr2[i]) != s.end()) {
            ans++;
        }
	}
    cout << ans;
    
    return 0;
}