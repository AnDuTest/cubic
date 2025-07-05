#!/bin/bash
source ../emsdk/emsdk_env.sh

emcc main.cpp src/glad.c \
  -Iinclude -Iglfw-3.4/include \
  glfw-3.4/build/src/libglfw3.a \
  -s USE_GLFW=3 \
  -s FULL_ES3=1 \
  -s USE_WEBGL2=1 \
  -s WASM=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
  -o game.js