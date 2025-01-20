#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long long sum_of_natural_numbers(int end, int step){
    // count of multiples
    int count = (end - 1) / step;
    
    // sum of arithmetic progressions
    return static_cast<long long>(count) * ( count + 1) * step / 2;
}

long long solution_closed_form(int n){
    return sum_of_natural_numbers(n, 3) + sum_of_natural_numbers(n, 5) - sum_of_natural_numbers(n, 15);
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
        cout << solution_closed_form(n)<< endl; // call it out for test
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
