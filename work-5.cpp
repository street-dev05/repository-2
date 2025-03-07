#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (isPalindrome(i) && isPalindrome(i * i)) {
            cout << i << " " << i * i << endl;
        }
    }
    return 0;
}
