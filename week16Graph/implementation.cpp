#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// ************** UNWEIGHTED GRAPH ****************
// class Graph {
// public:
//     unordered_map<int, list<int> > adjList;
//     void addEdge(int u, int v, bool direction) {
//         //if directed, direction -> 1
//         //undirected, direction -> 0
//         if(direction){
//             //u -> v
//             adjList[u].push_back(v);
//         }
//         else{
//             //u <--> v
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//     }    
//     void printEdges(){
//         for(auto it : adjList){
//             int node = it.first;
//             cout << node << " : { ";
//             for(auto edges : it.second){
//                 cout << edges << ", ";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

// ************** WEIGHTED GRAPH ***************
template<typename T>
class Graph {
public:
    unordered_map<T, list<pair<T, int> > > adjList;
    void addEdge(T u, T v, int wt, bool direction){
        //if directed, direction = 1
        //if undirected, direction = 0
        if(direction){
            adjList[u].push_back(make_pair(v, wt));
        }
        else{
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
    }
    void printEdges(){
        for(auto it : adjList){
            cout << it.first << " : { ";
            for(auto edge : it.second){
                cout << "{" << edge.first << ", " << edge.second << "}, ";
            }
            cout << " }" << endl;
        }
    }
};

int main()
{
    // Graph g;
    // // g.addEdge(0, 1, 1);
    // // g.addEdge(1, 2, 1);
    // // g.addEdge(2, 3, 1);
    // // g.addEdge(2, 1, 1);
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(2, 1, 0);
    // g.printEdges();
    // Graph<int> g;
    // g.addEdge(0, 1, 10, 1);
    // g.addEdge(1, 2, 20, 1);
    // g.addEdge(2, 3, 30, 1);
    // g.addEdge(2, 1, 40, 1);
    // g.printEdges();
    Graph<char> g;
    g.addEdge('a', 'b', 10, 1);
    g.addEdge('b', 'c', 20, 1);
    g.addEdge('c', 'd', 30, 1);
    g.addEdge('c', 'a', 40, 1);
    g.printEdges();
    return 0;
}