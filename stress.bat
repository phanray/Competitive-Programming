@echo off

for /l %%i in (1, 1, 1000) do (

    test.exe > test.inp
    A.exe < test.inp > test.out
    B.exe < test.inp > answer.out
    fc test.out answer.out > 0 || echo TEST %%i [WA] && type test.inp && goto :out
    echo TEST %%i [AC]

)

:out
