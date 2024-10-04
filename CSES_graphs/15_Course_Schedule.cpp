#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

const long long MOD = 1000000007;

#define ll long long

using namespace std;

// Description
/*
https://cses.fi/problemset/task/1679
This requires Topo sort.
*/

// Add functions
vector<int> bfs(vector<vector<int>>& nums, vector<int>& indegree) {
    queue<int> q;
    // Push all nodes with zero indegree
    int n = nums.size() - 1;
    for (int i=1; i<=n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for (int neighbor : nums[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }

    if (ans.size() == n) return ans;
    return {};
}

// Main function
int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster I/O
    cin.tie(nullptr); // Untie cin from cout to further improve performance
    // Start code here
    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n+1);    
    vector<int> indegree(n+1);
    for (int j=0; j<m; j++) {
        int a, b;
        cin >> a >> b;
        nums[a].push_back(b);
        indegree[b]++;
    }

    vector<int> ans = bfs(nums, indegree);
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int ele : ans) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return(0);
}