#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    if(nums.size() <= 1){
        return nums.size();
    }

    // for (int go : nums){
    //     for(int i= 1 ; i < nums.size(); i++){
    //         if (nums.at(i) == go){
    //             nums.erase(nums.begin() + i );
    //         }        
    //     }
    // }

    for (int select =0; select < nums.size(); select++){
        for(int remove = select+1; remove < nums.size(); remove++){
            if (nums.at(select) == nums.at(remove) ){
                nums.erase(nums.begin() + remove);
                remove--;
            }
            else if (nums.at(select) != nums.at(remove))
            {
                break;
            }
            
        }
    } 

    for (int go : nums){
        cout << go << endl;
    }
    cout<<endl;

    return nums.size();
}

int main(){

    vector<int> nums = {1,1,2};
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums3 = {1,1};
    vector<int> nums4 = {1,2};
    removeDuplicates(nums);
    removeDuplicates(nums2);
    removeDuplicates(nums3);
    removeDuplicates(nums4);
}