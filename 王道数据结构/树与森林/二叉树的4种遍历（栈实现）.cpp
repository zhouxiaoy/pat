/**
 * ������� 94 leetcode 
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
 * 144.ǰ����� 
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
 * 145 ������� 
 *
 * 1���������ͬ������ջʵ�֣����ҵ��������Ϊ������Ľڵ�3��һ����ջһ���ң���
 * 2���ڵ�3��û���Һ��ӣ��Ǵ�ʱ�ʹ�ӡ�ڵ�3�ˣ�֮��͵���ջ���ڵ�3
 * 3���ڵ�3�����Һ��ӣ���Ҫȥ���������������������ȱ��������ſɴ�ӡ3.�����ظ�����1��2��3����
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
            //�������� 
            p = s.top();
            //���������Ϊ�գ����ߵ�ǰp���������Ѿ�������
			//�������p��ӡ 
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

//����ʹ��BFS��queueʵ�֣��ԣ� 
