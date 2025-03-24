#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 1. Brute Force Solution - O(n^3)
bool allUnique(string s, int start, int end) {
    unordered_set<char> chars;
    for (int i = start; i <= end; i++) {
        if (chars.find(s[i]) != chars.end())
            return false;
        chars.insert(s[i]);
    }
    return true;
}

int bruteForce(string s) {
    int n = s.length(), maxLength = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (allUnique(s, i, j)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// 2. Improved Brute Force using Hash Set - O(n^2)
int improvedBruteForce(string s) {
    int n = s.length(), maxLength = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            if (seen.find(s[j]) != seen.end()) break;
            seen.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
        }
    }
    return maxLength;
}

// 3. Optimal Sliding Window using Hash Map - O(n)
int slidingWindow(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLength = 0;
    
    for (int right = 0; right < s.length(); right++) {
        if (lastSeen.find(s[right]) != lastSeen.end()) {
            left = max(left, lastSeen[s[right]] + 1);
        }
        lastSeen[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

// 4. Sliding Window using Hash Set - O(n)
int slidingWindowSet(string s) {
    unordered_set<char> seen;
    int left = 0, maxLength = 0;
    
    for (int right = 0; right < s.length(); right++) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Brute Force: " << bruteForce(s) << endl;
    cout << "Improved Brute Force: " << improvedBruteForce(s) << endl;
    cout << "Sliding Window (Hash Map): " << slidingWindow(s) << endl;
    cout << "Sliding Window (Hash Set): " << slidingWindowSet(s) << endl;

    return 0;
}
