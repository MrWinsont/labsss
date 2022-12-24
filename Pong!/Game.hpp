#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
namespace vg
{
	class Game
	{
	private:
		int m_width=0, m_high=0;
		std::string m_caption;
		sf::RenderWindow* m_window = nullptr;

	public:
		Game();

		void setCaption(const std::string& caption);

		void setResolution(int width, int high);

		void setup();

		void runGame();


		~Game();
	};
}