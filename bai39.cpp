#include <iostream>
#include <string>
using namespace std;

struct ThiSinh {
    int id;
    string name, school;
    float grade;
};

typedef ThiSinh Data;

Data setData() {
    Data d;
    cout << "Nhap so bao danh: "; cin >> d.id;
    cout << "Nhap ten thi sinh: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap ten truong: "; getline(cin, d.school);
    do {
        cout << "Nhap tong diem: "; cin >> d.grade;
    } while (d.grade < 0 || d.grade > 30);

    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.school << " | " << d.grade << endl; 
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

    bool found = false;
    Node* curr = list.head;

    while (curr) {
        if (curr->data.school == "THPTCG" && curr->data.grade >= 27) {
            if (!found) {
                cout << "Thi sinh thuoc truong THPT Cau Giay co diem >= 27 la:" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co thi sinh nao thuoc truong THPT Cau Giay va co diem >= 27" << endl;
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong thi sinh: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin thi sinh thu " << i << endl;
        Data d = setData();
        pushFront(list, d);
        cout << endl;
    }
    
    cout << "Danh sach sau khi nhap thong tin cac thi sinh la:" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popBack(list);
    cout << "Danh sach thi sinh sau khi xoa thi sinh cuoi cung la:" << endl;
    traverse(list);
    
    return 0;
}