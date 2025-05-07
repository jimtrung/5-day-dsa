#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int id;
    string name, lop, hk;
    float diem;  
};

typedef SinhVien Data;

Data setData() {
    Data d;
    cout << "Nhap ma sinh vien: "; cin >> d.id;
    cout << "Nhap ten sinh vien: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap lop cua sinh vien: "; getline(cin, d.lop);
    do {
        cout << "Nhap diem tong ket: "; cin >> d.diem;
    } while (d.diem < 0 || d.diem > 10);
    cout << "Nhap hanh kiem: "; cin.ignore(); getline(cin, d.hk);
    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.lop << " | " << d.diem << " | " << d.hk << endl;
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
    if (root->data.diem > value.diem) { 
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
    if (root == NULL || root->data.diem == target) {
        return root;
    } else if (root->data.diem > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void cau3(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->data.diem > 8) {
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
        cout << "Nhap so luong sinh vien: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin sinh vien thu " << i << endl;
        Data d = setData();
        tree.root = insert(tree.root, d);
        cout << endl;
    }
    
    cout << "Thong tin cac sinh vien vua nhap la:" << endl;
    inOrderTraversal(tree.root);
    cout << endl;
    
    cout << "Nhung sinh vien co diem tong ket lon hon 8.0 la:" << endl;
    cau3(tree.root);
    cout << endl;
    
    if (search(tree.root, 10) == NULL) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}
