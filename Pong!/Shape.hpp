#pragma once
#include <SFML/Graphics.hpp>
namespace vg
{
	struct PosRect
	{
		float x;
		float y;
	};
	class Rect
	{
	private:
		PosRect m_posRect;
		float m_speedRect;
		sf::RectangleShape* m_rect;
		float m_width;
		float m_high;
	public:
		Rect(PosRect posR, float Speed, float width, float high);
		void moveRect();
		float getPosX();
		sf::RectangleShape* Get();
		~Rect();
	};

}