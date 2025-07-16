class Solution {
  public:
  
  #define ll long long

// Sieve to generate primes up to a limit
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

    int countNumbers(int n) {
        // Code Here
        int count = 0;

    // Estimate the maximum value needed for primes
    int limit = sqrt(n) + 1;
    vector<int> primes = generatePrimes(limit);

    // Case 1: p^8 <= n
    for (int i = 0; i < primes.size(); i++) {
        ll p8 = 1;
        for (int j = 0; j < 8; j++) p8 *= primes[i];
        if (p8 <= n) count++;
        else break; // further primes will exceed
    }

    // Case 2: p^2 * q^2 <= n with p < q
    int sz = primes.size();
    for (int i = 0; i < sz; i++) {
        ll p2 = 1LL * primes[i] * primes[i];
        if (p2 > n) break;

        for (int j = i + 1; j < sz; j++) {
            ll q2 = 1LL * primes[j] * primes[j];
            if (p2 * q2 <= n) count++;
            else break;
        }
    }

    return count;
    }
};