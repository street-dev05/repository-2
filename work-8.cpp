#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string& str) {
    vector<string> words;
    istringstream stream(str);
    string word;
    while (stream >> word) {
        words.push_back(word);
    }
    return words;
}

string formatText(const string& text, int width) {
    vector<string> words = split(text);
    string formattedText;
    string line;
    for (const string& word : words) {
        if (line.length() + word.length() + 1 > width) {
            formattedText += line + "\n";
            line = word;
        } else {
            if (!line.empty()) line += " ";
            line += word;
        }
    }
    if (!line.empty()) {
        formattedText += line + "\n";
    }
    return formattedText;
}

int main() {
    string text = "������ ����� i ���������� ����� n > 50. ³����������� ����� ���, ��� ���� ������ ��������� n ������i�. ������ ��� �������� �� ��� ������� ������ �����";
    int width;
    cout << "������ ������ ������ (n > 50): ";
    cin >> width;
    if (width > 50) {
        cout << formatText(text, width) << endl;
    } else {
        cout << "������ ������� ���� ����� 50" << endl;
    }
    return 0;
}