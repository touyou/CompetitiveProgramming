#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef map<string, vector<int> > bmap;

int main() {
    string word;
    int page;
    bmap words;
    while (cin >> word >> page) {
        if (words.find(word)==words.end()) {
            vector<int> pages;
            pages.push_back(page);
            words[word] = pages;
        } else {
            words[word].push_back(page);
        }
    }
    bmap::iterator it;
    for (it=words.begin(); it!=words.end(); it++) {
        sort((*it).second.begin(), (*it).second.end());
        cout << (*it).first << endl;
        for (int i=0; i<(*it).second.size()-1; i++) {
            cout << (*it).second[i] << " ";
        }
        cout << (*it).second[(*it).second.size()-1] << endl;
    }
}
