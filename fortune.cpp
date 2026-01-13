#include <iostream>


int main() {
	srand(time(NULL));

	std::string title = R"( ____               __                              
/\  _`\            /\ \__                           
\ \ \L\_\___   _ __\ \ ,_\  __  __    ___      __   
 \ \  _\/ __`\/\`'__\ \ \/ /\ \/\ \ /' _ `\  /'__`\ 
  \ \ \/\ \L\ \ \ \/ \ \ \_\ \ \_\ \/\ \/\ \/\  __/ 
   \ \_\ \____/\ \_\  \ \__\\ \____/\ \_\ \_\ \____\
    \/_/\/___/  \/_/   \/__/ \/___/  \/_/\/_/\/____/)";



	std::string fortunes[] = {
		//Worst Fortunes
		"You will have 10 years bad luck, I saw that mirror you smashed",
		"You will be cursed to use bing as your seach engine for the rest of your life",
		//Bad Fortunes
		"You will step in a muddy puddle and ruin your trousers",
		"You will get a cough that will last, like a whole week",
		"Next peice of code you write will get a compile error that you just can not solve",
		"Your anime waifu will never love you",
		"You will be asked for jury duty, you will not be able to get out of it",
		"Your phone battery will die at the exact moment you need it most",
		//Mid Fortunes
		"You will meet a mysterious stranger",
		"You will explore a new place",
		"The fortune you seek is in another cookie",
		"You are cleverly disguised as a responsible adult",
		"Accept something that you cannot change, you will feel better",
		"A foolish man listens to his heart. A wise man listens to cookies",
		"You will read this fortune cookie message twice to make sure it makes sense",
		"The early bird gets the worm, but the second mouse gets the cheese",
		"An alien of some sort will be appearing to you shortly",
		"When marriage outlawed, only outlaws have in-laws",
		//Good Fortunes
		"You will find somthing you once thought was lost to you",
		"An important person will offer you support in your endeavors",
		"A beautiful, smart, and loving person will be coming into your life",
		//Best Fortunes
		"All your dreams and aspirations will come true in the best way possible"
	};

	int get_fortune = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));

	std::cout << title << "\n \n";
	std::cout << fortunes[get_fortune] << "\n";

	
	return 0;
}
