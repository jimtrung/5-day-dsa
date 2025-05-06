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
        cout << "Danh sach lien ket rong. Khong the xoa cuoi" << endl;
        return;
    }
    if (list.head->next == NULL) {
        delete list.head;
        list.head = list.tail = NULL;
        return;
    }
    list.tail = list.tail->prev;
    delete list.tail->next;
    list.tail->next = NULL;
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
        if (curr->data.diem > 8) { 
            if (!found) {
                cout << "Nhung sinh vien co diem lon hon 8 la" << endl; 
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co sinh vien nao co diem lon hon 8" << endl;
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
        pushFront(list, d);
        cout << "\n";
    }
    
    cout << "Danh sach sinh vien sau khi nhap thong tin" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popBack(list);
    cout << "Danh sach sinh vien sau khi xoa sinh vien cuoi" << endl;
    traverse(list);
    
    return 0;
}