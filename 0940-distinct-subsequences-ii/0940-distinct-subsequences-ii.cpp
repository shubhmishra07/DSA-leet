class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long current_total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long new_subseqs = (current_total + 1) % MOD;
            long long diff = (new_subseqs - last[idx] + MOD) % MOD;
            
            current_total = (current_total + diff) % MOD;
            last[idx] = new_subseqs;
        }

        return current_total;
    }
};