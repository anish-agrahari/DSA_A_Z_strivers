// class Solution {
// public:
//     vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
//     }
// };

class Solution {
public:
    vector<vector<int>> g, ng;   // g = original tree, ng = naya tree
    vector<int> newPar, last, ans;
    string str;

    // Step 1: har node ka naya parent nikalo (original tree pe)
    void dfs1(int x) {
        int c = str[x] - 'a';
        int prev = last[c];              // is letter ka purana nazdeeki ancestor
        if (x != 0 && prev != -1) newPar[x] = prev;
        last[c] = x;
        for (int ch : g[x]) dfs1(ch);
        last[c] = prev;                  // backtrack
    }

    // Step 2: naye tree me subtree size
    int dfs2(int x) {
        int sz = 1;
        for (int ch : ng[x]) sz += dfs2(ch);
        return ans[x] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        str = s;
        g.assign(n, {});
        ng.assign(n, {});
        newPar = parent;
        last.assign(26, -1);
        ans.assign(n, 0);

        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);

        dfs1(0);

        for (int i = 1; i < n; i++) ng[newPar[i]].push_back(i);

        dfs2(0);
        return ans;
    }
};