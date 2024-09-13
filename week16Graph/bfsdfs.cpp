#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

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
    void BFStraversal(T source, unordered_map<char, bool> &visited){
        // using queue
        //first make a visited map to check whether the current node is visited before or not
        
        // make a queue to store nodes
        queue<T> q;

        //inital conditions
        if(visited[source] == false){
            q.push(source);
            visited[source] = true;
        }
        
        while(!q.empty()){
            //get the front element
            T frontNode = q.front();
            //pop it
            q.pop();
            cout << frontNode << " ";
            for(auto it : adjList[frontNode]){
                T node = it.first;
                if(visited[node] == false){
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }
    void DFStraversal(T source, unordered_map<char, bool> &visited){
        if (!visited[source])
        {
            cout << source << " ";
            visited[source] = true;
        }
        for(auto it : adjList[source]){
            T node = it.first;
            if(!visited[node]){
                DFStraversal(node, visited);
            }
        }
        
    }
};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 10, 0);
    // g.addEdge('a', 'c', 30, 0);
    // g.addEdge('b', 'c', 40, 0);
    g.addEdge('c', 'd', 60, 0);
    g.addEdge('c', 'e', 20, 0);
    g.addEdge('e', 'f', 50, 0);
    g.printEdges();
    // now this condition will not be applied to disconnected graph
    // g.BFStraversal('a');
    // maintaining disconnected graph also
    unordered_map<char, bool> visited;
    // for(char i = 'a' ; i <= 'f' ; i++){
    //     g.BFStraversal(i, visited);
    // }
    g.DFStraversal('a', visited); // will not work in case of disconnected graph
    for(char i = 'a' ; i <= 'f' ; i++){
        g.DFStraversal(i, visited);
    }
    return 0;
}