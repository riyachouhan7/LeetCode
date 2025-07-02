class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i < n; i++) {
            if(isPrime[i] == 1) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};
