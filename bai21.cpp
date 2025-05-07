#include <iostream>
#include <iomanip>
using namespace std;

struct PhanSo {
    int tuSo, mauSo;
};

typedef PhanSo Data;

Data setData() {
    Data d;
    cout << "Nhap tu so: "; cin >> d.tuSo;
    cout << "Nhap mau so: "; cin >> d.mauSo;
    return d;
}

void getData(Data d) {
    cout << d.tuSo << "/" << d.mauSo;
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

struct Queue {
    Node* head;
    Node* tail;
};

void newQueue(Queue &q) {
    q.head = q.tail = NULL;
}

bool isEmpty(Queue q) {
    return q.head == NULL;
}

void enqueue(Queue &q, Data value) {
    Node* newNode = createNewNode(value);
    if (isEmpty(q)) {
        q.head = q.tail = newNode;
    } else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

void dequeue(Queue &q, Data &d) {
    if (isEmpty(q)) {
        cout << "Hang doi rong" << endl; 
        return;
    }
    d = q.head->data;
    if (q.head->next == NULL) {
        delete q.head;
        q.head = q.tail = NULL;
        return;
    }
    Node* curr = q.head;
    q.head = q.head->next;
    delete curr;
}

int main() {
    Queue q;
    newQueue(q);
    
    int N;
    do {
        cout << "Nhap so luong phan so: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin phan so thu " << i << endl;
        Data d = setData();
        enqueue(q, d);
        cout << endl;
    }
    
    float tong = 0;
    cout << "Cac phan so trong hang doi la:" << endl;
    while (!isEmpty(q)) {
        Data d;
        dequeue(q, d);
        getData(d);
        cout << " ";
        tong += float(d.tuSo) / d.mauSo;
    }
    
    cout << setprecision(2) << fixed 
         << "\nThong cua cac phan so la: " << tong << endl;
    
    return 0;
}