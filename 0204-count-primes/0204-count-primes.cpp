class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        // Mark even numbers as non-prime
        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
        }

        // Sieve only odd numbers
        for (int i = 3; (long long)i * i < n; i += 2) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    prime[j] = false;
                }
            }
        }

        int cnt = 1; // 2 is prime

        for (int i = 3; i < n; i += 2) {
            if (prime[i])
                cnt++;
        }

        return cnt;
    }
};