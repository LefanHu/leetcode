# Description
Given `wordLen` and `maxVowels`, where `wordLen` is the size of the string and `maxVowels` is the maximum allowed consecutive vowels in the string, return the # of unique strings that's possible (return `answer % (1e9 + 7)`).

# Approach
- 2D DP

DP matrix state - `dp[i][j]` represents the number of strings of `i` length and ends with `j` consecutive vowels.

# Code
```cpp
int MOD = 1e9 + 7;
int possibleStrings(int wordLen, int maxVowels) {
    vector<long> prev(maxVowels + 1, 0), curr(maxVowels + 1);
    prev[0] = 1; // initialize
    
    // build dp table
    for (int i{1}; i <= wordLen; ++i) {
        // reset
        fill(curr.begin(), curr.end(), 0);
        
        // fill
        for (int j{}; j <= maxVowels; ++j) {
            // add consonant
            curr[0] = (curr[0] + prev[j] * 21) % MOD;
            
            if (j < maxVowels) {
                // add vowel
                curr[j + 1] = (curr[j + 1] + prev[j] * 5) % MOD;
            }
        }
        
        prev = curr;
    }
    
    // sum to get answer
    long ans{};
    for (int i{}; i <= maxVowels; ++i) {
        ans = (ans + curr[i]) % MOD;
    }
    
    return ans;
}
```