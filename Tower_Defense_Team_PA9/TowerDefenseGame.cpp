
#include <SFML/Graphics.hpp>

#include "TowerDefenseGame.hpp"
#include "NPC.hpp"

//constructor
	TowerDefenseGame::TowerDefenseGame() {// -> start default and add thru setters?
        this->mPlayers = nullptr;//new Player[4];
        this->mHostPlayer = &(this->mPlayers[0]); //points at first player
        this->mMasterList = new std::list<Entity*>();
        this->mGameWindow = new sf::RenderWindow(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "Tower Defense!!"
            );
    }

	//destructor
	TowerDefenseGame::~TowerDefenseGame() {
        delete this->mPlayers;
        delete this->mMasterList;
        delete this->mGameWindow;
    }

	//getters
	Player* TowerDefenseGame::getPlayer(const int& playerID) const {
        return &(this->mPlayers[playerID]);//return a ptr!
    }
	Player* TowerDefenseGame::getHostPlayer() const {
        return this->mHostPlayer;
    }

	//setters

	//input player and their ID (player1, player2, player3, player4)
	//void TowerDefenseGame::setPlayer(const int& playerID, const Player*& player) {
    //    this->(mPlayers + playerID - 1);//return a ptr with ptr arithmetic >:)
    //}


	//public

    //start the game!
    void TowerDefenseGame::run() {
        // hard code 1 player - 3 NPC for now revisit if time
        //dynamic_cast<NPC*>(->mPlayers[1]);
        //dynamic_cast<NPC*>(->mPlayers[2]);
        //dynamic_cast<NPC*>(->mPlayers[3]);

        //set up any other initializing code here!!!
        sf::Event event;

        // starting time
        clock_t now = clock();

        // # of clocks until 1/60 sec has passed since now
        clock_t next = now + (CLOCKS_PER_SEC / MAX_FPS);


        /* ***MAIN GAME LOOP!!*** */

        // loop while game window is open and game is still running
        while (this->mGameWindow->isOpen() && this->GameComplete() == false) {
            
            //read in action, see if it will close window!
            while (this->mGameWindow->pollEvent(event)) {
                if(event.type == sf::Event::Closed) { this->mGameWindow->close(); }
            }

            //check for changes to word choices:
            //can this also take care of word visuals?
            this->updateWords();

            //read player input will modify list if word is complete:
            this->processInput();

            //step shape positions, checks for intersections and draws all
            this->updateEntities();

            //is it worth scanning for player input while we wait out clock?
            // -> leaving wait loop empty for now, letting Ingrid/Arni make the call

            while (clock() < next) {;}// -> do nothing until we hit frame rate

            now = clock();// -> clock end of loop
            next = now + (CLOCKS_PER_SEC / MAX_FPS);// -> get time for next loop end
        }

        //clean up before returning to main:

        //so far nothing dynamic to clean up!

    }

	void TowerDefenseGame::processInput() {// -> for handling keyboard event process!

    }

	void TowerDefenseGame::updateWords() {// -> for handling word and bonus options!

    }

	// takes bonus enum and adds bonus entity(s) to master list
	void TowerDefenseGame::mapBonus(enum Bonus& bonus) {
        Entity* pNew = nullptr;

        switch (bonus) {
            case spawn1:// -> insert one gnome at back!
                //pNew = new Entity(1, sf::CircleShape(5.f));
                if (pNew != nullptr) {
                    this->mMasterList->push_back(pNew);
                }
                break;
            case spawn5:// -> make 5 gnomes and insert at back of list
                for(int i = 0; i < 5; i++) {
                    //pNew = new Entity(1, sf::CircleShape(5.f));
                    this->mMasterList->push_back(pNew);
                }
                break;
            case spawnBigGnome:// -> add one big gnome!
                //pNew = new Entity(5, sf::CircleShape(10.f));
                this->mMasterList->push_back(pNew);
                break;
            default:
                std::cout << "how did you do this??" << std::endl;
        }
    }

	//updates shape positions, checks for intersections, and then draws all!
	void TowerDefenseGame::updateEntities() {

        //iterator???? :D
        //while (this->mMasterList->)
    }

    //checks game conditions for if they are over
	bool TowerDefenseGame::GameComplete() const {
        bool done = false;

        if (
        this->mPlayers->getHP() < 0
        &&
        this->mPlayers[1]->getHP() < 0
        ) 
        { done = true; }

        return done;
    }

    //private helpers
	void TowerDefenseGame::printMultiplayerMenu() const {// for join/create game
        std::cout
            << "1. Local Game " << std::endl
            << "2. Multiplayer Game " << std::endl;
    }