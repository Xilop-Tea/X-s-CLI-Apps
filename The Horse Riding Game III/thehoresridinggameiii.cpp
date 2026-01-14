#include <iostream>

class horse {
    public:
        int speed;
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

    horse stable[10] = {
        horse(10, "Blue Lightning"),
        horse(2, "Old Chompa"),
        horse(1, "Tilly Two Legs"),
        horse(8, "Big Bullet Bill"),
        horse(6, "Sir Coconuts"),
        horse(5, "Mr Ed"),
        horse(3, "Sleepy Ripply"),
        horse(7, "Green River"),
        horse(9, "Mist Runner"),
        horse(4, "Show Runner")
    };
    horse track[5];

    // Main game loop

    //Get the horses that will be racing this game
    for (int i = 0; i < 5; i++){
        horse to_race = stable[rand()%(sizeof(stable) / sizeof(stable[0]))];

        if (to_race.name == track[0].name || to_race.name == track[1].name || to_race.name == track[2].name || to_race.name == track[3].name || to_race.name == track[4].name){
            i --;
        } else {
            track[i] = to_race;
        }
        
    }

    for (int i = 0; i < 5; i++){std::cout << i+1 << ". " << track[i].name << "\n";}
    
    
    
    

    return 0;   
}