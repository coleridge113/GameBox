#ifndef TERMINAL_STATE_H
#define TERMINAL_STATE_H

#include <termios.h>

class TerminalState {
    struct termios old_settings;

    public:
        TerminalState();
        ~TerminalState();
};

#endif
