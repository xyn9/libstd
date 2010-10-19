@echo off
rem libstd make
rem xyn9 <xyn9.mail@gmail.com>
rem (CC) Attribution-NonCommercial-ShareAlike, http://creativecommons.org/licenses/by-nc-sa/3.0/
rem ------------------------------------------------------------
cd "%~dp0"
rem NMAKE path(required)
set LSTD_NMAKE_BIN="%ProgramFiles%\Microsoft Visual Studio\VC98\Bin\NMAKE.EXE"
rem Archiver option(optional)
set LSTD_ARCHIVER=
rem %SystemDrive%\bin\archiver\7-zip\7za.exe a -r- -ms=off -mx=9
rem ------------------------------------------------------------
set LSTD_NMAKE_CFG=%~1
if "%LSTD_NMAKE_CFG%" == "" (
	set LSTD_NMAKE_CFG=default
)
set LSTD_NMAKE_FILE=%LSTD_NMAKE_CFG%.mak
rem ------------------------------------------------------------
echo:
echo ::::: libstd(%LSTD_NMAKE_CFG%) :::::
echo:
%LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% /clean
del *.lib *.obj *.plg *.ncb *.pdb
%LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE%
if "%LSTD_NMAKE_CFG%" == "nostartup" (
	del /Q _crt0cw.obj _startup.obj
	%LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% console=1
)
rem del *.obj
rem %LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% unicode=1
rem del *.obj
rem %LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% debug=1
echo:
echo .......................................
del *.obj
%LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% mt=1
if "%LSTD_NMAKE_CFG%" == "nostartup" (
	del /Q _crt0cw.obj _startup.obj
	%LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% mt=1 console=1
)
rem del *.obj
rem %LSTD_NMAKE_BIN% /f %LSTD_NMAKE_FILE% mt=1 debug=1
echo:
echo .......................................
echo:
xcopy libstd*.lib libstd\ /I /-Y
del /Q libstd*.lib
xcopy libstd.h libstd\ /I /-Y
if %LSTD_NMAKE_CFG% == nostartup (
	xcopy _startup.cpp libstd\ /I /-Y
)
ren libstd %LSTD_NMAKE_CFG%
del *.obj
echo:
echo .......................................
if not "%LSTD_ARCHIVER%" == "" (
	%LSTD_ARCHIVER% libstd %LSTD_NMAKE_CFG%
	rmdir /S /Q .\%LSTD_NMAKE_CFG%
)
rem 
set LSTD_NMAKE_BIN=
set LSTD_ARCHIVER=
set LSTD_NMAKE_CFG=
set LSTD_NMAKE_FILE=
echo -done-
