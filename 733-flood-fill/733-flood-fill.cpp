class Solution {
private:
int n, m;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
void dfs(int i, int j, int prevColor, int newColor, vector<vector<int>>& image){
    if(i<0 || j<0 || i>=n || j>=m) return; // Out of Bounds
    if(image[i][j] != prevColor) return; // only src color should be changed      
    
    image[i][j] = newColor; // cahnging the color to new Color
    for(auto it : directions){
        dfs(i+it[0], j+it[1], prevColor, newColor, image);
    }

}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        
        if(image[sr][sc] != newColor) // We only do dfs, if we have to change the Color
            dfs(sr, sc, image[sr][sc], newColor, image);

        return image;
    }
};