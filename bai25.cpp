#include <iostream>
#include <string>
using namespace std;

struct DuAn {
    int id;
    string name, range;
    float cost;  
};

typedef DuAn Data;

Data setData() {
    Data d;
    cout << "Nhap ma du an: "; cin >> d.id;
    cout << "Nhap ten du an: "; cin.ignore(); getline(cin, d.name);

    do {
        cout << "Nhap qui mo du an (nho/trung binh/lon): "; 
        getline(cin, d.range);
    } while (d.range != "nho" && d.range != "trung binh" && d.range != "lon");
    
    do {
        cout << "Nhap tong kinh phi (ty dong): ";
        cin >> d.cost;
    } while (d.cost < 0);

    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.range << " | " << d.cost << endl;
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
    if (root->data.cost > value.cost) {
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
    if (root == NULL || root->data.cost == target) {
        return root;
    } else if (root->data.cost > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void cau3(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->data.cost > 10) {
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
        cout << "Nhap so luong du an: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin du an thu " << i << endl;
        Data d = setData();
        tree.root = insert(tree.root, d);
        cout << endl;
    }
    
    cout << "Thong tin cac du an vua nhap la:" << endl;
    inOrderTraversal(tree.root);
    cout << endl;
    
    cout << "Nhung du an co tong kinh phi lon hon 10 ty la:" << endl;
    cau3(tree.root);
    cout << endl;
    
    if (search(tree.root, 100) == NULL) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}