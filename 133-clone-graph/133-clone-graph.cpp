/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
       unordered_map<Node*,Node*> map;
        Node* copy=new Node(node->val);    //We create a new node with the nodes value
        map[node]=copy;                    //We store it in the map so it will help get get access to tha element in o(1) time
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            for(Node* x:t->neighbors)     //We explore all of its neighbors to make copies of edges and its adjacent nodes
            {
                if(!map.count(x))        //This is to make sure we dont visit the node multiple times
                {
                    map[x]=new Node(x->val);   //We create the new nodes
                    q.push(x);
                }
                map[t]->neighbors.push_back(map[x]);   //This the creation of edges
            }
            
        }
        return copy;
    }
};