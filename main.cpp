#include <SFML/Graphics.hpp>
#include "hash_map.cpp"
#include "stack.cpp"
#include "Maze.cpp"
#include <stdexcept>


int main(int argc, char const *argv[])
{
    try {
        int x,y;
        cout<<"Enter maze lenght and width"<<endl;
        cin>>x>>y;
        Maze m(x,y);

        // SFML window setup
        sf::RenderWindow window(sf::VideoMode(x * 30, y * 30), "Maze Display");
        sf::CircleShape playerCircle;
        
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    int cellX = event.mouseButton.x / 30;
                    int cellY = event.mouseButton.y / 30;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        m.setStartPoint(cellX, cellY);
                        playerCircle.setRadius(cellSize/2);
                        playerCircle.setPosition( cellSize*cellX , cellSize*cellY );
                        playerCircle.setFillColor(sf::Color::Blue);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        m.setEndPoint(cellX, cellY);
                    } else {
                        m.toggleWall(cellX, cellY);
                    }
                }else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ) {
                // ( event.key.code == sf::Keyboard::W )? keyPressed = 'W':( event.key.code == sf::Keyboard::A )? 'A':( event.key.code == sf::Keyboard::S )? 'S': ( event.key.code == sf::Keyboard::D )? 'D': 0;  
                    m.solve(playerCircle);
                }
            }
            window.clear();
            m.display(window,playerCircle);
            window.draw(playerCircle);
            window.display();
        }

    throw std::runtime_error("An error occurred!");
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
        //printStackTrace();
    }        

    return 0;
}
