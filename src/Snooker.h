#ifndef SNOOKER_H
#define SNOOKER_H

//#define GRAPHICS
#define USE_CUE

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include "Physics.h"
#include "Mouse.h"
#include "Snooker.h"

class Snooker {
private:
	const int screenWidth = 1920;
	const int screenHeight = 1080;
	sf::RenderWindow window;
	p2d::Physics physics;
	Mouse mouse;

	sf::Color Pink{ 255, 105, 180 };
	sf::Color Brown{ 139, 69, 19 };
	sf::Color GreenDark{ 0, 100, 0 };
	sf::Color GreenMid{ 0, 180, 0 };

	p2d::Vec2f tablePos;
	float tableGap, tableWidth, tableHeight;
	float radius;
	float redX, redY;
	float dx, dy;
	float fix;
	float PI;
	float wallThickness;
	float holeDiameter;
	p2d::Vec2f verticalWallSize;
	p2d::Vec2f horizontalWallSize;

	sf::Texture* texture;
	sf::RectangleShape table;

	sf::Texture* cueTexture;
	sf::RectangleShape cueShape;

	//Balls: red 1-15, yellow, green, brown, blue, pink, black, white (total = 22)
	std::vector<sf::CircleShape> ball_shape;
	std::vector<p2d::CircleBody> ball_body;
	std::vector<p2d::Vec2f> ball_pos;
	std::vector<sf::Texture*> ball_texture;

	//Walls: left, right, topLeft, topRight, bottomLeft, bottomRight (total = 6)
	std::vector<sf::RectangleShape> wall_shape;
	std::vector<p2d::RectangleBody> wall_body;
	std::vector<p2d::Vec2f> wall_pos;

	//Capsules: verticalLeft1-2, verticalRight1-2, topLeft1-2, topRight1-2, bottomLeft1-2, bottomRight1-2 (total = 12) 
	std::vector<sf::CircleShape> capsule_shape;
	std::vector<p2d::CircleBody> capsule_body;

	//potting logic: red 1-15, yellow, green, brown, blue, pink, black, white, redComplete (total = 23)
	std::vector<bool> pot;
	int points = 0;
	int goesPrev = 0;
	int goes = 0;

	sf::SoundBuffer bufferCollide;
	sf::Sound soundCollide;
	sf::Text textLeft;
	sf::Text textRight;
	sf::Font font;

	static constexpr int RED = 14;
	static constexpr int YELLOW = 15;
	static constexpr int GREEN = 16;
	static constexpr int BROWN = 17;
	static constexpr int BLUE = 18;
	static constexpr int PINK = 19;
	static constexpr int BLACK = 20;
	static constexpr int WHITE = 21;

	bool waiting = false;

public:

	Snooker() {

		window.create(sf::VideoMode(screenWidth, screenHeight), "SifuF Snooker");

		tableGap = float(screenWidth) / 10.0f;
		tableWidth = float(screenWidth) - tableGap;
		tableHeight = float(screenHeight) - tableGap;
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
		verticalWallSize = { wallThickness, tableHeight - 2.0f * holeDiameter };
		horizontalWallSize = { (tableWidth - 3.0f * holeDiameter) / 2.0f, wallThickness };

		for (int i = 0; i < 23; i++) {
			pot.push_back(false);
		}

		ball_pos.push_back({ redX, redY });
		ball_pos.push_back({ redX + dx * 2.0f * radius + fix, redY - 1.0f * radius - fix });
		ball_pos.push_back({ redX + dx * 2.0f * radius + fix, redY + 1.0f * radius + fix });
		ball_pos.push_back({ redX + dx * 4.0f * radius + (2.0f * fix), redY - 2.0f * radius - (2.0f * fix) });
		ball_pos.push_back({ redX + dx * 4.0f * radius + (2.0f * fix), redY });
		ball_pos.push_back({ redX + dx * 4.0f * radius + (2.0f * fix), redY + 2.0f * radius + (2.0f * fix) });
		ball_pos.push_back({ redX + dx * 6.0f * radius + (3.0f * fix), redY - 3.0f * radius - (2.0f * fix) });
		ball_pos.push_back({ redX + dx * 6.0f * radius + (3.0f * fix), redY + -1.0f * radius - (1.0f * fix) });
		ball_pos.push_back({ redX + dx * 6.0f * radius + (3.0f * fix), redY + +1.0f * radius + (1.0f * fix) });
		ball_pos.push_back({ redX + dx * 6.0f * radius + (3.0f * fix), redY + 3.0f * radius + (2.0f * fix) });
		ball_pos.push_back({ redX + dx * 8.0f * radius + (4.0f * fix), redY - 4.0f * radius - (2.0f * fix) });
		ball_pos.push_back({ redX + dx * 8.0f * radius + (4.0f * fix), redY - 2.0f * radius - (1.0f * fix) });
		ball_pos.push_back({ redX + dx * 8.0f * radius + (4.0f * fix), redY });
		ball_pos.push_back({ redX + dx * 8.0f * radius + (4.0f * fix), redY + 2.0f * radius + (1.0f * fix) });
		ball_pos.push_back({ redX + dx * 8.0f * radius + (4.0f * fix), redY + 4.0f * radius + (2.0f * fix) });
		ball_pos.push_back({ tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight * 2 / 3.0f });
		ball_pos.push_back({ tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight / 3.0f });
		ball_pos.push_back({ tablePos.x + tableWidth / 5.0f, tablePos.y + tableHeight * 1.5f / 3.0f });
		ball_pos.push_back({ tablePos.x + tableWidth / 2.0f, tablePos.y + tableHeight / 2.0f });
		ball_pos.push_back({ tablePos.x + tableWidth * 3.0f / 4.0f, tablePos.y + tableHeight / 2.0f });
		ball_pos.push_back({ tablePos.x + tableWidth * 10.0f / 11.0f, tablePos.y + tableHeight / 2.0f });
		ball_pos.push_back({ tablePos.x + tableWidth / 10.0f + 50.0f, tablePos.y + tableHeight * 1.5f / 3.0f });

		wall_pos.push_back({ tablePos.x + wallThickness / 2.0f, tablePos.y + tableHeight / 2.0f });
		wall_pos.push_back({ tablePos.x + tableWidth - wallThickness / 2.0f, tablePos.y + tableHeight / 2.0f });
		wall_pos.push_back({ tablePos.x + (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + wallThickness / 2.0f });
		wall_pos.push_back({ tablePos.x + tableWidth - (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + wallThickness / 2.0f });
		wall_pos.push_back({ tablePos.x + (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + tableHeight - wallThickness / 2.0f });
		wall_pos.push_back({ tablePos.x + tableWidth - (tableWidth / 2.0f + holeDiameter / 2.0f) / 2.0f, tablePos.y + tableHeight - wallThickness / 2.0f });

		//Table
		texture = new sf::Texture;
		if (!texture->loadFromFile("gfx/table.png"))
			std::cout << "failed to load table.png" << std::endl;
		table.setSize({ float(tableWidth), float(tableHeight) });
		table.setTexture(texture);
		table.setPosition({ tablePos.x, tablePos.y });

		//Cue
		cueTexture = new sf::Texture;
		if(!cueTexture->loadFromFile("gfx/cue.png"))
			std::cout << "failed to load cue.png" << std::endl;
		cueShape.setSize({ float(tableWidth)/2.0f, float(tableHeight)/40.0f });
		cueShape.setTexture(cueTexture);
		cueShape.setPosition({ tablePos.x + 100.0f, tablePos.y + 100.0f });

		//Balls
		for (int i = 0; i < 22; i++) {
			sf::CircleShape s;
			ball_shape.push_back(s);
			ball_shape[i].setRadius(radius);
			ball_shape[i].setOrigin(radius, radius);
			p2d::CircleBody b;
			ball_body.push_back(b);
			ball_body[i].create(radius, ball_pos[i].x, ball_pos[i].y, 1.0f, 0.90f);
			if (i < 15) {
				ball_shape[i].setFillColor(sf::Color::Red);
			}
		}
		ball_shape[15].setFillColor(sf::Color::Yellow);
		ball_shape[16].setFillColor(GreenDark);
		ball_shape[17].setFillColor(Brown);
		ball_shape[18].setFillColor(sf::Color::Blue);
		ball_shape[19].setFillColor(Pink);
		ball_shape[20].setFillColor(sf::Color::Black);
		ball_shape[21].setFillColor(sf::Color::White);

#ifdef GRAPHICS

		for (int i = 0; i < 22; i++) {
			ball_shape[i].setFillColor(sf::Color::White);
		}

		for (int i = 0; i < 8; i++) {
			ball_texture.push_back(new sf::Texture);
		}

		ball_texture[0]->loadFromFile("gfx/red.png");
		for (int i = 0; i < 15; i++) {
			ball_shape[i].setTexture(ball_texture[0]);
		}

		ball_texture[1]->loadFromFile("gfx/yellow.png");
		ball_shape[15].setTexture(ball_texture[1]);
		ball_texture[2]->loadFromFile("gfx/green.png");
		ball_shape[16].setTexture(ball_texture[2]);
		ball_texture[3]->loadFromFile("gfx/brown.png");
		ball_shape[17].setTexture(ball_texture[3]);
		ball_texture[4]->loadFromFile("gfx/blue.png");
		ball_shape[18].setTexture(ball_texture[4]);
		ball_texture[5]->loadFromFile("gfx/pink.png");
		ball_shape[19].setTexture(ball_texture[5]);
		ball_texture[6]->loadFromFile("gfx/black.png");
		ball_shape[20].setTexture(ball_texture[6]);
		ball_texture[7]->loadFromFile("gfx/white.png");
		ball_shape[21].setTexture(ball_texture[7]);

#endif

		//Walls
		for (int i = 0; i < 6; i++) {
			sf::RectangleShape s;
			wall_shape.push_back(s);
			p2d::RectangleBody b;
			wall_body.push_back(b);
			if (i < 2) {
				wall_shape[i].setSize({ verticalWallSize.x, verticalWallSize.y });
				wall_body[i].create(verticalWallSize.x, verticalWallSize.y, wall_pos[i].x, wall_pos[i].y, 1000.0f, 0.8f, true);
			}
			else {
				wall_shape[i].setSize({ horizontalWallSize.x, horizontalWallSize.y });
				wall_body[i].create(horizontalWallSize.x, horizontalWallSize.y, wall_pos[i].x, wall_pos[i].y, 1000.0f, 0.8f, true);
			}
			wall_shape[i].setOrigin(wall_shape[i].getSize().x / 2.0f, wall_shape[i].getSize().y / 2.0f);
			wall_shape[i].setFillColor(GreenMid);
		}

		//Capsule balls
		for (int i = 0; i < 12; i++) {
			sf::CircleShape s;
			capsule_shape.push_back(s);
			capsule_shape[i].setRadius(wallThickness / 2.0f);
			capsule_shape[i].setOrigin(capsule_shape[i].getRadius(), capsule_shape[i].getRadius());
			capsule_shape[i].setFillColor(GreenMid);

			p2d::CircleBody b;
			capsule_body.push_back(b);
		}
		capsule_body[0].create(wallThickness / 2.0f, wall_pos[0].x, wall_pos[0].y - verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		capsule_body[1].create(wallThickness / 2.0f, wall_pos[0].x, wall_pos[0].y + verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		capsule_body[2].create(wallThickness / 2.0f, wall_pos[1].x, wall_pos[1].y - verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		capsule_body[3].create(wallThickness / 2.0f, wall_pos[1].x, wall_pos[1].y + verticalWallSize.y / 2.0f, 1000.0f, 0.90f, true);
		capsule_body[4].create(wallThickness / 2.0f, wall_pos[2].x - horizontalWallSize.x / 2.0f, wall_pos[2].y, 1000.0f, 0.90f, true);
		capsule_body[5].create(wallThickness / 2.0f, wall_pos[2].x + horizontalWallSize.x / 2.0f, wall_pos[2].y, 1000.0f, 0.90f, true);
		capsule_body[6].create(wallThickness / 2.0f, wall_pos[3].x - horizontalWallSize.x / 2.0f, wall_pos[3].y, 1000.0f, 0.90f, true);
		capsule_body[7].create(wallThickness / 2.0f, wall_pos[3].x + horizontalWallSize.x / 2.0f, wall_pos[3].y, 1000.0f, 0.90f, true);
		capsule_body[8].create(wallThickness / 2.0f, wall_pos[4].x - horizontalWallSize.x / 2.0f, wall_pos[4].y, 1000.0f, 0.90f, true);
		capsule_body[9].create(wallThickness / 2.0f, wall_pos[4].x + horizontalWallSize.x / 2.0f, wall_pos[4].y, 1000.0f, 0.90f, true);
		capsule_body[10].create(wallThickness / 2.0f, wall_pos[5].x - horizontalWallSize.x / 2.0f, wall_pos[5].y, 1000.0f, 0.90f, true);
		capsule_body[11].create(wallThickness / 2.0f, wall_pos[5].x + horizontalWallSize.x / 2.0f, wall_pos[5].y, 1000.0f, 0.90f, true);

		//Physics
		for (p2d::CircleBody& b : ball_body) {
			physics.add(&b);
		}
		for (p2d::RectangleBody& b : wall_body) {
			physics.add(&b);
		}
		for (p2d::CircleBody& b : capsule_body) {
			physics.add(&b);
		}
		physics.setGravity({ 0.0f, 0.0f });
		physics.setDrag({ 0.2f, 0.0001f });
		physics.setOnCollision(onCollision);

		mouse.init(&window, &physics, screenWidth, screenHeight);
		mouse.add(&ball_body[21]);

		bufferCollide.loadFromFile("sound/collide.wav");
		soundCollide.setBuffer(bufferCollide);

		initText();

		run();
	}

	void initText() {

		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "Cannot load font!" << std::endl;
		}

		textLeft.setFont(font);
		textLeft.setString("READY");
		textLeft.setCharacterSize(24);
		textLeft.setFillColor(sf::Color::Green);
		textLeft.setStyle(sf::Text::Bold);
		textLeft.setScale(3.0f, 3.0f);
		textLeft.setPosition(tablePos.x, tablePos.y + tableHeight);

		textRight.setFont(font);
		textRight.setString("SCORE 0");
		textRight.setCharacterSize(24);
		textRight.setFillColor(sf::Color::Green);
		textRight.setStyle(sf::Text::Bold);
		textRight.setScale(3.0f, 3.0f);
		textRight.setPosition(tablePos.x + tableWidth - textRight.getGlobalBounds().width, tablePos.y + tableHeight);
	}
	
	void updateText(std::string str) {
		textLeft.setString(str);
	}

	void updateTextNumber(std::string str, int data) {
		std::string s = std::to_string(data);
		textRight.setString(str + s);
		textRight.setPosition(tablePos.x + tableWidth - textRight.getGlobalBounds().width, tablePos.y + tableHeight);
	}

	void resetTable() {

		for (int i = 0; i < 22; i++) {
			ball_body[i].reset();
			ball_body[i].setPosition(ball_pos[i]);
		}

		for (int i = 0; i < 23; i++) {
			pot[i] = false;
		}

		points = 0;
	}

	void gameLogic() {

		holesCheck(&ball_body[WHITE], ball_pos[WHITE]);
		
		p2d::Vec2f v = { 0.0f, -1000.0f };
		if (pot[22]) {
			if (holesCheck(&ball_body[YELLOW], v)) { pot[YELLOW] = true; points += 2; }
			if (holesCheck(&ball_body[GREEN], v)) {
				points += 3;
				if (!pot[YELLOW]) { ball_body[GREEN].setPosition(ball_pos[GREEN]); }
				else { pot[GREEN] = true; }
			}
			if (holesCheck(&ball_body[BROWN], v)) {
				points += 4;
				if (!(pot[YELLOW] && pot[GREEN])) { ball_body[BROWN].setPosition(ball_pos[BROWN]); }
				else { pot[BROWN] = true; }
			} 
			if (holesCheck(&ball_body[BLUE], v)) {
				points += 5;
				if (!(pot[YELLOW] && pot[GREEN] && pot[BROWN])) { ball_body[BLUE].setPosition(ball_pos[BLUE]); }
				else { pot[BLUE] = true; }
			}
			if (holesCheck(&ball_body[PINK], v)) {
				points += 6;
				if (!(pot[YELLOW] && pot[GREEN] && pot[BROWN] && pot[BLUE])) { ball_body[PINK].setPosition(ball_pos[PINK]); }
				else { pot[PINK] = true; }
			}
			if (holesCheck(&ball_body[BLACK], v)) {
				points += 7;
				if (!(pot[YELLOW] && pot[GREEN] && pot[BROWN] && pot[BLUE] && pot[PINK])) { ball_body[BLACK].setPosition(ball_pos[BLACK]); }
				else { pot[BLACK] = true; }
			}
		}
		else {
			if (holesCheck(&ball_body[YELLOW], ball_pos[YELLOW])) { points += 2; }
			if (holesCheck(&ball_body[GREEN], ball_pos[GREEN])) { points += 3; }
			if (holesCheck(&ball_body[BROWN], ball_pos[BROWN])) { points+=4; }
			if (holesCheck(&ball_body[BLUE], ball_pos[BLUE])) { points+=5; }
			if (holesCheck(&ball_body[PINK], ball_pos[PINK])) { points+=6; }
			if (holesCheck(&ball_body[BLACK], ball_pos[BLACK])) { points+=7; }
		}

		pot[22] = true;
		for (int i = 0; i < 15; i++) {
			if (holesCheck(&ball_body[i], v)) { 
				pot[i] = true; points++; 
			}
			pot[22] = pot[22] && pot[i];
		}

	}

	void update(double dt) {
		
		if (physics.atRest()) {
			mouse.setImpulseReady();
			textLeft.setString("READY");
			textLeft.setFillColor(sf::Color::Green);
			waiting = false;
		}
		else {
			textLeft.setString("WAIT...");
			textLeft.setFillColor(sf::Color::Red);
			waiting = true;
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
		
		//Middles
		if (o->getPosition().x > screenWidth / 2.0f - holeDiameter / 7.0f && o->getPosition().x < screenWidth / 2.0f + holeDiameter / 7.0f) {
			if (o->getPosition().y < tablePos.y + holeDiameter /3.0f || o->getPosition().y > tablePos.y + tableHeight - holeDiameter/3.0f) {
				o->reset(v);
				return true;
			}
		}
		
		//Sides
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

		for (int i = 0; i < 22; i++) {
			ball_shape[i].setPosition(ball_body[i].getPosition().x, ball_body[i].getPosition().y);
			window.draw(ball_shape[i]);
		}

		/*
		for (int i = 0; i < 6; i++) {
			wall_shape[i].setPosition(wall_body[i].getPosition().x, wall_body[i].getPosition().y);
			window.draw(wall_shape[i]);
		}

		for (int i = 0; i < 12; i++) {
			capsule_shape[i].setPosition(capsule_body[i].getPosition().x, capsule_body[i].getPosition().y);
			window.draw(capsule_shape[i]);
		}
		*/

		if (!waiting && mouse.chargingCue()) {
#ifdef USE_CUE
			p2d::Vec2f cuePos = mouse.getCuePosition();
			p2d::Vec2f ballPos = mouse.getBodyPosition();

			float angle = (cuePos - ballPos).angle({ -1.0f, 0.0f });
			cueShape.setRotation(-angle);
			cueShape.setPosition(cuePos.x, cuePos.y);
			std::cout << angle << std::endl;
		
			window.draw(cueShape);
#else
			sf::VertexArray lines(sf::LinesStrip, 2);
			lines[0].position = { mouse.getCuePosition().x, mouse.getCuePosition().y };
			lines[1].position = { mouse.getBodyPosition().x, mouse.getBodyPosition().y };

			window.draw(lines);
#endif
		}

		window.draw(textLeft);
		window.draw(textRight);
	}

	static void onCollision() {
		//std::cout << "Test!" << std::endl;
	}

	void run() {

		sf::Music music;
		if (!music.openFromFile("sound/music.ogg"))
			std::cout << "Cannot open music.ogg" << std::endl;
		music.setLoop(true);
		music.play();

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
		delete cueTexture;

#ifdef GRAPHICS

		for (int i = 0; i < 8; i++) {
			delete ball_texture[i];
		}
#endif

	}
};

#endif