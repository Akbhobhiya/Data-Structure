#include<bits/stdc++.h> 
using namespace std; 
  
// An AVL tree node  
class Node  
{  
    public: 
    int key; 
    Node *left;  
    Node *right;  
    int height;  
};  


class avl 
{   
public:
    Node* root = NULL;


    int height(Node *N)  
    {  
        if (N == NULL)  
            return 0;  
        return N->height;  
    }  
    int max(int a, int b)  
    {  
        return (a > b)? a : b;  
    } 

    Node* newNode(int key)  
    {  
        Node* node = new Node(); 
        node->key = key;  
        node->left = NULL;  
        node->right = NULL;  
        node->height = 1; // new node is initially 
                          // added at leaf  
        return(node);  
    }   
    Node *rightRotate(Node *y)  
    {  
        Node *x = y->left;  
        Node *T2 = x->right;  
      
        // Perform rotation  
        x->right = y;  
        y->left = T2;  
      
        // Update heights  
        y->height = max(height(y->left), 
                        height(y->right)) + 1;  
        x->height = max(height(x->left), 
                        height(x->right)) + 1;  
      
        // Return new root  
        return x;  
    }  
      
    // A utility function to left  
    // rotate subtree rooted with x  
    // See the diagram given above.  
    Node *leftRotate(Node *x)  
    {  
        Node *y = x->right;  
        Node *T2 = y->left;  
      
        // Perform rotation  
        y->left = x;  
        x->right = T2;  
      
        // Update heights  
        x->height = max(height(x->left),     
                        height(x->right)) + 1;  
        y->height = max(height(y->left),  
                        height(y->right)) + 1;  
      
        // Return new root  
        return y;  
    }  
    int getBalance(Node *N)  
    {  
        if (N == NULL)  
            return 0;  
        return height(N->left) - height(N->right);  
    }  
  
// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
    Node* insert(Node* node, int key)  
    {  
        /* 1. Perform the normal BST insertion */
        if (node == NULL)  
            return(newNode(key));  
      
        if (key < node->key)  
            node->left = insert(node->left, key);  
        else if (key > node->key)  
            node->right = insert(node->right, key);  
        else // Equal keys are not allowed in BST  
            return node;  
      
        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left),  
                            height(node->right));  
      
        /* 3. Get the balance factor of this ancestor  
            node to check whether this node became  
            unbalanced */
        int balance = getBalance(node);  
      
        // If this node becomes unbalanced, then  
        // there are 4 cases  
      
        // Left Left Case  
        if (balance > 1 && key < node->left->key)  
            return rightRotate(node);  
      
        // Right Right Case  
        if (balance < -1 && key > node->right->key)  
            return leftRotate(node);  
      
        // Left Right Case  
        if (balance > 1 && key > node->left->key)  
        {  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
      
        // Right Left Case  
        if (balance < -1 && key < node->right->key)  
        {  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
      
        /* return the (unchanged) node pointer */
        return node;  
    }  
      
    // A utility function to print preorder  
    // traversal of the tree.  
    // The function also prints height  
    // of every node  
    void preOrder(Node *root)  
    {  
        if(root != NULL)  
        {  
            cout << root->key << " ";  
            preOrder(root->left);  
            preOrder(root->right);  
        }  
    }

     Node* search(Node* root, int id)
    {
        if(root->key == id || root == NULL) {
            return root;
        }
        if(id > root->key) {
            return search(root->right, id);
        }
        return search(root->left, id);
        
    }

    Node* min() 
    {   
        Node* curr = root;
        while(curr->left != NULL && curr != NULL) 
        {
            curr = curr->left;
        }
        return curr;
    }
    Node* max()
    {
        Node* curr = root;
        while(curr->right != NULL && curr != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }
/*
    Node* successor() 
    {
        Node* curr = root->right;
        while(curr->left != NULL && curr != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    Node* predecessor() 
    {
        Node* curr = root->left;
        while(curr->right != NULL && curr != NULL)
        {
            curr = curr->right;
        }
        return curr;
    }*/


    void ps(Node*root,Node*&pre,Node*&suc,int n)
    {
        if(root==NULL)
            return;
        else if(n<root->key)
        {
            suc=root;
            ps(root->left,pre,suc,n);
        }
        else if(n>root->key)
        {
            pre=root;
            ps(root->right,pre,suc,n);
        }
        else
        {
            if(root->left!=NULL)
            {
            Node*temp=root->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                    pre=temp;
            }
               if(root->right!=NULL)
               {
                Node*temp=root->right;
                while(temp->left!=NULL)
                    temp=temp->left;
                    suc=temp;
               }
               return;
        }
    }
    Node * minValueNode(Node* node)  
    {  
        Node* current = node;  
      
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)  
            current = current->left;  
      
        return current;  
    }  
  
// Recursive function to delete a node  
// with given key from subtree with  
// given root. It returns root of the  
// modified subtree.  
Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  



};


int main()  
{  

    avl* t1 = new avl();
   /* t1->root = t1->insert(t1->root,10);
    t1->root = t1->insert(t1->root,20);
    t1->root = t1->insert(t1->root,30);
    t1->root = t1->insert(t1->root,40);
    t1->root = t1->insert(t1->root,50);
    t1->root = t1->insert(t1->root,25);

    
     The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    t1->preOrder(t1->root);

    //t1->root = t1->deleteNode(t1->root, 10);  
    Node* pre, *succ;
    t1->ps(t1->root,pre,succ,40);
    cout<<'\n'<<pre->key<<'\n'<<succ->key;
*/
    while(true) 
    {
        int opt;
        Node* pre, *succ;
        cout << "enter 1 to insert, enter 2 to deletenode 3 to search 4 to traverse 5 to successor 6 to predecessor 7 to min \n";
        cin >> opt;
        int inp;
        int ele;
        switch(opt) 
        {
            case 1: 
                    cin >> inp;
                    t1->root = t1->insert(t1->root, inp); 
                    break;
            case 2: //int inp;
                    cin >> inp;
                    t1->root = t1->deleteNode(t1->root, inp);
                    break;

            case 3: //int inp;
                    cin >> inp;
                    t1->search(t1->root, inp);
                    break;

            case 4: t1->preOrder(t1->root);break;
            case 5: 
                    cout<<"Enter element whose successor: ";
                    cin >> ele;
                    t1->ps(t1->root,pre,succ,ele);
                    cout<<succ->key<<'\n';
                    break;
            case 6:  
                    cout<<"Enter element whose pred: ";
                    cin >> ele;                 
                    t1->ps(t1->root,pre,succ,ele);
                    cout<<pre->key<<'\n'
                    ;break;
        }
    }
          
    return 0;  
}  
  
