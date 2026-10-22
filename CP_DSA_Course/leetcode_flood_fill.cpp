class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,
             int k, int n, int m, int color) {

        if (sr >= n || sc >= m || sr < 0 || sc < 0)
            return;

        if (image[sr][sc] != k)
            return;

        image[sr][sc] = color;

        dfs(image, sr, sc + 1, k, n, m, color);
        dfs(image, sr, sc - 1, k, n, m, color);
        dfs(image, sr + 1, sc, k, n, m, color);
        dfs(image, sr - 1, sc, k, n, m, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int k = image[sr][sc];

        if (k == color)
            return image;

        dfs(image, sr, sc, k, n, m, color);

        return image;
    }
};