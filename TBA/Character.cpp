#include <iostream>
#include <string>
using namespace std;

class Character {
	private:
		string direction;
		string room;
		string name;
		string inventory;
		string body[6] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};
		string backpack[16] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};
	public:
		Character(){
			direction = "start";
			room = "elevator_room";
			setName("None");
			inventory = body[6];
		};
		Character(string n){
			direction = "start";
			room = "elevator_room";
			setName(n);
			inventory = body[6];
		};
		string getName(){
			return name;
		};
		void setName(string n){
			name = n;
		};
		string getRoom(){
			return room;
		}
		void setRoom(string r){
			room = r;
		}
		string getDirection(){
			return direction;
		}
		void setDirection(string d){
			direction = d;
		}
		void setInventory(){
                inventory = backpack[16];
		}
		void insertInventory(string inventory[], string item){
			for (int i = 0; i < sizeof(inventory); i++){
				if (inventory[i] == "Empty"){
					inventory[i] = item;
					cout << "The " << item << " has been added to the inventory into slot " << i << " ." << endl;
					return;
				}
			}
			cout << "Your inventory is full, please remove an item before attempting to store another." << endl;
			return;
		}
		void useItem(int i){
		    inventory = getInventory();
		    int s = sizeof(inventory);
			for (i ; i < s; i++){
				if (inventory[i+1] != "Empty"){
					inventory[i] = inventory[i+1];
				} else{
					inventory[i+1] = "Empty";
					return;
				}
			}
		}
        void showInventory(){
            string inventory = getInventory();
			cout << "______" << endl;
			for (int i = 0; i < sizeof(inventory); i++){
				cout << i+1 << inventory[i] << ", " << endl;
			}
			cout << "______" << endl;
			return;
		}
		string checkInventory(){
			int size = sizeof(inventory);
			if (size = 6){
				return "Body";
			} else {
				return "Backpack";
			}
		}
		string getInventory(){
            return inventory;
		}

};

/*Character::Character() {
	direction = "start";
	room = "elevator_room";
	setName("None");
}*/

/*Character::Character(n) {
	direction = "start";
	room = "elevator_room";
	setName(n);
}*/

/*string getName(){
	return name;
}*/

/*void setName(string x){
	string name = x;
}*/
