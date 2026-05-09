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

unsigned long long nPr(unsigned long long n, unsigned long long r) {
	if (r > n) {
		cerr << "Input Error";
		return 0;
	}
	if (r == 0) {
		return 1;
	}
	unsigned long long p = 1;
	for (unsigned long long i = 0; i < r; i++) {
		unsigned long long old_p = p;
		p *= (n - i);
		if (p / (n - i) != old_p) {
			cerr << "Overflow";
			return 0;
		}
	}
	return p;
}


unsigned long long nCr(unsigned long long n, unsigned int r) {
	if (r > n) {
		cerr << "Invalid Input";
		return 0;
	}

	r = min(r, (unsigned int)(n - r));
	long double sum = 1;

	for (unsigned int i = 1; i <= r; i++) {
		sum = sum * (n - r + i) / i;
		if (sum < 0 || sum > 1.84e19L) {
			cerr << "Overflow";
			return 0;
		}
	}

	return (unsigned long long)round(sum);
}


long long nthCatalanNumber(int n) {
	return nCr(2 * n, n) / (n + 1);
}

vector<vector<long long>> PascalTriangle(int n) {
	vector<vector<long long>> matrix(n + 1, vector<long long>(n + 1, 0)); // row 0 included
	matrix[0][0] = 1;

	if (n == 0) {
		return matrix;
	}

	if (n > 63) {
		cerr << "Memory Overflow";
		return {}; // return empty matrix to satisfy return type
	}

	for (int i = 1; i <= n; i++) {
		matrix[i][0] = 1; // first element always 1
		for (int j = 1; j <= i; j++) {
			matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
		}
	}

	return matrix;
}

int main() {


	return 0;
}