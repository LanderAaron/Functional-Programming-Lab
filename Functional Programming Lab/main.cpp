#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <iterator>
using namespace std;

// Non-pure
void print_pairs(vector <pair<int, string>> v) {
    for (const auto &i : v) {
        cout << i.first << " " << i.second << endl;
    }
}

// Pure
vector <pair<int, string>> sort_by_frequency(vector <pair<int, string>> v) {
    sort(v.begin(), v.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first != b.first) {
            return a.second > b.second;
        }
        return a.second < b.second;
    });
    return v;
}

// Pure
vector <pair<int, string>> reverse_pairs(unordered_map<string, int> pairs) {
    vector<pair<int, string>> resultPairs;
    for (const auto &i : pairs) {
        resultPairs.push_back({i.second, i.first});
    }
    return resultPairs;
}

// Pure
unordered_map<string, int> count_occurences(vector<string> names) {
    unordered_map<string, int> countOcurrence;
    for_each(names.begin(), names.end(), [&countOcurrence] (const string& name) {
        countOcurrence[name]++;
    });
    return countOcurrence;
}

// Use transform and a for-loop; Pure
vector<string> words(string text) {
    
    transform(text.begin(), text.end(), text.begin(), [](char c) {
        return isalnum(c) ? c : ' ';
    });
    
    vector<string> stringResult;
    istringstream iss(text);
    for (string w; iss >> w; ) {
        stringResult.push_back(w);
    }
    return stringResult;
}

// Non-pure
void print_common_words(string text) {
    vector<string> w = words(text);
    unordered_map<string, int> m = count_occurences(w);
    vector<pair<int, string>> r = reverse_pairs(m);
    vector<pair<int, string>> s = sort_by_frequency(r);
    print_pairs(s);
}

int main() {
    print_common_words("How much wood would a woodchuck chuck if a woodchuck could chuck wood? A woodchuck would chuck as much wood as a woodchuck would if a woodchuck could chuck wood.");
}
