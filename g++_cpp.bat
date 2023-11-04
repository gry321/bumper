@echo off
if exist main.cpp (
    g++ functionFormat.cpp main.cpp -o bulper.exe
) else (
    echo No main.cpp
)