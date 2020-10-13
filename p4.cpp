// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST

struct lbst {
    int min;
    int max;
    int size;
    bool isbst;
};

lbst returner(int min, int max, int size, bool isbst) {
    lbst temp;
    temp.min = min;
    temp.max = max;
    temp.size = size;
    temp.isbst = isbst;
    return temp;
}

lbst postorder(Node* node) {
    if(node == NULL) 
        return returner(-1, -1, 0, true);
    if(node->left == NULL && node->right == NULL) 
        return returner(node->data, node->data, 1, true);
    lbst left = postorder(node->left);
    lbst right = postorder(node->right);
    
    if(left.isbst && right.isbst) {
        if(left.size == 0) 
            if(node->data < right.min)
                return returner(node->data, right.max, right.size+1, true);
        if(right.size == 0) 
            if(node->data > left.max) 
                return returner(left.min, node->data, left.size+1, true);
            
        if(node->data > left.max && node->data < right.min) 
            return returner(left.min, right.max, left.size + right.size + 1, true);
    }
    return returner(-1, -1, max(left.size, right.size), false);
}

int largestBst(Node *root)
{
    lbst ans = postorder(root);
    return ans.size;
}