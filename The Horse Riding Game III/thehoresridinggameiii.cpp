#include <iostream>
#include <chrono>
#include <thread>

class horse {
    public:
        int speed;
        int race_speed;
        int payback;
        std::string name;

        horse(){}//Make a default constructor so I can declare empty horse array
        horse(int spd, std::string nm) {
            speed = spd;
            name = nm;
            payback = 12 - speed;
        }

        horse(int spd, std::string nm, int rspd) {
            speed = spd;
            name = nm;
            race_speed = rspd;
        }
};

void thrg3(){
    std::cout << "\nThe Horse Riding Game III\n";
}

void eraseLines(int count) {
    if (count > 0) {
        std::cout << "\x1b[2K"; // Delete current line
        // i=1 because we included the first line
        for (int i = 1; i < count; i++) {
            std::cout
            << "\x1b[1A" // Move cursor up one
            << "\x1b[2K"; // Delete the entire line
        }
        std::cout << "\r"; // Resume the cursor at beginning of line
    }
}

int main (){
    srand(time(NULL));

    std::string title = R"(
                             /$$$$$$$$ /$$                        /$$   /$$                                                         
                            |__  $$__/| $$                       | $$  | $$                                                         
                                | $$   | $$$$$$$   /$$$$$$       | $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$                  
                                | $$   | $$__  $$ /$$__  $$      | $$$$$$$$ /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$                 
                                | $$   | $$  \ $$| $$$$$$$$      | $$__  $$| $$  \ $$| $$  \__/|  $$$$$$ | $$$$$$$$                 
                                | $$   | $$  | $$| $$_____/      | $$  | $$| $$  | $$| $$       \____  $$| $$_____/                 
                                | $$   | $$  | $$|  $$$$$$$      | $$  | $$|  $$$$$$/| $$       /$$$$$$$/|  $$$$$$$                 
                                |__/   |__/  |__/ \_______/      |__/  |__/ \______/ |__/      |_______/  \_______/                 
                                                                                                                                    
                                                                                                                                    
                                                                                                                                    
                        /$$$$$$$  /$$       /$$ /$$                            /$$$$$$                                              
                        | $$__  $$|__/      | $$|__/                           /$$__  $$                                             
                        | $$  \ $$ /$$  /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$            
                        | $$$$$$$/| $$ /$$__  $$| $$| $$__  $$ /$$__  $$      | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$           
                        | $$__  $$| $$| $$  | $$| $$| $$  \ $$| $$  \ $$      | $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$           
                        | $$  \ $$| $$| $$  | $$| $$| $$  | $$| $$  | $$      | $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/           
                        | $$  | $$| $$|  $$$$$$$| $$| $$  | $$|  $$$$$$$      |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$           
                        |__/  |__/|__/ \_______/|__/|__/  |__/ \____  $$       \______/  \_______/|__/ |__/ |__/ \_______/           
                                                            /$$  \ $$                                                             
                                                            |  $$$$$$/                                                             
                                                            \______/                                                              
                                                            /$$$$$$ /$$$$$$ /$$$$$$                                                 
                                                            |_  $$_/|_  $$_/|_  $$_/                                                 
                                                            | $$    | $$    | $$                                                   
                                                            | $$    | $$    | $$                                                   
                                                            | $$    | $$    | $$                                                   
                                                            | $$    | $$    | $$                                                   
                                                            /$$$$$$ /$$$$$$ /$$$$$$                                                 
                                                            |______/|______/|______/            
    )";
    std::string race_f1 = R"(
         ,
        /,`\
        ` | \____\\
        _(      ) \
        \-\~~~_|\  \
            \ `   \  `
        `     `
        CLOMP*
    )";

    std::string race_f2 = R"(
        ((^--__
        | /\  --___ __
            (  /  \  ) \\
            / |~~~~/  \  \\
          /    \ /      \


        CLOMP* CLOMP*
    )";

    std::string race_f3 = R"(
            ,~~_
            |/\ =_ _ ~
            _( )_( )\~~
            \,\  _|\ \~~~
                \`   \
                `    `

        CLOMP* CLOMP* CLOMP*
    )";

    int score = 0;
    int money = 1000;

    horse stable[14] = {
        horse(10, "Blue Lightning"),
        horse(2, "Old Chompa"),
        horse(1, "Tilly Two Legs"),
        horse(8, "Big Bullet Bill"),
        horse(6, "Sir Coconuts"),
        horse(5, "Mr Ed"),
        horse(3, "Sleepy Ripply"),
        horse(7, "Green River"),
        horse(9, "Mist Runner"),
        horse(4, "Show Runner"),
        horse(5, "Jelly"),
        horse(4, "Mylyn the Posh and Clean"),
        horse(6, "Polly Volly"),
        horse(5, "Baby Trotter")
    };
    horse track[5];

    std::cout << title << "\n";

    // Main game loop ADD WHIL LOOP WITH USING MONEY
    while (money > 0) {
        std::cout << "\nYour current balance is: $" << money << "\n";
        //Get the horses that will be racing this game
        for (int i = 0; i < 5; i++){
            horse to_race = stable[rand()%(sizeof(stable) / sizeof(stable[0]))];

            if (to_race.name == track[0].name || to_race.name == track[1].name || to_race.name == track[2].name || to_race.name == track[3].name || to_race.name == track[4].name){
                i --;
            } else {
                track[i] = to_race;
            }   
        }
        std::cout << "This race has these horses racing: \n";
        for (int i = 0; i < 5; i++){
            std::cout << i+1 << ". " << track[i].name << "\n";
        }
        thrg3();

        //Get the bet
        horse bet_horse;
        int bet_num;
        int bet;
        do {
            std::cout << "Who do you want to bet on? --> ";
            std::cin >> bet_num;
        } while (bet_num > 5);
        bet_horse = track[bet_num - 1];
        do {
            std::cout << "How much money do you want to bet? --> ";
            std::cin >> bet;
        } while (bet > money);
        
        //Get Winner
        horse winner;
        //Sets how fast the horse ran that race (race_speed)
        for (int i = 0; i < 5; i++){
            track[i].race_speed = (rand() % track[i].speed) + 1;
        }
        horse deadHorse(0, "Dead", 0);
        winner = deadHorse; // To have a default horse that can not winn as default was winning some times;
        //Sets winner based on highest race_speed
        for (int i = 0; i < 5; i++){
            if (track[i].race_speed > winner.race_speed){
                winner = track[i];
            }
        }

        // Draw the Race
        std::cout << race_f1 << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        eraseLines(9);
        std::cout << race_f2 << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        eraseLines(9);
        std::cout << race_f3 << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));



        std::cout << "\n\nThe winner is " << winner.name << "\n";
        
        //Get or lose money based on results
        if (bet_horse.name == winner.name) {
            std::cout << "Congrats you win";
            thrg3();
            money += bet * winner.payback;
            score += (bet * winner.payback) * 10;
        } else {
            std::cout << "Better luck next time boyo";
            thrg3();
            money -= bet;
        } 

        score += bet * 10;
    }

    std::cout << "Looks like you are out of money \nTime to hit the streets boyo";
    thrg3();
    std::cout << "\n\n Your score was: " << score;
    thrg3();

    return 0;   
}