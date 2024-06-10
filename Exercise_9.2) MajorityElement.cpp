//This program shows a way to find the number that apeares the same times or more than "n/2". Where n/2 is the length of the array.
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<unordered_map>
using namespace std;

#include "Functions.h"

int majorityElement(vector<int>& nums);

int main(){
    vector<int> nums;   //Declares an array

    write_on_file();
    read_from_file(nums);

    int result = majorityElement(nums);     //Execute the program

    cout << result << endl;
    return 0;
}

int majorityElement(vector<int>& nums){
    unordered_map<int,int> search;      //We use an unordered map to see how many times a number is stored in the array

    for(int n : nums){
        search[n]++;
        if(search[n] >= nums.size()/2){ //Then we look for the number stored n/2 times (or more)
            return n;
        }
    }
    return 0;
}