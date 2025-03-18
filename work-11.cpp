#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct City {
    int x, y;
};

int findMedian(vector<int>& coords) {
    sort(coords.begin(), coords.end());
    int n = coords.size();
    if (n % 2 == 0) {
        return (coords[n / 2 - 1] + coords[n / 2]) / 2;
    } else {
        return coords[n / 2];
    }
}

City findCapital(vector<City>& cities) {
    vector<int> xCoords, yCoords;
    for (const auto& city : cities) {
        xCoords.push_back(city.x);
        yCoords.push_back(city.y);
    }

    City capital;
    capital.x = findMedian(xCoords);
    capital.y = findMedian(yCoords);
    return capital;
}

int main() {
    int N;
    cout << "Введіть кількість міст: ";
    cin >> N;

    vector<City> cities(N);
    cout << "Введіть координати міст (x y):" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }

    City capital = findCapital(cities);
    cout << "Координати столиці: (" << capital.x << ", " << capital.y << ")" << endl;

    return 0;
}
