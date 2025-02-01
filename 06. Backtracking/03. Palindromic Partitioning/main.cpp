#include <bits/stdc++.h>
using namespace std;

// Function to check if a given substring is a palindrome
bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

// Backtracking function to find all palindromic partitions
void backtrack(int start, string &s, vector<string> &current, vector<vector<string>> &result) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1)); // Take the substring
            backtrack(end + 1, s, current, result);
            current.pop_back(); // Backtrack
        }
    }
}

// Function to generate all palindromic partitions
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    backtrack(0, s, current, result);
    return result;
}

// Utility function to print the partitions
void printPartitions(const vector<vector<string>> &partitions) {
    for (const auto &partition : partitions) {
        cout << "  [";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    string s = "aab";
    
    cout << "Palindromic Partitions of \"" << s << "\":\n";
    vector<vector<string>> partitions = partition(s);
    printPartitions(partitions);

    return 0;
}
