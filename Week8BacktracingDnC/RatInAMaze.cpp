#include<iostream>
#include <vector>
using namespace std;

bool isSafe(int maze[4][4], int row, int col, int dstx, int dsty, vector<vector<bool> >& visited){
    if((dstx >= 0 && dstx < row) && (dsty >=0  && dsty < col)
    && (maze[dstx][dsty] == 1) && (visited[dstx][dsty] == false)) return true;
    return false;
}
void RatInAMaze(int maze[4][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool> >& visited){
    //base condition
    if(srcx == row - 1 && srcy == col - 1){
        //destination reached
        cout << output << endl;
        return;
    }
    
    //UP
    if(isSafe(maze, row, col, srcx - 1, srcy, visited)){
        output.push_back('U');
        visited[srcx - 1][srcy] = true;
        RatInAMaze(maze, row, col, srcx - 1, srcy, output, visited);
        visited[srcx - 1][srcy] = false;
        output.pop_back();
    }

    //DOWN
    if(isSafe(maze, row, col, srcx + 1, srcy, visited)){
        output.push_back('D');
        visited[srcx + 1][srcy] = true;
        RatInAMaze(maze, row, col, srcx + 1, srcy, output, visited);
        visited[srcx + 1][srcy] = false;
        output.pop_back();
    }

    //RIGHT
    if(isSafe(maze, row, col, srcx, srcy + 1, visited)){
        output.push_back('R');
        visited[srcx][srcy + 1] = true;
        RatInAMaze(maze, row, col, srcx, srcy + 1, output, visited);
        visited[srcx][srcy + 1] = false;
        output.pop_back();
    }

    //LEFT
    if(isSafe(maze, row, col, srcx, srcy - 1, visited)){
        output.push_back('L');
        visited[srcx][srcy - 1] = true;
        RatInAMaze(maze, row, col, srcx, srcy - 1, output, visited);
        visited[srcx][srcy - 1] = false;
        output.pop_back();
    }
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int row = 4;
    int col = 4;
    vector<vector<bool> > visited(row, vector<bool>(col, false)); 
    
    string output = "";
    if(maze[0][0] == 0) cout << "Rat cannot move" << endl;
    else{
        visited[0][0] = true;
        RatInAMaze(maze, row, col, 0, 0, output, visited);
    }
    return 0;
}