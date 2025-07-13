class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int mx=INT_MIN;
        vector<int> lead;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>=mx){
                lead.push_back(arr[i]);
                mx=arr[i];
            }
        }
        reverse(lead.begin(),lead.end());
        return lead;
    }
};

