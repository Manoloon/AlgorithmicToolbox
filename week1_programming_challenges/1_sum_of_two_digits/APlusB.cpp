#include <iostream>

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
	int first = 0;
	int second = 0;
	std::cin >> first;
	std::cin >> second;
	int result = sum_of_two_digits(first,second);
	std::cout << result << std::endl;
    return 0;
}