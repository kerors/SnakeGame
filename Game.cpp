#include <iostream>
#include <conio.h>  // 用于 _kbhit 和 _getch
#include <windows.h> // 用于 Sleep
#include "Game.h"
#include "Utils.h"

Game::Game() : snake(5, 5), width(20), height(15), isRunning(true) {
    generateFood();
}

void Game::generateFood() {
    while (true) {
        int x = randInt(1, width - 2);
        int y = randInt(1, height - 2);

        // 检查生成的食物是否与蛇身重叠
        bool isOnSnake = false;
        for (const auto& segment : snake.getBody()) {
            if (segment.first == x && segment.second == y) {
                isOnSnake = true;
                break;
            }
        }

        // 如果食物位置不在蛇身上，生成食物
        if (!isOnSnake) {
            food = { x, y };
            break;
        }
    }
}


void Game::render() {
    system("cls");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                std::cout << "+"; // 边框
            }
            else if (std::make_pair(x, y) == food) {
                std::cout << "@"; // 食物
            }
            else {
                bool isBody = false;
                for (const auto& segment : snake.getBody()) {
                    if (segment == std::make_pair(x, y)) {
                        std::cout << "#"; // 蛇身
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void Game::handleInput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': snake.setDirection(UP); break;
        case 's': snake.setDirection(DOWN); break;
        case 'a': snake.setDirection(LEFT); break;
        case 'd': snake.setDirection(RIGHT); break;
        }
    }
}

void Game::start() {
    while (isRunning) {
        render();
        handleInput();
        snake.move();

        // 检查是否吃到食物
        if (snake.getBody().front() == food) {
            snake.grow();
            generateFood(); // 生成新的食物
        }

        // 检查是否发生碰撞
        if (snake.checkCollision(width, height)) {
            isRunning = false; // 结束游戏
        }

        Sleep(150); // 控制游戏速度
    }

    std::cout << "Game Over!\n";
}
