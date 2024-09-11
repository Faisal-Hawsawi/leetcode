#include <iostream>
#include <vector>
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
    int size = nums.size();
    quick_sort(nums, 0, size - 1);

    // for (int i = 0; i < nums.size(); i++){ 
    //     cout << nums.at(i) << endl;
    // }

    int end = nums.size()-1;
    int start = 0;

    while (end > start){
        int is_equal_to_target = nums.at(start) + nums.at(end);
        if (is_equal_to_target == target){
            ans.push_back((start));
            ans.push_back((end));
            end--;
        }
        else if (is_equal_to_target > target){
            end--;
        }
        else if (is_equal_to_target < target){
            start++;
        }
    }

    for (int i = 0; i < ans.size(); i++){ 
        cout << ans.at(i) << endl;
    }
    
    return ans;
}

int main(void){
    
    vector<int> arr = {2,7,11,15};
    twoSum (arr, 9);
}
