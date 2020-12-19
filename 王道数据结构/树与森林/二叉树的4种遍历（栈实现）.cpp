/**
 * 中序遍历 94 leetcode 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> v;
       stack<TreeNode*> s;
       TreeNode*p = root;
       while(p || !s.empty()){
           if(p){
               s.push(p);
               p = p->left;
           }
           else{
               p = s.top();
               v.push_back(p->val);
               s.pop();
               p = p->right;
           }
       }
    return v;
    }
};

/**
 * 144.前序遍历 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p){
                v.push_back(p->val);
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return v;
    }
};

/** 
 * 145 后序遍历 
 *
 * 1、后序遍历同样借助栈实现，先找到最左边且为最下面的节点3（一边入栈一边找）。
 * 2、节点3若没有右孩子，那此时就打印节点3了，之后就弹出栈顶节点3
 * 3、节点3若有右孩子，则要去继续遍历它的右子树，等遍历结束才可打印3.遍历重复步骤1，2，3……
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root,* pre;
        vector<int> v;
        while(p || !s.empty()){
			while(p){
                s.push(p);
                p = p->left;
            }
            //找右子树 
            p = s.top();
            //如果右子树为空，或者当前p的右子树已经遍历完
			//将根结点p打印 
            if(p->right == NULL || pre == p->right){
                v.push_back(p->val);
                s.pop();
                pre = p;
                p = NULL;
            }
            else
                p = p->right;
        }
        return v; 
    }
};

//层序使用BFS，queue实现（略） 
