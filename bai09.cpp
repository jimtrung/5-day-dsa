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
        return;
    }
    list.tail = list.tail->prev;
    delete list.tail->next;
    list.tail->next = NULL;
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
    
    Node* curr = list.head;
    bool found = false;
    
    while (curr) {
        if (curr->data.chuyenNganh == "TMDT" && curr->data.grade >= 8) {
            if (!found) {
                cout << "Thong tin hoc vien nganh TMDT co diem tong ket lon hon bang 8" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co hoc vien nao nganh TMDT va co diem tong ket lon hon bang 8" << endl;
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong hoc vien: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin hoc vien thu " << i << endl;
        Data d = setData();
        pushFront(list, d);
        cout << endl;
    }
    
    cout << "Danh sach sau khi nhap thong tin cac hoc vien:" << endl;  
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popBack(list);
    cout << "Danh sach hoc vien sau khi xoa hoc vien cuoi cung" << endl;
    traverse(list);
    
    return 0;
}