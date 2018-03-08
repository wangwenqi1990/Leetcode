class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> m;
        return clone(node, m);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode*node, unordered_map<int, UndirectedGraphNode*>& m){
        if(!node) return node;
        if(m.count(node->label)) return m[node->label];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        m[node->label] = newNode;
        for(int i=0; i<node->neighbors.size(); ++i){
            (newNode->neighbors).push_back(clone(node->neighbors[i], m));
        }
        return newNode;
    }
};