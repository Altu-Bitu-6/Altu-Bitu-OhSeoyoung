#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;
set<vector<int> > seen;  // To store and ensure unique sequences

void generate(int depth, vector<int>& sequence) {
    if (depth == M) {
        // If a complete sequence of length M is generated
        if (seen.count(sequence) == 0) {
            // If this sequence has not been seen before, print it
            for (int num : sequence) {
                cout << num << " ";
            }
            cout << "\n";
            seen.insert(sequence);  // Mark this sequence as seen
        }
        return;
    }
    
    for (int i = 0; i < N; ++i) {
        sequence.push_back(nums[i]);
        generate(depth + 1, sequence);
        sequence.pop_back();  // Backtrack
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    nums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    // Sort and eliminate duplicates for the initial numbers to ensure lexicographical order
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    vector<int> sequence;
    generate(0, sequence);

    return 0;
}
