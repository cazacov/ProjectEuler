/*
 * Project Euler
 * Problem 59, XOR decryption
 *
 * Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code
 * for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value,
 * taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text,
 * restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of
 * random bytes. The user would keep the encrypted message and the encryption key in different locations, and without
 * both "halves", it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key.
 * If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message.
 * The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt
 * (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that
 * the plain text must contain common English words, decrypt the message and find the sum of the ASCII values
 * in the original text.
 */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <numeric>

void decode(const std::vector<u_int8_t> &data, const std::vector<u_int8_t> &key, std::vector<u_int8_t> &result);
std::vector<u_int8_t> read_data(const char *file_name);

bool is_english_text(const std::vector<u_int8_t> &data, int pos, int step);


int main() {

    auto data = read_data("cipher.txt");
    std::vector<u_int8_t> key(3, 0);
    std::vector<u_int8_t> decrypted(data.size());

    for (int i = 0; i < key.size(); i++) {
        do {
            decode(data, key, decrypted);
            if (is_english_text(decrypted, i, key.size())) {
                break;
            }
            if (key[i] == 255) {
                std::cout << "Cannot break the cipher.";
                exit(0);
            }
            key[i]++;
        } while(key[i] != 0);
    }

    std::string result;
    int ascii_sum = 0;

    for (auto ch : decrypted) {
        ascii_sum += ch;
        result += char(ch);
    }
    std::cout << "Decrypted text:" << result << std::endl;
    std::cout << "Answer:" << ascii_sum << std::endl;

    return 0;
}


void decode(const std::vector<u_int8_t> &data, const std::vector<u_int8_t> &key, std::vector<u_int8_t> &result) {
    auto key_pos = 0;
    auto res = result.begin();
    for (auto elem: data ) {
        *res++ = elem ^ key[key_pos];
        key_pos++;
        if (key_pos >= key.size()) {
            key_pos = 0;
        }
    }
}

std::vector<u_int8_t> read_data(const char *file_name) {
    std::vector<u_int8_t> result;

    std::ifstream  data(file_name);
    std::string line;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string number;
        while(std::getline(lineStream, number,','))
        {
            result.push_back((u_int8_t)stoi(number));
        }
    }
    return result;
}

bool is_english_text(const std::vector<u_int8_t> &data, int pos, int step) {

    std::map<u_int8_t, int> frequency;
    int count = 0;

    auto index = pos;
    while (index < data.size()) {
        auto key = data[index];
        if (frequency.count(key)){
            frequency[key] = frequency[key] + 1;
        }
        else {
            frequency[key] = 1;
        }
        count++;
        index+=step;
    }

    auto cnt = [](int acc, std::pair<u_int8_t, int> pair) {
        int ch = pair.first;

        if (isblank(ch) || isalpha(ch) || isdigit(ch) || ch=='.') {
            return acc + pair.second;
        } else {
            return acc;
        }
    };

    // Check that at least 90% of characters are alphanumeric or punctuation
    auto alpha_chars = std::accumulate(frequency.begin(), frequency.end(), 0, cnt);

    if (alpha_chars < count * 0.9) {
        return false;
    }

    for (auto pair : frequency) {
        frequency[pair.first] = pair.second * 100 / count;
    }

    if (!frequency.count('e') || frequency['e'] < 8) {
        return false;
    }

    if (!frequency.count('t') || frequency['t'] < 5) {
        return false;
    }
    if (!frequency.count('a') || frequency['a'] < 3) {
        return false;
    }

    if (!frequency.count('o') || frequency['o'] < 3) {
        return false;
    }

    return true;
}


