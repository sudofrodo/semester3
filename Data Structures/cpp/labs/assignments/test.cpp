#include <iostream>
using namespace std;

struct person {
    int id;
    string name;
    bool registered;
    person* next = NULL;
};

class ParticipantList {
    person* head = NULL;
  public:
    void registerParticipant(person* p);
    void updateRegistration(person* p);
    void removeRegistration();
    void displayAParticipant(person* p);
    void displayConfirmedParticipants();
};

// Adds a participant to the end of the list
void ParticipantList::registerParticipant(person* p) {
    if (this->head == NULL) {
        this->head = p;
        return;
    }
    person* last = this->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = p;
}

// Toggles the registration status of a participant
void ParticipantList::updateRegistration(person* p) {
    p->registered = !(p->registered);
}

// Removes all participants whose registration is cancelled (registered == false)
void ParticipantList::removeRegistration() {
    // Remove unregistered nodes from the front
    while (head != NULL && !head->registered) {
        person* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL) return;

    // Remove unregistered nodes from the rest of the list
    person* prev = head;
    person* curr = head->next;
    while (curr != NULL) {
        if (!curr->registered) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Displays a single participant's details
void ParticipantList::displayAParticipant(person* p) {
    cout << "Name: " << p->name << endl;
    cout << "ID:   " << p->id   << endl;
}

// Displays all participants with confirmed registrations
void ParticipantList::displayConfirmedParticipants() {
    person* curr = this->head;
    while (curr != NULL) {
        if (curr->registered) {
            this->displayAParticipant(curr);
        }
        curr = curr->next;
    }
}

int main() {
    ParticipantList list;

    // Register three participants
    person* p1 = new person();
    p1->name = "Athar";
    p1->id = 1;
    p1->registered = true;

    person* p2 = new person();
    p2->name = "Sara";
    p2->id = 2;
    p2->registered = true;

    person* p3 = new person();
    p3->name = "Bilal";
    p3->id = 3;
    p3->registered = true;

    list.registerParticipant(p1);
    list.registerParticipant(p2);
    list.registerParticipant(p3);

    cout << "--- All Confirmed Participants ---" << endl;
    list.displayConfirmedParticipants();

    // Cancel Sara's registration
    list.updateRegistration(p2);
    cout << "\n--- After Cancelling Sara ---" << endl;
    list.displayConfirmedParticipants();

    // Remove all cancelled registrations
    list.removeRegistration();
    cout << "\n--- After Removing Cancelled ---" << endl;
    list.displayConfirmedParticipants();

    return 0;
}