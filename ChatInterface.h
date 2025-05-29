#pragma once
#include "WebSocketClient.h"
#include <CLI/CLI.hpp>

class ChatInterface {
public:
    int run(int argc, char** argv);

private:
    WebSocketClient client;
};
