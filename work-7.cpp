#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<pair<int, int>> findPrimePairs(int n) {
    vector<pair<int, int>> primePairs;
    for (int i = n; i <= 2 * n - 2; ++i) {
        if (isPrime(i) && isPrime(i + 2)) {
            primePairs.push_back(make_pair(i, i + 2));
        }
    }
    return primePairs;
}

int main() {
    int n;
    cout << "¬вед≥ть число: ";
    cin >> n;
    vector<pair<int, int>> primePairs = findPrimePairs(n);
    for (const auto& pair : primePairs) {
        cout << pair.first << ", " << pair.second << endl;
    }
    return 0;
}
