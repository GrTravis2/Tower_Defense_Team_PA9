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
    choice = 1;
    std::cin >> choice;
    if (choice == 1) {//local game, 3 NPC

        this->mPlayer1 = new Player(1, 30, this->spawner->getMushroomTower());
        this->mPlayer1->mBody.setPosition(sf::Vector2f(P1_X, P1_Y));

        this->mPlayer2 = new NPC(2, this->spawner->getMushroomTower(), easy);
        this->mPlayer2->mBody.setPosition(sf::Vector2f(WINDOW_WIDTH + P2_X, P2_Y));

        this->mPlayer3 = new NPC(3, this->spawner->getMushroomTower(), easy);
        this->mPlayer3->mBody.setPosition(sf::Vector2f(P3_X,WINDOW_HEIGHT + P3_Y));

        this->mPlayer4 = new NPC(4, this->spawner->getMushroomTower(), easy);
        this->mPlayer4->mBody.setPosition(sf::Vector2f(WINDOW_WIDTH + P4_X,WINDOW_HEIGHT + P4_Y));
    }
    while (setupComplete != true) {
        setupComplete = true;// place holder, need adding player sequence
    }

    this->mMasterList->push_back(this->mPlayer1);
    this->mMasterList->push_back(this->mPlayer2);
    this->mMasterList->push_back(this->mPlayer3);
    this->mMasterList->push_back(this->mPlayer4);
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

    return result;
}
  
//getters
//Player* TowerDefenseGame::getPlayer(const int& playerID) const {
//      Player* result = nullptr;
//      switch (playerID) {
//          case 1:
//              result = this->mPlayer1;
//              break;
//          case 2:
//              result = this->mPlayer2;
//              break;
//          case 3:
//              result = this->mPlayer3;
//              break;
//          case 4:
//              result = this->mPlayer4;
//              break;
//          default:
//              // :D broke
//              break;
//      }
//
//      return result; // Gavin I had to add this sorry if it ruins your day - Ingrid
//  }

Player* TowerDefenseGame::getHostPlayer() const {
    return this->mHostPlayer;
}

void TowerDefenseGame::assign3Words()
{
    for (int i = 0; i < 3; i++)
    {
        string randomWord = generateRandomWord();
        mPlayer1->setWord(i, randomWord);
    }
    for (int i = 0; i < 3; i++)
    {
        string randomWord = generateRandomWord();
        mPlayer2->setWord(i, randomWord);
    }
    for (int i = 0; i < 3; i++)
    {
        string randomWord = generateRandomWord();
        mPlayer3->setWord(i, randomWord);
    }
    for (int i = 0; i < 3; i++)
    {
        string randomWord = generateRandomWord();
        mPlayer4->setWord(i, randomWord);
    }
}

void TowerDefenseGame::assignExtremeWord()
{
    string extremeWord = generateExtremeWord();
    mPlayer1->setWord(3, extremeWord);
}

void TowerDefenseGame::assignSingleWord(int index)
{
    string randomWord = generateRandomWord();
    mPlayer1->setWord(index, randomWord);
}

void TowerDefenseGame::initialWordAssignments()
{
    assign3Words(); 
    assignExtremeWords();
}

void TowerDefenseGame::assignExtremeWords()
{
    mPlayer1->setWord(3, generateExtremeWord());
    mPlayer2->setWord(3, generateExtremeWord());
    mPlayer3->setWord(3, generateExtremeWord());
    mPlayer4->setWord(3, generateExtremeWord());
    mPlayer1->displayWords();
    /*mPlayer2->displayWords();
    mPlayer3->displayWords();
    mPlayer4->displayWords();*/
}



//setters

//public

//start the game!
void TowerDefenseGame::run() {

    //set up any other initializing code here!!!
    sf::Event event;
    initialWordAssignments();

    /* ***MAIN GAME LOOP START!!*** */

    // loop while game window is open and game is still running
    while (this->mGameWindow->isOpen() && this->GameComplete() == false) {
        
        //read in action, see if it will close window!
        while (this->mGameWindow->pollEvent(event)) {
            if(event.type == sf::Event::Closed) { this->mGameWindow->close(); }
            
            // this reads in continuous input 
            if (event.type == sf::Event::TextEntered)
            {
                // the updating and processing has to stay in this loop so that it
                // reads all the player input continuously
                mPlayer1->updateInput(); // captures all the input for player 1
                this->processInput(); // processes afformentioned input
            }
        }
       

        //step shape positions, checks for intersections and draws all
        this->updateEntities();
       
    }
    cout << "Current input in player class: " << mPlayer1->getInput() << endl;

    /* ***MAIN GAME LOOP END!!*** */

    //clean up before returning to main:

    //so far nothing dynamic to clean up!

}

void TowerDefenseGame::processInput() {// -> for handling keyboard event process!
    
    int determineBonus = generateRandomNumber();
    int wordSolved = 0;
    wordSolved = mPlayer1->processPlayerInput();

  
    if (wordSolved == 1)
    {
        if (determineBonus % 2 != 0) // if it's an odd number and small bonus 
        {
            // bonus tbd
            
        }
        else
        {
            // even number and small bonus 
            // bonus also tbd
            
        }
    }
    else if (wordSolved == 2)
    {
        if (determineBonus % 2 != 0) // if it's an odd number and larger bonus 
        {
            // bonus tbd
        
        }
        else
        {
            // even number and larger bonus 
            // bonus also tbd
          
        }
    }
    else if (wordSolved == 3)
    {
        if (determineBonus % 2 != 0) // if it's an odd number and x-treme bonus 
        {
            // bonus tbd
         
        }
        else
        {
            // even number and x-treme bonus 
            // bonus also tbd
           
        }
    }
    if (wordSolved > 0)
    {
        updateWords();
    }
    
    wordSolved = 0;
   
}

void TowerDefenseGame::updateWords() {// -> for handling word and bonus options!

    assign3Words();
    mPlayer1->displayWords();

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

    //over write screen for next iteration
    this->mGameWindow->clear(sf::Color::Black);

    //iterator???? :D
    for (// move through length of list and do stuff!
        std::list<Entity*>::iterator iter = this->mMasterList->begin();
        iter != this->mMasterList->end();
        ++iter
        ) {
        // check if element is already dead before processing
        if ((*iter)->isDead()) {
            this->mMasterList->erase(iter); // remove from list
            delete *iter; // deallocate memory
        }
        else { // entity is not dead, needs to check conflict, move, and draw  

            //first check for conflicting shapes, needs inner loop!
            for (
                std::list<Entity*>::iterator j = this->mMasterList->begin();
                j != this->mMasterList->end();
                ++j
            ) {
                
                //check if iter element is intersecting with all other shapes
                // -> if it is subtract HPs from each other!
                if (
                    (*iter)->mBody.getGlobalBounds().intersects((*j)->mBody.getGlobalBounds())
                    &&
                    iter != j) {
                    attackUntilDead(**iter, **j);
                }
            }

            //move this element by mDirection vec!

            (*iter)->mBody.move((*iter)->getDirection());

            // now draw element to screen, consider moving thru to another
            // loop if it makes the rendering of entities choppy!
            this->mGameWindow->draw((*iter)->mBody);// -> draw it and display at loop exit!
        }

    }
  
    // output contents of list to screen!
    this->mGameWindow->display();
}
    
//checks game conditions for if they are over
bool TowerDefenseGame::GameComplete() const {
    bool done = false;

    if (
    this->mPlayer1->getHP() < 0
    &&
    this->mPlayer2->getHP() < 0
    &&
    this->mPlayer3->getHP() < 0
    &&
    this->mPlayer4->getHP() < 0
    ) 
    { done = true; }

    return done;
}

//private helpers
void TowerDefenseGame::printMultiplayerMenu() const {// for join/create game
    std::cout
        << "1. Local Game " << std::endl
        << "2. Multiplayer Game " << std::endl
        << "Please enter choice: ";
}

int generateRandomNumber()
{
    int arraySize = sizeof(wordPool) / sizeof(wordPool[0]);
    int randomNumber = rand() % arraySize;
    return randomNumber;
}

int generateExtremeNumber()
{
    int arraySize = sizeof(extremePool) / sizeof(extremePool[0]);
    int randomNumber = rand() % arraySize;
    return randomNumber;
}

string generateRandomWord()
{
    string randomWord = "";
    randomWord = wordPool[generateRandomNumber()];
    return randomWord;
}

string generateExtremeWord()
{
    string extremeWord = "";
    extremeWord = extremePool[generateExtremeNumber()];
    return extremeWord;
}

