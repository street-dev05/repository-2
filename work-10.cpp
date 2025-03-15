#include <iostream>
#include <vector>
using namespace std;

void findMagicVectors(vector<int>& vec, int index, int remainingSum, int remainingProduct, int N) {
    if (index == N) {
        if (remainingSum == 0 && remainingProduct == 1) {
            for (int i = 0; i < N; ++i) {
                if (i != 0) cout << ",";
                cout << vec[i];
            }
            cout << endl;
        }
        return;
    }

    int start = (index == 0) ? 1 : vec[index - 1];
    for (int i = start; i <= remainingSum; ++i) {
        if (remainingProduct % i == 0) {
            vec[index] = i;
            findMagicVectors(vec, index + 1, remainingSum - i, remainingProduct / i, N);
        }
    }
}

int main() {
    int N;
    cout << "¬вед≥ть N: ";
    cin >> N;

    vector<int> vec(N);
    findMagicVectors(vec, 0, N, N, N);

    return 0;
}