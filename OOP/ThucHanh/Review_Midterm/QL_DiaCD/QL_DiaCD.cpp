#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CD {
private:
    int id;
    string title;
    string artist;
    int numberOfSongs;
    float price;

public:
    // constructors
    CD() {}
    CD(int id, string title, string artist, int numberOfSongs, float price) {
        this->id = id;
        this->title = title;
        this->artist = artist;
        this->numberOfSongs = numberOfSongs;
        this->price = price;
    }

    // getters and setters
    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getTitle() const {
        return title;
    }

    void setTitle(string title) {
        this->title = title;
    }

    string getArtist() const {
        return artist;
    }

    void setArtist(string artist) {
        this->artist = artist;
    }

    int getNumberOfSongs() const {
        return numberOfSongs;
    }

    void setNumberOfSongs(int numberOfSongs) {
        this->numberOfSongs = numberOfSongs;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        this->price = price;
    }

    // toString method
    string toString() const {
        return to_string(id) + "\t" + title + "\t" + artist + "\t" + to_string(numberOfSongs) + "\t" + to_string(price);
    }
};

class CDList {
private:
    CD* list;
    int size;
    int capacity;

public:
    // constructors and destructor
    CDList() {
        size = 0;
        capacity = 10;
        list = new CD[capacity];
    }

    CDList(int capacity) {
        size = 0;
        this->capacity = capacity;
        list = new CD[capacity];
    }

    ~CDList() {
        delete[] list;
    }

    // other methods
    bool addCD(const CD& cd) {
        // check if the list is full
        if (size >= capacity) {
            return false;
        }

        // check if the CD with the same id already exists
        for (int i = 0; i < size; i++) {
            if (list[i].getId() == cd.getId()) {
                return false;
            }
        }

        list[size] = cd;
        size++;

        return true;
    }

    int countCD() const {
        return size;
    }

    float totalCost() const {
        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += list[i].getPrice();
        }
        return sum;
    }

    void sortByPriceDescending() {
        sort(list, list + size, [](const CD& cd1, const CD& cd2) {
            return cd1.getPrice() > cd2.getPrice();
            });
    }

    void sortByTitleAscending() {
        sort(list, list + size, [](const CD& cd1, const CD& cd2) {
            return cd1.getTitle() < cd2.getTitle();
            });
    }

    void printAllCDs() const {
        cout << "ID\tTitle\tArtist\t#Songs\tPrice" << endl;
        for (int i = 0; i < size; i++) {
            cout << list[i].toString() << endl;
        }
    }
};

void run() {
    CDList cdList(5);

    while (true) {
        // display menu
        cout << endl;
        cout << "CD Collection" << endl;
        cout << "-------------" << endl;
        cout << "1. Add a CD" << endl;
        cout << "2. Count CDs" << endl;
        cout << "3. Total cost" << endl;
        cout << "4. Sort by Price (descending)" << endl;
        cout << "5. Sort by Title (ascending)" << endl;
        cout << "6. Print all CDs" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------" << endl;

        // get user's choice
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // get CD information from user input
            int id, numberOfSongs;
            string title, artist;
            float price;
            cout << "Enter CD ID: ";
            cin >> id;
            cout << "Enter CD Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter CD Artist: ";
            getline(cin, artist);
            cout << "Enter number of songs: ";
            cin >> numberOfSongs;
            cout << "Enter price: ";
            cin >> price;

            // create CD object and add to the list
            CD cd(id, title, artist, numberOfSongs, price);
            if (cdList.addCD(cd)) {
                cout << "CD added successfully." << endl;
            }
            else {
                cout << "Failed to add CD. Either the ID already exists or the list is full." << endl;
            }
            break;
        }
        case 2: {
            cout << "Number of CDs: " << cdList.countCD() << endl;
            break;
        }
        case 3: {
            cout << "Total cost: " << cdList.totalCost() << endl;
            break;
        }
        case 4: {
            cdList.sortByPriceDescending();
            cout << "CDs sorted by price (descending)." << endl;
            break;
        }
        case 5: {
            cdList.sortByTitleAscending();
            cout << "CDs sorted by title (ascending)." << endl;
            break;
        }
        case 6: {
            cdList.printAllCDs();
            break;
        }
        case 0: {
            cout << "Exiting program." << endl;
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

int main() {
    run();
}