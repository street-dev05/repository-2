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
    string text = "Задано текст i натуральне число n > 50. Відредагувати текст так, щоб його ширина становила n символiв. Абзаци слід зберегти як два символи нового рядка";
    int width;
    cout << "Введіть ширину тексту (n > 50): ";
    cin >> width;
    if (width > 50) {
        cout << formatText(text, width) << endl;
    } else {
        cout << "Ширина повинна бути більше 50" << endl;
    }
    return 0;
}