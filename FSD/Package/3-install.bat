@ECHO OFF

REM
REM This script uses the full path to your DRG Mods directory.
REM You can customize this using the env var "DRG_MODS".
REM

IF "%DRG_MODS%" == "" (
   SET "DRG_MODS=C:\Games\Steam\steamapps\common\Deep Rock Galactic\FSD\Mods"
)

ECHO.
ECHO --- Installing Mod...

XCOPY /S RigHUD\ "%DRG_MODS%\RigHUD\"

ECHO.
