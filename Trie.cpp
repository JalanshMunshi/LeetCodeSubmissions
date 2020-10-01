class Trie {
private:
    map<char, Trie*> dict;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
public:
    void insert(string word) {
        if(word.length()) {
            auto trie = *this;
            for(char c : word) {
                if(trie.dict.find(c) == trie.dict.end())
                    trie.dict[c] = new Trie();
                trie = trie.dict[c];
            }
            trie.isWord = true;
        }
    }
    bool search(string word) {
        if(word.length() == 0)
            return false;
        auto trie = *this;
        for(char c : word) {
            if(trie.dict.find(c) == trie.dict.end())
                return false;
            trie = trie.dict[c];
        }
        return trie.isWord;
    }
}
