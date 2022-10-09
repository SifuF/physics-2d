#ifndef MOUSE_H
#define MOUSE_H

	class Mouse {
	private:
		sf::RenderWindow* window;
		p2d::Physics* physics;
		int screenWidth;
		int screenHeight;

		sf::Vector2i position;
		std::vector<p2d::Body*> m_Body;
		
		p2d::Body* m_ob_impulse;
		p2d::Vec2f cuePosition;
		bool impulse = false;
		bool impulseApplied = true;

		//external app needs to allow impulses
		bool impulseReady = false;

	public:

		Mouse() : window(nullptr), physics(nullptr), screenWidth(100), screenHeight(100), m_ob_impulse(nullptr) {}

		Mouse(sf::RenderWindow* w, p2d::Physics* p, int width, int height) : m_ob_impulse(nullptr) {
			init(w, p, width, height);
		}

		void init(sf::RenderWindow* w, p2d::Physics* p, int width, int height) {
			physics = p;
			window = w;
			screenWidth = width;
			screenHeight = height;
		}

		void add(p2d::Body* ob) {
			m_Body.push_back(ob);
		}

		void update() {

			position = sf::Mouse::getPosition(*window);

			for (p2d::Body* o : m_Body) {

				if (o->isStatic()) {
					//continue;
				}
				
				p2d::Vec2f pos = { float(position.x), float(position.y) };

				p2d::Vec2f p = o->getPosition();
				bool condition = false;

				if (o->isCircle()) {
					float r = o->getRadius();
					float dist = p.distance(pos);
					condition = dist < r;
				}

				else if (o->isRectangle()) {
					p2d::Vec2f l = o->getLength()/2.0;
					bool x = (pos.x > p.x - l.x && pos.x < p.x + l.x);
					bool y = (pos.y > p.y - l.x && pos.y < p.y + l.y);
					condition = x && y;
				}

				if (condition) {

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						if (o->isCircle()) {
							o->setPosition(pos);
						}
						else {
							o->setPosition(pos);
						}
						o->setVelocity({ 0.0f, 0.0f });
					}

					else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						if (!impulseReady || o->isStatic()) {
							continue;
						}
						impulse = true;
						impulseApplied = false;
						selectImpulse(o);
					}
				}
				else {
					//o->setColor(o->getColor());
				}
			}

			if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				impulse = false;	
			}

			processImpulse();
		}

		void selectImpulse(p2d::Body* ob) {
			m_ob_impulse = ob;
		}

		void setImpulseReady() {
			impulseReady = true;
		}

		void processImpulse() {
			if (impulse) {
				//Right mouse button is being held down
				position = sf::Mouse::getPosition(*window);
				p2d::Vec2f pos = { float(position.x), float(position.y) };
				cuePosition = pos;
			}
			else if (!impulseApplied) {
				//Right mouse botton has been held and now just released
				impulseApplied = true;
				p2d::Vec2f impulseDir = (m_ob_impulse->getPosition() - cuePosition).normalise();
				float impulseMag = (m_ob_impulse->getPosition() - cuePosition).magnitude();
				m_ob_impulse->setVelocity(impulseDir * impulseMag);
				impulseReady = false;
			}
		}

		bool chargingCue() {
			return impulse;
		}

		p2d::Vec2f getCuePosition() {
			return cuePosition;
		}

		p2d::Vec2f getBodyPosition() {
			if (m_ob_impulse != nullptr) {
				return m_ob_impulse->getPosition();
			}
			else {
				return { 500.0f, 500.0f };
			}
		}
	};

#endif
