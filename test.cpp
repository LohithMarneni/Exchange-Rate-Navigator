#include<bits/stdc++.h>
using namespace std;

struct Edge {
    string destination;
    double exchangeRate;
    
    Edge(string destination, double exchangeRate) {
        this->destination = destination;
        this->exchangeRate = exchangeRate;
    }
};

class ExchangeRateNavigator {
private:
    unordered_map<string, vector<Edge>> adjList;
    
public:
    void initializeadjList() {
        adjList["USD"].push_back(Edge("EUR", 0.90));
        adjList["USD"].push_back(Edge("GBP", 0.75));
        adjList["EUR"].push_back(Edge("GBP", 0.83));
        adjList["EUR"].push_back(Edge("JPY", 130.02));
        adjList["GBP"].push_back(Edge("INR", 98.57));
        adjList["JPY"].push_back(Edge("INR", 0.67));
        adjList["INR"].push_back(Edge("CAD", 0.016));
        adjList["CAD"].push_back(Edge("AUD", 1.10));
        adjList["AUD"].push_back(Edge("USD", 0.70));
        adjList["USD"].push_back(Edge("JPY", 110.50));
    }
    
    void findBestPath(const string source, const string destination) {
        unordered_map<string, double> dist;
        unordered_map<string, string> parent;
        
        for (const auto& pair : adjList) {
            dist[pair.first] = 0.0;
            parent[pair.first] = "";
        }

        dist[source] = 1.0;
        set<pair<double, string>, greater<pair<double, string>>> s;
        s.insert({1.0, source});
        cout << "Initialized with source: " << source << " having rate 1.0\n";

        while (!s.empty()) {
            auto it = *s.begin();
            s.erase(it);
            double currRate = it.first;
            string currCurrency = it.second;
            cout << "\nProcessing currency: " << currCurrency << " with current rate: " << currRate << endl;
            
            for (auto edge : adjList[currCurrency]) {
                string nextCurrency = edge.destination;
                double newRate = currRate * edge.exchangeRate;
                
                cout << "  Checking edge to " << nextCurrency 
                     << " with exchange rate " << edge.exchangeRate 
                     << ", potential new rate: " << newRate << endl;
                
                if (newRate > dist[nextCurrency]) {
                    if (dist[nextCurrency] != 0.0) {
                        s.erase({dist[nextCurrency], nextCurrency});
                        cout << "    Removing outdated entry of " << nextCurrency 
                             << " with rate " << dist[nextCurrency] << " from set\n";
                    }

                    dist[nextCurrency] = newRate;
                    parent[nextCurrency] = currCurrency;
                    s.insert({newRate, nextCurrency});
                    
                    cout << "    Updated " << nextCurrency << ": dist = " << newRate 
                         << ", parent = " << currCurrency << "\n";
                }
            }
        }

        if (dist[destination] == 0.0) {
            cout << "There was no path from " << source << " to " << destination << endl;
            return;
        }

        vector<string> path;
        string step = destination;
        while (step != "") {
            path.push_back(step);
            step = parent[step];
        }
        reverse(path.begin(), path.end());

        cout << "\nThe best path from " << source << " to " << destination 
             << " with exchange rate: " << dist[destination] << endl;
        cout << "The best path from " << source << " to " << destination << " is: ";
        for (auto node : path) {
            cout << node;
            if (node != destination) {
                cout << " -> ";
            }
        }
        cout << endl;

        cout << "\nFinal exchange rates for each currency:" << endl;
        for (const auto& pair : dist) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    ExchangeRateNavigator navigator;
    navigator.initializeadjList();
    navigator.findBestPath("USD", "EUR");
    return 0;
}
