#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int n;
    cout << "Введіть число: ";
    cin >> n;
    vector<int> factors = primeFactors(n);
    cout << n << " = ";
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << factors[i];
    }
    cout << endl;
    return 0;
}
