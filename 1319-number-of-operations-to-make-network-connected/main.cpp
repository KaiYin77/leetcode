#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {

public:
    void dfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int from){
        visited[from] = true; 
        for (auto i : adj[from]){
            if(!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }
    int makeConnected(int n, std::vector<std::vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        std::vector<std::vector<int>> adj(n);
        for (auto c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        } 
        int components = 0;
        std::vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                components++;
            }
        }
        return components - 1;
    }
};

int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;
    int n =4;
    std::vector<std::vector<int>> connections{
        {0,1},
        {0,2},
        {1,2},
    };
    /*Test case 1*/
    int ans_1 = sol.makeConnected(n, connections);
    std::cout << ans_1 << std::endl;

    return 0;
}
