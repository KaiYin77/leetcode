#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int maximalPathQuality(std::vector<int>& values, std::vector<std::vector<int>>& edges, int maxTime) {
      int n = values.size();
      int res = values[0];
      std::vector<std::vector<std::pair<int, int>>> graph(n); 

      for (size_t i=0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]}); 
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]}); 
      }

      std::vector<int> visited(n, 0);
      dfs(graph, values, visited, res, 0, 0, 0, maxTime);
      return res;
    }
    void dfs(
        std::vector<std::vector<std::pair<int, int>>>& graph,
        std::vector<int> & values,
        std::vector<int> & visited,
        int &res, int node, int score, int time, int &maxTime
    ){
        if (time > maxTime) return;
    
        if(visited[node] == 0) {
            score += values[node];
        }
        visited[node]++;
        if(node == 0)
            res = std::max(res, score);
        for (auto it: graph[node]) {
            int neigh = it.first;
            int newTime = time + it.second;
            dfs(graph, values, visited, res, neigh, score, newTime, maxTime);
        }
        visited[node]--;
    }
};


int main(int argc, char* argv[]) {
    /*Initialize Solution Object*/
    Solution sol;

    /*Test case 1*/
    std::vector<int> values {
        0, 32, 10, 43
    };
    std::vector<std::vector<int>> edges {
        {0, 1, 10},
        {1, 2, 15},
        {0, 3, 10},
    };
    int maxTime = 49;

    int ans_1 = sol.maximalPathQuality(values, edges, maxTime);
    assert(75 == ans_1);
    std::cout << "my ans: " << ans_1 << "\n";
    return 0;
}
