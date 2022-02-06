@ECHO OFF

REM
REM This script invokes Unreal Editor utilities. They must be in your "PATH" var already, or match the path appended here.
REM
REM This script must be executed from the same directory it exists in, due to use of the "CD" var.
REM

SET PATH=%PATH%;C:\Games\UE_4.25\Engine\Binaries\Win64\
SET RESPONSEFILE=input.txt

ECHO.
ECHO --- Generating ResponseFile...

REM
REM The ResponseFile is generated in the "current directory".
REM The ResponseFile must contain:
REM    Full path to the "input" directory, containing your assets to be packed.
REM    A fixed relative path to be interpreted at runtime. This appears to be a relative path from "Paks" to the "FSD" directory.
REM Full disclosure: I'm assuming this based on the file set up by someone else, but it seems to work.
REM

ECHO.
ECHO "%CD%\input\" "../../../FSD/" > %RESPONSEFILE%


ECHO.
ECHO --- Packing...

ECHO.
MKDIR RigHUD
UnrealPak.exe "%CD%\RigHUD\RigHUD.pak" -Create="%CD%\%RESPONSEFILE%" -compress


ECHO.
ECHO --- Cleaning up ResponseFile...
DEL %RESPONSEFILE%


ECHO.
