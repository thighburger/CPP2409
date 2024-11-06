#include <vector>
#include <iostream>
using namespace std;

class Movie {
public:
    string name;
    float score;
    Movie(string name, float score) {
        this->name = name;
        this->score = score;
    }
};

int main(void) {
    vector<Movie> result;
    Movie movie1{"Titanic", 9.1}; 
    Movie movie2{"Gone with the Wind", 9.1};
    Movie movie3{"Terminator", 9.1};

    result.push_back(movie1);
    result.push_back(movie2);
    result.push_back(movie3);

    for (const Movie& movie : result) {
        cout << movie.name << ": " << movie.score << endl;
    }

    return 0;
}
