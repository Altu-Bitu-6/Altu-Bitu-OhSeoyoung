#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> numbers;
vector<int> operations; 

int compute(int a, int b, int op) {
    if (op == 0) return a + b;
    else if (op == 1) return a - b;
    else if (op == 2) return a * b;
    else { 
        if (a < 0) return -(-a / b);
        else return a / b;
    }
}

void solve(int& minVal, int& maxVal) {
   
    vector<int> ops;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < operations[i]; ++j) {
            ops.push_back(i);
        }
    }

    minVal = INT32_MAX;
    maxVal = INT32_MIN;

    do {
        int result = numbers[0];
        for (int i = 1; i < n; ++i) {
            result = compute(result, numbers[i], ops[i-1]);
        }
        minVal = min(minVal, result);
        maxVal = max(maxVal, result);
    } while (next_permutation(ops.begin(), ops.end()));
}

int main() {
    cin >> n;
    numbers.resize(n);
    operations.resize(4); 
    
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operations[i];
    }

    int minVal, maxVal;
    solve(minVal, maxVal);

    cout << maxVal << "\n" << minVal << endl;
    return 0;
}
