//This program finds the longest palindrom substring of an array
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestPalindrome(string s);

int main(){
    string input;
    bool check = true;

    cout << "INSERT STRING" << endl;

    while(check){
        cout << ">";
        cin >> input;

        if(input == "*") break;

        string result = longestPalindrome(input);

        cout << result << endl;
    }
    
    return 0;
}

string longestPalindrome(string s) {
    if(s.empty()) return "";

    int n = s.length();

    if(n == 1) return s;

    int start = 0;
    int maxLen = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false)); //It works with a bidimensional bool array

    for(int i = 0; i < n; i++){
        dp[i][i] = true;        //Every single character is palindrom by itself
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;      //If to adjacent char are the same, we have a 2 char palindrome string
            maxLen = 2;
            start = i;
        }
    }

    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n; i++){
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1]){   //Here we search for palindrome substrings longest than 2 chars
                dp[i][j] = true;
                maxLen = len;
                start = i;
            }
        }
    }

    return s.substr(start,maxLen);
}