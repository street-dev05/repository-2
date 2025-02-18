#include <iostream>
#include <vector>

void printPascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    printPascalsTriangle(n);

    return 0;
}
