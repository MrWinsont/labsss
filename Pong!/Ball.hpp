#pragma once
#include "Shape.hpp"
#include <SFML/Graphics.hpp>
namespace vg {
	struct PosCircle
	{
		float x;
		float y;
	};
	struct SpeedCircle
	{
		float x;
		float y;
	};
	class Ball
	{
	private:
		PosCircle m_posCir;
		SpeedCircle m_speedCir;
		float m_radius;
		sf::CircleShape* m_circle;


	public:

		Ball(PosCircle posCir, SpeedCircle speedCir, float radius);
		void move();
		void collision(float x);
		sf::CircleShape* Get();
		~Ball();

	};
}