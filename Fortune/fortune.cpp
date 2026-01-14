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



	std::string fortunes[30] = {
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
		"Ignore the previous cookie",
		"Yesterday is history, tomorrow is a mystery, but today is a gift. That is why it is called the present",
		"A beginning is the time for taking the most delicate care that the balances are correct",
		"Fear is the mind killer",
		"You are the architect of your own imprisonment",
		//Good Fortunes
		"You will find somthing you once thought was lost to you",
		"An important person will offer you support in your endeavors",
		"A beautiful, smart, and loving person will be coming into your life",
		"Borrow money from a pessimist. They don't expect it back",
		"Soon, you will receive pleasant news",
		//Best Fortunes
		"All your dreams and aspirations will come true in the best way possible",
		"You will see the end of a rainbow and be able to get your gold"
	};

	

	int get_fortune = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));

	std::cout << title << "\n \n";


	
	std::cout << " ";
	for(int i = fortunes[get_fortune].length() + 1; i >= 0; i--){
		std::cout << "_";
	}
	std::cout << " \n";
	std::cout << "{";
	for(int i = fortunes[get_fortune].length() + 1; i >= 0; i--){
		std::cout << " ";
	}
	std::cout << "} \n";
	std::cout << "{ " << fortunes[get_fortune] << " }" << "\n";
	std::cout << "{";
	for(int i = fortunes[get_fortune].length() + 1; i >= 0; i--){
		std::cout << "_";
	}
	std::cout << "} \n \n \n";
	
	return 0;
}
