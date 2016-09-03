// lab1: simplegame_OOP
// Jose L. de Jesus
// read main.cpp, and follow the instructions at the bottom of main.cpp
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>


void display_message(std::string s, int x, int y);

class Entity
{
private:  // player data
	int x;
	int y;
	char icon;

public:
	void set_data(int conx, int cony, char conicon)
	{
		x = conx;
		y = cony;
		icon = conicon;
	}
	Entity(int x, int y, char icon);
	int get_x() { 
		return x; 
	}              
	int get_y() { 
		return y; 
	}				
	char get_icon() { 
		return icon; 
	}
	void set_x(int x) { 
		this->x = x; 
	}				
	void set_y(int y) { 
		this->y = y;
	}				
	void set_icon(char icon) { icon = icon; }	
};
Entity::Entity(int x, int y, char icon)
{
	set_data(x, y, icon);
}


/**
* moves the console cursor to the given x/y coordinate
* @param x
* @param y
*/
void moveCursor(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
	Entity Player(3, 4, 1);	//created with parameterized constructor 
	//Player.get_x();
	//Player.get_y();
	//Player.get_icon(); //not needed

	//Player.x = 3; - Commented out for step 1c
	//Player.y = 4;	- Commented out for step 1c
	//Player.icon = 1;	- Commented out for step 1c

	// game state constants
	const int RUNNING = 1; 
	const int WIN = 2;
	const int LOST = 3; 
	const int USER_QUIT = -1;

	// game data
	int width = 20; 
	int height = 15;
	char input;
	int state = RUNNING;
	do
	{
		// draw the game world
		moveCursor(0, 0);
		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				std::cout << '.';
			}
			std::cout << '\n';
		}
		// draw the player
		moveCursor(Player.get_x(), Player.get_y());
		std::cout << Player.get_icon();

		// get input from the user (wait for one key press)
		input = _getch();
	
		//display_message(input, Player.get_x(), Player.get_y());
		// process input from the user
		switch (input)
		{
		case 'w':	
			Player.set_y(Player.get_y() - 1); 
			break;	// move up
		case 'a':	
			Player.set_x(Player.get_x() - 1);	
			break;	// move left
		case 's':	
			Player.set_y(Player.get_y() + 1);	
			break;	// move down
		case 'd':	
			Player.set_x(Player.get_x() + 1);	
			break;	// move right
		case 27:	
			state = USER_QUIT;	
			break;	// quit
		}
		// show the game state message
		moveCursor(0, height + 1);
		switch (state)
		{
		case WIN:	std::cout << "You WON! Congratulations!\n";	break;
		case LOST:	std::cout << "You lost...\n";				break;
		}
	} while (state == RUNNING);

	// user must press ESCAPE before closing the program
	std::cout << "press ESCAPE to quit\n";
	while (_getch() != 27);
	return 0;
}

void display_message(int msg, int x, int y) {
	//can hardcode for this example
	moveCursor(0, 18);
	std::cout << msg << std::endl;
	/*moveCursor(curX, curY);*/
}
// INSTRUCTIONS
// ------------
// Compile this code. You should see a happy-face character on a field of
// periods. You can move the character with the 'w', 'a', 's', and 'd' keys.
//
// Read through this code! Try to understand it before starting the assignment.
// Comment confusing lines with what you think code is doing, and experiment
// with existing code to test your understanding.
// Once you feel comfortable with this code, accomplish each of the following,
// and make sure your code compiles and runs after each step is completed.
//
// 1) Object Oriented Refactoring
//   a) Write a class called Entity to store two public integers named x and y,
//      and a char named icon (the player data).
//   b) Remove x, y, and icon (the player data) from main(), create an instance
//      of the Entity class (named whatever you like) in main(), and use its
//      members as replacements for the x, y, and icon variables that were
//      removed.
//   c) Write a parameterized constructor for the Entity class that sets x, y,
//      and icon, and use it when creating the instance.
//   d) Make x, y, and icon private variables of Entity, and create Accessor
//      and Mutator (or Getter and Setter) functions to use them in main().
//      (hint: "player.x++" could be "player.setX(player.getX()+1);" )
//   e) Write a struct called Vector2, which has two int variables, x and y.
//   f) Write a default constructor for Vector2, which sets x and y to 0.
//   g) Write a parameterized constructor for Vector2, which sets x and y.
//   h) Remove x, and y from Entity, add an instance of the Vector2 structure
//      named "pos" to the Entity class, and use pos's members as replacements
//      for the x, and y variables that were removed.
//   i) Remove height and width (in the game data) from main(), create an
//      instance of the Vector2 structure named "size", and use size's x member
//      as a replacement for width, and size's y member as a replacement for
//      height.
//   j) Write a method in Vector2 with the signature
//      "bool is(int a_x, int a_y)". "is" should return true if a_x is equal to
//      that instance's x, and a_y is equal that instance's y.
//   k) Instantiate a new object of class Vector2 called "winPosition", and set
//      it's x, y value to size.x/2, size.y/2.
// 2) Add Game Logic
//   a) Add code to the while-loop so that when the player reaches
//      "winPosition", which should be determined by using the "is" method, the
//      "state" variable should be set to WIN, ending the game.
//   b) Add code to the while-loop so that the state variable is set to to LOST
//      if the player leaves the play field (ending the game).
// 3) Using enums
//   a) Create an enum called "GameState" with the possible values "RUNNING",
//      "WIN", "LOST", and "USER_QUIT".
//   b) Replace the state variable with an isntance of the GameState enum.

// Stuck? Don't forget to do your reading! If you'd like more educational
// resources, these websites may also be useful:
// http://en.cppreference.com/book/intro/classes
// http://www.cplusplus.com/doc/tutorial/classes/
// http://www.cplusplus.com/doc/tutorial/structures/
// http://en.wikibooks.org/wiki/C++_Programming/Classes

// Achievements: (if you finished, and would like a challenge, try these)
//
// [I Can See!] Turn winPosition into an Entity, which draws an icon on the 
//     game world. Experiment with ASCII values for the goal icon. To see a
//     list of all ASCII values, use the following code:
//         for(int i = 0; i < 256; i++)
//         {
//             cout << "code: " << i << ", char \'" << (char)i << "\'" << endl;
//         }
//         _getch();
// [Nemesis] Create another agent, which can move using the "ijkl" keys, like
//     the current player is moved. If the player and this other agent are in
//     the same location, the game should end in defeat for the player.
// [I Am the Architect] Put the draw code in the main game loop into a function
//     called draw. Put the game logic into a function called update. Put all
//     of the data associated with the game in a new class called Game. Then,
//     put the draw and update functions into the Game class. Your main()
//     function should look something like this:
//         int main()
//         {
//             Game game;
//             do
//             {
//                 game.draw();
//                 game.input = _getch();
//                 game.update();
//             }
//             while(game.state == Game::RUNNING);
//             cout << "press ESCAPE to quit\n";
//             while(_getch() != 27);
//             return 0;
//         }
// [Separation of Concerns] Create new .h files for each of your classes, and
//     #include them at the top. Make separate .cpp files to define functions
//     that are more than a few lines of code.

// When finished:
// 1) Make sure your name is at the top of this source file
// 2) Submit this project online
//   a) Right-click on the .cpp file's name within visual studio, and select
//      "Open Containing Folder"
//   b) Close Visual Studio (you may re-open this .cpp file by right-clicking
//      on it in the file system, and selecting edit)
//   c) Make sure the following files are DELETED from the project's file
//      structure:
//      * Any file with the extension: ".ncb", ".sdf"
//      * Any folder named: "Debug" or "ipch"
//      * If Visual Studio is open, you will not be able to delete some files
//      * If you do not see file extensions, press Alt in the file explorer,
//        select "Tools"->"Folder options..."->"View", and uncheck
//        "Hide extensions for known file types".
//   d) zip the file structure (the project), which is now missing the
//      temporary files
//      * Select all of the files in the project folder
//      * If the resulting zip file is more than 1mb, you have included
//        temporary files mentioned above. Delete temporary files (that don't
//        have a .cpp or .h extension) and try again.
//   e) upload the project to the appropriate week's iLab at the GSP125
//      website, linked from http://www.devryu.net

