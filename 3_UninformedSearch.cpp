#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> graph = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

void bfs(int start, int end){
    queue<int> q;
    vector<int> visited(graph.size(), 0);
    q.push(start);
    visited[start] = 1;
    cout << "bfs starting from " << start << ": ";
    while(!q.empty()){
        start = q.front();
        q.pop();
        cout << start << " ";
        if(start == end){
            cout << "dest reached!" << endl;
            return ;
        }
        for(int i = start;i < graph[0].size();i++){
            if(visited[i] != 1 && graph[start][i] == 1){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void dfs(int start, int end){
    stack<int> s;
    vector<int> visited(graph.size(), 0);
    s.push(start);
    cout << "dfs starting from " << start << ": ";
    while (!s.empty()){
        start = s.top();
        int found = 0;
        if(visited[start] == 0){
            visited[start] = 1;
            cout << start << " ";
        }
        if(start == end){
            cout << "dest reached!" << endl;
            return ;
        }
        for(int i = start;i < graph[0].size();i++){
            if(visited[i] != 1 && graph[start][i] == 1){
                s.push(i);
                found = 1;
                break;
            }
        }

        if(found == 0){
            s.pop();
        }

    }
    
}

int main() {
    // code
    bfs(0, 3);
    dfs(0, 3);
    return 0;
}