class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long limit = 1000;

        while (n >= limit) {
            ans += (n - limit + 1);
            
            if (limit > LLONG_MAX / 1000) break;
            limit *= 1000;
        }

        return ans;
    }
};