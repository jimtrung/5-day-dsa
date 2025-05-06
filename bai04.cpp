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
    Node* next;
    Node* prev;
};

Node* createNewNode(Data value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct LinkedList {
    Node* head;  
    Node* tail;
};

void newLinkedList(LinkedList &list) {
    list.head = list.tail = NULL;
}

bool isEmpty(LinkedList list) {
    return list.head == NULL;
}

void pushBack(LinkedList &list, Data value) {
    Node* newNode = createNewNode(value);
    if (isEmpty(list)) { 
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
} 

void popFront(LinkedList &list) {
    if (isEmpty(list)) {
        cout << "Danh sach lien ket rong. Khong the xoa dau" << endl;
        return;
    }
    if (list.head->next == NULL) {
        delete list.head;
        list.head = list.tail = NULL;
        return;
    }
    Node *curr = list.head;
    list.head = list.head->next;
    list.head->prev = NULL;
    delete curr;
} 

void traverse(LinkedList list) {
    if (isEmpty(list)) {
        cout << "Danh sach lien ket rong. Khong the duyet" << endl;
        return;
    }

    Node* curr = list.head;
    while (curr) {
        getData(curr->data);
        curr = curr->next;
    }
}

void cau3(LinkedList list) {
    if (isEmpty(list)) {
        cout << "Danh sach lien ket rong. Khong the duyet" << endl;
        return;
    }
    
    bool found = false;
    Node* curr = list.head;
    while (curr) {
        if (curr->data.hk == "yeu") {
            if (!found) {
                cout << "Nhung sinh vien co hanh kiem yeu:" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co sinh vien nao duoc hanh kiem yeu" << endl; 
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin sinh vien thu " << i << endl;
        Data d = setData();
        pushBack(list, d);
        cout << "\n";
    }
    
    cout << "Danh sach sau khi nhap thong tin cua cac sinh vien:" << endl; 
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popFront(list);
    cout << "Danh sach sau khi xoa sinh vien dau la: " << endl;
    traverse(list);
    
    return 0;
}

