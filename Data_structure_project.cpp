#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
class treenode{
    public:
    int data;
    treenode *left;
    treenode *right;
    treenode(){
        data=0;
        left=right=NULL;
    }
    treenode(int val){
        data=val;
        left=right=NULL;
    }
};
class linkedlist{

    public:
    node *head;
    linkedlist(){
        head=NULL;
    }
    void insert(int val){
            node *newnode=new node(val);
            if (head==NULL)
            {
                head=newnode;
            }
            else {
                node *temp=head;
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                
            }
            
    }
    void insertstack(int val){
        node *newnode=new node(val);
        newnode->next=head;
        head=newnode;
    }
    void print(){
        node *temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }
    void deletefirstnode(){
        node *temp=head;
        head=head->next;
        delete temp;
        
        
    }
    void deleteatend(){
        node *temp=head;
        node *prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
            
        }
        prev->next=NULL;
        delete temp;
    }
};
class stack{
    public:
    linkedlist l1;
    void push(int val){
        l1.insertstack(val);
    }
    void pop(){
        l1.deletefirstnode();

    }
    void displaystack(){
        node *temp=l1.head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    
};
class queue{
    public:
    linkedlist l1;
    node *head;
    queue(){
        head=NULL;
    }
    void enqueue(int val){
        l1.insert(val);
    }
    void dequeue(){
        l1.deletefirstnode();
    }
    void displayqueue(){
        l1.print();
    }
};
class bst{
    public:
    treenode *root;
    bst(){
        root=NULL;
    }
    void insert(int val) {
        treenode *r = new treenode(val);

        if (root == NULL) {
            root = r;
        } else {
            treenode *temp = root;
            while (temp != NULL) {
                if (r->data == temp->data) {
                    cout << "value already exist:" << endl;
                    return;
                } else if ((r->data < temp->data) && (temp->left == NULL)) {
                    temp->left = r;
                    break;
                } else if (r->data < temp->data) {
                    temp = temp->left;
                } else if ((r->data > temp->data) && (temp->right == NULL)) {
                    temp->right = r;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    treenode *minvalue(treenode *r) {
        treenode *curr = r;
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }

    treenode *deletenode(treenode *r, int val) {
        if (r == NULL) {
            return r;
        } else if (val < r->data) {
            r->left = deletenode(r->left, val);
        } else if (val > r->data) {
            r->right = deletenode(r->right, val);
        } else {
            if (r->left == NULL) {
                treenode *temp = r->right;
                delete r;
                return temp;
            } else if (r->right == NULL) {
                treenode *temp = r->left;
                delete r;
                return temp;
            } else {
                treenode *temp = minvalue(r->right);
                r->data = temp->data;
                r->right = deletenode(r->right, temp->data);
            }
        }
        return r;
    }


    treenode* search(treenode* r, int val) {
        if (r == nullptr || r->data == val) {
            return r;
        } else if (val < r->data) {
            return search(r->left, val);
        } else {
            return search(r->right, val);
        }
    }
    void printpostorder(treenode *r) {
        if (r == NULL) {
            return;
        } else {
            printpostorder(r->left);
            printpostorder(r->right);
            cout << r->data << " ";
        }
    }
    void printpreorder(treenode *r) {
        if (r == NULL) {
            return;
        } else {
            cout << r->data << " ";
            printpostorder(r->left);
            printpostorder(r->right);
            
        }
    }
    void printinorder(treenode *r) {
        if (r == NULL) {
            return;
        } else {
            printpostorder(r->left);
            
            cout << r->data << " ";
            printpostorder(r->right);
        }
    }

};
int main(){
    linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    cout<<"linked list values"<<endl;
    l1.print();
    cout<<endl;
    cout<<"delete first node:"<<endl;
    l1.deletefirstnode();
    
    l1.print();
    cout<<endl;
    cout<<"delete last node:"<<endl;
    l1.deleteatend();
    l1.print();
   
   cout<<"stack operations:"<<endl;

    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.displaystack();
    cout<<endl;
    cout<<"after pop:"<<endl;
    s1.pop();
    s1.displaystack();
    cout<<endl;

    cout<<"queue operations:"<<endl;
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.displayqueue();
    cout<<endl;
    cout<<"after dequeue value:"<<endl;
    q1.dequeue();
    q1.displayqueue();
    cout<<endl;

    cout<<"Bst operations"<<endl;
    bst B1;
    B1.insert(1);
    B1.insert(5);
    B1.insert(4);
    B1.insert(2);
    B1.insert(7);
    B1.insert(9);
    cout<<"postorder traversal:"<<endl;
    B1.printpostorder(B1.root);
    cout<<endl;
    cout<<"inorder traversal:"<<endl;
    B1.printinorder(B1.root);
    cout<<endl;
    cout<<"preorder traversal:"<<endl;
    B1.printpreorder(B1.root);
    cout<<endl;
    treenode *x=B1.search(B1.root,4);
    if (x!= nullptr) {
        cout << "Value  is found in the BST." << endl;
    } else {
        cout << "Value  is not found in the BST." << endl;
    }
    treenode *z=B1.deletenode(B1.root,5);
    cout<<"After deletion:"<<endl;
    B1.printpreorder(B1.root);
    cout<<endl;

}