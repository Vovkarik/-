set PROGRAM = "%~1"

%PROGRAM% empty.txt %TEMP%\empty-out.txt
if %ERRORLEVEL% EQU 1 goto err

%PROGRAM% in.txt %TEMP%\out.txt Чайка Галка
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\out.txt in.txt
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% mama.txt %TEMP% / mama-out.txt ма мама
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\mama-out.txt mama.txt
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% numbers.txt %TEMP% / numbers-out.txt 1231234 1231231234
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\numbers-out.txt numbers.txt
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1