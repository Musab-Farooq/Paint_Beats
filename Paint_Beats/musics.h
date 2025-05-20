#pragma once

#include <SFML/Audio.hpp>

Music bgmusic;
Text name_music_1, name_music_2, name_music_3, name_music_4, name_music_5;
Font font;

void activate(screens &musics) {
    bgmusic.setVolume(80);

    if (musics.buttonexist(3)) {
        bgmusic.openFromFile("Music/idea_10.mp3");
        bgmusic.play();
    }
    else if (musics.buttonexist(2)) {
        bgmusic.pause();
    }

    else if (musics.buttonexist(5)) {
        bgmusic.openFromFile("Music/autumn_waltz.mp3");
        bgmusic.play();
    }

    else if (musics.buttonexist(4)) {
        bgmusic.pause();
    }

    else if (musics.buttonexist(7)) {
        bgmusic.openFromFile("Music/melancholic.mp3");
        bgmusic.play();
    }

    else if (musics.buttonexist(6)) {
        bgmusic.pause();
    }

    else if (musics.buttonexist(9)) {
        bgmusic.openFromFile("Music/magical_overture.mp3");
        bgmusic.play();
    }

    else if (musics.buttonexist(8)) {
        bgmusic.pause();
    }

    else if (musics.buttonexist(11)) {
        bgmusic.openFromFile("Music/gymnopedie.mp3");
        bgmusic.setVolume(120);
        bgmusic.play();
    }

    else if (musics.buttonexist(10)) {
        bgmusic.pause();
    }
}

void Musics_names() {
    font.loadFromFile("Fonts/arial.ttf");

    name_music_1.setFont(font);
    name_music_1.setCharacterSize(35);
    name_music_1.setFillColor(Color::White);
    name_music_1.setPosition(450, 80);
    name_music_1.setString("Idea 10");

    name_music_2.setFont(font);
    name_music_2.setCharacterSize(35);
    name_music_2.setFillColor(Color::White);
    name_music_2.setPosition(450, 230);
    name_music_2.setString("Autumn Waltz");

    name_music_3.setFont(font);
    name_music_3.setCharacterSize(35);
    name_music_3.setFillColor(Color::White);
    name_music_3.setPosition(450, 380);
    name_music_3.setString("Melancholic");

    name_music_4.setFont(font);
    name_music_4.setCharacterSize(35);
    name_music_4.setFillColor(Color::White);
    name_music_4.setPosition(450, 530);
    name_music_4.setString("Magical Overture");

    name_music_5.setFont(font);
    name_music_5.setCharacterSize(35);
    name_music_5.setFillColor(Color::White);
    name_music_5.setPosition(450, 680);
    name_music_5.setString("Gymnopedie no. 1");
}

void manage_buttons(RenderWindow& window, screens& musics) {
    if (musics.buttonexist(2)) {
        musics.button[2].active = false;
        musics.button[2].draw(window);
    }
    else if (musics.buttonexist(3)) {
        musics.button[1].active = false;
        musics.button[1].draw(window);
    }
    else if (musics.buttonexist(4)) {
        musics.button[4].active = false;
        musics.button[4].draw(window);
    }
    else if (musics.buttonexist(5)) {
        musics.button[3].active = false;
        musics.button[3].draw(window);
    }
    else if (musics.buttonexist(6)) {
        musics.button[6].active = false;
        musics.button[6].draw(window);
    }
    else if (musics.buttonexist(7)) {
        musics.button[5].active = false;
        musics.button[5].draw(window);
    }
    else if (musics.buttonexist(8)) {
        musics.button[8].active = false;
        musics.button[8].draw(window);
    }
    else if (musics.buttonexist(9)) {
        musics.button[7].active = false;
        musics.button[7].draw(window);
    }
    else if (musics.buttonexist(10)) {
        musics.button[10].active = false;
        musics.button[10].draw(window);
    }
    else if (musics.buttonexist(11)) {
        musics.button[9].active = false;
        musics.button[9].draw(window);
    }

    window.draw(name_music_1);
    window.draw(name_music_2);
    window.draw(name_music_3);
    window.draw(name_music_4);
    window.draw(name_music_5);
}