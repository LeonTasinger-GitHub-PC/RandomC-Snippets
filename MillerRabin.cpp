#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>

// C++ headers
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <codecvt>        // deprecated in C++17
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <execution>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <memory_resource>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
using namespace std;

long long ModularMultiplication(long long a, long long b, long long mod) {
    long long res = 0; a %= mod;
    while (b > 0) {
        if (b & 1) {  
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;  
        b >>= 1;        
    }

    return res;
}
long long ModularExponentiation(long long a, long long d, long long n) {
    long long result = 1; a %= n;
    while (d > 0) {
        if (d & 1) {
            if (result > 3000000000 || a > 3000000000) {
                result = ModularMultiplication(result, a, n);
            }
            else result = (result * a) % n;
        }
        if (a > 3000000000) {
            a = ModularMultiplication(a, a, n);
        }
        else a = (a * a) % n;
        d >>= 1;
    }

    return result;
}

bool MillerRabin(long long n) {
    long long d = n - 1; int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    //Random witness:
    random_device rd;
    mt19937_64 gen(rd());  // use 64-bit generator for large ranges
    uniform_int_distribution<long long> dist(2LL, n - 2);

    long long a = dist(gen);


    long long x = ModularExponentiation(a, d, n);
    if (x == 1 || x == n - 1) {
        return true;
    }
    long long speed = 3000000000;
    for (int i = 1; i < r; i++) {
        if (x > speed) {
            x = ModularMultiplication(x, x, n);
        }
        else x = (x * x) % n;
        if (x == 1) {
            return false;
        }
        if (x == n - 1) {
            return true;
        }
    }
    return false;
}
bool isPrime(long long n) {
    if (n < 2) { return false; }
    else if (n < 4) { return true; }
    else if (n % 2 == 0) { return false; } //Three time for general purposes about 99% sure is prime 
    for (int k = 0; k < 3; k++) { if (!MillerRabin(n)) { return false; } } return true;
}
int main() {
    long long n; cin >> n;
    cout << isPrime(n);

    return 0;
}