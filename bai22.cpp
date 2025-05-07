#include <iostream>
#include <iomanip>
using namespace std;

struct SoPhuc {
    int thuc, ao;
};

typedef SoPhuc Data;

Data setData() {
    Data d;
    cout << "Nhap phan thuc: "; cin >> d.thuc;
    cout << "Nhap phan ao: "; cin >> d.ao; 
    return d;
}

void getData(Data d) {
    cout << d.thuc << " + " << d.ao << "i";
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
        cout << "Nhap so luong so phuc: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin so phuc thu " << i << endl;
        Data d = setData();
        enqueue(q, d);
        cout << endl;
    }
    
    int tongThuc = 0, tongAo = 0;
    cout << "Cac so phuc trong hang doi la:" << endl;
    while (!isEmpty(q)) {
        Data d;
        dequeue(q, d);
        getData(d);
        cout << "\n";
        tongThuc += d.thuc;
        tongAo += d.ao;
    }
    cout << endl;
    
    cout << setprecision(2) << fixed 
         << "Tong cua cac so phuc la: " 
         << tongThuc << " + " << tongAo << "i" << endl; 
    
    return 0;
}
