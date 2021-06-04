#include "player.h"

Player::Player(std::string name, uint age, uint points)
{
    id = data::getAndIncrease();
    if (name.empty())
    {
        throw std::invalid_argument("Empty player name");
    }

    this->name = name;
    this->age = age;
    this->points = points;
}

void Player::addPoints(const uint points)
{
    this->points += points;
}

void Player::saveInfo(std::string fileName)
{
    std::ofstream playersFile(fileName, std::ios::out | std::ios::app);
    if (!playersFile)
    { // !playersFile.is_open()
        throw std::runtime_error("Could not open file " + fileName);
    }
    playersFile << id << " " << name << " " << age << " " << points << "\n";
    playersFile.close();
}