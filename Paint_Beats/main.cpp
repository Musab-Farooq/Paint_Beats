#include "shapes.h"
#include "screens.h"
#include "musics.h"

int main()
{
    RenderWindow window(VideoMode::getFullscreenModes()[0], "Paint", Style::Fullscreen);

    RectangleShape toolbar,bg,canvas_place;
    toolbar.setPosition(0, 0);
    toolbar.setSize(Vector2f(1400, 100));
    toolbar.setFillColor(Color(120, 120, 120));

    bg.setPosition(0, 100);
    bg.setSize(Vector2f(1400, 700));
    bg.setFillColor(Color(180, 180, 180));

    Texture updated_text = texture_mat();
    Sprite sp(updated_text);
    sp.setPosition(20, 120);
    Mouse m;
    int thick = 2;
    int R = 0,G = 0,B = 0;
    Color c(Color::Black);

    screens paint;
    paint.setscreen("",17,true);
    paint.setbuttons(1, "Textures/Circle.png", 50, 50, 210, 20, Color::White, false);
    paint.setbuttons(2, "Textures/Rectangle.png", 50, 50, 280, 20, Color::White, false);
    paint.setbuttons(3, "Textures/Line.png", 50, 50, 350, 20, Color::White, false); 
    paint.setbuttons(4, "Textures/arrow.png", 50, 50, 420, 20, Color::White, false);
    paint.setbuttons(5, "", 30, 30, 550, 10, Color::Red, false);
    paint.setbuttons(6, "", 30, 30, 580, 10, Color::Yellow, false);
    paint.setbuttons(7, "", 30, 30, 610, 10, Color::Black, false);
    paint.setbuttons(8, "", 30, 30, 1250, 50, Color::White, false);
    paint.setbuttons(9, "Textures/Music.png", 150, 90, 1000, 0, Color::White, false);
    paint.setbuttons(10, "Textures/save.png", 150, 90, 0, 0, Color::White, false);
    paint.setbuttons(11, "Textures/clear.png", 150, 70, 850, 10, Color::White, false);
    paint.setbuttons(12, "", 30, 30, 640, 10, Color::Blue, false);
    paint.setbuttons(13, "", 30, 30, 670, 10, Color::Green, false);
    paint.setbuttons(14, "", 40, 30, 550, 40, Color::White, false);
    paint.setbuttons(15, "", 40, 30, 600, 40, Color::White, false);
    paint.setbuttons(16, "", 40, 30, 650, 40, Color::White, false);
    paint.setbuttons(17, "", 40, 30, 700, 40, Color::White, false);

    screens musics;
    musics.setscreen("Textures/music_bg.jpg", 11,false);
    musics.setbuttons(1, "Textures/back.png", 150, 100, 50, 650, Color::White, false);
    musics.setbuttons(2, "Textures/play.png", 100, 100, 250, 50, Color::White, false);
    musics.setbuttons(3, "Textures/pause.png", 100, 100, 250,50, Color::White, false);
    musics.setbuttons(4, "Textures/play.png", 100, 100, 250, 200, Color::White, false);
    musics.setbuttons(5, "Textures/pause.png", 100, 100, 250, 200, Color::White, false);
    musics.setbuttons(6, "Textures/play.png", 100, 100, 250, 350, Color::White, false);
    musics.setbuttons(7, "Textures/pause.png", 100, 100, 250, 350, Color::White, false);
    musics.setbuttons(8, "Textures/play.png", 100, 100, 250, 500, Color::White, false);
    musics.setbuttons(9, "Textures/pause.png", 100, 100, 250, 500, Color::White, false);
    musics.setbuttons(10, "Textures/play.png", 100, 100, 250, 650, Color::White, false);
    musics.setbuttons(11, "Textures/pause.png", 100, 100, 250, 650, Color::White, false);

    Font font;
    font.loadFromFile("Fonts/arial.ttf");

    Text thick_write,text, textR, textG, textB, text2;
    thick_write.setFont(font);
    thick_write.setCharacterSize(20);
    thick_write.setFillColor(Color::Black);
    thick_write.setPosition(1200, 0);
    thick_write.setString("Set Thickness\n       (0 - 9)");

    text2.setFont(font);
    text2.setCharacterSize(20);
    text2.setFillColor(Color::Black);
    text2.setPosition(550, 70);
    text2.setString("R       G       B    Click");

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(Color::Black);
    text.setPosition(1250,50);
    text.setString("2");

    textR.setFont(font);
    textR.setCharacterSize(20);
    textR.setFillColor(Color::Black);
    textR.setPosition(550, 50);

    textG.setFont(font);
    textG.setCharacterSize(20);
    textG.setFillColor(Color::Black);
    textG.setPosition(600, 50);

    textB.setFont(font);
    textB.setCharacterSize(20);
    textB.setFillColor(Color::Black);
    textB.setPosition(650, 50);
    

    Musics_names();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
            else {

                if (musics.getexist()) {
                    musics.functionality(m, event, window);
                    if (musics.buttonexist(1)) {
                        paint.activate();
                        musics.deactivate();
                    }
                }

                else if (paint.getexist()) {
                    paint.functionality(m, event, window);

                    if (paint.buttonexist(1)) {
                        draw_circle(m, event, updated_text, sp, c, thick);
                    }

                    else if (paint.buttonexist(2)) {
                        draw_rectangle(m, event, updated_text, sp, c, thick);
                    }

                    else if (paint.buttonexist(3)) {
                        draw_line(m, event, updated_text, sp, c, thick);
                    }

                    else if (paint.buttonexist(4)) {
                        draw_arrow_line(m, event, updated_text, sp, c, thick);
                    }

                    if (paint.buttonexist(5)) {
                        c = Color(Color::Red);
                    }
                    if (paint.buttonexist(6)) {
                        c = Color(Color::Yellow);
                    }
                    if (paint.buttonexist(7)) {
                        c = Color(Color::Black);
                    }
                    if (paint.buttonexist(12)) {
                        c = Color(Color::Blue);
                    }
                    if (paint.buttonexist(13)) {
                        c = Color(Color::Green);
                    }

                    if (paint.buttonexist(8)) {
                        string input = "";
                        write(event, text, input);
                        string num = text.getString();
                        if (num[0] >= 48 && num[0] <= 57) {
                            thick = stoi(num);
                        }
                    }

                    if (paint.buttonexist(14)) {
                        string temp = textR.getString();
                        if(temp.length() < 3){ 
                            string input1 = textR.getString();
                            write(event, textR, temp);
                            string num = textR.getString();
                            if (num[0] >= 48 && num[0] <= 57) {
                                R = stoi(num);
                            }
                        }
                    }

                    if (paint.buttonexist(15)) {
                        string temp = textG.getString();
                        if (temp.length() < 3) {
                            string input2 = textG.getString();
                            write(event, textG, temp);
                            string num = textG.getString();
                            if (num[0] >= 48 && num[0] <= 57) {
                                G = stoi(num);
                            }
                        }
                    }

                    if (paint.buttonexist(16)) {
                        string temp = textB.getString();
                        if (temp.length() < 3) {
                            string input3 = textB.getString();
                            write(event, textB, temp);
                            string num = textB.getString();
                            if (num[0] >= 48 && num[0] <= 57) {
                                B = stoi(num);
                            }
                        }
                    }

                    if (paint.buttonexist(17)) {
                        c = Color(R,G,B);
                        textR.setString("");
                        textG.setString("");
                        textB.setString("");
                    }

                    if (paint.buttonexist(9)) {
                        musics.activate();
                        paint.deactivate();
                    }

                    if (paint.buttonexist(10)) {
                        RenderTexture renderTexture;
                        renderTexture.create(updated_text.getSize().x, updated_text.getSize().y);
                        renderTexture.clear(Color::Transparent);
                        renderTexture.draw(sp);
                        renderTexture.display();
                        Image image = renderTexture.getTexture().copyToImage();
                        image.saveToFile("Output Image.png");
                    }

                    if (paint.buttonexist(11)) {
                        clear(updated_text,sp);
                    }
                }

                activate(musics);
            }
        }

        window.clear();
        if (musics.getexist()) {
            musics.draw(window);
            manage_buttons(window, musics);
        }

        else if (paint.getexist()){
            window.draw(toolbar);
            window.draw(bg);
            paint.draw(window);
            window.draw(thick_write);
            window.draw(text);
            window.draw(textR);
            window.draw(textG);
            window.draw(textB);
            window.draw(text2);
            window.draw(sp);
        }
        window.display();
    }

    return 0;
}