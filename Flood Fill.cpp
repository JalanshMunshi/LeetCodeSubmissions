class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        queue<pair<int, int> > q; //row, col
        int orig = image[sr][sc], rows = image.size(), cols = image[0].size();
        set<pair<int, int> > painted;
        q.push(make_pair(sr, sc));
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            int old = image[i][j];
            image[i][j] = newColor;
            painted.insert(make_pair(i, j));
            q.pop();
            if(i > 0)
                if(old == image[i-1][j] && painted.find(make_pair(i-1, j)) == painted.end())
                    q.push(make_pair(i-1, j));
            if(i < rows - 1)
                if(old == image[i+1][j] && painted.find(make_pair(i+1, j)) == painted.end())
                    q.push(make_pair(i+1, j));
            if(j > 0)
                if(old == image[i][j-1] && painted.find(make_pair(i, j-1)) == painted.end())
                    q.push(make_pair(i, j-1));
            if(j < cols - 1)
                if(old == image[i][j+1] && painted.find(make_pair(i, j+1)) == painted.end())
                    q.push(make_pair(i, j+1));
        }
        return image;
    }
};