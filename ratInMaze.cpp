class Solution {
  public:
  void solve(vector<vector<int>>&maze,vector<string>&result,string ans,int row,int col){
      if(row==maze.size()-1&&col==maze[0].size()-1&&maze[row][col]==1){
          result.push_back(ans);
          return;
      }
      if(row>=maze.size()||col>=maze[0].size()||row<0||col<0||maze[row][col]==0){
          return;
      }
      if(maze[row][col]==1){
          maze[row][col]=0;
          solve(maze,result,ans+'D',row+1,col);
          solve(maze,result,ans+'L',row,col-1);
          solve(maze,result,ans+'R',row,col+1);
          solve(maze,result,ans+'U',row-1,col);
          maze[row][col]=1;
      }
      return;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int row=0;
        int col=0;
        string ans; 
        vector<string>result;
        solve(maze,result,ans,0,0);
        return result; 
        
    }
};