class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(result, "", num, target, 0, 0, 0);
        return result;
    }

    void backtrack(vector<string>& result, string path, string& num, int target, int pos, long eval, long multed) {
        if (pos == num.size()) {
            if (eval == target) result.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Skip numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long cur = stol(curStr);

            if (pos == 0) {
                // First number, no operator
                backtrack(result, path + curStr, num, target, i + 1, cur, cur);
            } else {
                backtrack(result, path + "+" + curStr, num, target, i + 1, eval + cur, cur);
                backtrack(result, path + "-" + curStr, num, target, i + 1, eval - cur, -cur);
                backtrack(result, path + "*" + curStr, num, target, i + 1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
};

