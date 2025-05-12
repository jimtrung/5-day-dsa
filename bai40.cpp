#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct ThiSinh {
    int sbd;
    string name, school;
    float diem;
};

typedef ThiSinh Data;

void nhap(Data &d) {
    cout << "Nhap so bao danh: "; cin >> d.sbd;
    cout << "Nhap ten thi sinh: "; cin.ignore(); getline(cin, d.name);
    cout << "Nhap truong: "; getline(cin, d.school);
    do {
        cout << "Nhap diem: "; cin >> d.diem;
    } while (d.diem < 0 || d.diem > 10);
}

void xuat(Data d) {
    cout << " - SBD: " << d.sbd
         << " Ten: " << d.name 
         << " Truong: " << d.school
         << " Diem: " << fixed << setprecision(2) << d.diem << endl;
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
        cout << "Danh sach rong" << endl;
        return;
    }
    if (list.head->next == NULL) {
        delete list.head;
        list.head = list.tail = NULL;
        return;
    }
    Node* curr = list.head;
    list.head = list.head->next;
    list.head->prev = NULL;
    delete curr;
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
        xuat(curr->data);
        curr = curr->next;
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
        cout << "Thong thong tin thi sinh thu " << i << endl;
        Data d;
        nhap(d);
        pushBack(list, d);
        cout << endl;
    }
    
    cout << "Cau 2" << endl;
    traverse(list);
    cout << endl;
    
    cout << "Cau 4" << endl;
    popFront(list);
    traverse(list);
    
    return 0;
}