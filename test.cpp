#include <bits/stdc++.h>
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
        unordered_map<string, double> maxRate;
        unordered_map<string, string> parent;
        set<pair<double, string>, greater<pair<double, string>>> s; // Set to store (rate, currency) pairs

        // Initialize distances to zero
        for (const auto& pair : adjList) {
            maxRate[pair.first] = 0.0;
            parent[pair.first] = "";
        }

        maxRate[source] = 1.0;  // Start with an exchange rate of 1 from the source
        s.insert({1.0, source});

        while (!s.empty()) {
            // Extract the best rate currency
            auto top = *s.begin(); // Get the element with the highest rate
            double currRate = top.first;
            string currCurrency = top.second;
            s.erase(s.begin()); // Remove it from the set

            for (const auto& edge : adjList[currCurrency]) {
                string nextCurrency = edge.destination;
                double newRate = currRate * edge.exchangeRate;  // Use multiplication for cumulative rate

                // Update if a better (higher) rate path is found
                if (newRate > maxRate[nextCurrency]) {
                    // Update the maximum rate and parent
                    maxRate[nextCurrency] = newRate;
                    parent[nextCurrency] = currCurrency;

                    // Insert the new rate into the set
                    s.insert({newRate, nextCurrency});
                }
            }
        }

        // If destination was not reachable, print error
        if (maxRate[destination] == 0.0) {
            cout << "There was no path from " << source << " to " << destination << endl;
            return;
        }

        // Reconstruct the path from destination to source
        vector<string> path;
        string step = destination;
        while (step != "") {
            path.push_back(step);
            step = parent[step];
        }
        reverse(path.begin(), path.end());

        // Output the results
        cout << "The best path from " << source << " to " << destination << " has cumulative exchange rate: " << maxRate[destination] << endl;
        cout << "Path: ";
        for (const string& currency : path) {
            cout << currency << " ";
            if (currency != destination) cout << "-> ";
        }
        cout << endl;

        cout << "Accumulated rates from " << source << " to each currency:" << endl;
        for (const auto& pair : maxRate) {
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
