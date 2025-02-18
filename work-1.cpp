#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть n: ";
    std::cin >> n;

    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            int c = std::sqrt(a * a + b * b);
            if (c <= n && a * a + b * b == c * c) {
                std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
            }
        }
    }

    return 0;
}
