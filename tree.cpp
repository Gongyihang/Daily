#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class creat_tree{
    public:
    void creatpre(TreeNode** root){
        int val;
        cin >> val;
        if(val == -1){
            root = nullptr;
        }
        else
        {
            *root = new TreeNode(val);
            creatpre(&((*root)->left));
            creatpre(&((*root)->right));
        }
    }
};

class traversal_ite{
    public:
    vector<int> res;
    vector<int> preorder(TreeNode* root){
        stack<TreeNode*> call;
        if(root != nullptr){
            call.push(root);
        }
        while(!call.empty()){
            TreeNode *t = call.top();
            call.pop();
            if(t != nullptr){
                if(t->right){
                    call.push(t->right);
                }
                if(t->left){
                    call.push(t->left);
                }
                call.push(t);
                call.push(nullptr);
            }else
            {
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

int main(){
    creat_tree creat;
    TreeNode *root = nullptr;
    creat.creatpre(&root);

    system("pause");
    return 0;
}