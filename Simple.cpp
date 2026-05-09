#include <bits/stdc++.h>
using namespace std;

bool oddOrEven(long long n) {
	return n & 1 == 0;
}

long long naturalSum(long long n) {
	return n * (n + 1) / 2;
}

long long squareSum(long long n) {
	return n * (n + 1) * (2 * n + 1) / 6;
} 

int closestNumber(int n, int m) {
    int q = n / m;

    // 1st possible closest number
    int n1 = m * q;

    // 2nd possible closest number
    int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));

    // if true, then n1 is the required closest number
    if (abs(n - n1) < abs(n - n2))
        return n1;

    // else n2 is the required closest number    
    return n2;
}

bool perfectNumber(long long n) {
    if (n <= 1) return false;
    long long target = sqrt(n);
    long long dsum = 1;

    for (long long i = 2; i <= target; i++) {
        if (n % i == 0) {
            dsum += i;
            if (i != n / i) {
                dsum += n / i;
            }
        }
        if (dsum > n) return false;
    }

    return dsum == n;
}

bool square(long long n) {
    long double squared = sqrt(n);
    if (squared == floor(squared)) {
        return true;
    }
    return false;
}


int main() {'
	cout << "This is the file which store simple templates."

	return 0;
}