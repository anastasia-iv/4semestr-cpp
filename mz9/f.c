section .data
    num dq 1.0
    num1 dq 3.0
    num2 dq 2.0
section .bss
    help resq 1
section .text
global f1
f1:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8] ;x
    fld qword[ebp+8] ;x
    fistp qword[help]
    fild qword[help] ; x [x]
    fsubp ;x - [x]
    f2xm1 ;2^(x - [x]) - 1
    fld1 ;2^(x - [x]) - 1  1
    faddp ;2^(x - [x])
    fild qword[help] ;2^(x - [x]) [x]
    fxch ;[x] 2^(x - [x])
    fscale ;2^(x - [x]) 2^(x - [x]) * 2^[x]
    fstp ST1
    fld qword[num]
    faddp
    mov esp, ebp
    pop ebp
    ret
    
global f2
f2:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[ebp+8]
    fmulp
    fld qword[ebp+8]
    fmulp
    fld qword[ebp+8]
    fmulp
    fld qword[ebp+8]
    fmulp
    mov esp, ebp
    pop ebp
    ret

global f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld qword[num]
    fld qword[ebp+8]
    fsubp ; 1 - x
    fld qword[num1]
    fdivp
    mov esp, ebp
    pop ebp
    ret