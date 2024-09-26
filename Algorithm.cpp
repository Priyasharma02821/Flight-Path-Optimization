#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const double INF = numeric_limits<double>::infinity();

struct Edge {
    int destination;
    double fuel_cost;
    double time_cost;
};

struct Node {
    int id;
    double fuel_left;
    double total_time;

    bool operator<(const Node &other) const {
        return total_time > other.total_time; // Min-heap based on time
    }
};

vector<int> dijkstra(int source, int target, vector<vector<Edge>> &graph, double initial_fuel) {
    int n = graph.size();
    vector<double> min_time(n, INF);
    vector<double> fuel_remaining(n, 0.0);
    vector<int> previous(n, -1); // To track the path

    priority_queue<Node> pq;
    pq.push({source, initial_fuel, 0.0});
    min_time[source] = 0.0;
    fuel_remaining[source] = initial_fuel;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.id == target) break; // Target reached

        for (const Edge &edge : graph[current.id]) {
            double new_fuel_left = current.fuel_left - edge.fuel_cost;
            double new_time = current.total_time + edge.time_cost;

            if (new_fuel_left >= 0 && new_time < min_time[edge.destination]) {
                min_time[edge.destination] = new_time;
                fuel_remaining[edge.destination] = new_fuel_left;
                previous[edge.destination] = current.id; // Track the previous node
                pq.push({edge.destination, new_fuel_left, new_time});
            }
        }
    }

    // Backtrack to find the path
    vector<int> path;
    for (int at = target; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    if (min_time[target] == INF) {
        return {}; // No path found
    } else {
        cout << "Minimum time to reach destination: " << min_time[target] << " hours" << endl;
        cout << "Fuel left upon arrival: " << fuel_remaining[target] << " units" << endl;
        cout << "Optimized path: ";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size()-1) cout << " -> ";
        }
        cout << endl;
    }

    return path;
}

int main() {
    int n, m;
    double initial_fuel;

    cout << "Enter the number of airports: ";
    cin >> n;

    vector<vector<Edge>> graph(n);

    int source, target;
    cout << "Enter the source airport: ";
    cin >> source;
    cout << "Enter the target airport: ";
    cin >> target;

    cout << "Enter the number of connections between airports: ";
    cin >> m;

    cout << "Enter the connections in the format 'source destination fuel_cost time_cost':\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        double fuel_cost, time_cost;
        cin >> u >> v >> fuel_cost >> time_cost;
        graph[u].push_back({v, fuel_cost, time_cost});
    }

    cout << "Enter the initial fuel: ";
    cin >> initial_fuel;

    vector<int> result = dijkstra(source, target, graph, initial_fuel);

    if (result.empty()) {
        cout << "No feasible path found." << endl;
    }

    return 0;
}
