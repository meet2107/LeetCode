class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> temp;

        for (auto i : hours) {
            int r = i % 24;
            temp[r]++;
        }

        int count = 0;

        for (const auto& [remainder, num] : temp) {
            if (remainder == 0 || remainder == 12) {
                count += (num * (num - 1)) / 2;
            } 
            else if (remainder < 12) {
                int ct = 24 - remainder;
                if (temp.find(ct) != temp.end()) {
                    count += num * temp[ct];
                }
            }
        }

        return count;
    }
};
