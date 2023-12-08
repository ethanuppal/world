// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include <SDL.h>
#include <unordered_map>

/** Handles keyboard input. */
class Keyboard final {
    /** The states of each key as defined by SDL. */
    std::unordered_map<SDL_Keycode, bool> states;

public:
    Keyboard();

    void update(const SDL_Event& key_event);

    /** Returns whether the key represented by the keycode `code` is currently
     * pressed. */
    bool query(SDL_Keycode code) const;
};
