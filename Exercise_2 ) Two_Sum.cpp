//Program must get 2 positions of a vector containing numbers wich, if summed up, give a target
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<unordered_map> //Allows to use unordered_maps
using namespace std;

#include "Functions.h" //Include code from a separete file

vector<int> twoSum(vector<int>& nums, int target); //Calls a function (bottom of the file)

int main(){

    write_on_file(); //Calls a function from another file

    vector<int> dataArray;      //Declare a vector of integers

    //Open a file for reading
    ifstream inputFile("file.txt");     

    int num;
    //Passes all the numbers to the vector through an integer
    while(inputFile >> num){
        dataArray.push_back(num);      
    }

    //Closes the file when it's done
    inputFile.close();  
    cout << endl;
    
    //The user must insert a target
    int target;
    cout << "Inserisci un target: ";
    cin >> target;

    //Calling the function
    vector<int> result = twoSum(dataArray, target);      

    cout << result[0] << " "<< result[1] <<endl;
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> myNums;  //Declares an unoredered_map

    //Finds the pair of position of interest
    for(int i = 0; i < nums.size(); i++){
        //We need a complement for each element of the array's element
        int complement = target - nums[i];

        //If the complement exist in the map and it isn't the same element we print the 2 positions
        if(myNums.count(complement)){
            return {i,myNums[complement]};
        }
        myNums[nums[i]] = i;
    }

    return{};
}