//The program tells if the number inserted is palindrome
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(int x);

int main(){
    int n;          //an integer that will handle the nuber
    bool check;     //Contains the result, if the nubers is palindrome or not
    string input;   //the actuale variable that gets the input

    //Just an introduction
    cout << "*************" << endl;
    cout << "THIS PROGRAM TELLS WETHER A NUMBER IS PALINDROME OR NOT, NEGATIVE NUMBERS NOT ALLOWED" << endl;
    cout << "write \"*\" to exit the program" <<endl;
    cout << "*************" << endl;

    //Do While that makes the program more user friendly
    while(input != "*"){
        cout << "> ";
        cin >> input;   //Gets the input

        //If the input is a "*", it ends
        if(input == "*") break;

        //Checks if the input is correct
        try{
            check = isPalindrome(input);
        }catch(const invalid_argument&){
            cerr << "Error, input a number or \"*\"" << endl;   //If the input isn't correct, it gives a warning but the program keeps running
            cin.clear();
        }

        //Print the result
        if(check){
            cout << "Palindrome" << endl;
        }else{
            cout << "NOT Palindrome" << endl;
        }
    }

    return 0;
}

//This function actually does the job
bool isPalindrome(string num) {
    //Gets the length of the numer as an array of char
    int len = num.length();

    for(int i = 0; i < len; i++){
        if(num[i] != num[len - 1 - i]) return false;  //Last position of the array just tells when the array has ended, so it's useless
    }  

    return true;     
}