// n-queens
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int **board, int n){
    // check columns and rows
    for(int i = 0; i < n; i++){
        if(board[row][i] ==1 || board[i][col] == 1){return false;}
    }
    // check diagonals
    int i, j;
    // check top left diagonal
    i = row;
    j = col;
    while(i >=0 and j >= 0){
        if(board[i][j] ==1){return false;}
        i--;
        j--;
    }
    i = row;
    j = col;
    while(i < n and j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool solvenqueens(int **board, int col, int n){
    // check if n-queens completed
    if(col >= n){
        return true;
    }
    for(int i = 0; i < n; i++){
        // is the place correct
        if(isSafe(i, col, board, n)){
            board[i][col] = 1;
            // check for the next
            if(solvenqueens(board, col+1, n)){
                return true;
            }
            // backtrack if solution not found
            board[i][col] = 0;
        }
    }
    return false;
}

void printsol(int **board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // print board
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number of queens: ";
    cin>>n;
    int **board = new int *[n];
    for(int i = 0; i < n; i++){
        board[i] = new int[n];
        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    if(solvenqueens(board, 0, n)){
        cout<<"Solution exists: "<<endl;
        printsol(board, n);
    }else{
        cout<<"No Solution exists."<<endl;
    }
    return 0;
}
