# WebSocket Client in C++ using GN Build System

## 👋 Overview
This is a C++ WebSocket Client built as part of an internship project. It demonstrates:

- Real-time text messaging using secure WebSocket (wss)
- Command-line interaction using CLI11
- Modern build system using GN + Ninja (used in Chromium projects)
- Clean code architecture with separate files for interface, client, and logic

## 📁 Project Structure
```
WebSocketClient/
├── BUILD.gn                 # GN build configuration
├── out/                     # Compiled output (from GN + Ninja)
├── src/                     # Source files
│   ├── main.cpp             # Entry point
│   ├── ChatInterface.cpp    # CLI interaction
│   ├── WebSocketClient.cpp  # WebSocket client logic
│   ├── ChatInterface.h
│   └── WebSocketClient.h
├── third_party/
│   ├── websocketpp/         # WebSocket++ library
│   └── CLI11/               # CLI11 CLI parser
└── README.md                # Project documentation
```

## 🧰 Requirements
- C++17 compatible compiler (G++ or Clang)
- Boost (specifically `boost_system`)
- OpenSSL (`libssl`, `libcrypto`)
- GN (Generate Ninja) build tool
- Ninja build system

## 🔧 Build Instructions (Windows)

### 1. Open PowerShell in the Project Root
Make sure you are in the same folder as `BUILD.gn`.

### 2. Generate Ninja Files with GN
```powershell
gn gen out\debug --args="is_debug=true"
```

### 3. Build the Project with Ninja
```powershell
ninja -C out\debug
```

### 4. Run the Executable
```powershell
.\out\debug\websocket_client.exe --url "wss://echo.websocket.events"
```

## 💬 Usage

Once the app starts:

- Type your message and press Enter
- It will be echoed back by the server
- Type `/quit` to exit

## 🌐 Echo Server
This app uses a public echo WebSocket server:  
[`wss://echo.websocket.events`](https://www.websocket.org/echo.html)

## ✨ Bonus Features
- ✅ Secure SSL/TLS (wss://)
- ✅ Clean modular code
- ✅ GN/Ninja build system
- ✅ Cross-platform compatible

## 🧪 Testing
Unit test scaffolding is ready. To run tests:
```powershell
.\out\debug\tests.exe
```

## 🙋 Author
**Maria**  
*Computer Science & Engineering Student*  
Internship Project – C++ Developer Assignment

---
