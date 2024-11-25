
#include <SFML/Graphics.hpp>

#include "TowerDefenseGame.hpp"
#include "NPC.hpp"

//constructor
	TowerDefenseGame() {// -> start default and add thru setters?
        this->mPlayers = new Player*[4];
        this->mHostPlayer = this->mPlayers[0]; //points at first player
        this->mMasterList = new std::List<Entity*>();
        this->mGameWindow = new sf::RenderWindow(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "Tower Defense!!"
            );
    }

	//destructor
	~TowerDefenseGame() {
        delete this->mPlayers;
        delete this->mMasterList;
        delete this->mGameWindow;
    }

	//getters
	Player* getPlayer(const int& playerID) const {
        return this->mPlayers[playerID];
    }
	Player* getHostPlayer() const {
        return this->mHostPlayer;
    }

	//setters

	//input player and their ID (player1, player2, player3, player4)
	void setPlayer(const int& playerID, const Player*& player) {
        this->mPlayers[playerID] = player;
    }


	//public

    //start the game!
    void run() {
        // hard code 1 player - 3 NPC for now revisit if time
        dynamic_cast<NPC*>(->mPlayers[1]);
        dynamic_cast<NPC*>(->mPlayers[2]);
        dynamic_cast<NPC*>(->mPlayers[3]);

        //set up any other initializing code here!!!
        sf::Event event;

        //consider adding || here for the game over condition!
        while (this->mGameWindow.isOpen()) {// check for window close
            
            //read in action, see if it will close window!
            while (this->mGameWindow.pollEvent(event)) {
                if(event.type == sf::Event::Closed) { this->mGameWindow.close(); }
            }

            //check for changes to word choices:
            this->updateWords();

            //read player input will modify list if word is complete:
            this->processInput();

            //step shape positions, checks for intersections and draws all
            this->updateEntities();
        }

    }

	void processInput() {// -> for handling keyboard event process!

    }

	void updateWords() {// -> for handling word and bonus options!

    }

	// takes bonus enum and adds bonus entity(s) to master list
	void mapBonus(enum Bonus& bonus) {
        Entity* pNew = nullptr;

        switch (bonus) {
            case spawn1:// -> insert one gnome at back!
                pNew = new Entity(1, sf::CircleShape(5.f));
                if (pNew != nullptr) {
                    this->mMasterList.push_back(pNew);
                }
                break;
            case spawn5:// -> make 5 gnomes and insert at back of list
                for(int i = 0; i < 5; i++) {
                    pNew = new Entity(1, sf::CircleShape(5.f));
                    this->mMasterList.push_back(pNew);
                }
                break;
            case spawnBigGnome:// -> add one big gnome!
                pNew = new Entity(5, sf::CircleShape(10.f));
                this->mMasterList.push_back(pNew);
                break;
            default:
                std::cout << "how did you do this??" << std::endl;
        }
    }

	//updates shape positions, checks for intersections, and then draws all!
	void updateEntities();

    //private helpers
	void printMultiplayerMenu() const {// for join/create game
        std::cout
            << "1. Local Game " << std::endl
            << "2. Multiplayer Game " << std::endl;
    }