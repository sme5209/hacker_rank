#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

#define HG_NUM 16
#define HG_COL 4
#define HG_ROW 4

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) {
    // approach row-wise
    /* rows broken down as follows:
    *   rows 0 and 5 - form only top or bottom of hourglasses
    *   rows 1 and 4 - form top or bottom, and middle of hourglasses
    *   rows 2 and 3 - form top, bottom, and middle of hourglasses
    *       only need to compute top or bottom, not both
    *
    *  columns broken down as follows:
    *   colums 0 and 5 - form only left or right side of hourglasses
    *   columns 1 and 4 - form left or right side, and middle
    *   columns 2 and 3 - form left, right, and middle
    */

    int max_val = 0;
    // allocate vector for sums (4x4 filled with zeros)
    vector<int> sums(HG_ROW * HG_COL, 0);
    for (auto i = 0; i < (int)arr.size(); i++) {
        for (auto j = 0; j < (int)arr[i].size(); j++) {

            cout << "Current input vector value: " << arr[i][j] << endl;

            // sums vector output (in grid)
            cout << "Sum vector values:" << endl;
            for (vector<int>::iterator k = sums.begin(); k != sums.end(); k++) {
                cout << *k << " ";
                if (((k - sums.begin()) + 1) % 4 == 0) {
                    cout << endl;
                }
            }
            cout << endl;

            if (i < 3) {
                if (j < 3) {
                    sums[i * HG_COL] += arr[i][j];
                    if (j > 0) {
                        sums[i * HG_COL + 1] += arr[i][j];
                        if (j > 1) {
                            sums[i * HG_COL + 2] += arr[i][j];
                        }
                    }
                }
                else if (j < 6) {
                    sums[i * HG_COL + 3] += arr[i][j];
                    if (j < 5) {
                        sums[i * HG_COL + 2] += arr[i][j];
                        if (j < 4) {
                            sums[i * HG_COL + 1] += arr[i][j];
                        }
                    }
                }
                if (i > 0) {
                    if (j > 0 && j < 5) {
                        sums[(i - 1) * HG_COL + (j - 1)] += arr[i][j];
                    }
                }
                if (i > 1) {
                    if (j < 3) {
                    sums[(i - 2) * HG_COL] += arr[i][j];
                        if (j > 0) {
                            sums[(i - 2) * HG_COL + 1] += arr[i][j];
                            if (j > 1) {
                                sums[(i - 2) * HG_COL + 2] += arr[i][j];
                            }
                        }
                    }
                    else if (j < 6) {
                        sums[(i - 2) * HG_COL + 3] += arr[i][j];
                        if (j < 5) {
                            sums[(i - 2) * HG_COL + 2] += arr[i][j];
                            if (j < 4) {
                                sums[(i - 2) * HG_COL + 1] += arr[i][j];
                            }
                        }
                    }
                }
            }
            else if (i < 6) {
                int new_i = i - (HG_ROW / 2);
                if (j < 3) {
                    sums[new_i * HG_COL] += arr[i][j];
                    if (j > 0) {
                        sums[new_i * HG_COL + 1] += arr[i][j];
                        if (j > 1) {
                            sums[new_i * HG_COL + 2] += arr[i][j];
                        }
                    }
                }
                else if (j < 6) {
                    sums[new_i * HG_COL + 3] += arr[i][j];
                    if (j < 5) {
                        sums[new_i * HG_COL + 2] += arr[i][j];
                        if (j < 4) {
                            sums[new_i * HG_COL + 1] += arr[i][j];
                        }
                    }
                }
                if (i < 5) {
                    if (j > 0 && j < 5) {
                        sums[(new_i + 1) * HG_COL + (j - 1)] += arr[i][j];
                    }
                }
                if (i < 4) {
                    if (j < 3) {
                    sums[(new_i + 2) * HG_COL] += arr[i][j];
                        if (j > 0) {
                            sums[(new_i + 2) * HG_COL + 1] += arr[i][j];
                            if (j > 1) {
                                sums[(new_i + 2) * HG_COL + 2] += arr[i][j];
                            }
                        }
                    }
                    else if (j < 6) {
                        sums[(new_i + 2) * HG_COL + 3] += arr[i][j];
                        if (j < 5) {
                            sums[(new_i + 2) * HG_COL + 2] += arr[i][j];
                            if (j < 4) {
                                sums[(new_i + 2) * HG_COL + 1] += arr[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Finished logic loop" << endl;
    // flattened hourglass sums data structure would work better
    max_val = *max_element(sums.begin(), sums.end());
     cout << "All computed values: " << endl;
    for (auto iter: sums) {
        cout << iter << endl;
    }
    cout << endl << "Computed max value: " << max_val << endl;
    return max_val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

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
