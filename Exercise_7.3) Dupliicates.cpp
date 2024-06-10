//The program finds duplicate elements in an array
#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_map>
using namespace std;

#include "Functions.h"

bool containsDuplicate(vector<int>& nums);

int main(){
    int n;
    bool check;
    vector<int> numeri;

    //The user inserts an array 
    write_on_file();

    //The program reads the array from a file
    read_from_file(numeri);

    //Let's find out
    check = containsDuplicate(numeri);

    //Prints the answer
    if(check){
        cout << "Contains DUPLICATES" << endl;  
    }else{
        cout << "DO NOT contains DUPLICATES" << endl;
    }

    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> search;

    //The map associate zero to every element of the array
    for(int n : nums){
        //If the value is grater or equal than 1, it means that it's already been encoutered
        if(search[n] >= 1){
            return true;
        }

        //It increments the value associeted to every element each cycle
        search[n]++;
    }
    
    return false;
}