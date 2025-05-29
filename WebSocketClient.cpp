#include "WebSocketClient.h"
#include <iostream>

WebSocketClient::WebSocketClient() {
    m_client.init_asio();
    m_client.set_message_handler([this](websocketpp::connection_hdl, client_t::message_ptr msg) {
        if(onMessage) onMessage(msg->get_payload());
    });
    m_client.set_open_handler([this](websocketpp::connection_hdl) {
        if(onOpen) onOpen();
    });
    m_client.set_close_handler([this](websocketpp::connection_hdl) {
        if(onClose) onClose();
    });
    m_client.set_fail_handler([this](websocketpp::connection_hdl) {
        if(onError) onError("Connection failed");
    });
}

WebSocketClient::~WebSocketClient() {
    m_client.stop();
}

void WebSocketClient::connect(const std::string& uri) {
    auto con = m_client.get_connection(uri, m_error);
    if(m_error) {
        if(onError) onError(m_error.message());
        return;
    }
    m_hdl = con->get_handle();
    m_client.connect(con);
    m_client.run();
}

void WebSocketClient::send(const std::string& message) {
    m_client.send(m_hdl, message, websocketpp::frame::opcode::text);
}

void WebSocketClient::close() {
    m_client.close(m_hdl, websocketpp::close::status::normal, "");
}
