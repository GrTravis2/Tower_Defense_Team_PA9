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
    this->wordDisplay = new WordDisplay();

    //figure out how many Players/NPCs
    this->setupGame();
}

//setup game
void TowerDefenseGame::setupGame() {
    bool setupComplete = false;
    int choice = -1;
    
    this->printMultiplayerMenu();
    choice = 1;
    //std::cin >> choice;
    if (choice == 1) {//local game, 3 NPC

        this->mPlayer1 = new Player(1, 30, this->spawner->getMushroomTower());
        this->mPlayer1->setWordDisplay(this->wordDisplay); // Set WordDisplay after initializing mPlayer1
        this->mPlayer1->mBody.setPosition(sf::Vector2f(P1_X, P1_Y + 100)); // Adjusted position

        this->mPlayer2 = new NPC(2, this->spawner->getMushroomTower(), easy);
        this->mPlayer2->mBody.setPosition(sf::Vector2f(WINDOW_WIDTH + P2_X, P2_Y + 100)); // Adjusted position

        this->mPlayer3 = new NPC(3, this->spawner->getMushroomTower(), easy);
        this->mPlayer3->mBody.setPosition(sf::Vector2f(P3_X, WINDOW_HEIGHT + P3_Y + 100)); // Adjusted position

        this->mPlayer4 = new NPC(4, this->spawner->getMushroomTower(), easy);
        this->mPlayer4->mBody.setPosition(sf::Vector2f(WINDOW_WIDTH + P4_X, WINDOW_HEIGHT + P4_Y + 100)); // Adjusted position
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
    delete this->wordDisplay;
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
    /*for (int i = 0; i < 3; i++)
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
    }*/
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

void TowerDefenseGame::initialRewardAssignments()
{
    for (int i = 0; i < 3; ++i) {
        rewards[i] = generateReward(false);
        switch (rewards[i]) {
            case spawn1:
                rewardArray[i] = "Spawn 1";
                break;
            case spawn5:
                rewardArray[i] = "Spawn 5";
                break;
            case plus5HP:
                rewardArray[i] = "Plus 5 HP";
                break;
            case plus10HP:
                rewardArray[i] = "Plus 10 HP";
                break;
            default:
                rewardArray[i] = "Unknown";
                break;
        }
        //std::cout << "Initial reward " << i << ": " << rewardArray[i] << std::endl; // Debug output
    }
    // Generate reward for the extreme word
    rewards[3] = generateReward(true);
    switch (rewards[3]) {
        case spawnBigGnome:
            rewardArray[3] = "Spawn Big Gnome";
            break;
        case plus15HP:
            rewardArray[3] = "Plus 15 HP";
            break;
        default:
            rewardArray[3] = "Unknown";
            break;
    }
    //std::cout << "Initial reward 3: " << rewardArray[3] << std::endl; // Debug output
    wordDisplay->setRewards(rewardArray);
}

void TowerDefenseGame::initialWordAssignments()
{
    assign3Words(); 
    assignExtremeWords();
    initialRewardAssignments();
}

void TowerDefenseGame::assignExtremeWords()
{
    mPlayer1->setWord(3, generateExtremeWord());
    /*mPlayer2->setWord(3, generateExtremeWord());
    mPlayer3->setWord(3, generateExtremeWord());
    mPlayer4->setWord(3, generateExtremeWord());*/
   
 /*   mPlayer3->displayWords();
    mPlayer4->displayWords();*/
}



//setters

//public

//start the game!
void TowerDefenseGame::run() {

    //set up any other initializing code here!!!
    sf::Event event;
    initialWordAssignments();
    mPlayer1->displayWords(*mGameWindow);

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
        wordDisplay->draw(*this->mGameWindow);
    }
    cout << "Current input in player class: " << mPlayer1->getInput() << endl;

    /* ***MAIN GAME LOOP END!!*** */

    //clean up before returning to main:

    //so far nothing dynamic to clean up!

}

void TowerDefenseGame::processInput() {// -> for handling keyboard event process!
    
    int wordSolved = 0;
    wordSolved = mPlayer1->processPlayerInput();

    if (wordSolved > 0) {
        Bonus reward = rewards[wordSolved - 1];
        mapBonus(reward, wordSolved); // Adjust target player ID based on word solved
        updateWords();

        // Figure out a way to randomize target when extreme word is solved?
    }
}

void TowerDefenseGame::updateWords() {// -> for handling word and bonus options!

    std::string wordArray[4];
    for (int i = 0; i < 3; ++i) {
        wordArray[i] = generateRandomWord();
        rewards[i] = generateReward(false);
        switch (rewards[i]) {
            case spawn1:
                rewardArray[i] = "Spawn 1";
                break;
            case spawn5:
                rewardArray[i] = "Spawn 5";
                break;
            case plus5HP:
                rewardArray[i] = "Plus 5 HP";
                break;
            case plus10HP:
                rewardArray[i] = "Plus 10 HP";
                break;
            default:
                rewardArray[i] = "Unknown";
                break;
        }
        //std::cout << "Generated word " << i << ": " << wordArray[i] << std::endl; // Debug output
        //std::cout << "Generated reward " << i << ": " << rewardArray[i] << std::endl; // Debug output
    }
    // Generate reward for the extreme word
    wordArray[3] = generateExtremeWord();
    rewards[3] = generateReward(true);
    switch (rewards[3]) {
        case spawnBigGnome:
            rewardArray[3] = "Spawn Big Gnome";
            break;
        case plus15HP:
            rewardArray[3] = "Plus 15 HP";
            break;
        default:
            rewardArray[3] = "Unknown";
            break;
    }
    //std::cout << "Generated word 3: " << wordArray[3] << std::endl; // Debug output
    //std::cout << "Generated reward 3: " << rewardArray[3] << std::endl; // Debug output

    wordDisplay->setWords(wordArray);
    wordDisplay->setRewards(rewardArray);
    mPlayer1->setWord(0, wordArray[0]);
    mPlayer1->setWord(1, wordArray[1]);
    mPlayer1->setWord(2, wordArray[2]);
    mPlayer1->setWord(3, wordArray[3]);
    mPlayer1->displayWords(*this->mGameWindow);

}

// takes bonus enum and adds bonus entity(s) to master list
void TowerDefenseGame::mapBonus(enum Bonus& bonus, int targetPlayerID) {
    Entity* pNew = nullptr;
    sf::Sprite gnomeSprite = spawner->getGnome();
    sf::Sprite bigGnomeSprite = spawner->getBigGnome();
    sf::Vector2f targetPos = getPlayer(targetPlayerID)->mBody.getPosition();
    
    // Figure out a way to randomize target when extreme word is solved?

    // Also what is done in mapBonus when the bonus is plus5HP, plus10HP, or plus15HP?

    switch (bonus) {
        case spawn1:// -> insert one gnome at back!       
            pNew = new Entity(1, gnomeSprite);
            if (pNew != nullptr) {
                sf::Vector2f direction = computeDirection(pNew->mBody.getPosition(), targetPos, 0.1f);
                pNew->setDirection(direction);
                this->mMasterList->push_back(pNew);
            }
            break;
        case spawn5:// -> make 5 gnomes and insert at back of list
            for(int i = 0; i < 5; i++) {
                pNew = new Entity(1, gnomeSprite);
                if (pNew != nullptr){
                    sf::Vector2f direction = computeDirection(pNew->mBody.getPosition(), targetPos, 0.1f);
                    pNew->setDirection(direction);
                    this->mMasterList->push_back(pNew);
                }
                
            }
            break;
        case spawnBigGnome:// -> add one big gnome!
            pNew = new Entity(5, bigGnomeSprite);
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

    // load background
    sf::Sprite grassSprite = this->spawner->getGrass();
    this->mGameWindow->draw(grassSprite);

    // Draw the WordDisplay on top of the background but below the entities
    wordDisplay->draw(*this->mGameWindow);

    //iterator???? :D
    for (// move through length of list and do stuff!
        std::list<Entity*>::iterator iter = this->mMasterList->begin(); 
        iter != this->mMasterList->end();
        //++iter // the incrementation I think was messing with the loop so I put it down at the end - Ingrid
        ) 
        { // position vector determines if something is out of bounds and kills it if it is 
        sf::Vector2f position = (*iter)->mBody.getPosition();
        if ((position.x < -05.0f || position.x > WINDOW_WIDTH + 05.0f) ||
            (position.y < -05.0f || position.y > WINDOW_HEIGHT + 05.0f)) {
            (*iter)->setHP(0);
        }
        // check if element is already dead before processing
        if ((*iter)->isDead()) {
            delete* iter; // deallocate memory
            iter = this->mMasterList->erase(iter); // remove from list
        
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

            ++iter; // only moves things forward if the entity is not dead 
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

std::string generateRandomWord()
{
    std::string randomWord = "";
    randomWord = wordPool[generateRandomNumber()];
    return randomWord;
}

std::string generateExtremeWord()
{
    std::string extremeWord = "";
    extremeWord = extremePool[generateExtremeNumber()];
    return extremeWord;
}

Bonus TowerDefenseGame::generateReward(bool isExtreme) {
    // Generate a random reward using the Bonus enum
    if (isExtreme) {
        // Rewards for extreme words
        int randomIndex = rand() % 2; // There are 2 possible extreme bonuses
        return static_cast<Bonus>(randomIndex + 4); // plus5HP and plus10HP are skipped
    } else {
        // Rewards for regular words
        int randomIndex = rand() % 4; // There are 4 possible regular bonuses
        return static_cast<Bonus>(randomIndex);
    }
}

