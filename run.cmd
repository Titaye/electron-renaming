mkdir test
powershell -Command "& { Invoke-WebRequest -Uri 'https://github.com/electron/electron/releases/download/v4.0.0-beta.4/electron-v4.0.0-beta.4-win32-ia32.zip' -OutFile 'test/electron-v4.0.0-beta.4-win32-ia32.zip' }"
powershell -Command "& { Expand-Archive 'test/electron-v4.0.0-beta.4-win32-ia32.zip' -DestinationPath 'electron4/' }"

REM beta 4 is failing as testnative.node is linked to node.exe
electron4\electron.exe .

REM testing with node.exe is ok
ren electron4\electron.exe node.exe
electron4\node.exe .

REM testing with myapp.exe is not ok
ren electron4\node.exe myapp.exe
electron4\myapp.exe .
