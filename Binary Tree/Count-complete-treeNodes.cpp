Count Complete Tree Nodes




//------------------------
Input: root = [1,2,3,4,5,6]
Output: 6
 //--------------------------  

class Solution {
    int sum = 0;
public:
    int countNodes(TreeNode* root) {
        
        if(root==NULL) 
            return 0;
        sum++; 
        countNodes(root->left); 
        countNodes(root->right); 
        return sum; 
    }
};
