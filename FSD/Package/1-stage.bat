@ECHO OFF

REM
REM This script only uses relative paths and does not need customization.
REM

SET SRCDIR=WindowsNoEditor\FSD
SET PACKDIR=input

ECHO.
ECHO --- Staging files...

ECHO.
XCOPY %SRCDIR%\AssetRegistry.bin %PACKDIR%\
XCOPY /S %SRCDIR%\Content\RigHUD\* %PACKDIR%\Content\RigHUD\*

ECHO.
