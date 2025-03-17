#include <vector>
#include <fstream>
#include <random>
#include <iostream>
#include <algorithm>

#define Green   "\033[32m"      /* Green */
#define Yellow  "\033[33m"      /* Yellow */
#define Reset   "\033[0m"       /*Reset Color*/

using std::vector;
using std::string;

class Wordle {
public:
    enum Colors { GRAY, YELLOW, GREEN };
    Wordle();
    vector<int> play(string);
    bool is_valid_guess(string);
private:
    void print_result(vector<int>, string);
    string answer;
    vector<string> color_vals = { Reset, Yellow, Green };
    vector<string> word_list;
};