#ifndef TERMINAL_STATE_H
#define TERMINAL_STATE_H

#include <termios.h>

struct TerminalState {
    struct termios old_settings;

    TerminalState() {
        tcgetattr(0, &old_settings);
        struct termios new_settings = old_settings;
        new_settings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSADRAIN, &new_settings);
    };

    ~TerminalState() {
        tcsetattr(0, TCSADRAIN, &old_settings);
    };
};

#endif
