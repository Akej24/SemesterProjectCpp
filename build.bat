@echo off

::Clear console
cls

:: Create target directory if does not exist
if not exist .\target\ (
    mkdir .\target
)

:: Clear target directory
del /q /s .\target\* > nul

:: Compile app into .exe
g++ .\src\*.cpp -o .\target\app.exe

:: Run app
start .\target\app.exe