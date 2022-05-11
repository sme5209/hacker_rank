#include <bits/stdc++.h>
#define MAX_JUMPS 2

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/**
 * 
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 * 
 * TODO: figure out what condition isn't accounted for
 * 
 */

void minimumBribes(vector<int> q) {
    // each person in line can bribe at most 2 other people 
    auto num_jumps = 0, shift = 0;
    // alternate implementation
    /*
    vector<int> back_values;
    for (auto i = 0; i < (int)q.size(); i++) {
        shift = q[i] - i - 1;
        if (shift > MAX_JUMPS) {
            cout << "Too chaotic" << endl;
            return;
        }
        // if the value at an index is shifted back in queue, accumulate
        if (shift < 0) {
            num_jumps += abs(shift);
            // check if past shifted-back values
            //  are out-of-order with current shifted-back value
            for (auto iter: back_values) {
                if (iter > q[i]) {
                    num_jumps++;
                }
            }
            back_values.push_back(q[i]);
        }
    }
    */
    int ooo_value = 0;
    for (auto i = 0; i < (int)q.size(); i++) {
        shift = q[i] - i - 1;
        if (shift > MAX_JUMPS) {
            cout << "Too chaotic" << endl;
            return;
        }
        // if the value at an index is shifted back in queue, accumulate
        if (shift < 0) {
            num_jumps += abs(shift);
            // check if most recent shifted-back value
            //  is out-of-order (store most recent shifted-
            //  back value if it is the first one)
            if (!ooo_value || (ooo_value < q[i])) {
                ooo_value = q[i];
            }
            else { // ooo_value > q[i]
                num_jumps++;
            }
        }
    }

    cout << num_jumps << endl;
    return;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
