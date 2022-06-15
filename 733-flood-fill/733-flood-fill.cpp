class Solution {
private:
    int n;
    int m;
    void dfs(int i, int j, int prevColor, int newColor, vector<vector<int>>& image){
        if(i<0 || j<0 || i>=n || j>=m) return; // Out of Bounds
        if(image[i][j] != prevColor) return; // only src color should be changed      
        
        image[i][j] = newColor;
        
        dfs(i, j+1, prevColor, newColor, image);
        dfs(i, j-1, prevColor, newColor, image);
        dfs(i+1, j, prevColor, newColor, image);
        dfs(i-1, j, prevColor, newColor, image);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        
        if(image[sr][sc] != newColor)
            dfs(sr, sc, image[sr][sc], newColor, image);
        
        return image;
    }
};