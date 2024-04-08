// 2607.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 두 단어의 알파벳 빈도수를 비교하여 비슷한 단어인지 판별하는 함수
bool isSimilarWord(const string& word1, const string& word2) {
    if (abs(int(word1.length()) - int(word2.length())) > 1) return false;

    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : word1) freq1[c - 'A']++;
    for (char c : word2) freq2[c - 'A']++;

    int diffCount = 0, diffChars = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq1[i] != freq2[i]) {
            diffCount += abs(freq1[i] - freq2[i]);
            diffChars++;
        }
    }

    if (diffCount > 2) return false;
    if (word1.length() == word2.length() && (diffChars > 2 || diffCount > 2)) return false;
    if (abs(int(word1.length()) - int(word2.length())) == 1 && diffCount > 1) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string baseWord;
    cin >> baseWord;
    int similarWordsCount = 0;

    for (int i = 1; i < n; ++i) {
        string currentWord;
        cin >> currentWord;
        if (isSimilarWord(baseWord, currentWord)) {
            similarWordsCount++;
        }
    }

    cout << similarWordsCount << '\n';

    return 0;
}


