#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Graph
{
private:
    vector< vector<int>> graph;
    vector<bool> used;
public:
    Graph(int size) {
        graph.resize(size);
        for (int i = 0; i < size; i++) {
            used.push_back(false);
        }
    }

    void add_point(int i, int a) {
        graph[i].push_back(a);
    }

    void dfs (int v) {
        used[v] = true;
        cout << v << " ";
        for (unsigned int i = 0; i < graph[v].size(); i++) {
            if (!used[graph[v][i]]) dfs(graph[v][i]);
        }
    }
};



int main()
{
    setlocale(0, "Russian");
    ifstream file;
    file.open("in.txt");

    int graph_size;
    file >> graph_size;
    Graph graph(graph_size);
    int i = -1;

    while (!file.eof()) {

        while (file.peek() == ' ') {
            file.get();
        }

        if (file.peek() == '\n') {
            i++;
            if (i == graph_size) break;
        }

        int x;
        file >> x;
        graph.add_point(i, x);
    }

    graph.dfs(0);

    return 0;
}
