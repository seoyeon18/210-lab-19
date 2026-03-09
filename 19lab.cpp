// COMSC-210 | Lab 18 | Seoyeon An
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node {
    float rating;
    string comment;
    Node* next;
};

class Movie {
private:
    string title;
    Node* head;

public:
    Movie() {
        title = "";
        head = nullptr;
    }

    Movie(string t) {
        title = t;
        head = nullptr;
    }

    void addReview(double rating, string comment) {
        Node* newNode = new Node;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }

    string getTitle() const {
        return title;
    }
};

void addHead(Node*& head, float rating, string comment) {
    Node* newNode = new Node;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}

void addTail(Node*& head, float rating, string comment) {
    Node* newNode = new Node;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

}


void output(Node* head) {
    Node* curr = head;
    int reviewNum = 1;
    float total = 0.0f;
    int count = 0;

    cout << "\nOutputting all reviews:" << endl;
    while (curr != nullptr) {
       cout << "> Review #" << reviewNum << ": "
             << curr->rating << ": "
             << curr->comment << endl;
        total += curr->rating;
        count++;
        reviewNum++;
        curr = curr->next;
    }
    if (count>0) {
        cout << (total / count);
    }
    else {
        cout << "Average:0" << endl;
    }
}
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int choice;
    float rating;
    string comment;
    char again;

    cout << "Which linked list method should we use?" << endl;
    cout << "New nodes are added at head of the linked list" << endl;
    cout << "New nodes are added at tail of linked list" << endl;
    cout << "Choice: ";
    cin >> choice;

    do{
        cout << "Enter review rating->";
        cin >> rating;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter review comments: ";
        getline(cin, comment);
        if(choice == 1){
            addHead(head, rating, comment);
        }
        else {
            addTail(head, rating, comment);
        }
        cout << "Enter another review? Y/N: ";
        cin >> again;
    }while (again == 'Y' || again == 'y');

    output(head);
    deleteList(head); 

    return 0;
}