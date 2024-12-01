#include <iostream>
#include "TowerDefenseGame.hpp"

//constructor
	TowerDefenseGame::TowerDefenseGame() {// -> start default and add thru setters?
        this->mMasterList = new std::list<Entity*>();
        this->mGameWindow = new sf::RenderWindow(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            "Tower Defense!!"
            );
        this->spawner = new SpriteManager();

        //figure out how many Players/NPCs
        this->setupGame();
    }

    //setup game
	void TowerDefenseGame::setupGame() {
        bool setupComplete = false;
        int choice = -1;

        this->printMultiplayerMenu();
        std::cin >> choice;
        if (choice == 1) {//local game, 3 NPC
            this->mPlayer1 = new Player(1, 30, this->spawner->getMushroomTower());
            this->mPlayer2 = new NPC(2, this->spawner->getMushroomTower(), easy);
            this->mPlayer3 = new NPC(3, this->spawner->getMushroomTower(), easy);
            this->mPlayer4 = new NPC(4, this->spawner->getMushroomTower(), easy);
        }
        while (setupComplete != true) {
            setupComplete = true;// place holder
        }
    }

	//destructor
	TowerDefenseGame::~TowerDefenseGame() {
        delete this->mPlayer1;
        delete this->mPlayer2;
        delete this->mPlayer3;
        delete this->mPlayer4;
        delete this->mMasterList;
        delete this->mGameWindow;
    }

	//getters
	Player* TowerDefenseGame::getPlayer(const int& playerID) const {
        Player* result = nullptr;
        switch (playerID) {
            case 1:
                result = this->mPlayer1;
                break;
            case 2:
                result = this->mPlayer2;
                break;
            case 3:
                result = this->mPlayer3;
                break;
            case 4:
                result = this->mPlayer4;
                break;
            default:
                // :D broke
                break;
        }

        return result; // Gavin I had to add this sorry if it ruins your day - Ingrid
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


        /* ***MAIN GAME LOOP START!!*** */

        // loop while game window is open and game is still running
        while (this->mGameWindow->isOpen() && this->GameComplete() == false) {
            
            //read in action, see if it will close window!
            while (this->mGameWindow->pollEvent(event)) {

                if(event.type == sf::Event::Closed) { this->mGameWindow->close(); }

                if (event.type == sf::Event::TextEntered)
                {
                    processInput();
                }

            }
            
            //check for changes to word choices:
            //can this also take care of word visuals?
            //this->updateWords();

            //read player input will modify list if word is complete:
            //this->processInput();

            //step shape positions, checks for intersections and draws all
            //this->updateEntities();

            
            //is it worth scanning for player input while we wait out clock?
            // -> leaving wait loop empty for now, letting Ingrid/Arni make the call

            while (clock() < next) { ; }// -> do nothing until we hit frame rate

            now = clock();// -> clock end of loop
            next = now + (CLOCKS_PER_SEC / MAX_FPS);// -> get clock for next loop end
        }
        
        ///* ***MAIN GAME LOOP END!!*** */

        //clean up before returning to main:

        //so far nothing dynamic to clean up!


        

    }

	void TowerDefenseGame::processInput() {// -> for handling keyboard event process!

        mPlayer1->updateInput();
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
        this->mPlayer1->getHP() < 0
        &&
        this->mPlayer2->getHP() < 0
        ) 
        { done = true; }

        return done;
    }
    
    string* getWordChoices()
    {
        int randomNumber = (std::rand() % (sizeof(wordPool) / sizeof(wordPool[0])));
        string wordChoicesArr[3];
        for (int i = 0; i < 3; i++)
        {
            wordChoicesArr[i] = wordPool[randomNumber];
        }

        return wordChoicesArr;
    }

    

    //private helpers
	void TowerDefenseGame::printMultiplayerMenu() const {// for join/create game
        std::cout
            << "1. Local Game " << std::endl
            << "2. Multiplayer Game " << std::endl
            << "Please enter choice: ";
    }

