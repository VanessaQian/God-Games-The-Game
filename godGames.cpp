//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_BONUS_DMG = 10;

struct characterStats_t {
    int hp;
    int maxHp;
    int baseDmg; // totalDmg = baseDmg + rand() % 11
    int shieldStrength; // If dmg dealt is higher than this, full dmg is dealt
    int currentRoomX;
    int currentRoomY;
    int previousX;
    int previousY;
};

struct conversationParameters_t {
    vector<string> options;
    char correctAnsFirstLetter;
    vector<string> incorrectAnsResponses;
    string correctAnsResponse;
};

struct enhancement_t {
    int maxHpBuff;
    int shieldBuff;
    int dmgBuff;
};

struct room_t {

    int x;
    int y;
    string name;
    string description;
    string type;
    string openingCutscene;
    characterStats_t enemy;
    conversationParameters_t conversation;
    string closingCutscene;
    enhancement_t enhancements;
};

vector<room_t> makeRooms() {
    return {
        {
            .x = 1,
            .y = 0,
            .name = "Hallway",
            .description = "a majestic hallway made with polished white marble and with golden columns.",
            .type = "Empty",
        },
        {
            .x = 0,
            .y = 0,
            .name = "Apollo",
            .description = "a sunlit room with large windows and a lyre on a pedestal.",
            .type = "Conversation",
            .openingCutscene = "Apollo:\n"
                        "   You all know I'm a fan of catchy songs\n"
                        "   So with so many sirens gone, I think Ody's in the wrong\n",
            .conversation = 
            {
                .options = {"You're wrong.\n\n", 
"Why do you even need the sirens?\nThey have never even seen Chiron\nThey are a danger to the sailors\nThey may even hurt your dear musicians.\n\n",
"They were trying to do him worse\nAll he did was reimburse them\nNow they'll tread with caution first\nTo live another day and sing another verse\n"},
                .correctAnsFirstLetter = 't',
                .incorrectAnsResponses = {"Apollo:\n    ODY IS STILL IN WRONG!!", "Apollo:\n    Try again, sis."},
                .correctAnsResponse = "Apollo:\n    If that's true, release him"
            },
            .enhancements = 
            {
                .maxHpBuff = 50,
                .shieldBuff = 0,
                .dmgBuff = 0,
            },
        },
        {
            .x = 2,
            .y = 0,
            .name = "Hephaestus",
            .description = "a rugged and fiery workshop filled with volcanos and fire.",
            .type = "Combat",
            .openingCutscene = "Hephaestus:\n"
                            "    Trust is not given, it's forged\n"
                            "    Why should I give him my support?\n"
                            "    He sacrificed his own cohort\n",
            .enemy = 
            {
                .hp = 100,
                .maxHp = 100,
                .baseDmg = 13,
                .shieldStrength = 25,
                .currentRoomX = 2,
                .currentRoomY = 0,
            },
            .closingCutscene = "Athena (you):\n"
                                "   Did you forget they failed to listen?\n"
                                "   He was betrayed and then imprisoned\n"
                                "   But if you make the right decision\n"
                                "   He can still build a future with those who miss him\n"

                                "Hephaestus:\n"
                                "    Fine, release him.\n",
            .enhancements = 
            {
                .maxHpBuff = 0,
                .shieldBuff = 10,
                .dmgBuff = 0,
            },
        },
        {
            .x = 3,
            .y = 0,
            .name = "Aphrodite",
            .description = "a luxurious bedchamber with soft silk drapes and a sea shell-like bed.",
            .type = "Combat",
            .openingCutscene = "Aphrodite:\n"
                            "    Your little high and mighty Odysseus\n"
                            "    Claims to love his mother\n"
                            "    But let her die of a broken heart\n"

                            "Athena (you):\n"
                            "    He was busy fighting\n"

                            "Aphrodite:\n"
                            "    More like busy spiting the cyclops\n"
                            "    Let him feel the pain that his mother felt and rot\n"

                            "Athena (you):\n"
                            "    Wait, please reconsider this\n"

                            "Ares:\n"
                            "    Really Athena? These old tricks?\n"

                            "Athena (you):\n"
                            "    Ares!\n"

                            "Ares:\n"
                            "    What kind of sick coward\n"
                            "    Holds back his power\n"
                            "    While his friends get devoured?\n"
                            "    He didn't even fight Scylla\n"
                            "    Didn't even try to kill her\n"
                            "    Hides inside a wooden horse to get the job done\n"
                            "    Never handles things upfront\n"
                            "    Pathetic and weak like his son\n",
            .enemy = 
            {
                .hp = 100,
                .maxHp = 100,
                .baseDmg = 27,
                .shieldStrength = 22,
                .currentRoomX = 3,
                .currentRoomY = 0,
            },
            .closingCutscene = "Athena:\n"
                                "   Hold your tongue now\n"
                                "   His son's my friend\n"
                                "   And tell your lover that a broken heart can mend\n"
                                "   You want more bloodshed?\n"
                                "   Then set him free\n"
                                "   To get back to his homestead, he'll make everybody bleed\n"

                                "Aphrodite and Ares:\n"
                                "    Ugh, release him\n",
            .enhancements = 
            {
                .maxHpBuff = 0,
                .shieldBuff = 5,
                .dmgBuff = 10,
            },
        },
        {
            .x = 1,
            .y = 1,
            .name = "Hera",
            .description = "an elegant, open room with towering ivory pillars and peacock-feather motifs.",
            .type = "Conversation",
            .openingCutscene = "Hera:\n"
                            "    Hey baby\n"
                            "    So many heroes\n"
                            "    So many tales\n"
                            "    Give me one good reason why yours should prevail\n",
            .conversation = 
            {
                .options = {"AHe's got the mind of a genius", 
                            "BHe's pretty skilled with words", 
                            "CHe's kind of funny?",
                            "Never once has he cheated on his wife"},
                .correctAnsFirstLetter = 'n',
                .incorrectAnsResponses = {"Hera:\n    Try harder", 
                                          "Hera:\n    You can do better than that", 
                                          "Hera:\n    Eh"},
                .correctAnsResponse = "Hera:\n    Release him."
            },
            .enhancements = 
            {
                .maxHpBuff = 50,
                .shieldBuff = 0,
                .dmgBuff = 0,
            },
        },
        {
            .x = 1,
            .y = 2,
            .name = "Zeus",
            .description = "an open arena resembling that of a colosseum with marble pillars reaching into the storm clouds above.",
            .type = "Boss",
            .openingCutscene = "You dare to defy me?\n"
                                "To make me feel shame?\n"
                                "No one beats me, no one wins my game!\n"
                                "Thunder, bring her through the wringer\n"
                                "Show her I'm the judgement call\n"
                                "The one who makes her kingdom fall!\n",
            .enemy = 
            {
                .hp = 200,
                .maxHp = 200,
                .baseDmg = 30,
                .shieldStrength = 35,
                .currentRoomX = 1,
                .currentRoomY = 2,
            },
            .closingCutscene = "Ares:\n"
                                "   Is she dead?\n"
                                "Athena (you):\n"
                                "   Let him go, please\n"
                                "   Let him go\n",
            .enhancements = 
            {
                .maxHpBuff = 0,
                .shieldBuff = 0,
                .dmgBuff = 0,
            },
        }
    };
}

char getUserInputMenu(const vector<string> &choices) {
    char userResponse;

    // Display menu
    for (string choice: choices){
        cout << "(" << choice.at(0) << ")" << choice.substr(1) << ", ";
    }
    while (true) {
        // Get userResponse
        cin >> userResponse;
        userResponse = tolower(userResponse);
        // Check if valid
        for (string choice : choices) {
            if (tolower(choice.at(0)) == userResponse) {
                cout << endl;
                return userResponse;
            }
        }
        cout << "Invalid input! Please try again\n";
    }
}

string directionOfRoom(const room_t &room1, const room_t &room2) {
    bool isNorth = (room1.x == room2.x) && (room1.y + 1 == room2.y);
    bool isSouth = (room1.x == room2.x) && (room1.y - 1 == room2.y);
    bool isEast = (room1.x + 1 == room2.x) && (room1.y == room2.y);
    bool isWest = (room1.x - 1 == room2.x) && (room1.y == room2.y);

    if (isEast) {
        return "East";
    }
    if (isWest) {
        return "West";
    }
    if (isNorth) {
        return "North";
    }
    if (isSouth) {
        return "South";
    }

    return "";

}

int findRoomNumWithCoordinates(int x, int y, const vector<room_t> &rooms){
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).x == x && rooms.at(i).y == y) {
            return i;
        }
    }

    cout << "We could not find any room with those coordinates :(\n";
    return 0;
}

int changeToNewRoom(room_t currentRoom, const vector<room_t> &rooms, characterStats_t &character) {
    // Change previous room
    character.previousX = character.currentRoomX;
    character.previousY = character.currentRoomY;


    // Change to new room
    cout << "Where do you want to go now?\n";
    vector<string> possibleDirections;
    // Check if room is adjacent
    for (room_t nextRoom: rooms) {
        string direction = directionOfRoom(currentRoom, nextRoom);
        if (direction != "") {
            possibleDirections.push_back(direction);
        }
    }

    char userInput = getUserInputMenu(possibleDirections);
    
    // Change current room of character (using x and y values)
    if (userInput == 'n') {
        character.currentRoomY++;
    }
    if (userInput == 's') {
        character.currentRoomY--;
    }
    if (userInput == 'e') {
        character.currentRoomX++;
    }
    if (userInput == 'w') {
        character.currentRoomX--;
    }

    return findRoomNumWithCoordinates(character.currentRoomX, character.currentRoomY, rooms);
}

int kickToPreviousRoom(characterStats_t &character, const vector<room_t> rooms) {
    character.currentRoomX = character.previousX;
    character.currentRoomY = character.previousY;
    return findRoomNumWithCoordinates(character.currentRoomX, character.currentRoomY, rooms);
}

void playOpeningCutscene() {
    cout << "Welcome to \"God Games\", a game inspired by Jorge Rivera-Herrans' God Games from Epic the Musical.\n\n";
    cout << "The story is as follows:\n";
    cout << "You are Athena, the god of wisdom.\n";
    cout << "Odysseus, a human you support, has been trapped on Calypso's island for 7 years.\n";
    cout << "For more context, search up \"The Odyssey\".\n";
    cout << "Now, into the game we go!\n\n";

    cout << "Athena:\n";
    cout << "   Father, God King \n";
    cout << "   Rarely do I ask for favors\n";
    cout << "   Now, I'm knocking on your door\n";
    cout << "   With hopes to save a friendship with one who's a prisoner far from home\n";
    cout << "   Odysseus.\n";

    cout << "Zeus:\n";
    cout << "   Divine intervention, is that what you seek?\n";
    cout << "   To untie apprehensions that were placed on that Greek?\n";
    cout << "   You are playing with thunder for a man full of shame\n";
    cout << "   But if he's worth the risk of going under, why not make it a game?\n";
    cout << "   Convince each of them that he ought to be released, and I'll release him\n";

    cout << "Athena: \n";
    cout << "   Who's them?\n";

    cout << "Zeus: \n";
    cout << "   Apollo, Hephaestus, Aphrodite, Ares, Hera,\n";
    cout << "   or me\n";
    cout << "   What do you say?\n";

    cout << "Apollo: Great\n";
    cout << "Hephaestus: Very well\n";
    cout << "Aphrodite: Eh\n";
    cout << "Ares: Alright!\n";
    cout << "Hera: Groovy~\n";

    cout << "       Note: you are facing your first choice.\n";
    cout << "       Enter the letter in () to select.\n";
    
    // This choice does not affect anything (therefore no need to keep the value)
    getUserInputMenu({"Bring it."});
}

void openingForRoom(const room_t &room) {
    cout << "You enter " << room.description << endl;
    cout << room.name << "!\n";
}

void printPlayerStats(const characterStats_t &character) {
    cout << "HP: " << character.hp << "/" << character.maxHp << endl;
    cout << "Base DMG: " << character.baseDmg << endl;
    cout << "Shield Strength: " << character.shieldStrength << endl;
}

void addEnhancements(characterStats_t &character, const room_t &room) {
    character.maxHp += room.enhancements.maxHpBuff;
    character.shieldStrength += room.enhancements.shieldBuff;
    character.baseDmg += room.enhancements.dmgBuff;
}

void doEmpty(room_t &room, characterStats_t &character, const vector<string> &approvals) {
    openingForRoom(room);
    printPlayerStats(character);
    cout << "You have the support of " << approvals.size() << " gods." << endl;
    cout << "There is nothing to do here.\n";

}

void doConversation(room_t &room, characterStats_t &character, vector<string> &approvals) {
    openingForRoom(room);
    printPlayerStats(character);
    cout << "You have the support of " << approvals.size() << " gods." << endl;
    cout << room.openingCutscene << endl;
    while (true) {
        cout << "Please select an option:\n";
        char userInput = getUserInputMenu(room.conversation.options);
        if (userInput == room.conversation.correctAnsFirstLetter) {
            cout << room.conversation.correctAnsResponse;
            cout << endl << endl;
            break;
        } else {
            vector<string> incorrectResponses = room.conversation.incorrectAnsResponses;
            cout << incorrectResponses.at(rand()%incorrectResponses.size());
            cout << endl;
        }
    }
    room.type = "Empty";

    // Enhancements
    approvals.push_back(room.name + "'s approval");
    addEnhancements(character, room);
    character.hp = character.maxHp;
}

int calculateDmg(const characterStats_t &perpetrator, const characterStats_t &victim) {
    int totalDmg = perpetrator.baseDmg + rand() % (MAX_BONUS_DMG + 1);
    if (victim.shieldStrength >= totalDmg) {
        cout << "Attack blocked. ";
        return 0;
    } else {
        return totalDmg;
    }
}

void doCombat(room_t &room, characterStats_t &character, vector<room_t> &rooms, vector<string> &approvals) {
    openingForRoom(room);
    printPlayerStats(character);
    cout << "You have the support of " << approvals.size() << " gods." << endl;
    cout << room.openingCutscene << endl;
    cout << "Battle begins.\n";
    cout << "Enemy stats:\n";
    printPlayerStats(room.enemy);

    // Fight happens
    while (true) {
        cout << "It is your turn.\n";
        char characterChoice = getUserInputMenu({"Attack", "Run away"});
        if (characterChoice == 'a') {
            int dmg = calculateDmg(character, room.enemy);
            room.enemy.hp -= dmg;
            cout << "You deal " << dmg << " damage.\n";
        } else if (characterChoice == 'r') {
            int roomNum = kickToPreviousRoom(character, rooms);
            doEmpty(rooms.at(roomNum), character, approvals);
            break;
        }
        cout << "Your turn has ended.\n\n";
        if (room.enemy.hp <= 0) {
            cout << "You defeated your opponent.\n\n";
            room.type = "Empty";
            cout << room.closingCutscene << endl;

            // Enhancements
            approvals.push_back(room.name + "'s approval");
            addEnhancements(character, room);
            break;
        }

        cout << "It is your opponent's turn.\n";
        int enemyDmg = calculateDmg(room.enemy, character);
        character.hp -= enemyDmg;
        cout << "You lost " << enemyDmg << " HP.\n";

        if (character.hp <= 0) {
            cout << "You were defeated.\n";
            cout << "If you want to free Odysseus, please try again.\n";
            cout << "Thank you for playing \"God Games\".\n";
            exit(EXIT_SUCCESS);
        }

        cout << "Your HP: " << character.hp << "/" << character.maxHp << endl;
        cout << "Opponent HP: " << room.enemy.hp << "/" << room.enemy.maxHp << endl;
        
    }
}

void doBoss(room_t &room, characterStats_t &character, vector<room_t> &rooms, vector<string> &approvals) {
    cout << "Congrats! You made it to the goal room!\n";
    cout << "You win!!!!!\n";
    cout << "Wait- Zeus looks angry.\n";
    cout << "Looks like you will have to fight him first...\n";
    cout << "Good luck Athena!\n\n";
    doCombat(room, character, rooms, approvals);
    cout << "Wow you actually survived that!\n";
    cout << "Looks like I'll have to go inform Odysseus that he is free now.\n";
    getUserInputMenu({"Who even are you?"});
    cout << "Oh.\n";
    cout << "Don't worry about that, Athena!\n";
    cout << "Or should I say, player of this game.\n";
    cout << "HAHAHAHHAHAHAHAHAHAHAHA\n";
    cout << "Well, since you entered this room and beat Zeus, I guess you win!\n";
    cout << "Congrats for real this time :D\n";
    cout << "Thank you for playing \"God Games\".\n";
    exit(EXIT_SUCCESS);
}

int main()
{
    srand(time(0));
    // Initiate player character
    characterStats_t player {
        .hp = 150, // Hera will heal you to maxHp
        .maxHp = 150, // Apollo will increase this 
        .baseDmg = 20, // Ares will increase this
        .shieldStrength = 20, // Hephaestus and Aphrodite increases this
        .currentRoomX = 1,
        .currentRoomY = 0,
        .previousX = 1,
        .previousY = 0
    };
    
    vector<room_t> rooms = makeRooms();
    vector<string> approvals;

    playOpeningCutscene();

    int currentRoomNum = 0;


    while (rooms.at(5).type != "Empty") {
        // Make reference to the current room:
        room_t &currentRoom = rooms.at(currentRoomNum);

        // Do the room:
        if (currentRoom.type == "Combat") {
            doCombat(currentRoom, player, rooms, approvals);
        } else if (currentRoom.type == "Conversation") {
            doConversation(currentRoom, player, approvals);
        } else if (currentRoom.type == "Empty") {
            doEmpty(currentRoom, player, approvals);
        } else if (currentRoom.type == "Boss" && approvals.size() == 4) {
            doBoss(currentRoom, player, rooms, approvals);
        } else {
            cout << "Are you sure you want to die at Zeus's hand right now?\n"
                    "Please go visit the other gods first.\n";
        }

        // Check if currentRoomNum is in the same as the players current room
        // Switch players room
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms.at(i).x == player.currentRoomX && rooms.at(i).y == player.currentRoomY) {
                currentRoomNum = changeToNewRoom(rooms.at(i), rooms, player);
                break;
            }
        }

    }

    cout << "Thank you for playing \"God Games\".\n";

    return 0;
}