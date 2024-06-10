//The program finds duplicate elements in an array
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
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
    //It sorts the array from smallest to largest element
    sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); i++){

        //Checks if there are adjacents elements
        if (nums[i] == nums[i+1]){
            return true;
        }
    }

    return false;
}