#include <iostream>
#include <string>
using namespace std;

struct HocVien {
    int id;
    string name, lop, chuyenNganh;
    float grade;
};

typedef HocVien Data;

Data setData() {
    Data d;
    cout << "Nhap ma hoc vien: "; cin >> d.id;
    cout << "Nhap ten hoc vien: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap lop hoc vien: "; getline(cin, d.lop);

    do {
        cout << "Nhap chuyen nganh (TMDT/QTANM/KHMT): "; 
        getline(cin, d.chuyenNganh); 
    } while (d.chuyenNganh != "TMDT" && d.chuyenNganh != "QTANM" && d.chuyenNganh != "KHMT");

    do {
        cout << "Nhap diem tong ket: ";
        cin >> d.grade;
    } while (d.grade < 0 || d.grade > 10);

    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.lop << " | " << d.chuyenNganh << " | " << d.grade << endl;
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
    if (root->data.grade > value.grade) { 
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

Node* search(Node* root, string target) {
    if (root == NULL || root->data.chuyenNganh == target) {
        return root;
    } else if (root->data.chuyenNganh > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void cau3(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->data.grade > 8) {
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
        cout << "Nhap so luong hoc vien: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin hoc vien thu " << i << endl;
        Data d = setData();
        tree.root = insert(tree.root, d);
        cout << endl;
    }
    
    cout << "Thong tin cac hoc vien vua nhap la:" << endl;
    inOrderTraversal(tree.root);
    cout << endl;
    
    cout << "Nhung hoc vien co diem tong ket lon hon 8.0 la:" << endl;
    cau3(tree.root);
    cout << endl;
    
    if (search(tree.root, "TMDT") == NULL) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}



