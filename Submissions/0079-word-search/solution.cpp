class Solution {
public:

    bool search(vector<vector<char>> &board, string word, int row, int col, int n, int m, int ind){
        if(ind == word.length()){
            return true;
        }

        if(row < 0 || col < 0 || row==n || col==m || board[row][col] != word[ind] || board[row][col] == '*'){
            return false;
        }

        char c = board[row][col];
        board[row][col] = '*';

        // top
        bool top = search(board,word,row-1,col,n,m,ind+1);
        // left
        bool left = search(board,word,row,col-1,n,m,ind+1);
        // bottom
        bool bottom = search(board,word,row+1,col,n,m,ind+1);
        // right
        bool right = search(board,word,row,col+1,n,m,ind+1);

        board[row][col] = c;

        return top || left || bottom || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int ind = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[ind]){
                    if(search(board,word,i,j,n,m,ind)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
