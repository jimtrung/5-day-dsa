#include <iostream>
#include <string>
using namespace std;

struct DuAn {
    int id;
    string name, range;
    float cost;
};

typedef DuAn Data;

Data setData() {
    Data d;
    cout << "Nhap ma du an: "; cin >> d.id;
    cout << "Nhap ten du an: "; cin.ignore(); getline(cin, d.name);
    
    do {
        cout << "Nhap qui mo du an (nho/trung binh/lon): ";
        getline(cin, d.range);
    } while (d.range != "nho" && d.range != "trung binh" && d.range != "lon");
    
    do {
        cout << "Nhap tong kinh phi (ty dong): "; 
        cin >> d.cost;
    } while (d.cost < 0);

    return d;
}

void getData(Data d) {
    cout << d.id << " | " << d.name << " | " << d.range << " | " << d.cost << endl;
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
        if (curr->data.cost < 5) {
            if (found == false) {
                cout << "Du an co tong kinh phi nho hon 5 ty la:" << endl;
                found = true;
            }
            getData(curr->data);
        }
        curr = curr->next;
    }
    if (!found) {
        cout << "Khong co du an nao co tong kinh phi nho hon 5 ty" << endl;
    }
}

int main() {
    LinkedList list;
    newLinkedList(list);
    
    int N;
    do {
        cout << "Nhap so luong du an: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin cua du an thu " << i << endl;
        Data d = setData();
        pushBack(list, d);
        cout << endl;
    }
    
    cout << "Danh sach sau khi nhap thong tin du an:" << endl;
    traverse(list);
    cout << endl;
    
    cau3(list);
    cout << endl;
    
    popFront(list);
    cout << "Danh sach du an sau khi xoa du an dau tien la:" << endl;
    traverse(list);
    
    return 0;
}
