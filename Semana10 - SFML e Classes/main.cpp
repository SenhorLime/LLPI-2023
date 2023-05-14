#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace sf;
using namespace std;

class Ball {
  private:
    int time = 1;
    float size = (15 + rand() % 50);
    int posx;
    int posy;
    int velx = -(1 + rand() % 25);
    int vely = (1 + rand() % 25);
    Color randColor = Color((rand() % 255), (rand() % 255), (rand() % 255));
    CircleShape shape;

  public:
    Ball (RenderWindow *window){
      posx = window -> getSize().x / 2;
      posy = window -> getSize().y / 2;
      
      shape.setRadius(size);
      shape.setFillColor(randColor);
      shape.setOrigin(size / 2, size / 2);
      shape.setPosition(posx, posy);
    }
  
  public:
    void defineVelocity (RenderWindow *window){
      vely = posy < window -> getSize().y && posy > 0 ? vely: -vely;
      velx = posx < window -> getSize().x && posx > 0 ? velx: -velx;
    }
    
    void definePosition (RenderWindow *window){
      defineVelocity(window);
      
      posy = posy + vely * time;
      posx = posx + velx * time;
      
      shape.setPosition(posx, posy);
    }

    void renderBall (RenderWindow *window){
      definePosition(window);

      window -> draw(shape);
    }
};

int main() {

  srand(time(NULL));

  RenderWindow window(VideoMode(640, 480), "Bolinhas com OOP");
  
  vector<Ball> bolinhas;

  for (int i; i < 3; i++){
    bolinhas.push_back(Ball(&window));
  }

  while (window.isOpen()){
    Event event;

    while (window.pollEvent(event)){
      if(event.type == Event::Closed){
        window.close();
      } 
    }

    window.clear();

    for (auto& ball : bolinhas){
      ball.renderBall(&window);
    }

    window.display();
    sleep(milliseconds(30.0f));
  }

  return 0;
}
