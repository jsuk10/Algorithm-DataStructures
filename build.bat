@echo off
cls

echo [g++] Compiling...
g++ %* -std=c++23 -o gout.exe
IF %ERRORLEVEL% EQU 0 (
    echo [g++] Compile Success! Running gout.exe...
    gout.exe | c++filt -t
) ELSE (
    echo [g++] Compile Failed.
)
