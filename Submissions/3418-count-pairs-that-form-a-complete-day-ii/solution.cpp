class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long, long long> temp;

        for (auto i : hours) {
            long long r = i % 24;
            temp[r]++;
        }

        long long count = 0;

        for (const auto& [remainder, num] : temp) {
            if (remainder == 0 || remainder == 12) {
                count += (long long)(num * (num - 1)) / 2;
            } 
            else if (remainder < 12) {
                long long ct = 24 - remainder;
                if (temp.find(ct) != temp.end()) {
                    count += num * temp[ct];
                }
            }
        }

        return count;
    }
};
