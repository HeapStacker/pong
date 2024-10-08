#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class AudioPlayer: public UpdateableObject {
    std::vector<sf::Music*> playlist; 
    unsigned int currentSongId = 0;
    bool played = false;
public:

    AudioPlayer(const std::vector<sf::Music*>& playlist) {
        this->playlist = playlist;
    }

    void update() override {
        if (playlist.empty()) {
            return;
        }

        if (!played) {
            playlist[currentSongId]->play();
            played = true;
        }

        if (playlist[currentSongId]->getStatus() == sf::SoundSource::Stopped) {
            currentSongId++;

            if (currentSongId >= playlist.size()) {
                currentSongId = 0;
            }
            played = false;
        }
    }
};