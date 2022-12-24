#include "Ball.hpp"

namespace vg 
{
	Ball::Ball(PosCircle posCir, SpeedCircle speedCir, float radius) {
		m_posCir = posCir;
		m_speedCir = speedCir;
		m_radius = radius;
		m_circle = new sf::CircleShape(m_radius);
		m_circle->setFillColor(sf::Color::Red);
		m_circle->setOrigin(m_radius, m_radius);
	}

	void Ball::move() {
		m_posCir.x += m_speedCir.x;
		m_posCir.y += m_speedCir.y;

		m_circle->setPosition(m_posCir.x, m_posCir.y);
	}

	void Ball::collision(float x) {
		if ((m_posCir.x + m_radius) >= 600)
			m_speedCir.x = -m_speedCir.x;

		if (m_posCir.x - m_radius <= 0)
			m_speedCir.x = -m_speedCir.x;

		if ((m_posCir.y - m_radius) < 0)
			m_speedCir.y = -m_speedCir.y;

		if ((m_posCir.y + m_radius >= 750) && (m_posCir.x >= x) && (m_posCir.x <= x + 120))
			m_speedCir.y = -m_speedCir.y;

		if (m_posCir.y + m_radius >= 800) {
			m_speedCir.x = 0;
			m_speedCir.y = 0;
		}
	}

	sf::CircleShape* Ball::Get() {
		return m_circle;
	}
	Ball::~Ball() {
		delete m_circle;
	}

}