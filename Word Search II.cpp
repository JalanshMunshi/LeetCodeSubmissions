class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;
        bool isWord;
        
        TrieNode(): isWord(false) {}
    };
    TrieNode* buildTrie(vector<string> words)
    {
        TrieNode *root = new TrieNode();
        for(string s : words)
        {
            TrieNode *curr = root;
            for(char c : s)
            {
                if(curr->children.find(c) == curr->children.end())
                    curr->children.insert({c, new TrieNode});
                curr = curr->children[c];
            }
            curr->isWord = true;
            curr->word = s;
        }
        return root;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, set<string> &foundWords)
    {
        // Base condition
        if(i < 0 || i >= board.size()
          || j < 0 || j >= board[0].size()
          || root->children.find(board[i][j]) == root->children.end())
            return;
        root = root->children[board[i][j]];
        if(root->isWord)
            foundWords.insert(root->word);
        char c = board[i][j];
        board[i][j] = '*';
        // Recursively call the adjacent coordinates
        dfs(board, i-1, j, root, foundWords);
        dfs(board, i+1, j, root, foundWords);
        dfs(board, i, j-1, root, foundWords);
        dfs(board, i, j+1, root, foundWords);
        
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *root = buildTrie(words);
        int n = board.size(), m = board[0].size();
        set<string> foundWords;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                dfs(board, i, j, root, foundWords);
        vector<string> ans;
        for(string s : foundWords)
            ans.push_back(s);
        return ans;
    }
};