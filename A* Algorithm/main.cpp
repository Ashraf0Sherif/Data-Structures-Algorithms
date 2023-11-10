#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define F first
#define S second
#define eb emplace_back
#define prpair(x) for(auto it:x)cout<<it.F<<" "<<it.S<<"\n";

map<char, vector<pair<char, int>>> graph;
map<char, int> H_TABLE;

class Compare {
public:
    bool operator()(const vector<pair<char, int>> &path1, const vector<pair<char, int>> &path2) {
        return path_cost(path1) > path_cost(path2);
    }

    static int path_cost(const vector<pair<char, int>> &path) {
        int cost{H_TABLE[path.back().F]};
        for (const auto &step: path)
            cost += step.S;
        return cost;
    }
};

vector<pair<char, int>> A_STAR(char start, char goal) {
    map<char, bool> visited;
    priority_queue<vector<pair<char, int>>, vector<vector<pair<char, int>>>, Compare> pq;
    pq.push({{start, 0}});
    while (!pq.empty()) {
        auto path{pq.top()};
        char node{path.back().F};
        pq.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        if (node == goal)
            return path;
        auto adj{graph[node]};
        for (auto it: adj) {
            auto new_path{path};
            new_path.eb(it.F, it.S);
            pq.push(new_path);
        }
    }
    cout << "No path found\n";
    return {{'x', -1}};
}

int main() {
    graph = {{'A', {{'B', 1}, {'C', 4}}},
             {'B', {{'C', 2}, {'D', 3}}},
             {'C', {{'E', 5}}},
             {'D', {{'F', 2}, {'G', 4}}},
             {'E', {{'G', 3}}},
             {'F', {{'G', 1}}},
    };
    H_TABLE = {{'A', 5},
               {'B', 6},
               {'C', 4},
               {'D', 3},
               {'E', 3},
               {'F', 1},
               {'G', 0}};
    auto ans{A_STAR('A', 'G')};
    prpair(ans)
    cout << Compare::path_cost(ans);
    return 0;
}
