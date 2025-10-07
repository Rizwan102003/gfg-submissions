/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if (!root) return ans;

        // map to store horizontal distance -> node data
        map<int, int> hdMap;

        // queue for BFS: stores pair of node and its horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int hd = p.second;

            // overwrite the value at horizontal distance
            hdMap[hd] = node->data;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // extract bottom view from the map in sorted order of horizontal distance
        for (auto it : hdMap) {
            ans.push_back(it.second);
        }

        return ans;
    }
};