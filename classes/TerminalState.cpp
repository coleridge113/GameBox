#include "./TerminalState.h"
#include <termios.h>
#include <unistd.h>

TerminalState::TerminalState() {
    tcgetattr(0, &old_settings);
    struct termios new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSADRAIN, &new_settings);
}

TerminalState::~TerminalState() {
    tcsetattr(0, TCSADRAIN, &old_settings);
}
