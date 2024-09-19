#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int partition(vector<int>& arr, int low, int high){

    //the right element on the array
    int pivot = arr.at(high);

    // postion to swap number less than pivot
    int i = low - 1;
    
    //if found num less than pivot swap (current small) num with old bigger num   
    for (int j = low; j <= high; j++){
        if(arr.at(j) < pivot){
            i++;
            swap(arr.at(i), arr.at(j));
        }
    }

    //swap the pivot in front of the sorted elements 
    swap(arr.at(i+1), arr.at(high));
    return i + 1;
}

void quick_sort(vector<int>& num_list, int low, int high){

    if (low < high){

        int pi = partition(num_list, low, high);

        quick_sort(num_list, low, pi - 1);
        quick_sort(num_list, pi + 1, high);        
    }
}

vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> ans;
    ans.reserve(10);
    unordered_map<int, vector<int>> num_to_pos;
    int size = nums.size();

    for(int i = 0; i < size; i ++){
        num_to_pos[nums.at(i)].push_back(i);
    }

    // if (num_to_pos.find(7) != num_to_pos.end()){
    //     for(int pos : num_to_pos[7]){
    //         cout << "ello? " << pos << " ";
    //     }
    //     cout << endl;
    // }
    //
    // else{
    //     cout << "not there" << endl;
    // }

    // for (auto it : num_to_pos)
    //     cout << "here ello?: " << it.first << " " << it.second.front() << endl; 
    
    quick_sort(nums, 0, size - 1);

    // for (int i = 0; i < nums.size(); i++){ 
    //     cout << nums.at(i) << endl;
    // }

    int end = nums.size()-1;
    int start = 0;


    while (end > start){
        int add1 = nums.at(start) , add2 = nums.at(end);
        int is_equal_to_target = add1 + add2;
        if (is_equal_to_target == target){
            for (int pos : num_to_pos[add1] ){
                // ans.push_back(pos);
                ans.emplace_back(pos);
            }

            if (add1 != add2){
                for (int pos : num_to_pos[add2] ){
                    // ans.push_back(pos);
                    ans.emplace_back(pos);
                }
            }
            end--;
        }
        else if (is_equal_to_target > target){
            end--;
        }
        else if (is_equal_to_target < target){
            start++;
        }
    }

    cout << "your answer: ";
    for (int i = 0; i < ans.size(); i++){ 
        cout << ans.at(i) << " ";
    }
    cout << endl;
    
    return ans;
}

int main(void){
    
    vector<int> arr = {2,7,11,15}; // [0,1]
    vector<int> arr2 = {3,2,4}; // [1,2]
    vector<int> arr3 = {3,3}; // [0,1]
    
    twoSum (arr, 9);
    twoSum (arr2, 6);
    twoSum (arr3, 6);
}
