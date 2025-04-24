#include <iostream>
#include <string>
using namespace std;

class RRS {
    string name;
    string phone;
    int price;
    RRS *lc, *rc;

public:
    void create();
    void insert(RRS *, RRS *);
    void display(RRS *root);
    void displayAC(RRS *root);
    void displayNonAC(RRS *root);
    int totalTicketPrice(RRS *root);
    
    RRS* searchPassenger(RRS* root, int key);
    
} * root = NULL;

void RRS::create() {
    int ch;
    RRS *next;
    root = new RRS;
    cout << "\nEnter the Name: ";
    cin >> root->name;
    cout << "Enter the Phone number: ";
    cin >> root->phone;
    cout << "Enter the ticket price: ";
    cin >> root->price;
    root->lc = root->rc = NULL;

    do {
        cout << "\nYou want to add more passengers? (1/0): ";
        cin >> ch;

        if (ch == 1) {
            next = new RRS;
            cout << "\nEnter the Name: ";
            cin >> next->name;
            cout << "Enter the Phone number: ";
            cin >> next->phone;
            cout << "Enter the ticket price: ";
            cin >> next->price;
            next->lc = next->rc = NULL;
            insert(root, next);
        }

    } while (ch == 1);
}

void RRS::insert(RRS *root, RRS *next) {
    if (root->price > next->price) {
        if (root->lc == NULL) {
            root->lc = next;
        } else {
            insert(root->lc, next);
        }
    } else {
        if (root->rc == NULL) {
            root->rc = next;
        } else {
            insert(root->rc, next);
        }
    }
}

void RRS::display(RRS *root) {
    if (root == NULL) {
        return;
    }
    display(root->lc);
    cout << "\n" << root->name << "\t" << root->phone << "\t" << root->price;
    display(root->rc);
}

void RRS::displayAC(RRS *root) {
    if (root == NULL) return;
    displayAC(root->lc);
    if (root->price > 500)  // Assuming AC tickets are priced above 500
        cout << "\n" << root->name << "\t" << root->phone << "\t" << root->price;
    displayAC(root->rc);
}

void RRS::displayNonAC(RRS *root) {
    if (root == NULL) return;
    displayNonAC(root->lc);
    if (root->price <= 500)  // Assuming Non-AC tickets are priced below 500
        cout << "\n" << root->name << "\t" << root->phone << "\t" << root->price;
    displayNonAC(root->rc);
}

int RRS::totalTicketPrice(RRS *root) {
    if (root == NULL)
        return 0;
    return root->price + totalTicketPrice(root->lc) + totalTicketPrice(root->rc);
}

RRS* RRS::searchPassenger(RRS *root, int key) {
    if (root == NULL || root->price == key)
        return root;

    if (key < root->price)
        return searchPassenger(root->lc, key);
    else
        return searchPassenger(root->rc, key);
}



int main() {
    int ch;
    int pz;

    while (true) {
        cout << "\n\nMenu\n1. INSERT passenger detail\n2. Display all passengers\n3. Display AC passengers\n4. Display Non-AC passengers";
        cout << "\n5. Total sum of ticket prices\n6. Delete a passenger by name\n7. Search a passenger by name\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                root->create();
                break;
            case 2:
                root->display(root);
                break;
            case 3:
                root->displayAC(root);
                break;
            case 4:
                root->displayNonAC(root);
                break;
            case 5:
                cout << "\nTotal Ticket Price: " << root->totalTicketPrice(root);
                break;
            /*case 6:
                cout << "\nEnter Name to Delete: ";
                cin >> name;
                root = root->deletePassenger(root, name);
                cout << "\nPassenger Deleted!";
                break;*/
            case 7:
                cout << "\nEnter Name to Search: ";
                cin >> pz;
                if (root->searchPassenger(root, pz))
                    cout << "\nPassenger Found!";
                else
                    cout << "\nPassenger Not Found!";
                break;
            case 8:
                return 0;
            default:
                cout << "\nWrong choice.";
        }
    }
}
