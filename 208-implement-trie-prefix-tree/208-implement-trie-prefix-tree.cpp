struct Node {
    Node* link[26];
    bool flag=false;
    bool containKey(char ch)
    { 
        return (link[ch-'a']!=NULL);
    }

    void createKey (char ch, Node* node)
    {
        link[ch-'a']=node;
    }

    Node* next(char ch)
    {
        return link[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() 
    {
        root= new Node();
    }
    
    void insert(string word) 
    {
        Node* node=root;
        for(auto& ch: word){
            if(!node->containKey(ch))
            { 
                node->createKey(ch, new Node());
            }
            node=node->next(ch);
        }
        node->setEnd(); 
    }
    
    bool search(string word)
    {
        Node* node=root;
        for(auto& ch:word){
            if(!node->containKey(ch)) return false; 
            node=node->next(ch); 
        }
        return node->isEnd(); 
    }
    
    bool startsWith(string prefix)
    {
        Node* node=root;
        for(auto& ch:prefix)
        {
            if(!node->containKey(ch)) return false; 
            node=node->next(ch);
        }
        return true; 
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */