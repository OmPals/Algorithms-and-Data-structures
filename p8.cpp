#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* a, TreeNode* b):val(x), left(a), right(b){} 
};

// recursive inorder
void inorder (TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
    return;
}

// recursive preorder
void preorder (TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

// recursive postorder
void postorder (TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
    return;
}


// iterative inorder
void inorderStack (TreeNode* root) {
    TreeNode* temp = root;
    stack<TreeNode*> st;
    while (temp || !st.empty()) {
        while(temp) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->val << ' ';
        temp = temp->right;
    }
    return;
}

// iterative preorder
void preorderStack (TreeNode* root) {
    TreeNode* temp = root;
    stack<TreeNode*> st;
    while (temp || !st.empty()) {
        while (temp) {
            cout << temp->val << ' ';
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        temp = temp->right;
    }
    return;
}

// iterative postorder
// using 2 stacks
void postorderTwoStacks (TreeNode* root) {
    TreeNode* temp = root; 
    stack<TreeNode*> st;
    stack<TreeNode*> st2;
    st.push(temp);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
        if (temp->left) st.push(temp->left);
        if (temp->right) st.push(temp->right);
        st2.push(temp);
    }
    while(!st2.empty()) {
        cout << st2.top()->val << ' ';
        st2.pop();
    }
}

// using single stack
void postorderStack(TreeNode* root) {
    TreeNode* temp = root;
    stack<TreeNode*> st;
    st.push(temp);
    temp = temp->left;
    while (temp || !st.empty()) {
        while(temp) {
            st.push(temp);
            if (temp->left) temp=temp->left;
            else temp=temp->right;
        }
        
        TreeNode* temp2 = st.top();
        cout << temp2->val << ' ';
        st.pop();
        
        while (!st.empty() && st.top()->right == temp2) {
            temp2=st.top();
            cout << temp2->val << ' ';
            st.pop();
        }
        
        if (!st.empty()) {
            temp = st.top()->right;
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    root->left = l;
    root->right = r;
    l->left = new TreeNode(4);
    l->right = new TreeNode(5);
    r->left = new TreeNode(6);
    r->right = new TreeNode(7);
    inorder(root);
    cout << '\n';
    preorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    inorderStack(root);
    cout << '\n';
    preorderStack(root);
    cout << '\n';
    postorderTwoStacks(root);
    cout << '\n';
    postorderStack(root);
    cout << '\n';
    return 0;
}