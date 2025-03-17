#include "../include/wordle.h"

Wordle::Wordle() {
    srand(time(0));
    std::ifstream list("assets/word_list.txt");
    string input;
    while (list >> input) {
        this->word_list.push_back(input);
    }
    this->answer = this->word_list[rand() % this->word_list.size()];
    // this->answer = this->word_list[0]; // debug
}

bool Wordle::is_valid_guess(string guess) {
    for (char& c : guess) { c = toupper(c); }
    auto it = std::find(this->word_list.begin(), this->word_list.end(), guess);
    return it != this->word_list.end() ? true : false;
}

vector<int> Wordle::play(string guess) {
    for (char& c : guess) { c = toupper(c); }

    vector<int> result(5, 0);
    string sub = this->answer;
    for (int i = 0; i < 5; i++) {
        // std::cout << sub << '\n'; // debug
        if (this->answer[i] == guess[i]) {
            result[i] = Colors::GREEN;
            sub[i] = '_';
        }
        else {
            size_t pos = sub.find(guess[i]);
            if (pos != string::npos && result[pos] != Colors::GREEN) {
                result[i] = Colors::YELLOW;
                sub[pos] = '_';
            }
        }
    }
    print_result(result, guess);
    return result;
}

void Wordle::print_result(vector<int> result, string guess) {
    for (int i = 0; i < 5; i++) {
        std::cout << color_vals[result[i]] << guess[i] << color_vals[0];
    }
    std::cout << '\n';
}