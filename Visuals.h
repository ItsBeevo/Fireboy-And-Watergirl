#pragma once
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <cstring>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <sftools/Chronometer.hpp>
#include <fstream>
#include "DataRetrieval.h"
using namespace std;
using namespace sf;
using namespace sftools;


//Pools Textures
Texture waterLeftText, waterMidText, waterRightText, lavaLeftText, lavaMidText, lavaRightText, acidLeftText, acidMidText, acidRightText;
Texture smallLavaText, smallAcidText, smallWaterText;

//Button
Texture textureButtonOff, textureButtonOn;
Texture textureStoneMid;


//  Declaring fireBoy and waterGirl sprites and textures
Texture fireBoyTexture, fireBoyTextureLeft, fireBoyTextureRight, waterGirlTexture, waterGirlTextureLeft, waterGirlTextureRight;


RectangleShape buttonOn({ 80,60 }), buttonOff({ 80,60 });
RectangleShape ground({ 1280, 1 });
Color color(0, 0, 0, 0);


Texture textureBackground;
RectangleShape spriteBackground(Vector2f(80, 40));

// Asking for players' names
string player1Name, player2Name;
Text player1Text, player2Text;
Texture textureSideBorder, textureBottomBorder, textureTopBorder;


// 0 -> Top border, 1 -> Bottom border, 2 -> Left border, 3 -> Right border
RectangleShape borders[4];
Vector2f vec1(1280, 40), vec2(40, 720);

RectangleShape spriteStoneMid(Vector2f(80.f, 40.f));
RectangleShape spriteStoneLeft(Vector2f(80.f, 40.f));
RectangleShape spriteStoneRight(Vector2f(80.f, 40.f));
Texture smoke1Text, smoke2Text;
Sprite smoke1, smoke2;
Texture textureStoneLeft;
Texture textureStoneRight;

Font fontTitle;
Text textTitle;
FloatRect textRect;


Text textEnterYourName;
RectangleShape enterYourNameRectangle;
Color color2(255, 255, 255, 0);
RectangleShape enterYourNameRectangle2;


Text textIntro;
Texture texturePauseBackground;
Sprite spritePauseBackground;
Text textPaused;
Text textGameOver;
Text textStart;
Text textMainMenu;
Text textRetryLevel;
Text textContinue;
Text textContinueIntro;
Text textExit;
Text textGuest;
Text textLeaderboards;
Text textLeaderboard;

Text textLevels[10];
Text textMainLevels[10];
Text textLevel1;
Text textLevel2 = textLevel1;
Text textSettings;
Text textOn;
Text textOff;
Text textMusic;
Text textSoundFx;


Texture textureWhiteArrow, textureRedArrow;
RectangleShape arrow;
RectangleShape arrowLevelInquire;
RectangleShape arrowLeaderboards;
RectangleShape arrowLevelLeaderboard;
Texture textureDoor;
Sprite spriteDoor;
SoundBuffer bufferFireboyJump, bufferWatergirlJump, bufferLevelComplete, bufferButtonHover, bufferPlayerDeath, bufferButtonSound;

Sound soundButtonHover(bufferButtonHover);
Sound soundLevelComplete(bufferLevelComplete);
Sound soundFireboyJump(bufferFireboyJump), soundWatergirlJump(bufferWatergirlJump);
Sound soundPlayerDeath(bufferPlayerDeath);
Sound buttonSound(bufferButtonSound);
Music musicIntro, musicLevel;

Text textTimer;
stringstream ss;
Chronometer chron;
string stringTimer;

//Gate and bridges
Texture textureGateTop, textureGateMiddle, textureGateBottom, textureGateBottomMiddle;
Texture textureBridgeLeft, textureBridgeMiddle;

int currentLevelLeaderboardPage = 0;
int continueFillColor = 255;
int enterYourNameFillColor = 255;

int callCounter = 0;
void initVisuals()
{
    callCounter++;

    //Gate
    textureGateBottom.loadFromFile(m + "assets/graphics/gateBottom.png");
    textureGateMiddle.loadFromFile(m + "assets/graphics/gateMiddle.png");
    textureGateTop.loadFromFile(m + "assets/graphics/gateTop.png");

    //Bridges
    textureBridgeLeft.loadFromFile(m + "assets/graphics/bridgeLeft.png");
    textureBridgeMiddle.loadFromFile(m + "assets/graphics/bridgeMiddle.png");

    textureRedArrow.loadFromFile(m + "assets/graphics/redArrow.png");
    textureWhiteArrow.loadFromFile(m + "assets/graphics/whiteArrow.png");
    // Arrows
    arrow.setSize(Vector2f(150, 80));
    arrow.setPosition(30, 40);
    arrow.setTexture(&textureWhiteArrow);

    arrowLevelInquire = arrow;
    arrowLeaderboards = arrow;
    arrowLevelLeaderboard = arrow;

    // Door
    textureDoor.loadFromFile(m + "assets/graphics/door.png");

    spriteDoor.setTexture(textureDoor);

    // Sound effects
    bufferFireboyJump.loadFromFile(m + "assets/audio/fireboyJump.ogg");
    bufferButtonHover.loadFromFile(m + "assets/audio/buttonHover.ogg");
    bufferWatergirlJump.loadFromFile(m + "assets/audio/watergirlJump.ogg");
    bufferLevelComplete.loadFromFile(m + "assets/audio/levelComplete.ogg");
    bufferPlayerDeath.loadFromFile(m + "assets/audio/death.ogg");
    bufferButtonSound.loadFromFile(m + "assets/audio/buttonSound.wav");


    // Music
    musicIntro.openFromFile(m + "assets/audio/intro.ogg");
    musicLevel.openFromFile(m + "assets/audio/level.ogg");
    musicIntro.setLoop(true), musicLevel.setLoop(true);

    musicIntro.setVolume(50);
    musicLevel.setVolume(40);
    soundButtonHover.setVolume(1000);

    // Timer
    textTimer.setFont(fontTitle);
    textTimer.setPosition(590, 0);
    textTimer.setCharacterSize(35);
    textTimer.setFillColor(Color::White);

    // Player names and scores
    for (int i = 0; i < 10; i++)
    {
        textLevels[i].setFont(fontTitle);
        textLevels[i].setCharacterSize(50);
        textLevels[i].setFillColor(Color::White);
        textLevels[i].setString("Level " + to_string(i + 1));

        textRect = textLevels[i].getLocalBounds();
        textLevels[i].setOrigin(textRect.left +
            textRect.width / 2.0f,
            textRect.top +
            textRect.height / 2.0f);
        textLevels[i].setPosition(((i < 5) ? 440 : 840), (i < 5) ? (i + 1) * 100 + 130 : (i - 5 + 1) * 100 + 130);
    }

    for (int i = 0; i < 10; i++)
    {
        textMainLevels[i].setFont(fontTitle);
        textMainLevels[i].setCharacterSize(70);
        textMainLevels[i].setFillColor(Color::White);
        textMainLevels[i].setString("Level " + to_string(i + 1) + " leaderboard");

        textRect = textMainLevels[i].getLocalBounds();
        textMainLevels[i].setOrigin(textRect.left +
            textRect.width / 2.0f,
            textRect.top +
            textRect.height / 2.0f);
        textMainLevels[i].setPosition(640, 100);
    }

    // Level 1 (Test)
    textLevel1.setFont(fontTitle);
    textLevel1.setString("Level 1 (For testing)");
    textLevel1.setCharacterSize(70);
    textLevel1.setFillColor(Color::White);

    textRect = textLevel1.getLocalBounds();
    textLevel1.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textLevel1.setPosition(640, 300);

    // Level 2 (Test)
    textLevel2 = textLevel1;
    textLevel2.setString("Level 2 (For testing)");
    textLevel2.setPosition(640, 450);

    // Settings
    textSettings.setFont(fontTitle);
    textSettings.setString("Settings");
    textSettings.setCharacterSize(50);
    textSettings.setFillColor(Color::White);

    textRect = textSettings.getLocalBounds();
    textSettings.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textSettings.setPosition(640, 500);

    textOn.setFont(fontTitle);
    textOn.setString("On");
    textOn.setCharacterSize(50);
    textOn.setFillColor(Color::White);
    textRect = textOn.getLocalBounds();
    textOn.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textOn.setPosition(640, 300);

    textOff.setFont(fontTitle);
    textOff.setString("Off");
    textOff.setCharacterSize(50);
    textOff.setFillColor(Color::White);
    textRect = textOff.getLocalBounds();
    textOff.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textOff.setPosition(640, 500);

    textMusic.setFont(fontTitle);
    textMusic.setString("Music: ");
    textMusic.setCharacterSize(50);
    textMusic.setFillColor(Color::White);
    textRect = textMusic.getLocalBounds();
    textMusic.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textMusic.setPosition(620, 300);

    textSoundFx.setFont(fontTitle);
    textSoundFx.setString("Sound Fx: ");
    textSoundFx.setCharacterSize(50);
    textSoundFx.setFillColor(Color::White);
    textRect = textSoundFx.getLocalBounds();
    textSoundFx.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textSoundFx.setPosition(620, 400);

    // Intro text
    if (callCounter < 2) { loadText(); }
    textIntro.setFont(fontTitle);
    textIntro.setCharacterSize(30);
    textIntro.setFillColor(Color::White);
    textIntro.setString(introText);

    textRect = textIntro.getLocalBounds();
    textIntro.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textIntro.setPosition(640, 200);

    // Pause background
    texturePauseBackground.loadFromFile(m + "assets/graphics/pauseBackground.png");
    spritePauseBackground.setTexture(texturePauseBackground);
    spritePauseBackground.setPosition(0, 0);

    // Paused
    textPaused.setFont(fontTitle);
    textPaused.setCharacterSize(70);
    textPaused.setFillColor(Color::White);
    textPaused.setString("Paused");

    textRect = textPaused.getLocalBounds();
    textPaused.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textPaused.setPosition(640, 100);

    // Game over
    textGameOver = textPaused;
    textGameOver.setString("Game over");
    textRect = textGameOver.getLocalBounds();
    textGameOver.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textGameOver.setPosition(640, 100);

    // Start
    textStart.setFont(fontTitle);
    textStart.setCharacterSize(50);
    textStart.setFillColor(Color::White);
    textStart.setString("Start");

    textRect = textStart.getLocalBounds();
    textStart.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textStart.setPosition(640, 300);

    // Main menu
    textMainMenu.setFont(fontTitle);
    textMainMenu.setCharacterSize(50);
    textMainMenu.setFillColor(Color::White);
    textMainMenu.setString("Main menu");

    textRect = textMainMenu.getLocalBounds();
    textMainMenu.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textMainMenu.setPosition(640, 600);

    // Retry level
    textRetryLevel.setFont(fontTitle);
    textRetryLevel.setCharacterSize(50);
    textRetryLevel.setFillColor(Color::White);
    textRetryLevel.setString("Retry Level");

    textRect = textRetryLevel.getLocalBounds();
    textRetryLevel.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textRetryLevel.setPosition(640, 400);

    // Continue
    textContinue.setFont(fontTitle);
    textContinue.setCharacterSize(50);
    textContinue.setFillColor(Color::White);
    textContinue.setString("Continue");

    textRect = textContinue.getLocalBounds();
    textContinue.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textContinue.setPosition(640, 300);

    // Continue intro
    textContinueIntro.setFont(fontTitle);
    textContinueIntro.setCharacterSize(60);
    textContinueIntro.setFillColor(Color::White);
    textContinueIntro.setString("Continue");

    textRect = textContinueIntro.getLocalBounds();
    textContinueIntro.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textContinueIntro.setPosition(640, 430);

    // Exit
    textExit.setFont(fontTitle);
    textExit.setString("Exit");
    textExit.setCharacterSize(50);
    textExit.setFillColor(Color::White);

    textRect = textExit.getLocalBounds();
    textExit.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textExit.setPosition(1200, 680);

    // Guest
    textGuest.setFont(fontTitle);
    textGuest.setString("play as a guest");
    textGuest.setCharacterSize(50);
    textGuest.setFillColor(Color::White);

    textRect = textGuest.getLocalBounds();
    textGuest.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textGuest.setPosition(640, 575);

    // Leaderboards
    textLeaderboards.setFont(fontTitle);
    textLeaderboards.setCharacterSize(50);
    textLeaderboards.setFillColor(Color::White);
    textLeaderboards.setString("Leaderboard");

    textRect = textLeaderboards.getLocalBounds();
    textLeaderboards.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textLeaderboards.setPosition(640, 500);

    textLeaderboard.setFont(fontTitle);
    textLeaderboard.setCharacterSize(70);
    textLeaderboard.setFillColor(Color::White);
    textLeaderboard.setString("Leaderboard");

    textRect = textLeaderboard.getLocalBounds();
    textLeaderboard.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    textLeaderboard.setPosition(640, 100);

	//Enter your name guide
	textEnterYourName.setFont(fontTitle);
	textEnterYourName.setFillColor(Color::White);

	textEnterYourName.setCharacterSize(50);
	textEnterYourName.setString("Enter player 1 name:");
	textRect = textEnterYourName.getLocalBounds();
	textEnterYourName.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	textEnterYourName.setPosition(640, 230);

	// Player 1 name
	player1Text.setFont(fontTitle);

	player1Text.setFillColor(Color::White);
	textRect = player1Text.getLocalBounds();
	player1Text.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	player1Text.setPosition(640, 350);
	player1Text.setCharacterSize(40);

	// Player 2 name
	player2Text.setFont(fontTitle);
	player2Text.setFillColor(Color::White);
	textRect = player2Text.getLocalBounds();
	player2Text.setPosition(640, 450);
	player2Text.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	player2Text.setCharacterSize(40);

	// Players name input boxes
	enterYourNameRectangle.setSize(Vector2f(400, 45));

	enterYourNameRectangle.setFillColor(color2);
	enterYourNameRectangle.setOutlineThickness(5);
	enterYourNameRectangle.setOutlineColor(Color::White);
	textRect = enterYourNameRectangle.getLocalBounds();
	enterYourNameRectangle.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	enterYourNameRectangle.setPosition(640, 350);

	enterYourNameRectangle2 = enterYourNameRectangle;
	enterYourNameRectangle2.setPosition(640, 450);


	// Stones
	textureStoneMid.loadFromFile(m + "assets/graphics/stoneMid.png");
	spriteStoneMid.setTexture(&textureStoneMid);

	textureStoneLeft.loadFromFile(m + "assets/graphics/stoneLeft.png");
	spriteStoneLeft.setTexture(&textureStoneLeft);

	textureStoneRight.loadFromFile(m + "assets/graphics/stoneRight.png");
	spriteStoneRight.setTexture(&textureStoneRight);

	// Smoke
	smoke1Text.loadFromFile(m + "assets/graphics/smoke1.png");
	smoke2Text.loadFromFile(m + "assets/graphics/smoke2.png");
	smoke1.setTexture(smoke1Text);
	smoke2.setTexture(smoke2Text);

	// Title

	fontTitle.loadFromFile(m + "assets/fonts/KOMIKAP_.ttf");

	textTitle.setFont(fontTitle);
	textTitle.setCharacterSize(70);
	textTitle.setFillColor(Color::White);
	textTitle.setString("Fireboy and Watergirl");
	textRect = textTitle.getLocalBounds();

	textTitle.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	textTitle.setPosition(640, 100);


	// Background
	textureBackground.loadFromFile(m + "assets/graphics/backGroundBrick.png");

	spriteBackground.setTexture(&textureBackground);

	// Borders
	textureTopBorder.loadFromFile(m + "assets/graphics/topBorder.png");
	textureSideBorder.loadFromFile(m + "assets/graphics/sideBorder.png");
	textureBottomBorder.loadFromFile(m + "assets/graphics/bottomBorder.png");



	borders[2].setSize(vec2), borders[3].setSize(vec2);
	borders[0].setSize(vec1), borders[1].setSize(vec1);

	borders[2].setPosition(0, 0), borders[3].setPosition(1240, 0);
	borders[0].setPosition(0, 0), borders[1].setPosition(0, 680);

	borders[2].setTexture(&textureSideBorder), borders[3].setTexture(&textureSideBorder);
	borders[0].setTexture(&textureTopBorder), borders[1].setTexture(&textureBottomBorder);

	//Ground
	ground.setFillColor(color);
	ground.setPosition({ 0, 680 });

	// Declaring characters
	fireBoyTexture.loadFromFile(m + "assets/graphics/fireBoy.png");
	fireBoyTextureLeft.loadFromFile(m + "assets/graphics/fireBoyLeft.png");
	fireBoyTextureRight.loadFromFile(m + "assets/graphics/fireBoyRight.png");
	waterGirlTexture.loadFromFile(m + "assets/graphics/waterGirl.png");
	waterGirlTextureLeft.loadFromFile(m + "assets/graphics/waterGirlLeft.png");
	waterGirlTextureRight.loadFromFile(m + "assets/graphics/waterGirlRight.png");

	//Pools Textures
	waterLeftText.loadFromFile(m + "assets/graphics/waterLeft.png");
	waterMidText.loadFromFile(m + "assets/graphics/waterMid.png");
	waterRightText.loadFromFile(m + "assets/graphics/waterRight.png");
	lavaLeftText.loadFromFile(m + "assets/graphics/lavaLeft.png");
	lavaMidText.loadFromFile(m + "assets/graphics/lavaMid.png");
	lavaRightText.loadFromFile(m + "assets/graphics/lavaRight.png");
	acidLeftText.loadFromFile(m + "assets/graphics/acidLeft.png");
	acidMidText.loadFromFile(m + "assets/graphics/acidMid.png");
	acidRightText.loadFromFile(m + "assets/graphics/acidRight.png");
	smallWaterText.loadFromFile(m + "assets/graphics/smallWater.png");
	smallAcidText.loadFromFile(m + "assets/graphics/smallAcid.png");
	smallLavaText.loadFromFile(m + "assets/graphics/smallLava.png");

	// Button
	textureButtonOff.loadFromFile(m + "assets/graphics/btnoff.png");
	textureButtonOn.loadFromFile(m + "assets/graphics/btnon.png");
	buttonOn.setTexture(&textureButtonOn);
	buttonOff.setTexture(&textureButtonOff);
}