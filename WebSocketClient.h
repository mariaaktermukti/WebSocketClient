#pragma once
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <string>
#include <functional>

class WebSocketClient {
public:
    using client_t = websocketpp::client<websocketpp::config::asio_client>;
    WebSocketClient();
    ~WebSocketClient();

    void connect(const std::string& uri);
    void send(const std::string& message);
    void close();

    std::function<void(const std::string&)> onMessage;
    std::function<void()> onOpen;
    std::function<void()> onClose;
    std::function<void(const std::string&)> onError;

private:
    client_t m_client;
    websocketpp::connection_hdl m_hdl;
};
