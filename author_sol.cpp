#include <bits/stdc++.h>

using namespace std;

vector<int> prime;

void Sieve(int n) {
	bool p[n + 1];
	memset(p, true, sizeof(p));
	for (int i = 2; i * i <= n; i++) {
		if (p[i]) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (p[i]) {
			prime.emplace_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// precompute all the prime numbers from 1 up to 'n'
	Sieve(n);
	int cnt = 0;
	// start the loop from 6 up to 'n' (since numbers 1 to 5 are not valid)
	for (int i = 6; i <= n; i++) {
		int prime_counter = 0;
		// count the number of prime divisors of each number from 6 to 'n' by testing
		// it with all the numbers that was collected from the 'Sieve()' function above
		for (int j = 0; j < (int) prime.size(); j++) {
			if (i % prime[j] == 0) {
				prime_counter++;
			}
		}
		// check if the number of its prime divisors is EXACTLY equal to 2
		if (prime_counter == 2) {
			// if yes, then increment 'cnt'
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
