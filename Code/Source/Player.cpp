#include "Player.h"
#include <string>
using std::string;

/*================================== Public Part ==================================*/

Player::Player(string s) : name(s) {

	playerCount++;
	earnAmount = 0;
	payAmount = 0;
	balance = 0;
}

string Player::getName() {

	return name;
}

int Player::playerCount = 0;

void Player::addEarning(int amounts) {

	this->earnAmount += amounts;
	calculate();
}

int Player::getEarning() {
	
	return this->earnAmount;
}

void Player::addPaying(int amounts) {

	this->payAmount += amounts;
	calculate();
}

int Player::getPaying() {
	
	return this->payAmount;
}

int Player::getBalance() {
	
	return this->balance;
}

/*================================== Private Part ==================================*/

void Player::calculate() {

	this->balance = this->earnAmount - this->payAmount;
}