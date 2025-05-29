#include "ChatInterface.h"
#include <iostream>
#include <thread>

int ChatInterface::run(int argc, char** argv) {
    CLI::App app("WebSocket Chat Client");
    std::string uri = "wss://echo.websocket.events";
    app.add_option("-u,--url", uri, "WebSocket server URL");
    CLI11_PARSE(app, argc, argv);

    client.onOpen = []() { std::cout << "Connected!" << std::endl; };
    client.onMessage = [](const std::string& msg) { std::cout << "Received: " << msg << std::endl; };
    client.onError = [](const std::string& err) { std::cout << "Error: " << err << std::endl; };
    client.onClose = []() { std::cout << "Connection closed" << std::endl; };

    std::thread wsThread([&]() {
        client.connect(uri);
    });
    std::string line;
    while(std::getline(std::cin, line)) {
        if(line == "/quit") break;
        client.send(line);
    }
    client.close();
    wsThread.join();
    return 0;
}
