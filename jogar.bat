@echo off
title AI Safety - Alinhamento da AURA-67
cd /d "%~dp0"

echo ========================================================
echo   AI Safety: Alinhamento da AURA-67
echo   CESAR School - Projeto Integrador 2 (PI2)
echo ========================================================
echo.

:: 1. Compila as alteracoes mais recentes para Windows via WSL se disponivel
echo [1/2] Verificando compilacao e atualizacoes de codigo...
wsl bash -c "cd /mnt/c/Users/Lenovo-Gabriel/Documents/pi2-squad-e7 && make windows" 2>nul

:: 2. Se o executavel nativo do Windows existir, executa diretamente
if exist "bin\jogo.exe" (
    echo [OK] Executavel Windows atualizado: bin\jogo.exe
    if exist "lib\raylib.dll" copy /y "lib\raylib.dll" "bin\" >nul
    echo [2/2] Iniciando jogo nativo na tela...
    start "" "bin\jogo.exe"
    goto fim
)

:: 3. Se nao conseguir compilar o .exe, executa bin/jogo no WSL
echo.
echo [INFO] Executando binario Linux via WSL...
wsl bash -c "cd /mnt/c/Users/Lenovo-Gabriel/Documents/pi2-squad-e7 && make && (test -n \"$DISPLAY\" || export DISPLAY=:0) && ./bin/jogo"

:fim
echo.
echo ========================================================
echo Sessao finalizada.
echo ========================================================
pause
