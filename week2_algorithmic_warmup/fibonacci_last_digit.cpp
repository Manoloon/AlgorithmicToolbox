#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
long long get_fibonacci_last_digit_fast(int n)
{
	if(n <= 1) return 1;
	
	int current = 1;
	int previous = 0;
	for(int i = 2; i <= n; i++)
	{
		int newCurrent = (previous + current)%10;
		previous = current;
		current = newCurrent;
	}
	return current * 1LL;
}
int main() {
    int n;
    std::cin >> n;
    auto c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
