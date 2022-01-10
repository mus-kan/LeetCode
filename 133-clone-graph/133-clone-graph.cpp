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
    
    unordered_map<Node*, Node*>copies;
    Node* cloneGraph(Node* node) {
        
        //BFS approach:-
//         if(!node)
//         {
//             return NULL;
//         }
//         queue<Node*>q;
//         q.push(node);
        
//         unordered_map<Node*, Node*>copies;
//         Node* root=new Node(node->val);
//         copies[node]=root;
        
//         while(!q.empty())
//         {
//             Node* curr=q.front();
//             q.pop();
           
//             for(auto x:curr->neighbors)
//             {
                
//                 if(copies.find(x)==copies.end())
//                 {
//                     copies[x]=new Node(x->val);
//                     q.push(x);
//                 }
//                 copies[curr]->neighbors.push_back(copies[x]);
                
//             }
            
//         }
        
//         return root;
        
        
        
        //DFS approach:-
        
        if(!node)
            return NULL;
        
        if(copies.find(node)==copies.end())
        {
            copies[node]=new Node(node->val);
            for(auto x:node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(x));
            }
        }
        
        return copies[node];
        
    }
};