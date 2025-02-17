# websocket async-server

Simple example of the **asynchronous** websocket echo server. Built with oat++ (AKA oatpp) web framework.

See more:

- [Oat++ Website](https://oatpp.io/)
- [Oat++ Github Repository](https://github.com/oatpp/oatpp)
- [Get Started With Oat++](https://oatpp.io/docs/start)

## Overview

### Project layout

```
|- CMakeLists.txt                         // projects CMakeLists.txt
|- src/
|    |
|    |- controller/
|    |    |
|    |    |- MyController.hpp             // ApiController with websocket endpoint
|    |
|    |- websocket/
|    |    |
|    |    |- WSListener.hpp               // WebSocket listeners are defined here
|    |
|    |- AppComponent.hpp                  // Application config. 
|    |- App.cpp                           // main() is here
|
|- utility/install-oatpp-modules.sh       // utility script to install required oatpp-modules.  
```

## Build and Run

### Using Meson

```
$ meson setup build
$ meson compile -C build
$ ./build/async_websocket_server  # - run application.

```
