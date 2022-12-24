#include "Shape.hpp"

namespace vg
{
	Rect::Rect(PosRect posR, float Speed, float width, float high) {
		m_posRect = posR;
		m_speedRect = Speed;
		m_width = width;
		m_high = high;
		m_rect = new sf::RectangleShape(sf::Vector2f(width, high));
		m_rect->setFillColor(sf::Color::Blue);
		m_rect->setPosition(m_posRect.x, m_posRect.y);
	}

	void Rect::moveRect() {
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (m_posRect.x > 0)) {
			m_posRect.x -= m_speedRect;
			m_rect->setPosition(m_posRect.x, m_posRect.y);

		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (m_posRect.x < 480)) {
			m_posRect.x += m_speedRect;
			m_rect->setPosition(m_posRect.x, m_posRect.y);

		}
	}

	float Rect::getPosX() {
		return m_posRect.x;
	}

	sf::RectangleShape* Rect::Get() {
		return m_rect;
	}

	Rect::~Rect() {
		delete m_rect;
	}
}