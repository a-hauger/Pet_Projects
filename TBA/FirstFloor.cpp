#include <iostream>
#include <string>
#include "Character.cpp"
using namespace std;

string elevatorRoom(Character player); //function headers
string sec_office(Character player);

int main(){
	cout << "Commands:\nq - Quit\nn - North\ns - South\ne - East\nw - west\nl - look\nuse - Use Item from Inventory\nshow - Show Inventory" << endl;
	string n;
	cout << "What is your name, stranger?" << endl;
	getline(cin, n);
	Character player(n); //create character
	while (player.getRoom() != "credits"){ //start game
		if (player.getRoom() == "elevator_room"){
			player.setRoom(elevatorRoom(player)); //returns string to continue game - security office
		} else if (player.getRoom() == "sec_office"){
			player.setRoom(sec_office(player)); //returns string to continue game - elevator room
		}
		cout << player.getRoom() << endl;
	}
}

string elevatorRoom(Character player){
	string direction;
	int item;
	cout << "You are in the elevator room. In this room you see an elevator to the north and a solid wood door to the west." << endl; //intro text
	cout << "Please type in a command."<<endl;
	getline(cin, direction);
	player.setDirection(direction); //set direction
	while (player.getDirection()!="q"){ //test direction - quit game
		cout << "while loop"<< endl;
		if (player.getDirection() == "l"){ //test direction - look - elevator room
			cout << "You look around the room.  There is a long table along the eastern wall with a coffee pot, a few styrofoam cups, "
            "some coffee creamer and some sugar.  Nothing else appears to be on the desk.  There is a potted plant in the corner of the room."
            "  The walls are taupe.  It's quite a nice shade of brown." << endl;
			cout << "Please type in a command." << endl;
			getline(cin, direction);
			player.setDirection(direction); //set direction
		} else if (player.getDirection() == "n"){ //test direction - north - elevator
			cout << "The elevator is in front of you.  You press the button to call the elevator to your floor, however the light doesn't"
            " come on.  Right gentlemen?"<<endl;
            cout << "The light doesn't come on.  You gently press along the outside of the button.  Maybe there's a short." << endl;
            cout << "The light still doesn't show its luminescence.  Frustrated, you press the button a few times with the heel of your hand"
            " before seeing that there is a key card scanner next to the elevator call button.  Good thing there isn't anybody watching, because"
            " you look like an idiot!  Just like your mother said you would!  You need a card key!"<<endl;
			cout << "Please type in a command." << endl;
			getline(cin, direction);
			player.setDirection(direction); //set direction
			if (player.getDirection() == "use"){ //test direct - "use" - looking for security card
				cout << "Which item in your inventory would you like to use?" << endl << "Please type in the number of the item."<<endl;
				//string inventory = player.getInventory();
				player.showInventory();
				getline(cin, item);
				while (item != "none"){
					if (item == "key_card"){
                        player.useItem(item);
						cout << "You swipe the key card.  It doesn't do anything.  You swipe it again, with the same results.  You try turning the strip the other way, and it "
						"doesn't work.  You franctically swipe it a couple times before swiping it really slow.  Finally the light turns green and you press the up button.  You "
						"are so so SO late.  You step into the elevator and press the button for 3, the top floor and where your office is.  The elevator starts to rise and you "
						"begin to relax.  You're only a half hour late, no big deal!  You feel the elevator begin to shake a bit before it comes to a halt.  You step towards "
						"the door, thinking its about to open when the elevator begins to plummet!  That sinking feeling hits your stomach as you fall.  The elevator car "
						"scrapes against the wall with a sickening grind, bouncing back and forth against the elevator shaft until it slams into the bottom of the shaft.  "
						"You crumple to the floor upon impact.  The elevator door dings and opens just enough for you to squeeze through.  You stand up and assess the damages; "
						"Other than a few aches and bruises, you seem fine.  It's a Christmas miracle.  You step through the broken elevator's doors.  You are now on Basement "
						"Level 3." << endl;
						return "b3";
					} else {
						cout << "That item will not work here.  Please try again." << endl;
						cin >> inventory_command;
					}
				cout << "Please type in a command." << endl;
				getline(cin, direction);
				player.setDirection(direction); //set direction
			} else if (player.getDirection() = "show"){
				player.showInventory(player.getInventory());
			}
		} else if (player.getDirection() == "s"){ //tests direction - south - backpack
			if (player.checkInventory() == "Body"){
				player.setInventory();
				cout << "Oh shit, that's right! Your backpack! You decide to run back to your shitty Buick LeSabre and pick up your Teenage Mutant "
            	"Ninja Turtle backpack.  Nobody said you were mature, just an adult."<<endl;
			}
            cout << "Type in a command." <<endl;
            player.setDirection(direction);  //set direction
		} else if (player.getDirection() == "w"){ //test direction - west - security office
			cout << "You have entered the Security Office." << endl;
			return "sec_office"; //returns string to continue to security office
		} else if (player.getDirection() == "e"){
			cout << "You are standing in front of the long folding table.  It is roughly ten feet long and is sagging in the middle. There is a Mr. Café half filled with what"
			"looks to be some sort of dirt.  Red clay?  Whatever, it's passing as 'coffee.' Next to the Mr. Café are three styrofoam cups. The taupe walls are spotted with "
			"dried fly guts.  Seems sanitary." << endl;
			cout << "Please type in a command."<< endl;
			getline(cin, direction);
			player.setDirection(direction);
			if (player.getDirection() == "get"){
				cout << "You fill up a cup with coffee and put it in your hand."
				item = "coffee";
				player.insertInventory(player.getInventory(), item);
			}
		} else{
			cout << "That is not a valid command, please try again" << endl;
			cout << "Please type in a command." << endl;
			getline(cin, direction);
			player.setDirection(direction);
		}
	}
	return "Whoops!";
}

string sec_office(Character player){
	string direction;
	cout << "In this room, you see a door to your South and a man to your North." << endl;
	cout << "Please type in a command." << endl;
	getline(cin, direction);
	player.setDirection(direction);
	while (player.getDirection() != "q"){
		if (player.getDirection() == "l"){
			cout << "The office is small and cramped.  The walls are bare and a shade of off white that only years of poor maintenance can provide. The "
			"desk is kept fairly clean; since it is small there isn't a lot of room to place a lot of, I don't know, candy wrappers.  The security officer is watching some"
			"sort of television series online." << endl;
			cout << "Please type in a command."  << endl;
			getline(cin, direction);
			player.setDirection(direction);
		} else if (player.getDirection() == "n"){
			cout << "You approach the security officer.  He raises his hand without looking away from his monitor,/n 'Not until I've had my coffee.'" << endl;
			cout << "Please type in a command." << endl;
			getline(cin, direction);
			player.setDirection(direction);
			if (player.getDirection() == "use"){
				cout << "Which inventory item would you like to use?" << endl;
				/*print inventory list
				cin >> inventory_command;
				while (inventory_command != none){
					if (inventory_command == "coffee"){
						cout << "You approach the 'security' officer with the coffee.  You didn't put any cream or sugar in it, so he's got disgusting generic garbage unless"
						"he wants to get up himself and do it.  He glares at you as you set down the coffee cup. 'I'm late.' You make a 'could we get this going' gesture"
						" to help you explain your exasperation.  He takes your picture and prints you your security card.  As you're leaving the room, he mocks; \n'Have a "
						"great day!'/n Dripping with sarcasm, you call back\n 'Don't work too hard now.'\n You are now in the elevator room." << endl;
						return "elevator_room";
					} else{
						cout << "That item will not work here.  Please try again." << endl;
						cin >> inventory_command;
					}
				}
				cout << "You are in the Security Office*/
				cout << "Please type in a command" << endl;
				getline(cin, direction);
				player.setDirection(direction);
				}
			} else if (player.getDirection() == "s"){
				cout << "You have entered the Elevator Room." << endl;
				return "elevator_room";
			}
		}
		return "Whoops!";
	}
