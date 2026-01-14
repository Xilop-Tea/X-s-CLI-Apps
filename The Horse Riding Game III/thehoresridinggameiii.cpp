#include <iostream>

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
};

int main (){
    srand(time(NULL));
    int money = 1000;

    horse stable[13] = {
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
        horse(6, "Polly Volly")
    };
    horse track[5];

    // Main game loop ADD WHIL LOOP WITH USING MONEY

    //Get the horses that will be racing this game
    for (int i = 0; i < 5; i++){
        horse to_race = stable[rand()%(sizeof(stable) / sizeof(stable[0]))];

        if (to_race.name == track[0].name || to_race.name == track[1].name || to_race.name == track[2].name || to_race.name == track[3].name || to_race.name == track[4].name){
            i --;
        } else {
            track[i] = to_race;
        }
        
    }

    for (int i = 0; i < 5; i++){
        std::cout << i+1 << ". " << track[i].name << "\n";
    }
    
    //Get Winner
    horse winner;

    //Sets how fast the horse ran that race
    for (int i = 0; i < 5; i++){
        track[i].race_speed = (rand() % track[i].speed) + 1;
    }
    //Sets winner based on highest race speed
    for (int i = 0; i < 5; i++){
        if (track[i].race_speed > winner.race_speed){
            winner = track[i];
        }
    }

    for (int i = 0; i < 5; i++){std::cout << track[i].race_speed;}
    std::cout << winner.name;

    
    

    return 0;   
}