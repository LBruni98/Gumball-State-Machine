#include <iostream>
#include <string>

//These const int varibles are set to work with two numbers. This is for ease of use, mainly
const int NO_QUARTER = 0; //0 is no quarter
const int HAS_QUARTER = 1; //1 is there is a quarter
//bool noExit = true;
bool isBankrupt = true; //Global boolean to help end the program

class gumballMachine {
public:

	//Returns that state number to the user
	int getState() {
		return state;
	}

	//Returns the amount of cranks to the user
	int getCrank() {
		return crank;
	}

	//Returns the amount of gumballs to the user
	int getGumballs() {
		return gumballs;
	}

	//A function that predefines the values of the state, cranks and gumballs, only at the start
	void beforeWeBegin() {
		setState(NO_QUARTER); //The state is set to not have a quarter.
		setCrank(0); //The cranks are set to 0
		setGumballs(50); //The machine starts with 50 gumballs
	}

	//Bonus Gumball
	void bonusGumball() {
		//This if statement was set to get the function working as desired
		if ((crank % 10) == 0 && gumballs > 1 && crank != 0 && state == 0) { //After every ten cranks and more than one gumball... and the crank isn't 0... AND the machine has no quarter in it...
			gumballs = gumballs - 1; //...Another gumball is negated, meaning one is given for free
			std::cout << "YOU ARE THE TENTH CUSTOMER! HAVE ANOTHER GUMBALL ON THE HOUSE!\n"; //The customer gets a nice message
		}
		else if ((crank % 10) && gumballs == 1) { //However,there were 10 cranks but only one gumball left...
			std::cout << "Well... at this point you would get an extra gumball but, we're down to one. Sorry, mate!"; //It only displays the message and only deposits one as usual
		}
	}

	//Inserting the coins
	void insertQuarter() {
		if (state == NO_QUARTER) { //If the machine hasn't a quarter when the user inserts $0.25
			std::cout << "Quarter Inserted\n"; //Notifies the user
			setState(HAS_QUARTER); //The machine now has a quarter
		}
		else {
			std::cout << "There's already one in there!\n"; //Otherwise it will note that it has one in there
		}
	}

	//This function works like insertQuarter() but a bit backwards
	void ejectQuarter() {
		if (state == HAS_QUARTER) { //If the machine has a quarter in it and the user ejects...
			std::cout << "Quarter Ejected\n";
			std::cout << "No change in the Gumball Machine\n"; //Messages will note that the quarter is ejected
			setState(NO_QUARTER); //The machine is set to not have a quarter in it
		}
		else {
			std::cout << "Machine's empty, mate\n"; //Unless it's empty still, however, and the customer is notified
		}
	}

	//Function for turning the crank
	void turnCrank() {
		if (state == HAS_QUARTER) { //If the machine has a quarter in it,..
			crank++; //...The customer can turn the crank and it keeps note of an added crank turn...
			gumballs--; //...and dispenses a gumball, knocking one off the counter
			setState(NO_QUARTER); //It also sets the machine to no quarter
		}
		else { //Otherwise...
			std::cout << "Put a quarter in the machine first, cheapskate!\n"; //...This message appears if the customer is trying to get a freebie
		}
	}

	//Function for when the gumballs run out
	void outOfBalls() {
		char choice; //This will be where the customer makes their selection
		while (gumballs == 0) { //Once the gumballs have run out...
			//Messages display that the machine is out of gumballs
			std::cout << "We're all out of gumballs!\n";
			std::cout << "Do you want us to refill the system or leave it and come back next time?\n";
			std::cout << "Y/N?\n";
			std::cin >> choice; //The customer inputs their choice

			switch (choice) {
				//If their choice is yes
				case 'Y': //Uppercase
				case 'y': //Or lowercase
					std::cout << "'Ere ya go, mate!\n"; //Message Displays
					setGumballs(50); //and the gumballs are set to 50
					break; //Breaks the loop
				//Otherwise if the choice is no
				case 'N': //Uppercase
				case 'n': //Or lowercase
					std::cout << "Ah well! Come back next time!\n"; //Message Displays
					isBankrupt = false; //Boolean set to false, that will be used later
					//setState(HAS_QUARTER);
					return; //This technically ends the loop and goes back to the main
					//break;
				default: //If any other choice is made
					std::cout << "Mate, be clear! I don't understand that\n"; //Message tells the customer to get their head on straight
			}

			//if(choice == "Yes" || choice == "yes"){
			//std::cout << "'Ere ya go, mate!\n";
			//gumballs = 50;
			//}
			//if(choice == "No" || choice == "no") {
			//std::cout << "Nevermind! Come back next time!\n";
			//}
		}
	}

protected:

private:
	int gumballs; //Variable for the gumballs
	int crank; //Variable for the number of cranks
	int state; //Variable for the state

	//Command to set the state of the machine
	void setState(int newState) { //The newState variable is declared for a number to be set
		state = newState; //That new state assigns the original variable
	}

	//Command to set the amount of cranks
	void setCrank(int newCrank) { //Like the newState varible, the newCrank variable is declared for a number to be set
		crank = newCrank; //The value of newCrank is also given to the normal crank varible
	}

	//Command to set the amount of gumballs
	void setGumballs(int newGumballs) { //The newGumballs variable is declared for a number to be set
		gumballs = newGumballs; //The value of newGumballs is also given to the normal crank varible
	}

};

int main() {
	gumballMachine gumball; //Varible that will use the functions from the gumballMachine class
	std::string selection; //Where the user will input their selection
	bool noExit = true; //Boolean for aid in exiting the program

	//First up, these messages...
	std::cout << "Welcome to the Gumball State Machine!\n";
	std::cout << "Your options are INSERT, CRANK, EJECT and EXIT\n";
	std::cout << "Enjoy!\n";

	gumball.beforeWeBegin(); //This function is called to put the set values in place
	//gumball.outOfBalls();

	while (noExit == true) { //The main part of the program functions while the noExit boolean is true

		//The out of gumballs function is called here.
		//If the machine runs out of gumballs, this function will kick in
		gumball.outOfBalls();

		if (isBankrupt == false) { //If the isBankrupt is set to false...
			noExit = false; //This boolean is false, breaking the loop
			return 0; //And ends the program
		}

		//These messages display the values of each variable
		std::cout << "Current State: " << gumball.getState() << "\n"; //The current state of the gumball machine
		std::cout << "Cranks: " << gumball.getCrank() << "\n"; //The amount of cranks
		std::cout << "Gumballs Left: " << gumball.getGumballs() << "\n"; //The amount of Gumballs left
		std::cin >> selection; //This is where the customer makes their selection

		if (selection == "Insert" || selection == "insert") { //The customer chooses insert
			gumball.insertQuarter(); //Function from the gumballMachine class is called and inserts a quarter
		}
		else if (selection == "Eject" || selection == "eject") { //The customer chooses eject
			gumball.ejectQuarter(); //Function from the class is called and ejects the quarter
		}
		else if (selection == "Crank" || selection == "crank") { //The customer chooses crank
			gumball.turnCrank(); //The crank is turned
		}
		else if (selection == "Exit" || selection == "exit") { //The customer chooses exit
			noExit = false; //The boolean responsible for this while loop is set to false so the program can end
			std::cout << "Cheers, mate! See ya soon\n"; //Message displays
		}
		else { //The customer chooses to be an idiot, A.K.A make an unclear function
			std::cout << "Be clear will ya, I can't understand ya!\n"; //Messages tells them to be clear
		}

		gumball.bonusGumball(); //The bonus gumball function is called for the free gumball after 10 cranks

	}

	return 0; //Program ends normally
}
