#include<iostream>
#include<string>
using namespace std;

string intToRoman(int num);

int main(){
    int intero;
    cout << ">";
    cin >> intero;

    string risultato = intToRoman(intero);

    cout << risultato << endl;

    return 0;
}

string intToRoman(int num) {
    string unita[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string decine[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string centinaia[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string migliaia [] = {"","M","MM","MMM"};

    return migliaia[num/1000] + centinaia[(num%1000)/100] + decine[(num%100)/10] + unita[num%10];
}