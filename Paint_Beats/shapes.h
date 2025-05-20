#pragma once
#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>
using namespace sf;
using namespace cv;

bool drawing = false;
Point Starting_point;
int circleRadius = 0;
Mat cvImageRGBWorking;
Image screenshot;

Texture texture_mat() {
    RenderTexture renderTexture;
    renderTexture.create(1320, 620);
    renderTexture.clear(Color::White);
    renderTexture.display();

    const Texture& texture = renderTexture.getTexture();
    screenshot = texture.copyToImage();
    Mat cvImage(620, 1320, CV_8UC4, (void*)screenshot.getPixelsPtr());

    Mat cvImageRGB;
    cvtColor(cvImage, cvImageRGB, COLOR_RGBA2BGR);
    cvImageRGBWorking = cvImageRGB.clone();

    Texture updatedTexture;
    updatedTexture.create(1320, 620);
    updatedTexture.update(screenshot.getPixelsPtr(), 1320, 620, 0, 0);

    return updatedTexture;
}

void draw_circle(Mouse m, Event event, Texture& texture, Sprite& sprite, sf::Color c, int thick) {

    if (m.getPosition().x >= 20 && m.getPosition().x <= 1340 && m.getPosition().y >= 120 && m.getPosition().y <= 740) {
        Mat cvImageRGBA(cvImageRGBWorking.size(), CV_8UC4);
        int x_sprite = sprite.getPosition().x;
        int y_sprite = sprite.getPosition().y;

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            drawing = true;
            Starting_point = Point(event.mouseButton.x - x_sprite, event.mouseButton.y - y_sprite);
        }
        else if (event.type == sf::Event::MouseMoved && drawing) {
            int x = event.mouseMove.x - x_sprite;
            int y = event.mouseMove.y - y_sprite;
            circleRadius = int(sqrt(pow(x - Starting_point.x, 2) + pow(y - Starting_point.y, 2)));

            Mat tempImage = cvImageRGBWorking.clone();
            circle(tempImage, Starting_point, circleRadius, Scalar(c.b, c.g, c.r), thick);
            cvtColor(tempImage, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
        else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            drawing = false;

            circle(cvImageRGBWorking, Starting_point, circleRadius, Scalar(c.b, c.g, c.r), thick);
            cvtColor(cvImageRGBWorking, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
    }
}

void draw_rectangle(Mouse m, Event event, Texture& texture, Sprite& sprite, sf::Color c, int thick) {

    if (m.getPosition().x >= 20 && m.getPosition().x <= 1340 && m.getPosition().y >= 120 && m.getPosition().y <= 740) {
        Mat cvImageRGBA(cvImageRGBWorking.size(), CV_8UC4);
        int x_sprite = sprite.getPosition().x;
        int y_sprite = sprite.getPosition().y;

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            drawing = true;
            Starting_point = Point(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));
        }
        else if (event.type == Event::MouseMoved && drawing) {
            Point current(int(m.getPosition().x - x_sprite), int(m.getPosition().y - y_sprite));

            Mat tempImage = cvImageRGBWorking.clone();
            rectangle(tempImage, Starting_point, current, Scalar(c.b, c.g, c.r), thick);
            cvtColor(tempImage, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
        else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            drawing = false;

            Point current(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));

            rectangle(cvImageRGBWorking, Starting_point, current, Scalar(c.b, c.g, c.r), thick);
            cvtColor(cvImageRGBWorking, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
    }
}

void draw_arrow_line(Mouse m, Event event, Texture& texture, Sprite& sprite, sf::Color c, int thick) {

    if (m.getPosition().x >= 20 && m.getPosition().x <= 1340 && m.getPosition().y >= 120 && m.getPosition().y <= 740) {
        Mat cvImageRGBA(cvImageRGBWorking.size(), CV_8UC4);
        int x_sprite = sprite.getPosition().x;
        int y_sprite = sprite.getPosition().y;

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            drawing = true;
            Starting_point = Point(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));
        }
        else if (event.type == Event::MouseMoved && drawing) {
            Point current(int(m.getPosition().x - x_sprite), int(m.getPosition().y - y_sprite));

            Mat tempImage = cvImageRGBWorking.clone();
            arrowedLine(tempImage, Starting_point, current, Scalar(c.b, c.g, c.r), thick, 8, 0, 0.1);
            cvtColor(tempImage, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
        else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            drawing = false;

            Point current(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));
            arrowedLine(cvImageRGBWorking, Starting_point, current, Scalar(c.b, c.g, c.r), thick, 8, 0, 0.1);
            cvtColor(cvImageRGBWorking, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
    }
}

void draw_line(Mouse m, Event event, Texture& texture, Sprite& sprite, sf::Color c, int thick) {

    if (m.getPosition().x >= 20 && m.getPosition().x <= 1340 && m.getPosition().y >= 120 && m.getPosition().y <= 740) {
        Mat cvImageRGBA(cvImageRGBWorking.size(), CV_8UC4);
        int x_sprite = sprite.getPosition().x;
        int y_sprite = sprite.getPosition().y;

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            drawing = true;
            Starting_point = Point(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));
        }
        else if (event.type == Event::MouseMoved && drawing) {
            Point current(int(m.getPosition().x - x_sprite), int(m.getPosition().y - y_sprite));

            Mat tempImage = cvImageRGBWorking.clone();
            line(tempImage, Starting_point, current, Scalar(c.b, c.g, c.r), thick, LINE_4);
            cvtColor(tempImage, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
        else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            drawing = false;

            Point current(int(event.mouseButton.x - x_sprite), int(event.mouseButton.y - y_sprite));
            line(cvImageRGBWorking, Starting_point, current, Scalar(c.b, c.g, c.r), thick, LINE_4);
            cvtColor(cvImageRGBWorking, cvImageRGBA, COLOR_BGR2RGBA);
            texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
            sprite.setTexture(texture);
        }
    }
}

void write(Event event, Text& text, std::string input) {
    //text.getString();
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128 && event.text.unicode != 13) {
            input += char(event.text.unicode);
        }
        text.setString(input);
    }
}

void clear(Texture& texture, Sprite& sprite) {

    Mat cvImageRGBA;
    cvImageRGBWorking.setTo(cv::Scalar(255, 255, 255));
    cvtColor(cvImageRGBWorking, cvImageRGBA, COLOR_BGR2RGBA);
    texture.update(cvImageRGBA.data, cvImageRGBA.cols, cvImageRGBA.rows, 0, 0);
    sprite.setTexture(texture);
}

