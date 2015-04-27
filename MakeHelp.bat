@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by MYINFORMATIONHIDDING.HPJ. >"hlp\MyInformationHidding.hm"
echo. >>"hlp\MyInformationHidding.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\MyInformationHidding.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\MyInformationHidding.hm"
echo. >>"hlp\MyInformationHidding.hm"
echo // Prompts (IDP_*) >>"hlp\MyInformationHidding.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\MyInformationHidding.hm"
echo. >>"hlp\MyInformationHidding.hm"
echo // Resources (IDR_*) >>"hlp\MyInformationHidding.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\MyInformationHidding.hm"
echo. >>"hlp\MyInformationHidding.hm"
echo // Dialogs (IDD_*) >>"hlp\MyInformationHidding.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\MyInformationHidding.hm"
echo. >>"hlp\MyInformationHidding.hm"
echo // Frame Controls (IDW_*) >>"hlp\MyInformationHidding.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\MyInformationHidding.hm"
REM -- Make help for Project MYINFORMATIONHIDDING


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\MyInformationHidding.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\MyInformationHidding.hlp" goto :Error
if not exist "hlp\MyInformationHidding.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\MyInformationHidding.hlp" Debug
if exist Debug\nul copy "hlp\MyInformationHidding.cnt" Debug
if exist Release\nul copy "hlp\MyInformationHidding.hlp" Release
if exist Release\nul copy "hlp\MyInformationHidding.cnt" Release
echo.
goto :done

:Error
echo hlp\MyInformationHidding.hpj(1) : error: Problem encountered creating help file

:done
echo.
