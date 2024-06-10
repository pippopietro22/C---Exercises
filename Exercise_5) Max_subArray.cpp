//This prograrm gives the sum of the max subArray into the array given by the user (also printed on a file)
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#include "Functions.h"  //Include a part of code that allows to write on a file

//The function which carry on the job
int maxSubArray(vector<int>& nums);

int main(){
    vector<int> nums;
    int result;

    //Writes on a file the array
    write_on_file();

    //Read the file
    read_from_file(nums);
    
    result = maxSubArray(nums);

    cout << "Maximum sum in this array is: "<< result << endl;

    return 0;
}


int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for(int i = 1; i < nums.size(); i++){
        currentSum = max(nums[i],nums[i] + currentSum);     //If the new number is grater than the currentSum, than we reset the subArray
        maxSum = max(maxSum, currentSum);               //If the currentSum is grater than the maxSum, we have a new maxSum
    }

    return maxSum;
}