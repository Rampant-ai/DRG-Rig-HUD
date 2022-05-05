@ECHO OFF

REM
REM This script invokes Unreal Editor utilities. They must be in your "PATH" var already, or match the path appended here.
REM
REM This script must be executed from the same directory it exists in, due to use of the "CD" var.
REM

SET PATH=%PATH%;C:\Games\UE_4.27\Engine\Binaries\Win64\

UnrealPak.exe %1 -extract "%CD%\unpacked"

PAUSE
