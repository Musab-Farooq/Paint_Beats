#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

struct buttons {

    Texture buttonTexture;
    RectangleShape button;
    string path;
    Color color;
    float buttonsizeX;
    float buttonsizeY;
    float buttonpositionX;
    float buttonpositionY;
    bool active;

    void setButton(string path, float Bsizex, float Bsizey, float Bposx, float Bposy, Color c, bool isexist)
    {
        this->path = path;
        this->buttonpositionX = Bposx;
        this->buttonpositionY = Bposy;
        this->buttonsizeX = Bsizex;
        this->buttonsizeY = Bsizey;
        this->color = c;
        this->active = isexist;

        buttonTexture.loadFromFile(path);
        button.setSize(Vector2f(Bsizex, Bsizey));
        button.setPosition(Bposx, Bposy);
        button.setTexture(&buttonTexture);
        button.setFillColor(c);
    }

    void hover(float Bsizex, float Bsizey, float Bposx, float Bposy)
    {
        button.setSize(sf::Vector2f(Bsizex, Bsizey));
        button.setPosition(Bposx, Bposy);
    }

    void functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window)
    {
        if ((m.getPosition().x >= buttonpositionX && m.getPosition().x <= buttonpositionX + buttonsizeX) && (m.getPosition().y >= (buttonpositionY) && m.getPosition().y <= buttonpositionY + buttonsizeY)) {
            hover(this->buttonsizeX + 10, this->buttonsizeY + 10, this->buttonpositionX - 10, this->buttonpositionY);
            if (e.type == Event::MouseButtonPressed) {
                active = !active;
            }
        }

        else {
            hover(this->buttonsizeX, this->buttonsizeY, this->buttonpositionX, this->buttonpositionY);
        }
    }

    bool getcheck()
    {
        return active;
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(button);
    }
};

struct screens {
    string path;
    Texture screenTexture;
    Sprite screenSprite;
    bool exist;
    buttons* button;
    int numberofbuttons;

    void setscreen(string path, int num_button, bool exist) {
        this->path = path;
        screenTexture.loadFromFile(this->path);
        screenSprite.setTexture(screenTexture);
        screenSprite.setColor(Color(255, 255, 255, 255 * 0.9));

        button = new buttons[num_button];
        this->numberofbuttons = num_button;
        this->exist = exist;
    }

    void setbuttons(int num, string path, float Bsizex, float Bsizey, float Bposx, float Bposy, sf::Color c, bool isexist)
    {
        button[num - 1].setButton(path, Bsizex, Bsizey, Bposx, Bposy, c, isexist);
    }

    void functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window)
    {
        if (this->exist) {
            for (int i = 0; i < this->numberofbuttons; i++) {
                button[i].functionality(m, e, window);
            }
        }
    }

    bool buttonexist(int n)
    {
        if (numberofbuttons == 0) {
            exist = false;
            return exist;
        }

        else {
            return button[n - 1].getcheck();
        }
    }

    bool getexist()
    {
        return this->exist;
    }

    void activate() {
        this->exist = true;
    }

    void deactivate() {
        this->exist = false;
        for (int i = 0; i < numberofbuttons; i++) {
            button[i].active = false;
        }
    }

    void draw(sf::RenderWindow& window)
    {
        if (this->exist) {
            window.draw(screenSprite);
            for (int i = 0; i < this->numberofbuttons; i++) {
                button[i].draw(window);
            }
        }
    }
};