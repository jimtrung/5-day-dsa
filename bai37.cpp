#include <iostream>
#include <string>
using namespace std;

struct NhanVien { 
    int id;
    string name, address, sdt;
    float luong;
};

typedef NhanVien Data;

Data setData() {
    Data d;
    cout << "Nhap ma khach hang: "; cin >> d.id;
    cout << "Nhap ten khach hang: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap dia chi cua khach hang: "; getline(cin, d.address);
    cout << "Nhap so dien thoai: "; getline(cin, d.sdt);
    do {
        cout << "Nhap tien luong: "; cin >> d.luong; 
    } while (d.luong < 0);
    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.address << " | " << d.sdt << " | " << d.luong << endl;
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

void pushFront(LinkedList &list, Data value) {
    Node* newNode = createNewNode(value);
    if (isEmpty(list)) {
        list.head = list.tail = newNode;
    } else {
        newNode->next = list.head;
        list.head->prev = newNode;
        list.head = newNode;
    }
}

void popBack(LinkedList &list) {
    if (isEmpty(list)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    if (list.head->next == NULL) {
        delete list.head;
        list.head = list.tail = NULL;
    } else {
        list.tail = list.tail->prev;
        delete list.tail->next;
        list.tail->next = NULL;
    }
}

void traverse(LinkedList list) {
    if (isEmpty(list)) {
        cout << "Danh sach rong" << endl; 
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
        cout << "Danh sach rong" << endl;
        return;
    }
    
    bool found = false;
    Node* curr = list.head;
    while (curr) {
        if (curr->data.address == "hp") {
            if (!found) {
                cout << "Thong tin khach hang co dia chi Hai Phong la:" << endl;  
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co khach hang nao co dia chi o Hai Phong" << endl; 
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong khach hang: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin khach hang thu " << i << endl;
        Data d = setData();
        pushFront(list, d);
        cout << endl;
    }
    
    cout << "Danh sach sau khi nhap thong tin khach hang la:" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popBack(list);
    cout << "Danh sach khach hang sau khi xoa khach hang cuoi cung la:" << endl;
    traverse(list);
    
    return 0;
}
