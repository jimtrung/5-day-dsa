#include <iostream>
#include <string>
using namespace std;

struct MayTinh {
    int id;
    string name, nsx;
    float gia;
};

typedef MayTinh Data;

Data setData() {
    Data d;
    cout << "Nhap ma may tinh: "; cin >> d.id;
    cout << "Nhap ten may: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap nha san xuat: "; getline(cin, d.nsx);
    do {
        cout << "Nhap gia ban: ";
        cin >> d.gia;
    } while (d.gia < 0);
    
    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.nsx << " | " << d.gia << endl;
}

struct Node {
    Data data;
    Node* next;
};

Node* createNewNode(Data value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
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
        list.head = NULL;
        return;
    }
    Node* curr = list.head;
    while (curr->next->next) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    list.tail = curr;
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
        if (curr->data.nsx == "SamSung") {
            if (!found) {
                cout << "Thong tin may tinh san xuat boi SamSung" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co may tinh nao san xuat boi SamSung" << endl;
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong may tinh: "; 
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin may tinh thu " << i << endl;
        Data d = setData();
        pushFront(list, d);
        cout << endl;
    }
    
    cout << "Thong tin cac may tinh vua nhap la:" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popBack(list);
    cout << "Danh sach may tinh sau khi xoa phan tu cuoi cung:" << endl;
    traverse(list);
    
    return 0;
}