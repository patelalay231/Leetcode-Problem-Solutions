class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int low = 0;
        int high = arr.size()-1;
        int missing = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low+k;
    }
};