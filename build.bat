@echo off
cls

:: call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: === g++ compile ===
echo [g++] Compiling...
g++ %* -std=c++23 -o gout.exe
IF %ERRORLEVEL% EQU 0 (
    echo [g++] Compile Success! Running gout.exe...
    gout.exe | c++filt -t
) ELSE (
    echo [g++] Compile Failed.
)
