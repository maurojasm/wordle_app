#include <iostream>
#include <vector>
#include <fstream>

#include "../include/wordle.h"

using std::string;
using std::vector;
using std::cout;


int main() {
    Wordle game;
    string guess;
    int sum = 0, tries = 0;

    while (std::cin >> guess) {
        if (guess.size() != 5 || !game.is_valid_guess(guess)) { printf("Try Again!\n"); continue; }
        sum = 0; ++tries;
        vector<int> result = game.play(guess);

        for (int x : result) {
            sum += x;
            // cout << x << ' '; //debug
        }
        // cout << '\n';

        if (sum == 10) {
            cout << "Correct! Tries: " << tries << '\n';
            return 0;
        }
    }

    return 0;
}