#include <iostream>
#include <string>
using namespace std;

int main (){
string my_dir;
string name;
cout << "Please type in your name."<< endl;
getline(cin, name);
cout << "Hello, " << name << " .  It's your first day at your fancy new IT job.  How exciting!  Like usual, you're "
    "already late, despite having set your alarm a half hour earlier than usual.  You blame the snooze gnomes."
    "You had a treaty with the Gnome King, damnit!" << endl;
cout << "The 100 year sleep war will have to wait.  You hustle to the door and throw it open." <<endl;
cout << "Politely, of course." << endl;
cout << "You are in the elevator room. In this room you see an elevator to the north and a solid wood door to the west." << endl;
cout << "Type in a command." <<endl;
string my_room="elevator room";
while(/*my_room!=credits && */my_dir!="q"||my_dir!="quit"||my_dir!="Quit"||my_dir!="qUit"||my_dir!="quIt"||my_dir!="quiT"||my_dir!="QUit"||my_dir!="QuIt"||my_dir!="QuiT"||my_dir!="QUIt"||my_dir!="QUIT"){
    
    cin >> my_dir;
    if(my_room=="elevator room"){
        
        if (my_dir=="l"||my_dir=="look"||my_dir=="Look"||my_dir=="lOok"||my_dir=="loOk"||my_dir=="looK"||my_dir=="LOok"||my_dir=="LoOk"||my_dir=="LooK"||my_dir=="LOOk"||my_dir=="LOoK"||my_dir=="LOOK"){
            cout << "You look around the room.  There is a long table along the eastern wall with a coffee pot, a few styrofoam cups, "
            "some coffee creamer and some sugar.  Nothing else appears to be on the desk.  There is a potted plant in the corner of the room."
            "  The walls are taupe.  It's quite a nice shade of brown." << endl;
            my_room="elevator room";
            cout << "Type in a command." <<endl;
        }
        if (my_dir=="n"||my_dir=="north"||my_dir=="North"||my_dir=="nOrth"||my_dir=="noRth"||my_dir=="norTh"||my_dir=="nortH"||my_dir=="NOrth"||my_dir=="NoRth"||my_dir=="NorTh"||my_dir=="NortH"||my_dir=="NORth"||my_dir=="NOrTh"||my_dir=="NOrtH"||my_dir=="NORTh"||my_dir=="NORTH"){
            /*cout << "The elevator is in front of you.  You press the button to call the elevator to your floor, however the light doesn't"
            " come on.  Right gentlemen?"<<endl;
            cout << "The light doesn't come on.  You gently press along the outside of the button.  Maybe there's a short.  Right ladies?" << endl;
            cout << "The light still doesn't show its luminescence.  Frustrated, you press the button a few times with the heel of your hand"
            " before seeing that there is a key card scanner next to the elevator call button.  Good thing there isn't anybody watching, because"
            " you look like an idiot!  Just like your mother said you would!  You need a card key!"<<endl;*/
            my_room="elevator room";
            cout << "Type in a command." <<endl;
            cout << my_dir<<endl;
        }
        if (my_dir=="s"||my_dir=="south"||my_dir=="South"||my_dir=="sOuth"||my_dir=="soUth"||my_dir=="souTh"||my_dir=="soutH"||my_dir=="SOuth"||my_dir=="SoUth"||my_dir=="SouTh"||my_dir=="SoutH"||my_dir=="SOUth"||my_dir=="SOuTh"||my_dir=="SOutH"||my_dir=="SOUtH"||my_dir=="SOUTH"){
            cout << "Oh shit, that's right! Your backpack! You decide to run back to your shitty Buick LeSabre and pick up your Teenage Mutant "
            "Ninja Turtle backpack.  Nobody said you were mature, just an adult."<<endl;
            cout<<"South"<<endl;
            //add backpack
            my_room="elevator room";
            cout << "Type in a command." <<endl;
        }
        else{
            cout<<"That is not a valid command, please try again."<<endl;
            my_room="elevator room";
            cout << "Type in a command." <<endl;
        }
    }
}
return 0;
}
