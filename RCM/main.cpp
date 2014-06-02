//
//  main.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "GameManager.h"

int main(int argc, const char * argv[])
{
    GameManager *gameManager = &GameManager::getGameManager();
    gameManager->runGameLoop();
    GameManager::destroyGameManager();
    
    return 0;
}

