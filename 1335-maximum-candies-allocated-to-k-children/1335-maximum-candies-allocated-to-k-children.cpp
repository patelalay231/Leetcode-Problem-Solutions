class Solution {
public:
    int maximumCandies(vector<int>& arr, long long k) {
          long long int result = 0 ;
          long long int low  = 1;
          auto it = max_element(arr.begin() , arr.end());
          long long int high = (long long int)(*it);
          int n = arr.size();
          while(low <= high){
              long long int mid = low + (high - low)/2;
              long long int count = 0;
              for(int i = 0 ; i < n ; i++){
                  count += ((long long int)arr[i] / mid);
                  if(count >= k)break;
              }
              if(count >= k){
                   result = mid;
                   low = mid + 1;
               }else{
                   high = mid - 1;
              }
          }
          return result;
    }
};