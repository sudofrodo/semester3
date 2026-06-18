#include <iostream>
using namespace std;

struct person{
	int id;
	string name;
	bool registered;
	person* next = NULL;
};

class ParticipantList{
	person* head = NULL;
	public:
	void registerParticipant(person* p);
	void updateRegistration(person* p);
	void removeRegistration();
	void displayAParticipant(person* p);
	void displayConfirmedParticipants();
};

void ParticipantList::registerParticipant(person* p) {
	if(this -> head == NULL) {
		this -> head = p;
		return;
	}

	person* last = this -> head;
	while(last -> next != NULL) {
		last = last -> next;
	}
	last -> next = p;
	
}

void ParticipantList::updateRegistration(person* p) {
	if(p -> registered)
		p -> registered = false;
	else
		p -> registered = true;
}

void ParticipantList::removeRegistration(){

	while(head != NULL && !head -> registered){
		person* temp = this -> head;
		this -> head = head -> next;
		delete temp;
	}
	

	person* curr = this -> head;
	while(curr != NULL && curr -> next != NULL) {
		if(!curr -> next -> registered) {
			person* temp = curr -> next;
			curr -> next = curr -> next -> next;
			delete(temp);
		} else {
			curr = curr -> next;
		}
	}
}

void ParticipantList::displayAParticipant(person* p){
	cout << "Name: " << p -> name << endl;
	cout << "ID: " << p -> id << endl;

}

void ParticipantList::displayConfirmedParticipants() {
	person* curr = this -> head;
	while(curr != NULL) {
		if(curr -> registered) {
			this -> displayAParticipant(curr);
		}
		curr = curr -> next;
	}
	
}

int main() {

ParticipantList list;

person* p = new person();
p -> name = "athar";
p -> id = 1;
p -> registered = true;

person* p2 = new person();
p2 -> name = "ali";
p2 -> id = 1;
p2 -> registered = true;

list.registerParticipant(p2);
list.registerParticipant(p);
list.displayConfirmedParticipants();
 list.updateRegistration(p);
list.removeRegistration();
cout << "Updated:" << endl;
 list.displayConfirmedParticipants();
return 0;
}
