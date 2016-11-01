set PROGRAM="%~1"

rem empty file test
%PROGRAM% empty.txt %TEMP%\empty-out.txt "first string" "second string"
if %ERRORLEVEL% EQU 1 goto err

rem replace one string in one line
%PROGRAM% one-line.txt %TEMP%\one-line-out.txt "the" "a"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\one-line-out.txt one-line.txt
if %ERRORLEVEL% EQU 0 goto err

rem one line test with empty search string
%PROGRAM% one-line.txt %TEMP%\one-line-out.txt "" "a"
if %ERRORLEVEL% NEQ 1 goto err

rem 1231234 test
%PROGRAM% numbers.txt %TEMP%\numbers-out.txt "1231234" "6"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\numbers-out.txt numbers.txt
if %ERRORLEVEL% EQU 0 goto err

rem multiline multiword test
%PROGRAM% multiline-multiword.txt %TEMP%\multiline-multiword-out.txt "is" "was"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\multiline-multiword-out.txt multiline-multiword.txt
if %ERRORLEVEL% EQU 0 goto err

rem mama test
%PROGRAM% mama.txt %TEMP%/mama-out.txt "ma" "mama"
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\mama-out.txt mama.txt
if %ERRORLEVEL% EQU 0 goto err

rem undentified file
%PROGRAM% input.txt %TEMP%/output.txt "first string" "second string"
if %ERRORLEVEL% NEQ 1 goto err

rem invalid number of arguments
%PROGRAM% mama.txt %TEMP%/mama-out.txt "ma"
if %ERRORLEVEL% NEQ 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1