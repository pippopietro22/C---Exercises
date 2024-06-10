//This program takes an array where every number is written twice, exeption made for two of theme, and tells who are the two single numbers. 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<int> numberIII(vector<int> nums);

int main(){
    int num;
    vector<int> nums;
    
    ifstream inputFile ("file.txt");        //Read the array from a file
    if(!inputFile){
        cerr << "Error opening file." << endl;  //It stops if there is a problem with file.txt
        return 1;
    }

    while (inputFile >> num){
        nums.push_back(num);        //passes the number one by one from the file to the array (vector)
    }

    vector<int> result = numberIII(nums);   //Executes the program

    cout << result[0] << " " << result[1] << endl;  

    return 0;
}

vector<int> numberIII(vector<int> nums){
    int overallXor = 0;     //This is the variable where we are going to binary xor all the numbers
    int n = nums.size();

    for(int i = 0; i < n; i++){
        overallXor ^= nums[i];      //The result will tell where the 2 numbers differ
    }

    int bitPosition = 1;
    while(((overallXor >> bitPosition) & 1) == 0){  // We find the a position, in the overallXor, where the two numbers differs
        bitPosition++;
    }

    int firstGroup = 0;         //This are made to group the numbers with different bit in the position of interest
    int secondGroup = 0;
    for(int i = 0; i < n; i++){
        if(((nums[i] >> bitPosition) & 1) == 1){
            firstGroup ^= nums[i];
        }else{
            secondGroup ^= nums[i];
        }
    }

    return {firstGroup, secondGroup};    //This are the two single numbers
}