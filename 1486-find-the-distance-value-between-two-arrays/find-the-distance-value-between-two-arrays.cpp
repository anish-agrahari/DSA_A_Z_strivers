class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));

        int count = 0;

        int n = arr2.size();

        for(int i = 0; i < arr1.size(); i++) {
            int j = lower_bound(begin(arr2), end(arr2), arr1[i]) - begin(arr2);

            if(j == 0) { //all elements are greater or equal to arr1[i]
                count += (arr2[0] - arr1[i]) > d;
            } else if(j >= n) { //all elements are smaller than arr1[i]
                count += (arr1[i] - arr2[n-1]) > d;
            } else {
                count += (arr2[j] - arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
            }
        }

        return count;
    }
};