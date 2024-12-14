@echo off

for /l %%i in (1, 1, 1000) do (

    test.exe > test.inp
    A.exe < test.inp > test.out
    B.exe < test.out > answer.out
    fc answer.inp answer.out > 0 || echo TEST %%i [WA] && type test.inp && goto :out
    echo TEST %%i [AC]

)

:out
