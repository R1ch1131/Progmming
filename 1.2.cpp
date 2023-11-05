#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

int main() {
    vector<int> vect = {4, 5, 5, 4};
    int index = removeElement(vect, 4);
    
    cout << "Modified Array: ";
    for (int i = 0; i < index; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
    
    cout << "New Length: " << index << endl;
    
    return 0;
}

