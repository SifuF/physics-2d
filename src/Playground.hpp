#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include "Physics.hpp"
#include "Mouse.hpp"

class Playground {
private:
	
	sf::CircleShape shape_1;
	p2d::CircleBody body_1;
	sf::CircleShape shape_2;
	p2d::CircleBody body_2;
	sf::CircleShape shape_3;
	p2d::CircleBody body_3;
	
	sf::RectangleShape shape_4;
	p2d::RectangleBody body_4;
	sf::RectangleShape shape_5;
	p2d::RectangleBody body_5;

	sf::Texture texture;
	sf::Sprite shape_6;
	p2d::RectangleBody body_6;

	sf::RectangleShape shape_top;
	p2d::RectangleBody body_top;
	sf::RectangleShape shape_left;
	p2d::RectangleBody body_left;
	sf::RectangleShape shape_right;
	p2d::RectangleBody body_right;
	sf::RectangleShape shape_bottom;
	p2d::RectangleBody body_bottom;


	p2d::Physics physics;
	Mouse mouse;

	int screenWidth = 1000;
	int screenHeight = 1000;
	sf::RenderWindow window;
public:
	Playground() {

		srand(time(NULL));

		window.create(sf::VideoMode(screenWidth, screenHeight), "SifuF Planets");

		physics.setGravity({ 0.0f, 100.0f });
		physics.setDrag({ 0.05f, 0.001f });
		physics.setDragRotational({ 0.01f, 0.01f });

		mouse.init(&window, &physics, screenWidth, screenHeight);

		shape_1.setRadius(50.0f);
		shape_1.setOrigin(shape_1.getRadius(), shape_1.getRadius());
		shape_1.setFillColor(sf::Color::Green);
		body_1.create(50.0f, 150.0f, 200.0f, 1.0f, 0.90f);
		physics.add(&body_1);
		mouse.add(&body_1);

		shape_2.setRadius(50.0f);
		shape_2.setOrigin(shape_2.getRadius(), shape_2.getRadius());
		shape_2.setFillColor(sf::Color::Red);
		body_2.create(50.0f, 800.0f, 200.0f, 1.0f, 0.90f);
		physics.add(&body_2);
		mouse.add(&body_2);

		shape_3.setRadius(75.0f);
		shape_3.setOrigin(shape_3.getRadius(), shape_3.getRadius());
		shape_3.setFillColor(sf::Color::Blue);
		body_3.create(75.0f, 500.0f, 300.0f, 1000.0f, 0.75f, true);
		physics.add(&body_3);
		mouse.add(&body_3);

		shape_4.setSize({100.0f, 100.0f});
		shape_4.setOrigin(shape_4.getSize().x / 2.0f, shape_4.getSize().y / 2.0f);
		shape_4.setFillColor(sf::Color::Yellow);
		body_4.create(100.0f, 100.0f, 700.0f, 300.0f, 1.0f, 0.75f);
		physics.add(&body_4);
		mouse.add(&body_4);

		shape_5.setSize({ 200.0f, 150.0f });
		shape_5.setOrigin(shape_5.getSize().x / 2.0f, shape_5.getSize().y / 2.0f);
		shape_5.setFillColor(sf::Color::Magenta);
		body_5.create(200.0f, 150.0f, 200.0f, 700.0f, 2.0f, 0.8f);
		physics.add(&body_5);
		mouse.add(&body_5);

		texture.loadFromFile("gfx/image.png");
		shape_6.setTexture(texture);
		sf::FloatRect rec = shape_6.getGlobalBounds();
		shape_6.setOrigin(rec.width / 2.0f, rec.height / 2.0f);
		shape_6.setColor(sf::Color::White);
		body_6.create(rec.width, rec.height, 600.0f, 600.0f, 0.5f, 0.70f);
		physics.add(&body_6);
		mouse.add(&body_6);

		shape_top.setSize({ float(screenWidth), 10.0f });
		shape_top.setOrigin(shape_top.getSize().x / 2.0f, shape_top.getSize().y / 2.0f);
		shape_top.setFillColor(sf::Color::Yellow);
		body_top.create(float(screenWidth), 10.0f, float(screenWidth) / 2.0f, 10.0f / 2.0f, 100.0f, 0.8f, true);
		physics.add(&body_top);

		shape_left.setSize({ 10.0f,  float(screenHeight) });
		shape_left.setOrigin(shape_left.getSize().x / 2.0f, shape_left.getSize().y / 2.0f);
		shape_left.setFillColor(sf::Color::Yellow);
		body_left.create(10.0f, float(screenHeight), 10.0f / 2.0f, float(screenHeight) / 2.0f, 100.0f, 0.8f, true);
		physics.add(&body_left);

		shape_right.setSize({ 10.0f,  float(screenHeight) });
		shape_right.setOrigin(shape_right.getSize().x / 2.0f, shape_right.getSize().y / 2.0f);
		shape_right.setFillColor(sf::Color::Yellow);
		body_right.create(10.0f, float(screenHeight), float(screenWidth) - 10.0f / 2.0f, float(screenHeight) / 2.0f, 100.0f, 0.8f, true);
		physics.add(&body_right);

		shape_bottom.setSize({ float(screenWidth), 10.0f });
		shape_bottom.setOrigin(shape_bottom.getSize().x / 2.0f, shape_bottom.getSize().y / 2.0f);
		shape_bottom.setFillColor(sf::Color::Yellow);
		body_bottom.create(float(screenWidth), 10.0f, float(screenWidth) / 2.0f, float(screenHeight) - 10.0f / 2.0f, 100.0f, 0.8f, true);
		physics.add(&body_bottom);
		
		run();
	}

	sf::Color randColor() {
		sf::Color c;
		c.r = rand() % 256;
		c.g = rand() % 256;
		c.b = rand() % 256;
		return c;
	}

	float randPos() {
		return float(rand() % 1000);
	}

	void wrap(p2d::Body& o) {
		if (o.getPosition().x + o.getLength().x / 2.0f > screenWidth) {
			o.setPosition({ -o.getLength().x / 2.0f, o.getPosition().y });
		}

		if (o.getPosition().y + o.getLength().y / 2.0f > screenHeight) {
			o.setPosition({ o.getPosition().x,  -o.getLength().y / 2.0f });
		}

		if (o.getPosition().x + o.getLength().x / 2.0f < 0) {
			o.setPosition({ float(screenWidth - o.getLength().x / 2.0f), o.getPosition().y });
		}

		if (o.getPosition().y + o.getLength().y / 2.0f < 0) {
			o.setPosition({ o.getPosition().x, float(screenHeight - o.getLength().y / 2.0f) });
		}
	}

	void run() {

		auto timePrev = std::chrono::steady_clock::now();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			auto timeNow = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = timeNow - timePrev;
			double dt = elapsed_seconds.count();
			timePrev = timeNow;

			draw();

			mouse.setImpulseReady();
			mouse.update();
			physics.update(dt);
		}
	}

	void draw() {
		
		shape_1.setPosition(body_1.getPosition().x, body_1.getPosition().y);
		shape_1.setRotation(body_1.getTheta());
		window.draw(shape_1);

		shape_2.setPosition(body_2.getPosition().x, body_2.getPosition().y);
		shape_2.setRotation(body_2.getTheta());
		window.draw(shape_2);

		shape_3.setPosition(body_3.getPosition().x, body_3.getPosition().y);
		shape_3.setRotation(body_3.getTheta());
		window.draw(shape_3);

		shape_4.setPosition(body_4.getPosition().x, body_4.getPosition().y);
		shape_4.setRotation(body_4.getTheta());
		window.draw(shape_4);

		shape_5.setPosition(body_5.getPosition().x, body_5.getPosition().y);
		shape_5.setRotation(body_5.getTheta());
		window.draw(shape_5);

		shape_6.setPosition(body_6.getPosition().x, body_6.getPosition().y);
		shape_6.setRotation(body_6.getTheta());
		window.draw(shape_6);

		shape_top.setPosition(body_top.getPosition().x, body_top.getPosition().y);
		shape_top.setRotation(body_top.getTheta());
		window.draw(shape_top);

		shape_left.setPosition(body_left.getPosition().x, body_left.getPosition().y);
		shape_left.setRotation(body_left.getTheta());
		window.draw(shape_left);

		shape_right.setPosition(body_right.getPosition().x, body_right.getPosition().y);
		shape_right.setRotation(body_right.getTheta());
		window.draw(shape_right);

		shape_bottom.setPosition(body_bottom.getPosition().x, body_bottom.getPosition().y);
		shape_bottom.setRotation(body_bottom.getTheta());
		window.draw(shape_bottom);

		if (mouse.chargingCue()) {
			sf::VertexArray lines(sf::LinesStrip, 2);
			lines[0].position = { mouse.getCuePosition().x, mouse.getCuePosition().y };
			lines[1].position = { mouse.getBodyPosition().x, mouse.getBodyPosition().y };

			window.draw(lines);
		}
	
		window.display();
	}

	~Playground() {}
};

#endif