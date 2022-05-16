#ifndef SNOOKER_H
#define SNOOKER_H

//#define GRAPHICS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Physics.h"
#include "Mouse.h"
#include "Snooker.h"

class Snooker {
private:

	sf::RenderWindow window;
	
	p2d::Physics physics;
	Mouse mouse;

	sf::Color Pink{ 255, 105, 180 };
	sf::Color Brown{ 139, 69, 19 };
	sf::Color GreenDark{ 0, 100, 0 };
	sf::Color GreenMid{ 0, 180, 0 };

	const int screenWidth = 1920;
	const int screenHeight = 1080;

	int tableGap;
	int tableWidth;
	int tableHeight;
	int radius;

	p2d::Vec2f tablePos;

	float PI;
	float redX;
	float redY;
	float dx;
	float dy;
	float fix;

	float wallThickness;
	float holeDiameter;

	bool hit;

	p2d::Vec2f whitePos;
	p2d::Vec2f greenPos;
	p2d::Vec2f brownPos;
	p2d::Vec2f yellowPos;
	p2d::Vec2f bluePos;
	p2d::Vec2f pinkPos;
	p2d::Vec2f blackPos;

	p2d::Vec2f red1Pos;
	p2d::Vec2f red2Pos;
	p2d::Vec2f red3Pos;
	p2d::Vec2f red4Pos;
	p2d::Vec2f red5Pos;
	p2d::Vec2f red6Pos;
	p2d::Vec2f red7Pos;
	p2d::Vec2f red8Pos;
	p2d::Vec2f red9Pos;
	p2d::Vec2f red10Pos;
	p2d::Vec2f red11Pos;
	p2d::Vec2f red12Pos;
	p2d::Vec2f red13Pos;
	p2d::Vec2f red14Pos;
	p2d::Vec2f red15Pos;

	p2d::Vec2f leftWallPos;
	p2d::Vec2f rightWallPos;
	p2d::Vec2f topLeftWallPos;
	p2d::Vec2f topRightWallPos;
	p2d::Vec2f bottomLeftWallPos;
	p2d::Vec2f bottomRightWallPos;

	sf::Texture* texture;
	sf::RectangleShape table;
	
	sf::SoundBuffer bufferCollide;
	sf::Sound soundCollide;

	//balls
	sf::CircleShape redBall1;
	sf::CircleShape redBall2;
	sf::CircleShape redBall3;
	sf::CircleShape redBall4;
	sf::CircleShape redBall5;
	sf::CircleShape redBall6;
	sf::CircleShape redBall7;
	sf::CircleShape redBall8;
	sf::CircleShape redBall9;
	sf::CircleShape redBall10;
	sf::CircleShape redBall11;
	sf::CircleShape redBall12;
	sf::CircleShape redBall13;
	sf::CircleShape redBall14;
	sf::CircleShape redBall15;
	sf::CircleShape whiteBall;
	sf::CircleShape greenBall;
	sf::CircleShape brownBall;
	sf::CircleShape yellowBall;
	sf::CircleShape blueBall;
	sf::CircleShape pinkBall;
	sf::CircleShape blackBall;

	p2d::CircleBody redBall1Object;
	p2d::CircleBody redBall2Object;
	p2d::CircleBody redBall3Object;
	p2d::CircleBody redBall4Object;
	p2d::CircleBody redBall5Object;
	p2d::CircleBody redBall6Object;
	p2d::CircleBody redBall7Object;
	p2d::CircleBody redBall8Object;
	p2d::CircleBody redBall9Object;
	p2d::CircleBody redBall10Object;
	p2d::CircleBody redBall11Object;
	p2d::CircleBody redBall12Object;
	p2d::CircleBody redBall13Object;
	p2d::CircleBody redBall14Object;
	p2d::CircleBody redBall15Object;
	p2d::CircleBody whiteBallObject;
	p2d::CircleBody greenBallObject;
	p2d::CircleBody brownBallObject;
	p2d::CircleBody yellowBallObject;
	p2d::CircleBody blueBallObject;
	p2d::CircleBody pinkBallObject;
	p2d::CircleBody blackBallObject;

	sf::Texture* redTexture;
	sf::Texture* yellowTexture;
	sf::Texture* greenTexture;
	sf::Texture* brownTexture;
	sf::Texture* blueTexture;
	sf::Texture* pinkTexture;
	sf::Texture* blackTexture;

	//Walls
	p2d::Vec2f verticalWallSize = { wallThickness, tableHeight - 2.0f * holeDiameter };
	p2d::Vec2f horizontalWallSize = { (tableWidth - 3.0f * holeDiameter) / 2.0f, wallThickness };

	sf::RectangleShape leftWall;
	p2d::RectangleBody objectLeftWall;
	sf::RectangleShape rightWall;
	p2d::RectangleBody objectRightWall;
	sf::RectangleShape topLeftWall;
	p2d::RectangleBody objectTopLeftWall;
	sf::RectangleShape topRightWall;
	p2d::RectangleBody objectTopRightWall;
	sf::RectangleShape bottomLeftWall;
	p2d::RectangleBody objectBottomLeftWall;
	sf::RectangleShape bottomRightWall;
	p2d::RectangleBody objectBottomRightWall;

	//Capsule balls vertical
	sf::CircleShape capsuleLeft1;
	p2d::CircleBody capsuleLeft1Object;
	sf::CircleShape capsuleLeft2;
	p2d::CircleBody capsuleLeft2Object;
	sf::CircleShape capsuleRight1;
	p2d::CircleBody capsuleRight1Object;
	sf::CircleShape capsuleRight2;
	p2d::CircleBody capsuleRight2Object;

	//Capsule balls horizontal top
	sf::CircleShape capsuleTopLeft1;
	p2d::CircleBody capsuleTopLeft1Object;
	sf::CircleShape capsuleTopLeft2;
	p2d::CircleBody capsuleTopLeft2Object;
	sf::CircleShape capsuleTopRight1;
	p2d::CircleBody capsuleTopRight1Object;
	sf::CircleShape capsuleTopRight2;
	p2d::CircleBody capsuleTopRight2Object;

	//Capsule balls horizontal bottom
	sf::CircleShape capsuleBottomLeft1;
	p2d::CircleBody capsuleBottomLeft1Object;
	sf::CircleShape capsuleBottomLeft2;
	p2d::CircleBody capsuleBottomLeft2Object;
	sf::CircleShape capsuleBottomRight1;
	p2d::CircleBody capsuleBottomRight1Object;
	sf::CircleShape capsuleBottomRight2;
	p2d::CircleBody capsuleBottomRight2Object;

	//potting logic
	bool pot1 = false;
	bool pot2 = false;
	bool pot3 = false;
	bool pot4 = false;
	bool pot5 = false;
	bool pot6 = false;
	bool pot7 = false;
	bool pot8 = false;
	bool pot9 = false;
	bool pot10 = false;
	bool pot11 = false;
	bool pot12 = false;
	bool pot13 = false;
	bool pot14 = false;
	bool pot15 = false;
	bool redComplete = false;
	
	bool potGreen = false;
	bool potYellow = false;
	bool potBrown = false;
	bool potBlue = false;
	bool potPink = false;
	bool potBlack = false;

	int points = 0;
	int goesPrev = 0;
	int goes = 0;

	sf::Text text;
	sf::Text text2;
	sf::Font font;

public:

	Snooker(){ 
		create();
	}

	void create() {
		
		window.create(sf::VideoMode(screenWidth, screenHeight), "SifuF Snooker");
		
		tableGap = screenWidth / 10.0f;
		tableWidth = screenWidth - tableGap;
		tableHeight = screenHeight - tableGap;
		radius = tableWidth / 80.0f;

		tablePos = { tableGap / 2.0f, tableGap / 2.0f };

		PI = 3.14159f;
		redX = tablePos.x + tableWidth * 3.0f / 4.0f + 2 * radius + 10.0f;
		redY = tablePos.y + tableHeight / 2.0f;
		dx = cos(PI / 6.0f);
		dy = sin(PI / 6.0f);
		fix = 2.0f;

		wallThickness = 70.0f;
		holeDiameter = radius * 6.5f;

		hit = false;

		physics.setGravity({ 0.0f, 0.0f });
		physics.setDrag({ 0.0f, 0.0f });

		whitePos = { tablePos.x + tableWidth / 10.0f + 50.0f, tablePos.y + tableHeight * 1.5f / 3.0f };
		greenPos = { tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight / 3.0f };
		brownPos = { tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight * 1.5f / 3.0f };
		yellowPos = { tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight * 2 / 3.0f };
		bluePos = { tablePos.x + tableWidth / 2.0f, tablePos.y + tableHeight / 2.0f };
		pinkPos = { tablePos.x + tableWidth * 3.0f / 4.0f, tablePos.y + tableHeight / 2.0f };
		blackPos = { tablePos.x + tableWidth * 10.0f / 11.0f, tablePos.y + tableHeight / 2.0f };

		red1Pos = { redX, redY };
		red2Pos = { redX + dx * 2.0f * radius + fix, redY - 1.0f * radius - fix };
		red3Pos = { redX + dx * 2.0f * radius + fix, redY + 1.0f * radius + fix };
		red4Pos = { redX + dx * 4.0f * radius + (2.0f * fix), redY - 2.0f * radius - (2.0f * fix) };
		red5Pos = { redX + dx * 4.0f * radius + (2.0f * fix), redY };
		red6Pos = { redX + dx * 4.0f * radius + (2.0f * fix), redY + 2.0f * radius + (2.0f * fix) };
		red7Pos = { redX + dx * 6.0f * radius + (3.0f * fix), redY - 3.0f * radius - (2.0f * fix) };
		red8Pos = { redX + dx * 6.0f * radius + (3.0f * fix), redY + -1.0f * radius - (1.0f * fix) };
		red9Pos = { redX + dx * 6.0f * radius + (3.0f * fix), redY + +1.0f * radius + (1.0f * fix) };
		red10Pos = { redX + dx * 6.0f * radius + (3.0f * fix), redY + 3.0f * radius + (2.0f * fix) };
		red11Pos = { redX + dx * 8.0f * radius + (4.0f * fix), redY - 4.0f * radius - (2.0f * fix) };
		red12Pos = { redX + dx * 8.0f * radius + (4.0f * fix), redY - 2.0f * radius - (1.0f * fix) };
		red13Pos = { redX + dx * 8.0f * radius + (4.0f * fix), redY };
		red14Pos = { redX + dx * 8.0f * radius + (4.0f * fix), redY + 2.0f * radius + (1.0f * fix) };
		red15Pos = { redX + dx * 8.0f * radius + (4.0f * fix), redY + 4.0f * radius + (2.0f * fix) };

		leftWallPos = { tablePos.x + wallThickness / 2.0f, tablePos.y + tableHeight / 2.0f };
		rightWallPos = { tablePos.x + tableWidth - wallThickness / 2.0f, tablePos.y + tableHeight / 2.0f };
		topLeftWallPos = { tablePos.x + (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + wallThickness / 2.0f };
		topRightWallPos = { tablePos.x + tableWidth - (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + wallThickness / 2.0f };
		bottomLeftWallPos = { tablePos.x + (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + tableHeight - wallThickness / 2.0f };
		bottomRightWallPos = { tablePos.x + tableWidth - (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + tableHeight - wallThickness / 2.0f };

		redBall1.setRadius(radius);
		redBall2.setRadius(radius);
		redBall3.setRadius(radius);
		redBall4.setRadius(radius);
		redBall5.setRadius(radius);
		redBall6.setRadius(radius);
		redBall7.setRadius(radius);
		redBall8.setRadius(radius);
		redBall9.setRadius(radius);
		redBall10.setRadius(radius);
		redBall11.setRadius(radius);
		redBall12.setRadius(radius);
		redBall13.setRadius(radius);
		redBall14.setRadius(radius);
		redBall15.setRadius(radius);
		whiteBall.setRadius(radius);
		greenBall.setRadius(radius);
		brownBall.setRadius(radius);
		yellowBall.setRadius(radius);
		blueBall.setRadius(radius);
		pinkBall.setRadius(radius);
		blackBall.setRadius(radius);

#ifdef GRAPHICS

		yellowTexture = new sf::Texture;
		yellowTexture->loadFromFile("gfx/yellow.png");
		yellowBall.setTexture(yellowTexture);

		greenTexture = new sf::Texture;
		greenTexture->loadFromFile("gfx/green.png");
		greenBall.setTexture(greenTexture);

		brownTexture = new sf::Texture;
		brownTexture->loadFromFile("gfx/brown.png");
		brownBall.setTexture(brownTexture);

		blueTexture = new sf::Texture;
		blueTexture->loadFromFile("gfx/blue.png");
		blueBall.setTexture(blueTexture);

		pinkTexture = new sf::Texture;
		pinkTexture->loadFromFile("gfx/pink.png");
		pinkBall.setTexture(pinkTexture);

		blackTexture = new sf::Texture;
		blackTexture->loadFromFile("gfx/black.png");
		blackBall.setTexture(blackTexture);

		redTexture = new sf::Texture;
		redTexture->loadFromFile("gfx/red.png");
		redBall1.setTexture(redTexture);
		redBall2.setTexture(redTexture);
		redBall3.setTexture(redTexture);
		redBall4.setTexture(redTexture);
		redBall5.setTexture(redTexture);
		redBall6.setTexture(redTexture);
		redBall7.setTexture(redTexture);
		redBall8.setTexture(redTexture);
		redBall9.setTexture(redTexture);
		redBall10.setTexture(redTexture);
		redBall11.setTexture(redTexture);
		redBall12.setTexture(redTexture);
		redBall13.setTexture(redTexture);
		redBall14.setTexture(redTexture);
		redBall15.setTexture(redTexture);
#endif

		//Table
		texture = new sf::Texture;
		texture->loadFromFile("gfx/table.png");
		table.setSize({ float(tableWidth), float(tableHeight) });
		table.setTexture(texture);
		table.setPosition({ tablePos.x, tablePos.y });

		//Red balls
		redBall1Object.create(radius, red1Pos.x, red1Pos.y, 1.0f, 0.90f);
		redBall2Object.create(radius, red2Pos.x, red2Pos.y, 1.0f, 0.90f);
		redBall3Object.create(radius, red3Pos.x, red3Pos.y, 1.0f, 0.90f);
		redBall4Object.create(radius, red4Pos.x, red4Pos.y, 1.0f, 0.90f);
		redBall5Object.create(radius, red5Pos.x, red5Pos.y, 1.0f, 0.90f);
		redBall6Object.create(radius, red6Pos.x, red6Pos.y, 1.0f, 0.90f);
		redBall7Object.create(radius, red7Pos.x, red7Pos.y, 1.0f, 0.90f);
		redBall8Object.create(radius, red8Pos.x, red8Pos.y, 1.0f, 0.90f);
		redBall9Object.create(radius, red9Pos.x, red9Pos.y, 1.0f, 0.90f);
		redBall10Object.create(radius, red10Pos.x, red10Pos.y, 1.0f, 0.90f);
		redBall11Object.create(radius, red11Pos.x, red11Pos.y, 1.0f, 0.90f);
		redBall12Object.create(radius, red12Pos.x, red12Pos.y, 1.0f, 0.90f);
		redBall13Object.create(radius, red13Pos.x, red13Pos.y, 1.0f, 0.90f);
		redBall14Object.create(radius, red14Pos.x, red14Pos.y, 1.0f, 0.90f);
		redBall15Object.create(radius, red15Pos.x, red15Pos.y, 1.0f, 0.90f);

		//Color balls
		whiteBallObject.create(radius, whitePos.x, whitePos.y, 1.0f, 0.90f);
		greenBallObject.create(radius, greenPos.x, greenPos.y, 1.0f, 0.90f);
		brownBallObject.create(radius, brownPos.x, brownPos.y, 1.0f, 0.90f);
		yellowBallObject.create(radius, yellowPos.x, yellowPos.y, 1.0f, 0.90f);
		blueBallObject.create(radius, bluePos.x, bluePos.y, 1.0f, 0.90f);
		pinkBallObject.create(radius, pinkPos.x, pinkPos.y, 1.0f, 0.90f);
		blackBallObject.create(radius, blackPos.x, blackPos.y, 1.0f, 0.90f);

		redBall1.setOrigin(redBall1.getRadius(), redBall1.getRadius());
		redBall2.setOrigin(redBall2.getRadius(), redBall2.getRadius());
		redBall3.setOrigin(redBall3.getRadius(), redBall3.getRadius());
		redBall4.setOrigin(redBall4.getRadius(), redBall4.getRadius());
		redBall5.setOrigin(redBall5.getRadius(), redBall5.getRadius());
		redBall6.setOrigin(redBall6.getRadius(), redBall6.getRadius());
		redBall7.setOrigin(redBall7.getRadius(), redBall7.getRadius());
		redBall8.setOrigin(redBall8.getRadius(), redBall8.getRadius());
		redBall9.setOrigin(redBall9.getRadius(), redBall9.getRadius());
		redBall10.setOrigin(redBall10.getRadius(), redBall10.getRadius());
		redBall11.setOrigin(redBall11.getRadius(), redBall11.getRadius());
		redBall12.setOrigin(redBall12.getRadius(), redBall12.getRadius());
		redBall13.setOrigin(redBall13.getRadius(), redBall13.getRadius());
		redBall14.setOrigin(redBall14.getRadius(), redBall14.getRadius());
		redBall15.setOrigin(redBall15.getRadius(), redBall15.getRadius());

		whiteBall.setOrigin(whiteBall.getRadius(), whiteBall.getRadius());
		greenBall.setOrigin(greenBall.getRadius(), greenBall.getRadius());
		brownBall.setOrigin(brownBall.getRadius(), brownBall.getRadius());
		yellowBall.setOrigin(yellowBall.getRadius(), yellowBall.getRadius());
		blueBall.setOrigin(blueBall.getRadius(), blueBall.getRadius());
		pinkBall.setOrigin(pinkBall.getRadius(), pinkBall.getRadius());
		blackBall.setOrigin(blackBall.getRadius(), blackBall.getRadius());

		
#ifdef GRAPHICS
		//color
#else
		redBall1.setFillColor(sf::Color::Red);
		redBall2.setFillColor(sf::Color::Red);
		redBall3.setFillColor(sf::Color::Red);
		redBall4.setFillColor(sf::Color::Red);
		redBall5.setFillColor(sf::Color::Red);
		redBall6.setFillColor(sf::Color::Red);
		redBall7.setFillColor(sf::Color::Red);
		redBall8.setFillColor(sf::Color::Red);
		redBall9.setFillColor(sf::Color::Red);
		redBall10.setFillColor(sf::Color::Red);
		redBall11.setFillColor(sf::Color::Red);
		redBall12.setFillColor(sf::Color::Red);
		redBall13.setFillColor(sf::Color::Red);
		redBall14.setFillColor(sf::Color::Red);
		redBall15.setFillColor(sf::Color::Red);
		greenBall.setFillColor(GreenDark);
		brownBall.setFillColor(Brown);
		yellowBall.setFillColor(sf::Color::Yellow);
		blueBall.setFillColor(sf::Color::Blue);
		pinkBall.setFillColor(Pink);
		blackBall.setFillColor(sf::Color::Black);
		whiteBall.setFillColor(sf::Color::White);
#endif

		//Walls
		p2d::Vec2f verticalWallSize = { wallThickness, tableHeight - 2.0f * holeDiameter };
		p2d::Vec2f horizontalWallSize = { (tableWidth - 3.0f * holeDiameter) / 2.0f, wallThickness };

		leftWall.setSize({ verticalWallSize.x, verticalWallSize.y });
		leftWall.setFillColor(GreenMid);
		leftWall.setOrigin(leftWall.getSize().x / 2.0f, leftWall.getSize().y / 2.0f);
		objectLeftWall.create(verticalWallSize.x , verticalWallSize.y, leftWallPos.x, leftWallPos.y, 1000.0f, 0.8f, true);
		
		rightWall.setSize({ verticalWallSize.x, verticalWallSize.y });
		rightWall.setFillColor(GreenMid);
		rightWall.setOrigin(rightWall.getSize().x / 2.0f, rightWall.getSize().y / 2.0f);
		objectRightWall.create(verticalWallSize.x, verticalWallSize.y, rightWallPos.x, rightWallPos.y, 1000.0f, 0.8f, true);

		topLeftWall.setSize({ horizontalWallSize.x, horizontalWallSize.y });
		topLeftWall.setOrigin(topLeftWall.getSize().x / 2.0f, topLeftWall.getSize().y / 2.0f);
		topLeftWall.setFillColor(GreenMid);
		objectTopLeftWall.create(horizontalWallSize.x, horizontalWallSize.y, topLeftWallPos.x, topLeftWallPos.y, 1000.0f, 0.8f, true);

		topRightWall.setSize({ horizontalWallSize.x, horizontalWallSize.y });
		topRightWall.setOrigin(topRightWall.getSize().x / 2.0f, topRightWall.getSize().y / 2.0f);
		topRightWall.setFillColor(GreenMid);
		objectTopRightWall.create(horizontalWallSize.x, horizontalWallSize.y, topRightWallPos.x, topRightWallPos.y, 1000.0f, 0.8f, true);
		
		bottomLeftWall.setSize({ horizontalWallSize.x, horizontalWallSize.y });
		bottomLeftWall.setOrigin(bottomLeftWall.getSize().x / 2.0f, bottomLeftWall.getSize().y / 2.0f);
		bottomLeftWall.setFillColor(GreenMid);
		objectBottomLeftWall.create(horizontalWallSize.x, horizontalWallSize.y, bottomLeftWallPos.x, bottomLeftWallPos.y, 1000.0f, 0.8f, true);
			
		bottomRightWall.setSize({ horizontalWallSize.x, horizontalWallSize.y });
		bottomRightWall.setOrigin(bottomRightWall.getSize().x / 2.0f, bottomRightWall.getSize().y / 2.0f);
		bottomRightWall.setFillColor(GreenMid);
		objectBottomRightWall.create(horizontalWallSize.x, horizontalWallSize.y, bottomRightWallPos.x, bottomRightWallPos.y, 1000.0f, 0.8f, true);
	
		


		//Capsule balls vertical
		capsuleLeft1.setRadius(wallThickness / 2.0f);
		capsuleLeft1.setOrigin(capsuleLeft1.getRadius(), capsuleLeft1.getRadius());
		capsuleLeft1.setFillColor(GreenMid);
		capsuleLeft1Object.create(wallThickness / 2.0f, leftWallPos.x, leftWallPos.y - verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		

		capsuleLeft2.setRadius(wallThickness / 2.0f);
		capsuleLeft2.setOrigin(capsuleLeft2.getRadius(), capsuleLeft2.getRadius());
		capsuleLeft2.setFillColor(GreenMid);
		capsuleLeft2Object.create(wallThickness / 2.0f, leftWallPos.x, leftWallPos.y + verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		

		capsuleRight1.setRadius(wallThickness / 2.0f);
		capsuleRight1.setOrigin(capsuleRight1.getRadius(), capsuleRight1.getRadius());
		capsuleRight1.setFillColor(GreenMid);
		capsuleRight1Object.create(wallThickness / 2.0f, rightWallPos.x, rightWallPos.y - verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		

		capsuleRight2.setRadius(wallThickness / 2.0f);
		capsuleRight2.setOrigin(capsuleRight2.getRadius(), capsuleRight2.getRadius());
		capsuleRight2.setFillColor(GreenMid);
		capsuleRight2Object.create(wallThickness / 2.0f, rightWallPos.x, rightWallPos.y + verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		

		//Capsule balls horizontal top
		capsuleTopLeft1.setRadius(wallThickness / 2.0f);
		capsuleTopLeft1.setOrigin(capsuleTopLeft1.getRadius(), capsuleTopLeft1.getRadius());
		capsuleTopLeft1.setFillColor(GreenMid);
		capsuleTopLeft1Object.create(wallThickness / 2.0f, topLeftWallPos.x - horizontalWallSize.x / 2.0f, topLeftWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleTopLeft2.setRadius(wallThickness / 2.0f);
		capsuleTopLeft2.setOrigin(capsuleTopLeft2.getRadius(), capsuleTopLeft2.getRadius());
		capsuleTopLeft2.setFillColor(GreenMid);
		capsuleTopLeft2Object.create(wallThickness / 2.0f, topLeftWallPos.x + horizontalWallSize.x / 2.0f, topLeftWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleTopRight1.setRadius(wallThickness / 2.0f);
		capsuleTopRight1.setOrigin(capsuleTopRight1.getRadius(), capsuleTopRight1.getRadius());
		capsuleTopRight1.setFillColor(GreenMid);
		capsuleTopRight1Object.create(wallThickness / 2.0f, topRightWallPos.x - horizontalWallSize.x / 2.0f, topRightWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleTopRight2.setRadius(wallThickness / 2.0f);
		capsuleTopRight2.setOrigin(capsuleTopRight2.getRadius(), capsuleTopRight2.getRadius());
		capsuleTopRight2.setFillColor(GreenMid);
		capsuleTopRight2Object.create(wallThickness / 2.0f, topRightWallPos.x + horizontalWallSize.x / 2.0f, topRightWallPos.y, 1000.0f, 0.90f, true);
		

		//Capsule balls horizontal bottom
		capsuleBottomLeft1.setRadius(wallThickness / 2.0f);
		capsuleBottomLeft1.setOrigin(capsuleBottomLeft1.getRadius(), capsuleBottomLeft1.getRadius());
		capsuleBottomLeft1.setFillColor(GreenMid);
		capsuleBottomLeft1Object.create(wallThickness / 2.0f, bottomLeftWallPos.x - horizontalWallSize.x / 2.0f, bottomLeftWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleBottomLeft2.setRadius(wallThickness / 2.0f);
		capsuleBottomLeft2.setOrigin(capsuleBottomLeft2.getRadius(), capsuleBottomLeft2.getRadius());
		capsuleBottomLeft2.setFillColor(GreenMid);
		capsuleBottomLeft2Object.create(wallThickness / 2.0f, bottomLeftWallPos.x + horizontalWallSize.x / 2.0f, bottomLeftWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleBottomRight1.setRadius(wallThickness / 2.0f);
		capsuleBottomRight1.setOrigin(capsuleBottomRight1.getRadius(), capsuleBottomRight1.getRadius());
		capsuleBottomRight1.setFillColor(GreenMid);
		capsuleBottomRight1Object.create(wallThickness / 2.0f, bottomRightWallPos.x - horizontalWallSize.x / 2.0f, bottomRightWallPos.y, 1000.0f, 0.90f, true);
		

		capsuleBottomRight2.setRadius(wallThickness / 2.0f);
		capsuleBottomRight2.setOrigin(capsuleBottomRight2.getRadius(), capsuleBottomRight2.getRadius());
		capsuleBottomRight2.setFillColor(GreenMid);
		capsuleBottomRight2Object.create(wallThickness / 2.0f, bottomRightWallPos.x + horizontalWallSize.x / 2.0f, bottomRightWallPos.y, 1000.0f, 0.90f, true);
		

		resetTable();

		bufferCollide.loadFromFile("sound/collide.wav");
		soundCollide.setBuffer(bufferCollide);

		physics.add(&redBall1Object);
		physics.add(&redBall2Object);
		physics.add(&redBall3Object);
		physics.add(&redBall4Object);
		physics.add(&redBall5Object);
		physics.add(&redBall6Object);
		physics.add(&redBall7Object);
		physics.add(&redBall8Object);
		physics.add(&redBall9Object);
		physics.add(&redBall10Object);
		physics.add(&redBall11Object);
		physics.add(&redBall12Object);
		physics.add(&redBall13Object);
		physics.add(&redBall14Object);
		physics.add(&redBall15Object);
		physics.add(&greenBallObject);
		physics.add(&brownBallObject);
		physics.add(&yellowBallObject);
		physics.add(&blueBallObject);
		physics.add(&pinkBallObject);
		physics.add(&blackBallObject);
		physics.add(&whiteBallObject);

		physics.add(&objectLeftWall);
		physics.add(&objectRightWall);
		physics.add(&objectTopLeftWall);
		physics.add(&objectTopRightWall);
		physics.add(&objectBottomLeftWall);
		physics.add(&objectBottomRightWall);

		physics.add(&capsuleLeft1Object);
		physics.add(&capsuleLeft2Object);
		physics.add(&capsuleRight1Object);
		physics.add(&capsuleRight2Object);

		physics.add(&capsuleTopLeft1Object);
		physics.add(&capsuleTopLeft2Object);
		physics.add(&capsuleTopRight1Object);
		physics.add(&capsuleTopRight2Object);

		physics.add(&capsuleBottomLeft1Object);
		physics.add(&capsuleBottomLeft2Object);
		physics.add(&capsuleBottomRight1Object);
		physics.add(&capsuleBottomRight2Object);

		physics.setOnCollision(onCollision);

		mouse.init(&window, &physics, screenWidth, screenHeight);
		/*
		mouse.add(&redBall1Object);
		mouse.add(&redBall2Object);
		mouse.add(&redBall3Object);
		mouse.add(&redBall4Object);
		mouse.add(&redBall5Object);
		mouse.add(&redBall6Object);
		mouse.add(&redBall7Object);
		mouse.add(&redBall8Object);
		mouse.add(&redBall9Object);
		mouse.add(&redBall10Object);
		mouse.add(&redBall11Object);
		mouse.add(&redBall12Object);
		mouse.add(&redBall13Object);
		mouse.add(&redBall14Object);
		mouse.add(&redBall15Object);
		mouse.add(&greenBallObject);
		mouse.add(&brownBallObject);
		mouse.add(&yellowBallObject);
		mouse.add(&blueBallObject);
		mouse.add(&pinkBallObject);
		mouse.add(&blackBallObject);
		*/
		mouse.add(&whiteBallObject);
		//mouse.add(&objectLeftWall);
		//mouse.add(&objectRightWall);
		//mouse.add(&objectTopLeftWall);
		//mouse.add(&objectTopRightWall);
		//mouse.add(&objectBottomLeftWall);
		//mouse.add(&objectBottomRightWall);

		//mouse.add(&capsuleLeft1Object);
		//mouse.add(&capsuleLeft2Object);
		//mouse.add(&capsuleRight1Object);
		//mouse.add(&capsuleRight2Object);

		//mouse.add(&capsuleTopLeft1Object);
		//mouse.add(&capsuleTopLeft2Object);
		//mouse.add(&capsuleTopRight1Object);
		//mouse.add(&capsuleTopRight2Object);

		//mouse.add(&capsuleBottomLeft1Object);
		//mouse.add(&capsuleBottomLeft2Object);
		//mouse.add(&capsuleBottomRight1Object);
		//mouse.add(&capsuleBottomRight2Object);

		initText();

		run();
	}

	void initText() {
		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "Cannot load font!" << std::endl;
		}

		text.setFont(font);
		text.setString("READY");
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Green);
		text.setStyle(sf::Text::Bold);
		text.setScale(3.0f, 3.0f);
		text.setPosition(tablePos.x, tablePos.y + tableHeight);

		text2.setFont(font);
		text2.setString("SCORE 0");
		text2.setCharacterSize(24);
		text2.setFillColor(sf::Color::Green);
		text2.setStyle(sf::Text::Bold);
		text2.setScale(3.0f, 3.0f);
		text2.setPosition(tablePos.x + tableWidth - text2.getGlobalBounds().width, tablePos.y + tableHeight);
		
	}

	void updateTextNumber(std::string str, int data) {
		std::string s = std::to_string(data);
		text2.setString(str + s);
		text2.setPosition(tablePos.x + tableWidth - text2.getGlobalBounds().width, tablePos.y + tableHeight);
	}

	void updateText(std::string str) {
		text.setString(str);
	}

	void resetTable() {
		whiteBallObject.reset();
		whiteBallObject.setPosition(whitePos);
		redBall1Object.reset();
		redBall1Object.setPosition(red1Pos);
		redBall2Object.reset();
		redBall2Object.setPosition(red2Pos);
		redBall3Object.reset();
		redBall3Object.setPosition(red3Pos);
		redBall4Object.reset();
		redBall4Object.setPosition(red4Pos);
		redBall5Object.reset();
		redBall5Object.setPosition(red5Pos);
		redBall6Object.reset();
		redBall6Object.setPosition(red6Pos);
		redBall7Object.reset();
		redBall7Object.setPosition(red7Pos);
		redBall8Object.reset();
		redBall8Object.setPosition(red8Pos);
		redBall9Object.reset();
		redBall9Object.setPosition(red9Pos);
		redBall10Object.reset();
		redBall10Object.setPosition(red10Pos);
		redBall11Object.reset();
		redBall11Object.setPosition(red11Pos);
		redBall12Object.reset();
		redBall12Object.setPosition(red12Pos);
		redBall13Object.reset();
		redBall13Object.setPosition(red13Pos);
		redBall14Object.reset();
		redBall14Object.setPosition(red14Pos);
		redBall15Object.reset();
		redBall15Object.setPosition(red15Pos);
		greenBallObject.reset();
		greenBallObject.setPosition(greenPos);
		brownBallObject.reset();
		brownBallObject.setPosition(brownPos);
		yellowBallObject.reset();
		yellowBallObject.setPosition(yellowPos);
		blueBallObject.reset();
		blueBallObject.setPosition(bluePos);
		pinkBallObject.reset();
		pinkBallObject.setPosition(pinkPos);
		blackBallObject.reset();
		blackBallObject.setPosition(blackPos);

		pot1 = false;
		pot2 = false;
		pot3 = false;
		pot4 = false;
		pot5 = false;
		pot6 = false;
		pot7 = false;
		pot8 = false;
		pot9 = false;
		pot10 = false;
		pot11 = false;
		pot12 = false;
		pot13 = false;
		pot14 = false;
		pot15 = false;
		redComplete = false;

		potGreen = false;
		potYellow = false;
		potBrown = false;
		potBlue = false;
		potPink = false;
		potBlack = false;

		points = 0;
	}

	void gameLogic() {
		
		holesCheck(&whiteBallObject, whitePos);
		
		p2d::Vec2f v = { 0.0f, -1000.0f };
		if (redComplete) {
			if (holesCheck(&yellowBallObject, v)) { potYellow = true; points += 2;}
			if (holesCheck(&greenBallObject, v)) { 
				points += 3;
				if (!potYellow) { greenBallObject.setPosition(greenPos); }
				else { potGreen = true; }
			}
			if (holesCheck(&brownBallObject, v)) {
				points += 4;
				if (!(potYellow && potGreen)) { brownBallObject.setPosition(brownPos); }
				else { potBrown = true; }
			} 
			if (holesCheck(&blueBallObject, v)) {
				points += 5;
				if (!(potYellow && potGreen && potBrown)) { blueBallObject.setPosition(bluePos); }
				else { potBlue = true; }
			}
			if (holesCheck(&pinkBallObject, v)) {
				points += 6;
				if (!(potYellow && potGreen && potBrown && potBlue)) { pinkBallObject.setPosition(pinkPos); }
				else { potPink = true; }
			}
			if (holesCheck(&blackBallObject, v)) {
				points += 7;
				if (!(potYellow && potGreen && potBrown && potBlue && potPink)) { blackBallObject.setPosition(blackPos); }
				else { potBlack = true; }
			}

		}
		else {
			if (holesCheck(&yellowBallObject, yellowPos)) { points+=2; }
			if (holesCheck(&brownBallObject, brownPos)) { points+=3; }
			if (holesCheck(&greenBallObject, greenPos)) { points+=4; }
			if (holesCheck(&blueBallObject, bluePos)) { points+=5; }
			if (holesCheck(&pinkBallObject, pinkPos)) { points+=6; }
			if (holesCheck(&blackBallObject, blackPos)) { points+=7; }
		}

		if (holesCheck(&redBall1Object, v)) { pot1 = true; points++; }
		if (holesCheck(&redBall2Object, v)) { pot2 = true; points++; }
		if (holesCheck(&redBall3Object, v)) { pot3 = true; points++; }
		if (holesCheck(&redBall4Object, v)) { pot4 = true; points++; }
		if (holesCheck(&redBall5Object, v)) { pot5 = true; points++; }
		if (holesCheck(&redBall6Object, v)) { pot6 = true; points++; }
		if (holesCheck(&redBall7Object, v)) { pot7 = true; points++; }
		if (holesCheck(&redBall8Object, v)) { pot8 = true; points++; }
		if (holesCheck(&redBall9Object, v)) { pot9 = true; points++; }
		if (holesCheck(&redBall10Object, v)) { pot10 = true; points++; }
		if (holesCheck(&redBall11Object, v)) { pot11 = true; points++; }
		if (holesCheck(&redBall12Object, v)) { pot12 = true; points++; }
		if (holesCheck(&redBall13Object, v)) { pot13 = true; points++; }
		if (holesCheck(&redBall14Object, v)) { pot14 = true; points++; }
		if (holesCheck(&redBall15Object, v)) { pot15 = true; points++; }
		
		if (pot1 && pot2 && pot3 && pot4 && pot5 && pot6 && pot7 && pot8 && pot9 && pot10 && pot11 && pot12 && pot13 && pot14 && pot15) {
			redComplete = true;
		}

		
	}

	void update(double dt) {
		
		if (physics.atRest()) {
			//mouse.setImpulseReady();
			text.setString("READY");
			text.setFillColor(sf::Color::Green);
		}
		else {
			text.setString("WAIT...");
			text.setFillColor(sf::Color::Red);
		}

		updateTextNumber("SCORE ", points);

		gameLogic();
		if (physics.collisionCheck()) {
		    soundCollide.play();
		}
		physics.update(dt);
		mouse.update();
	}

	bool holesCheck(p2d::Body* o, p2d::Vec2f v) {
		if (o->getPosition().y < -500.0f) {
			return false;
		}
		
		//middles
		if (o->getPosition().x > screenWidth / 2.0f - holeDiameter / 7.0f && o->getPosition().x < screenWidth / 2.0f + holeDiameter / 7.0f) {
			if (o->getPosition().y < tablePos.y + holeDiameter /3.0f || o->getPosition().y > tablePos.y + tableHeight - holeDiameter/3.0f) {
				o->reset(v);
				return true;
			}
		}
		//sides
		if (o->getPosition().x < tablePos.x + holeDiameter / 2.0f || o->getPosition().x > tablePos.x +tableWidth - holeDiameter / 2.0f) {
			if (o->getPosition().y < tablePos.y + holeDiameter / 2.0f || o->getPosition().y > tablePos.y + tableHeight - holeDiameter / 2.0f) {
				o->reset(v);
				return true;
			}
		}
		return false;
	}

	void draw() {

		window.draw(table);
		
		redBall1.setPosition(redBall1Object.getPosition().x, redBall1Object.getPosition().y);
		window.draw(redBall1);
		
		redBall2.setPosition(redBall2Object.getPosition().x, redBall2Object.getPosition().y);
		window.draw(redBall2);
		
		redBall3.setPosition(redBall3Object.getPosition().x, redBall3Object.getPosition().y);
		window.draw(redBall3);
		
		redBall4.setPosition(redBall4Object.getPosition().x, redBall4Object.getPosition().y);
		window.draw(redBall4);
		
		redBall5.setPosition(redBall5Object.getPosition().x, redBall5Object.getPosition().y);
		window.draw(redBall5);
	
		redBall6.setPosition(redBall6Object.getPosition().x, redBall6Object.getPosition().y);
		window.draw(redBall6);
		
		redBall7.setPosition(redBall7Object.getPosition().x, redBall7Object.getPosition().y);
		window.draw(redBall7);
		
		redBall8.setPosition(redBall8Object.getPosition().x, redBall8Object.getPosition().y);
		window.draw(redBall8);
		
		redBall9.setPosition(redBall9Object.getPosition().x, redBall9Object.getPosition().y);
		window.draw(redBall9);
		
		redBall10.setPosition(redBall10Object.getPosition().x, redBall10Object.getPosition().y);
		window.draw(redBall10);
		
		redBall11.setPosition(redBall11Object.getPosition().x, redBall11Object.getPosition().y);
		window.draw(redBall11);
		
		redBall12.setPosition(redBall12Object.getPosition().x, redBall12Object.getPosition().y);
		window.draw(redBall12);
		
		redBall13.setPosition(redBall13Object.getPosition().x, redBall13Object.getPosition().y);
		window.draw(redBall13);
		
		redBall14.setPosition(redBall14Object.getPosition().x, redBall14Object.getPosition().y);
		window.draw(redBall14);
		
		redBall15.setPosition(redBall15Object.getPosition().x, redBall15Object.getPosition().y);
		window.draw(redBall15);
		
		greenBall.setPosition(greenBallObject.getPosition().x, greenBallObject.getPosition().y);
		window.draw(greenBall);
		
		brownBall.setPosition(brownBallObject.getPosition().x, brownBallObject.getPosition().y);
		window.draw(brownBall);
		
		yellowBall.setPosition(yellowBallObject.getPosition().x, yellowBallObject.getPosition().y);
		window.draw(yellowBall);
		
		blueBall.setPosition(blueBallObject.getPosition().x, blueBallObject.getPosition().y);
		window.draw(blueBall);
		
		pinkBall.setPosition(pinkBallObject.getPosition().x, pinkBallObject.getPosition().y);
		window.draw(pinkBall);
		
		blackBall.setPosition(blackBallObject.getPosition().x, blackBallObject.getPosition().y);
		window.draw(blackBall);
		
		whiteBall.setPosition(whiteBallObject.getPosition().x, whiteBallObject.getPosition().y);
		window.draw(whiteBall);

		/*
		objectLeftWall.draw();
		objectRightWall.draw();
		objectTopLeftWall.draw();
		objectTopRightWall.draw();
		objectBottomLeftWall.draw();
		objectBottomRightWall.draw();

		capsuleLeft1Object.draw();
		capsuleLeft2Object.draw();
		capsuleRight1Object.draw();
		capsuleRight2Object.draw();

		capsuleTopLeft1Object.draw();
		capsuleTopLeft2Object.draw();
		capsuleTopRight1Object.draw();
		capsuleTopRight2Object.draw();

		capsuleBottomLeft1Object.draw();
		capsuleBottomLeft2Object.draw();
		capsuleBottomRight1Object.draw();
		capsuleBottomRight2Object.draw();
		*/
		
		window.draw(text);
		window.draw(text2);
	}

	static void onCollision() {
		//std::cout << "Test!" << std::endl;
	}

	void run() {

		sf::Music music;
		if (!music.openFromFile("sound/music.ogg"))
			std::cout << "Cannot open music.ogg" << std::endl;
		music.setLoop(true);
		//music.play();

		auto timePrev = std::chrono::steady_clock::now();

		while (window.isOpen()) {

			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				resetTable();
			}

			window.clear();

			auto timeNow = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = timeNow - timePrev;
			double dt = elapsed_seconds.count();
			timePrev = timeNow;

			update(dt);
			draw();

			window.display();

		}
	}

	~Snooker() {
		delete texture;
		delete redTexture;
		delete yellowTexture;
		delete greenTexture;
		delete brownTexture;
		delete blueTexture;
		delete pinkTexture;
		delete blackTexture;
	}
};

#endif