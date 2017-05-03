#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

struct SMSLanguage {
    string text;
    string ans;

    string translate(string _text) {
        text = _text;
        ans = "";
        for (int i=0; i<text.length(); i++) if (text[i] >= 'A' && text[i] <= 'Z') text[i] = text[i] - 'A' + 'a';
        for (int i=0; i<text.length(); i++) {
          if (text[i]=='a' && i<text.length()-2) {
            if (text[i+1]=='n' && text[i+2]=='d') {
              ans.push_back('&'); i += 2; continue;
            }
            if (text[i+1]=='t' && text[i+2]=='e') {
              ans.push_back('8'); i += 2; continue;
            }
          }

          if (text[i]=='a' && i<text.length()-1) {
            if (text[i+1]=='t') {
              ans.push_back('@'); i++; continue;
            }
          }

          if (i<text.length()-2 && text[i]=='y' && text[i+1]=='o' && text[i+2]=='u') {
            ans.push_back('U'); i += 2; continue;
          }

          if (!(text[i]=='.' || text[i]==',' || text[i]=='?' || text[i]=='!')) ans.push_back(text[i]);
        }
        return ans;
    }
};

// CUT begin
ifstream data("SMSLanguage.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string text, string __expected, int caseNo) {
    time_t startClock = clock();
    SMSLanguage *instance = new SMSLanguage();
    string __result = instance->translate(text);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;
    cout << "  Testcase #" << caseNo << " ... ";
    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string text;
        from_stream(text);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        if ( do_test(text, __answer, cases - 1)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1429709630;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "SMSLanguage (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
