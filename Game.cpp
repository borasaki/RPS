// rock, paper, scissors but advanced where each move has a special effect, suich as the next next move, if successful, does more dmg
// For each clash that happens, it powers up the next move to hit, stacks nearly indefinitely
// https://wokwi.com/projects/362262893783791617
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
// 'Select', 128x20px
const unsigned char Bubble [] PROGMEM = {
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0
};

// 'Sword', 8x8px
const unsigned char Icon_Sword [] PROGMEM = {
	0x03, 0x05, 0x0a, 0x54, 0x28, 0x30, 0x48, 0x80
};
// 'Hat', 8x8px
const unsigned char Icon_Hat [] PROGMEM = {
	0x00, 0x02, 0x0c, 0x1c, 0x3e, 0xff, 0x00, 0x00
};
// 'Key', 8x8px
const unsigned char Icon_Key [] PROGMEM = {
	0x18, 0x24, 0x24, 0x18, 0x10, 0x18, 0x10, 0x1c
};
// 'Rock', 8x8px
const unsigned char Icon_Rock [] PROGMEM = {
	0x0c, 0x32, 0x25, 0x55, 0x89, 0x91, 0x52, 0x7c
};
// 'Paper', 8x8px
const unsigned char Icon_Paper [] PROGMEM = {
	0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7f, 0x1e, 0x0c
};
// 'Scissors', 8x8px
const unsigned char Icon_Scissors [] PROGMEM = {
	0x10, 0x28, 0x10, 0x12, 0xfd, 0x12, 0x10, 0x10
};
// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 192)
const int iconLen = 6;
const unsigned char* bitmapIcons[6] = {
    Icon_Sword,
	Icon_Hat,
	Icon_Key,
    Icon_Rock,
	Icon_Paper,
	Icon_Scissors,
};

// Area icon bitmaps ////////////////////////////////////////

// 'Caves', 16x16px
const unsigned char Caves [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x02, 0x10, 
	0x02, 0x08, 0x04, 0xc8, 0x09, 0x28, 0x0a, 0x28, 0x0a, 0x24, 0x12, 0x14, 0x34, 0x94, 0x25, 0x52
};
// 'Grand Forest', 16x16px
const unsigned char Grand_Forest [] PROGMEM = {
	0x31, 0x07, 0x3e, 0x19, 0x30, 0xcd, 0xb1, 0x87, 0x7f, 0x03, 0x3c, 0x01, 0x30, 0x01, 0x30, 0x01, 
	0x30, 0x71, 0x70, 0x0f, 0xb0, 0x01, 0x30, 0x01, 0x30, 0x09, 0x30, 0x09, 0x32, 0x3d, 0x33, 0x7d
};
// 'Ruins', 16x16px
const unsigned char Ruins [] PROGMEM = {
	0x00, 0x3b, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x31, 0x00, 0x3b, 0x00, 0x00, 
	0x00, 0x4e, 0x02, 0xee, 0x03, 0x00, 0x03, 0xb3, 0x01, 0xbb, 0x00, 0x00, 0x86, 0x46, 0xce, 0xec
};
// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 144)
const int areasLEN = 3;
const unsigned char* areaIcons[3] = {
	Caves,
	Grand_Forest,
	Ruins
};

// Numerous enums for many different possible states of anything within this game, for me this makes sense  
enum State {
            Start, // Implemented
            Scoreboard, // Not implemented
            JobSelect, // Implemented
            Job, // Player can select a job, not that it does anything yet
            Continue,
            Village, // Not Implemented, Do I want this?
            Venture, // Not Implemented
            Walpurgis, // Final boss, Not Implemented, may not use, may just be included in Venture
            Combat
            };

enum Type {
          Rock,
          Paper,
          Scissors
          };

enum Status {
            Null,
            Broken,
            Stunned
            };

enum Item {
          hpot
          };

enum Hobo {
         Fighter = 0, // More health, rock more effective on neutral
         Mage = 1, // Move prediction probability, Paper more effective on neutral
         Thief = 2, // Effective moves to more damage, scissors more effective on neutral
         Trainee = 3
        };

enum XP {
        starter = 0,
        rookie = 3,
        regular = 12,
        experienced = 32,
        veteran = 54,
        fill
        };

enum Turn {
            pre,
            select,
            first,
            second,
            post
            };

class Action {
    public:

        Type type;
        byte value;

    Action (Type type, byte value) {
        type = type;
        value = value;
    }
};

class Entity {
    public:

        byte hp;
        Status status;

        Entity(byte hp, Status status = Null) {
            hp = hp;
            status = status;
        }

        void dmgd(byte dmg) {
                hp -= dmg;
            }
};

class Player : public Entity {
    public:

        Hobo job;
        char* icon;
        byte xpTotal;
        XP rank;
        byte inv[4] = {0, 0, 0, 0};

        Player(Hobo job = 3, char* icon = 0, byte xpTotal = 0, XP rank = starter, byte hp = 0, Status status = Null) : Entity(hp, status) {
            job = job;
            icon = icon;
            xpTotal = xpTotal;
            rank = rank;
        }

        XP getRank() {
            return rank;
        }

        levelup(byte xpYield) {
            xpTotal += xpYield;
            for (int i =  rookie; i != fill; i++) {
                if (xpTotal >= i) {
                    rank = i;
                }
            }
        }
};

class Mob : public Entity {
    public:

        byte xpYield;
        Type weak;

        Mob(byte xpYield, byte hp, Type weak, Status status = Null) : Entity(hp, status) {
            xpYield = xpYield;
            weak = weak;
        }

        byte getXP() {
            return xpYield;
        }
};

class Boss : public Entity {
    public:

        Type weak;
        
        Boss(byte hp, Type weak, Status status = Null) : Entity(hp, status){
            weak = weak;
        }
};

// Early monsters ///////////////////////////////////////////

Mob Slime(1,3,Paper);
Mob Rat(1,2,Scissors);
Mob Cockroach(1,4,Rock);
Mob Bunicorn(3,2,Rock);
Mob early[] = {
            Slime,
            Rat,
            Bunicorn
            };

// Mid monsters /////////////////////////////////////////////

Mob Goblin(3,7,Rock);
Mob Kobold(3,6,Paper);
Mob Wolf(4,6,Scissors);
Mob Harpy(6,8,Rock);
Mob mid[] = {
            Goblin,
            Kobold,
            Wolf,
            Harpy
            };

// Late monsters ////////////////////////////////////////////

Mob Orc(6,15,Scissors);
Mob Elder_Kobold(6,12,Scissors);
Mob Skeleton(4,10,Rock);
Mob Zombie(5,15,Paper);
Mob Bear(8,18,Scissors);
Mob late[] = {
             Orc,
             Elder_Kobold,
             Skeleton,
             Zombie,
             Bear
             };

// Bosses ///////////////////////////////////////////////////

Boss Death_Spots(10,Scissors);
Boss Zoran_Zesshu(20,Rock);
Boss Lich(12,Rock);
Boss Gan_Ceann(20,Paper);
Boss Dragon(30,Scissors);
Boss Demon_Lord(15,Paper);
Boss final[] = {
                Death_Spots,
                Zoran_Zesshu,
                Lich,
                Gan_Ceann,
                Dragon,
                Demon_Lord              
                };

// Interactive Logistics ////////////////////////////////////

// Button Pins
#define Rocker 12
#define Paperer 8 
#define Scissorer 4 

// One input per button press, holding doesn't do anything
int rocklick = 0;
int paplick = 0;
int scisslick = 0;

// pin and state pairing from variables set above
int buttpinclick[3][2] = {
                         {Rocker, rocklick},
                         {Paperer, paplick},
                         {Scissorer, scisslick}
                         };

State state = Start; // Game state for state machine, starts in the Play Menu

Player player;  // Instantiate the player instance

void setup() {

    pinMode(Rocker, INPUT_PULLUP);
    pinMode(Paperer, INPUT_PULLUP);
    pinMode(Scissorer, INPUT_PULLUP);

// Setting display font and color on oled screen
    u8g.setFont(u8g_font_7x14Br);
    u8g.setColorIndex(1);
}

void loop() {

// UI display Logic via state machine
    u8g.firstPage();
            do{
        switch(state) {
            case Start: // Starting Screen
                u8g.drawStr(50,28,"Play");
                u8g.drawStr(30,54,"Scoreboard");
                break;
            case Scoreboard: // Scoreboard of Players, not implemented
                 u8g.drawStr(20,20,"Scoreboard");
                 break;
            case JobSelect: //Display Class options
                u8g.drawStr(41,14,"Fighter");
                u8g.drawStr(50,36,"Mage");
                u8g.drawStr(46,58,"Thief");
                break;
            // case Job: //Set player values and display elements
            //     switch(player.job) {
            //         case Fighter:
            //             player.hp = 5;
            //             u8g.drawStr(41,14,"Fighter");
            //             u8g.drawBitmapP(0,0,128/8,20, Bubble);
            //             u8g.drawBitmapP(26,5,8/8,8, Icon_Sword);
            //             u8g.drawBitmapP(94,5,8/8,8, Icon_Rock);
            //             select = 1;
            //             break;
            //         case Mage:
            //             player.hp = 3;
            //             u8g.drawStr(50,36,"Mage");
            //             u8g.drawBitmapP(0,22,128/8,20, Bubble);
            //             u8g.drawBitmapP(35,27,8/8,8, Icon_Hat);
            //             u8g.drawBitmapP(83,27,8/8,8, Icon_Paper);
            //             select = 1;
            //             break;
            //         case Thief:
            //             player.hp = 3;
            //             u8g.drawStr(46,58,"Thief");
            //             u8g.drawBitmapP(0,44,128/8,20, Bubble);
            //             u8g.drawBitmapP(34,49,8/8,8, Icon_Key);
            //             u8g.drawBitmapP(85,49,8/8,8, Icon_Scissors);
            //             select = 1;
            //             break;
            //     }
            //     break;
            // case Village: // Maybe?
            //     break;
            case Continue:
                u8g.drawStr(16,14,"Start Journey?");
                u8g.drawStr(52,36,"Yes");
                u8g.drawStr(56,58,"No");
                u8g.drawBitmapP(20,20,8/8,8, player.icon);
                break;
            case Venture:
                u8g.drawStr(20,20,"Venture");
                u8g.drawBitmapP(20,32,16/8,16, Caves);
                u8g.drawBitmapP(54,32,16/8,16, Grand_Forest);
                u8g.drawBitmapP(88,32,16/8,16, Ruins);

                break;
            case Combat:
                u8g.drawStr(0,0,"Combat");
                break;
        }
    } while (u8g.nextPage());

// Controls per state, again via state machine
// I wonder, would is it better the way I have it, as in the state machine looks for the game scene it is in and denotes button press meanings: looking at game state > button press > scene controls
// or is it better to have the system detect button presses first, and denote controls from: button press > looking at game state > scene
    switch(state) {
        case Start:
            startConfig();
            break;
        case JobSelect:
            jobselectConfig();
            break;
        case Continue:
            continueConfig();
            break;
        case Village:
            break;
        case Venture:
            break;
        case Combat:
            break;

    }

}

// Control Configs //////////////////////////////////////////////////////////

void startConfig() {
    for (int i = 0; i < (sizeof(buttpinclick)/sizeof(buttpinclick[0])); i++) {
        if ((digitalRead(buttpinclick[i][0]) == LOW) && (buttpinclick[i][1] == 0) && (i != 2))  {
            state = JobSelect;
            buttpinclick[i][1] = 1;
        }
        else if ((digitalRead(buttpinclick[i][0]) == LOW) && (buttpinclick[i][1] == 0)) {
            state = Scoreboard;
            buttpinclick[i][1] = 1;
        }
        if ((digitalRead(buttpinclick[i][0]) == HIGH) && (buttpinclick[i][1] == 1)) {
            buttpinclick[i][1] = 0;
        }
    }
}
void jobselectConfig () {
    for (int i = 0; i < sizeof(buttpinclick)/sizeof(buttpinclick[0]); i++) {
        if ((digitalRead(buttpinclick[i][0]) == LOW) && (buttpinclick[i][1] == 0)) {
                player.job = i;
                player.icon = bitmapIcons[i];
                state = Continue;
                buttpinclick[i][1] = 1;
            }
        if ((digitalRead(buttpinclick[i][0]) == HIGH) && (buttpinclick[i][1] == 1)) {
            buttpinclick[i][1] = 0;
        }
    }
}
void continueConfig () {
    for (int i = 0; i < (sizeof(buttpinclick)/sizeof(buttpinclick[0])); i++) {
        if ((digitalRead(buttpinclick[i][0]) == LOW) && (buttpinclick[i][1] == 0) && (i != 2))  {
            // state = Village;
            state = Venture;
            buttpinclick[i][1] = 1;
        }
        else if ((digitalRead(buttpinclick[i][0]) == LOW) && (buttpinclick[i][1] == 0)) {
            state = JobSelect;
            buttpinclick[i][1] = 1;
        }
        if ((digitalRead(buttpinclick[i][0]) == HIGH) && (buttpinclick[i][1] == 1)) {
            buttpinclick[i][1] = 0;
        }
    }
}

Entity venture(Player player) { // Pre-generated mob encounter route for the player based on experience value
    switch(player.getRank()) {
        case starter:
            spawn(early);
            break;
        case rookie:
            spawn(mid);
            break;
        case regular:
            spawn(mid);
            break;
        case experienced:
            spawn(late);
            break;
        case veteran:
            spawn(final);
            break;
    }
}

Entity spawn(Entity mobs[]) { // Randomly select mob from passed mob pool based on player experience, ideally weighted chances, for switch case above
    int numMobs = sizeof(mobs) / sizeof(Entity);
    int pool = numMobs + 1;
    Entity mob = mobs[random(pool)];
    return mob;
}

// Miscellaneous methods ////////////////////////////////////////////////

void level(Mob mob) { // Get mob instance and add its xp to player
    player.levelup(mob.getXP());
}

void transferDmg(Entity Attacker, Entity Target) { // Grab entity dmg values and call entity dmg method (each entity can take damage), doesn't make sense to put this particular one in the entity class

}