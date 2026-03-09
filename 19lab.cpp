// COMSC-210 | Lab 18 | Seoyeon An
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

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



void outputReviews() const {
        Node* curr = head;
        int count = 0;
        double total = 0.0;

        cout << "\nMovie: " << title << endl;
        while (curr != nullptr) {
            count++;
            cout << "  Review #" << count << ": "
                 << curr->rating << " - "
                 << curr->comment << endl;
            total += curr->rating;
            curr = curr->next;
        }
        if (count > 0) {
            cout << "  Average Rating: " << total / count << endl;
        }
    }
    };


    double randomRating() {
    return (rand() % 40 + 10) / 10;
}


int main() {
    // Node* head = nullptr;
    // int choice;
    // float rating;
    // string comment;
    // char again;
    

    

    do{
        cout << "Enter review rating->";
        cin >> rating;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter review comments: ";
        getline(cin, comment);
        if(choice == 1){
            addReview(head, rating, comment);
        }
        else {
            outputReviews(head, rating, comment);
        }
        cout << "Enter another review? Y/N: ";
        cin >> again;
    }while (again == 'Y' || again == 'y');

    output(head);
    deleteList(head); 

    return 0;
}