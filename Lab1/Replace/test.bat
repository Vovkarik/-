set PROGRAM="%~1"

%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem unexisting file test
%PROGRAM% null.txt %TEMP%\null.txt "some string" "some another string"
if %ERRORLEVEL% EQU 0 goto err

rem empty file test
%PROGRAM% empty.txt %TEMP%\empty.txt "some string" "some another string"
if %ERRORLEVEL% EQU 0 goto err

rem multiline file test
%PROGRAM% in.txt %TEMP%\in.txt Водитель Велосипедист
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\in.txt in.txt
if %ERRORLEVEL% EQU 0 goto err

rem mama test
%PROGRAM% mama.txt %TEMP%/mama.txt ма мама
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\mama.txt mama.txt
if %ERRORLEVEL% EQU 0 goto err

rem numbers test
%PROGRAM% numbers.txt %TEMP%/numbers.txt 1231234 easy
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\numbers.txt numbers.txt
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1