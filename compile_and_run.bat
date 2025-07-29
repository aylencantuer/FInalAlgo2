@echo off

echo ===================================
echo   Compiling C++ source files...
echo ===================================

REM -Iinclude tells g++ to look for header files in the 'include' directory.
REM We list all .cpp files, specifying their paths from the root directory.
g++ main.cpp ^
    src\Sensor.cpp ^
    src\EmailNotifier.cpp ^
    src\FileHistoryRepository.cpp ^
    src\DataCenterClimate.cpp ^
    src\ConsoleUI.cpp ^
    -Iinclude -o climate_control.exe -std=c++17 -Wall

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo.
    echo ***********************************
    echo * COMPILATION FAILED!        *
    echo ***********************************
    goto end
)

echo.
echo ===================================
echo      Compilation Successful!
echo ===================================
echo.
echo ===================================
echo      Running the application...
echo ===================================
echo.

REM Run the compiled program
climate_control.exe

:end
echo.
pause
