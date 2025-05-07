#include <iostream>
#include <string>
using namespace std;

struct Ticket {
    int id;
    string type, start, end;
    float gia;
};

typedef Ticket Data;

Data setData() {
    Data d;
    cout << "Nhap ma ve may bay: "; cin >> d.id;
    cin.ignore();
    do {
        cout << "Nhap loai ve(N/TG/PT): ";  
        getline(cin, d.type); 
    } while (d.type != "N" && d.type != "TG" && d.type != "PT");
    cout << "Nhap diem khoi hanh: "; getline(cin, d.start);
    cout << "Nhap diem den: "; getline(cin, d.end);
    cout << "Nhap gia ve: "; cin >> d.gia;
    
    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.type << " | " << d.start << " | " << d.end << " | " << d.gia << endl;
}

struct Node {
    Data data;
    Node* left;
    Node* right;
};

Node* createNewNode(Data value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BST {
    Node* root;
};

void newBST(BST &tree) {
    tree.root = NULL;
}

Node* insert(Node* root, Data value) {
    if (root == NULL) {
        return createNewNode(value);
    }
    if (root->data.gia > value.gia) { 
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    getData(root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    getData(root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    getData(root->data);
}

Node* search(Node* root, float target) {
    if (root == NULL || root->data.gia == target) {
        return root;
    } else if (root->data.gia > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void cau3(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->data.gia > 4) {
        getData(root->data);
    }
    cau3(root->left);
    cau3(root->right);
}

int main() {
    BST tree;
    newBST(tree);
    
    int N;
    do {
        cout << "Nhap so luong ve may bay: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin ve may bay thu " << i << endl;
        Data d = setData();
        tree.root = insert(tree.root, d);
        cout << endl;
    }
    
    cout << "Thong tin cac ve may bay vua nhap la:" << endl;
    inOrderTraversal(tree.root);
    cout << endl;
    
    cout << "Nhung ve may bay co gia lon hon 4 trieu la:" << endl;
    cau3(tree.root);
    cout << endl;
    
    if (search(tree.root, 10) == NULL) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}


