//The program finds duplicate elements in an array
#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_set>
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
    unordered_set<int> search;     
    
    //Use an unordered set to see if an element is already sotored while running on the array memory
    for(int i : nums){
        if(search.count(i) > 0){
            return true;
        }

        search.insert(i);
    }
    
    return false;
}