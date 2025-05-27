#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int aLen = a.length(), bLen = b.length();
        
        // Rabin-Karp hash parameters
        const int base = 256;
        const int mod = 1e9 + 7;

        // Compute hash for b
        long long bHash = 0, aHash = 0, power = 1;
        for (int i = 0; i < bLen; ++i) {
            bHash = (bHash * base + b[i]) % mod;
            if (i < bLen - 1) power = (power * base) % mod;
        }

        string repeatedA;
        int count = 0;
        // Keep repeating a until its length is at least b's length
        while (repeatedA.length() < bLen) {
            repeatedA += a;
            count++;
        }

        // Check repeatedA and repeatedA + a to ensure we don't miss a match across boundaries
        for (int i = 0; i <= aLen; ++i) {
            string current = repeatedA + a.substr(0, i);
            if (rabinKarp(current, b, bHash, power, base, mod)) {
                return count + (i > 0 ? 1 : 0);
            }
        }

        return -1;
    }

private:
    bool rabinKarp(const string& text, const string& pattern, long long patHash, long long power, int base, int mod) {
        int tLen = text.length(), pLen = pattern.length();
        if (tLen < pLen) return false;

        long long hash = 0;
        for (int i = 0; i < pLen; ++i) {
            hash = (hash * base + text[i]) % mod;
        }

        if (hash == patHash && text.substr(0, pLen) == pattern) return true;

        for (int i = pLen; i < tLen; ++i) {
            hash = ((hash - text[i - pLen] * power % mod + mod) * base + text[i]) % mod;
            if (hash == patHash && text.substr(i - pLen + 1, pLen) == pattern) {
                return true;
            }
        }
        return false;
    }
};

