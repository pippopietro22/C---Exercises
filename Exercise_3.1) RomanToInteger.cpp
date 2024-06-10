#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int RomantoInteger(string Roman);

int main(){
    string Number;
    int result;
    cout << "Insert Roman number (CAPS LOCK): ";
    cin >> Number;

    result = RomantoInteger(Number);

    cout << result << endl;

    return 0;
}

int RomantoInteger(string Roman){
    int sum = 0;
    unordered_map<char,int> RomInt;

    RomInt['I'] = 1;
    RomInt['V'] = 5;
    RomInt['X'] = 10;
    RomInt['L'] = 50;
    RomInt['C'] = 100;
    RomInt['D'] = 500;
    RomInt['M'] = 1000;
    RomInt['i'] = 1;
    RomInt['v'] = 5;
    RomInt['x'] = 10;
    RomInt['l'] = 50;
    RomInt['c'] = 100;
    RomInt['d'] = 500;
    RomInt['m'] = 1000;

    for(int i = 0; i < Roman.length(); i++){
        if (RomInt[Roman[i]] >= RomInt[Roman[i+1]]){
            sum += RomInt[Roman[i]];
        }else{
            sum -= RomInt[Roman[i]];
        }
    }

    return sum;
}