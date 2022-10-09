#ifndef PLANETS_H
#define PLANETS_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include "Physics.h"
#include "Mouse.h"

class Planets {
private:
	std::vector<sf::CircleShape> v_circ_shape;
	std::vector<p2d::Body> v_circ_body;

	std::vector<sf::RectangleShape> v_rect_shape;
	std::vector<p2d::Body> v_rect_body;

	sf::CircleShape shape_sun;
	p2d::CircleBody body_sun;

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
	Planets() {

		srand(time(NULL));

		window.create(sf::VideoMode(screenWidth, screenHeight), "SifuF Planets");

		physics.setGravity({ 0.0f, 0.0f });
		physics.setDrag({ 0.0f, 0.0f });

		mouse.init(&window, &physics, screenWidth, screenHeight);

		for (int i = 0; i < 1000; i++) {
			sf::CircleShape shape(3.0f);
			shape.setFillColor(randColor());
			shape.setOrigin(shape.getRadius(), shape.getRadius());
			v_circ_shape.push_back(shape);

			p2d::CircleBody body(shape.getRadius(), randPos(), randPos(), 1.0f, 0.90f);
			if (i == 0) {
				body.setVelocity({ 1000.0f, 0.0f });
			}
			v_circ_body.push_back(body);
		}

		for (int i = 0; i < v_circ_body.size(); i++) {
			physics.add(&v_circ_body[i]);
		}

		shape_sun.setRadius(75.0f);
		shape_sun.setOrigin(shape_sun.getRadius(), shape_sun.getRadius());
		shape_sun.setFillColor(sf::Color::Yellow);
		body_sun.create(75.0f, 500.0f, 300.0f, 1000.0f, 0.75f, true);
		physics.add(&body_sun);
		mouse.add(&body_sun);
		
		/*
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
		*/

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
			
			for (int i = 0; i < v_circ_body.size(); i++) {
				wrap(v_circ_body[i]);
			}
			
			mouse.update();
			physics.update(dt);
		}
	}

	void draw() {
		for (int i = 0; i < v_circ_shape.size(); i++) {
			v_circ_shape[i].setPosition({ v_circ_body[i].getPosition().x, v_circ_body[i].getPosition().y });
			v_circ_shape[i].setRotation( v_circ_body[i].getTheta() );
			window.draw( v_circ_shape[i] );
		}
		
		shape_sun.setPosition(body_sun.getPosition().x, body_sun.getPosition().y);
		shape_sun.setRotation(body_sun.getTheta());
		window.draw(shape_sun);

		/*
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
		*/

		window.display();
	}

	~Planets() {}
};

#endif