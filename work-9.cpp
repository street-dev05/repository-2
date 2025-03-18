#include <string>
#include <bitset>
using namespace std;

string charToBinary(char c) {
    return bitset<8>(c).to_string();
}

string encrypt(string text, string phrase) {
    string binaryPhrase = "";
    for (char c : phrase) {
        binaryPhrase += charToBinary(c);
    }
    string encryptedText = "";
    int phraseIndex = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        encryptedText += text[i];
        if (text[i] == ' ' && phraseIndex < binaryPhrase.size()) {
            if (binaryPhrase[phraseIndex] == '1') {
                encryptedText += ' ';
            }
            ++phraseIndex;
        }
    }
    return encryptedText;
}

string decrypt(string encryptedText) {
    string binaryPhrase = "";
    for (size_t i = 0; i < encryptedText.size() - 1; ++i) {
        if (encryptedText[i] == ' ' && encryptedText[i + 1] == ' ') {
            binaryPhrase += '1';
            ++i;
        } else if (encryptedText[i] == ' ') {
            binaryPhrase += '0';
        }
    }
    string phrase = "";
    for (size_t i = 0; i < binaryPhrase.size(); i += 8) {
        bitset<8> charBits(binaryPhrase.substr(i, 8));
        phrase += static_cast<char>(charBits.to_ulong());
    }
    return phrase;
}

int main() {
    setlocale(LC_ALL, ""); // Устанавливаем локаль
    string text = "Це приклад тексту для шифрування за допомогою стеганографії.";
    string phrase = "hello";

    string encryptedText = encrypt(text, phrase);
    cout << "Зашифрований текст: " << encryptedText << endl;

    string decryptedPhrase = decrypt(encryptedText);
    cout << "Розшифрована фраза: " << decryptedPhrase << endl;

    return 0;
}
