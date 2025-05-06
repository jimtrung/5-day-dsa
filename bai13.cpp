#include <iostream>
#include <string>
using namespace std;

struct Ticket {
    int id;
    string type, start, end;
    float gia;
};

typedef Ticket Data;

Data setData() {
    Data d;
    cout << "Nhap ma ve may bay: "; cin >> d.id;
    cin.ignore();
    do {
        cout << "Nhap loai ve(N/TG/PT): ";  
        getline(cin, d.type); 
    } while (d.type != "N" && d.type != "TG" && d.type != "PT");
    cout << "Nhap diem khoi hanh: "; getline(cin, d.start);
    cout << "Nhap diem den: "; getline(cin, d.end);
    cout << "Nhap gia ve: "; cin >> d.gia;
    
    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.type << " | " << d.start << " | " << d.end << " | " << d.gia << endl;
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

void pushBack(LinkedList &list, Data value) {
    Node* newNode = createNewNode(value);
    if (isEmpty(list)) {
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
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
    delete curr;
}

void traverse(LinkedList &list) {
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
        if (curr->data.start == "hn") {
            if (!found) {
                cout << "Ve may bay co diem khoi hanh o Ha Noi la:" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co ve may bay nao khoi hanh tu Ha Noi" << endl;
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong ve may bay: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin ve may bay thu " << i << endl;
        Data d = setData();
        pushBack(list, d);
        cout << endl;
    }
    
    cout << "Danh sach sau khi nhap thong tin ve may bay:" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popFront(list);
    cout << "Danh sach ve may bay sau khi xoa phan tu dau tien la:" << endl;
    traverse(list);
    
    return 0;
}