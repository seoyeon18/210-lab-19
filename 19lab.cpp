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
                 << curr->rating << " -"
                 << curr->comment << endl;
            total += curr->rating;
            curr = curr->next;
        }
        if (count > 0) {
            cout << "  Average Rating:" << total / count << endl;
        }
    }
    };


    double randomRating() {
    return (rand() % 40 + 10) / 10 ;
}


int main() {

    srand(time(0));

    vector<Movie> movies;

    movies.push_back(Movie("dvc life"));
    movies.push_back(Movie("aaa")) ;
    movies.push_back(Movie("Zootopia"));
    movies.push_back(Movie("Avatar"));

    ifstream fin("reviews.txt");

    string line;

    int i;
    int j ;

    for(i = 0; i < movies.size(); i++) 
    {
    for(j = 0; j < 3;j++) {

            getline(fin, line) ;

            double rating = (rand() % 41 + 10) / 10.0;

            movies[i].addReview(rating, line);

        }
    }

    fin.close();

    cout << endl;
    cout << "Movie Reviews\n";

    for(i = 0; i < movies.size(); i++){

        movies[i].outputReviews();
    }

    return 0;
}