class Solution {
public:
    vector<int> generateRow(int n) {

        vector<int> row;
        row.push_back(1);

        long long ans = 1;

        for (int col = 1; col < n; col++) {

            ans = ans * (n - col);
            ans = ans / col;

            row.push_back(ans);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};