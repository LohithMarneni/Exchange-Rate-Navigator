#include<bits/stdc++.h>
using namespace std;
struct Edge{
    string destination;
    double exchangeRate;
    //u can use this also
    //Edge(string source, string destination, double exchangeRate)
    //: source(source), destination(destination), exchangeRate(exchangeRate) {}
    Edge(string destination,double exchangeRate){
        this->destination=destination;
        this->exchangeRate=exchangeRate;
    }
};
class ExchangeRateNavigator{
    private:
    unordered_map<string,vector<Edge>> adjList;
    
    void fetchGraphFromApi(){
        cout<<"API Integration is not completed yet"<<endl;
        //infuture need to fetch from currency apis which are paid
    }
    public:
    
    void initializeadjList(){
        //for temporarily only used gpt generated edges in future determined to use the api to fetch the edges
        adjList["USD"].push_back(Edge("EUR", 0.90));//1USD=0.90EUR
        adjList["USD"].push_back(Edge("GBP", 0.75));//1USD=0.75GBP
        adjList["EUR"].push_back(Edge("GBP", 0.83));//1EUR=0.83GBP
        adjList["EUR"].push_back(Edge("JPY", 130.02));//1EUR=130.02JPY
        adjList["GBP"].push_back(Edge("INR", 98.57));//1GBP=98.57INR
        adjList["JPY"].push_back(Edge("INR", 0.67));//1JPY=0.67INR
        adjList["INR"].push_back(Edge("CAD", 0.016));//1INR=0.016CAD
        adjList["CAD"].push_back(Edge("AUD", 1.10));//1CAD=1.10AUD
        adjList["AUD"].push_back(Edge("USD", 0.70));//1AUD=0.70USD
        adjList["USD"].push_back(Edge("JPY", 110.50));//1USD=110.50JPY
    }
    unordered_set<string> getAvailableCurrencyCodes()const{
        unordered_set<string> currencyCodes;
        for(const auto& pair:adjList){
            currencyCodes.insert(pair.first);
        }
        return currencyCodes;
    }
    void findBestPath(const string source,const string destination){
        unordered_map<string, double> dist;
        unordered_map<string, string> parent;
        for (const auto& pair : adjList) {
            dist[pair.first]=0.0;
            parent[pair.first]="";//in future it can be used to print the path like looping till finding source using condition of parent[souce]=""
        }
        /*above part will make like this dist = {
                                            {"USD",0.0},
                                            {"EUR",0.0},
                                            {"GBP",0.0},
                                            {"JPY",0.0},
                                            {"INR",0.0},
                                            {"CAD",0.0},
                                            {"AUD",0.0}
                                        }

                                        parent = {
                                            {"USD",""},
                                            {"EUR",""},
                                            {"GBP",""},
                                            {"JPY",""},
                                            {"INR",""},
                                            {"CAD",""},
                                            {"AUD",""}
                                        };
        */  
        dist[source] = 1.0;//the distance (or rate) from source to source is 1.0.
        set<pair<double, string>,greater<pair<double,string>>> s;
        s.insert({1.0, source});
        //cout<<"Run before loop"<<endl;//debug line
        while(!s.empty()){
            auto it=*s.begin();
            s.erase(it);
            double currRate=it.first;
            string currCurrency=it.second;
            for(auto edge:adjList[currCurrency]){
                string nextCurrency=edge.destination;
                double newRate=currRate*edge.exchangeRate;
                if(newRate>dist[nextCurrency]){
                    // auto outDated=s.find({dist[nextCurrency],nextCurrency});
                    // if(outDated!=s.end()){
                    //     s.erase(outDated);
                    // }
                    //if already modify remove previous version add new version
                    if(dist[nextCurrency]!=0.0){
                        s.erase({dist[nextCurrency],nextCurrency});
                    }
                    dist[nextCurrency]=newRate;
                    parent[nextCurrency]=currCurrency;
                    s.insert({newRate,nextCurrency});
                }
            } 
        }
        //cout<<"Run after loop"<<endl;debug line
        //error condition for if there was no path to destination from source node
        if(dist[destination]==0.0){
            cout<<"There was no path from "<<source<<" to "<<destination<<endl;
            return;
        }
        vector<string> path;
        string step=destination;
        while(step!=""){
            path.push_back(step);
            step=parent[step];
        }
        reverse(path.begin(),path.end());
        cout<<"The best path from "<<source<<" to "<<destination<<" with exchange rate: "<<dist[destination]<<endl;
        cout<<"The best path from "<<source<<" to "<<destination<<" is: ";
        for(auto node:path){
            cout<<node<<" ";
            if(node!=destination){
                cout<<"-> ";
            }
        }
        cout<<endl;
        /*printing distance unordered map
            for(const auto& pair:dist) {
            cout<<pair.first<<" "<<pair.second<<endl;
         }
        cout<<endl;*/
        cout<<"\nExplanation:\n";
        cout<<"Starting with 1 unit of "<<source<<",you can convert through the following path:\n";
        double cumulativeRate = 1.0;
        for(size_t i = 0;i<path.size()-1;++i){
            string current=path[i];
            string next=path[i + 1];
            for(const auto& edge:adjList[current]){
                if(edge.destination==next){
                    cumulativeRate*=edge.exchangeRate;
                    cout<<current<<" to "<<next<<" at rate "<<edge.exchangeRate
                         <<", cumulative rate: "<<cumulativeRate<<endl;
                    break;
                }
            }
        }
        cout<<"\nBy following this path, you'll end up with "<<dist[destination] 
            << " units of "<<destination<<" for each 1 unit of "<<source<< "."<<endl;
    cout<<endl;
    }
};
int main() {
    ExchangeRateNavigator navigator;
    navigator.initializeadjList(); // Initialize the adjacency list with exchange rates
    // navigator.findBestPath("USD","INR"); // Find the best path from USD to EUR testing code
    //Display available currency codes
    cout<<"Currently available currency codes:"<<endl;
    unordered_set<string> currencyCodes=navigator.getAvailableCurrencyCodes();
    for(const auto& code:currencyCodes){
        cout<<code<<" ";
    }
    cout<<endl;
    string source, destination;
    cout << "Please enter the source currency code: ";
    cin >> source;
    cout << "Please enter the destination currency code: ";
    cin >> destination;
    navigator.findBestPath(source, destination);
    return 0;
}
