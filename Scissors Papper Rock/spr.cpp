#include <iostream>
#include <chrono>
#include <thread>

int getUserChoice(){
    int user_input;

    do {
        std::cout << "1. Scissors   2. Paper   3. Rock \nWhat is your choice? --> ";
        std::cin >> user_input;
    } while (user_input < 0 || user_input > 3);

    return user_input;
}

int getComChoice(){
    srand(time(NULL));
    return rand() % 3 + 1;
}

void suspWait(){
    for (int i = 0; i < 3; i ++) {
        std::cout << "." << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}



int main(){
    std::string title = R"(
   _____      _                                                      
  / ___/_____(_)_____________  __________                            
  \__ \/ ___/ / ___/ ___/ __ \/ ___/ ___/                            
 ___/ / /__/ (__  |__  ) /_/ / /  (__  )                             
/____/\___/_/____/____/\____/_/  /____/                              
         / __ \____ _____  ___  _____                               
        / /_/ / __ `/ __ \/ _ \/ ___/                               
       / ____/ /_/ / /_/ /  __/ /                                   
      /_/    \__,_/ .___/\___/_/                                    
                 /_/_             __                                
                / __ \____  _____/ /__                              
               / /_/ / __ \/ ___/ //_/                              
              / _, _/ /_/ / /__/ ,<                                 
             /_/ |_|\____/\___/_/|_|                                
    )";

    std::cout << title << "\n \n";
    std::string scissors = R"(
        ______
    ---'   ___)______
              ________)
             (________
             _________)
            (___)
    ---.____(__)
    )";
;
    std::string papper = R"(
        _______
    ---'   ____)____
              ______)
              _______)
             _______)
    ---.__________))";
    std::string rock = R"(
        _______
    ---'   ____)
          (_____)
          (_____)
          (____)
    ---.__(___)
    )";
    int com_choice = getComChoice();
    std::string com_type;
    switch (com_choice){
        case 1: com_type = scissors;
        break;
        case 2: com_type = papper;
        break;
        case 3: com_type = rock;    
    }

    int user_choice = getUserChoice();
    std::string user_type;
    switch (user_choice){
        case 1: user_type = scissors;
        break;
        case 2: user_type = papper;
        break;
        case 3: user_type = rock;    
    }

    std::cout << "You picked \n" << user_type;
    std::cout << "\n\nThe The Computer picks";
    suspWait();
    std::cout << "\n" << com_type;
    
    if (user_choice != com_choice){
        //WIN
        if (user_choice == 1 && com_choice == 2 || user_choice == 2 && com_choice == 3 || user_choice == 3 && com_choice == 1){
            std::cout << "\n\nYOU WIN, YAY \n YAY \n";
        } else {  //LOOSE
            std::cout << "\n\nYOU LOOSE, What a LOOSER \n";
        }

    } else {
        std::cout << "\n\nThats a tie \n";
    }  
    return 0;
}