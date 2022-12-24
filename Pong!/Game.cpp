
#include "Game.hpp"
#include "Shape.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <string>

		
namespace vg {

		Game::Game() {

		}

		Game::~Game() {
			if (m_window != nullptr) {
				delete m_window;
			}
		}
		
		void Game::setCaption(const std::string& caption) {
			m_caption = caption;
		}

		void Game::setResolution(int width, int high) {
			m_width = width;
			m_high = high;
		}

		void Game::setup() {
			m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_high), m_caption);
		}

		void Game::runGame() {
			
			sf::Clock timer;
			vg::Ball ball({ 240,350 }, { 3,-6 }, 15);
			vg::Rect rect({ 240,750 }, 3, 120, 25);
			while (m_window->isOpen())
			{

				sf::Event event;
				ball.move();
				ball.collision(rect.getPosX());
				rect.moveRect();
				

				while (m_window->pollEvent(event)) 
				{	
					if (event.type == sf::Event::Closed) {
						m_window->close();
					}
				}
				m_window->clear();
				m_window->draw(*rect.Get());
				m_window->draw(*ball.Get());
				m_window->display();
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			
		}
	
}