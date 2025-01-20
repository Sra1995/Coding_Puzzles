#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

unsigned int SumNAT(int a){
    unsigned int sum = 0;
    unordered_set<int> unqi_multiples;
    
    for ( int i = 3; i < a; i+=3){
        sum += i;
        unqi_multiples.insert(i);
    }
    
    for (int i = 5; i < a; i+=5){
        if ( unqi_multiples.find(i) == unqi_multiples.end()){
            sum += i;
        }
    }
    return sum;
}
/*
idea was to go through multiples of 3 first and hash it in set so that if I run into something like
number 15 which is multiple of both I don't overlap and do redundunt work.

However, this method only passed 4 testcases out of 6
reason being needing to use the Sum of n Natural Numbers Formula

*/

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));
        cout << SumNAT(n)<< endl;
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
