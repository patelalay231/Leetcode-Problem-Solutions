#define MOD 1000000007
class Solution {
public:
    void findRightLesser(int n, vector<int>& arr, vector<int>& rightLesser) {
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            rightLesser[i] = cnt;
        }
    }

    void findLeftLesser(int n, vector<int>& arr, vector<int>& leftLesser) {
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            leftLesser[i] = cnt;
        }
    }

    void findRightGreater(int n, vector<int>& arr, vector<int>& rightGreater) {
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!st.empty() && st.top().first <= arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            rightGreater[i] = cnt;
        }
    }

    void findLeftGreater(int n, vector<int>& arr, vector<int>& leftGreater) {
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!st.empty() && st.top().first < arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            leftGreater[i] = cnt;
        }
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightLesser(n, 0);
        vector<int> leftLesser(n, n);
        vector<int> rightGreater(n, 0);
        vector<int> leftGreater(n, n);
        findRightLesser(n, arr, rightLesser);
        findLeftLesser(n, arr, leftLesser);
        findRightGreater(n, arr, rightGreater);
        findLeftGreater(n, arr, leftGreater);

        long long minimumSum = 0;
        long long maximumSum = 0;
        for (int i = 0; i < n; i++) {
            minimumSum += (long long)(rightLesser[i] * leftLesser[i]) * arr[i];
            maximumSum += (long long)(rightGreater[i] * leftGreater[i]) * arr[i];
        }

        return (maximumSum - minimumSum);
    }
};