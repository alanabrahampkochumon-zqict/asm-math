bits 64                                                  ; 64-bit architecture
default rel                                              ; Enable RIP relative addressing

;------------------------------------------;
;               DATA SEGMENT               ;
;------------------------------------------;
segment .data


;------------------------------------------;
;               CODE SEGMENT               ;
;------------------------------------------;
segment .text

; Macro Definition for basic integral math operations
; Macro argument list
;   %1 Function name
;   %2 Instruction (add, sub)
;   %3 LHS Register
;   %4 RHS Register
;   %5 Return Register
%macro GENERATE_OP_PROC_INT 5
    global %1                                           ; Export the function

    %1:                                                 ; Function definition
    %2 %3, %4                                           ; Perform the operation on LHS and RHS, and store the result in LHS register
    mov %5, %3                                          ; Move the result to return register
    ret                                                 ; Return from the function

%endmacro


; Macro definition for basic floating point math operations
; Macro argument list
;   %1 Function name
;   %2 Instruction (addss, addsd...)
%macro GENERATE_OP_PROC_FP 2
    global %1                                           ; Export the function

    %1:                                                 ; Function definition
    %2 xmm0, xmm1                                       ; Perform operation on xmm0 and xmm1 (result for return value is stored in xmm0)
    ret                                                 ; Return from function

%endmacro


; Macro expansion for add operations
GENERATE_OP_PROC_INT _scalar_add_8,    add,  cl,  dl,  al
GENERATE_OP_PROC_INT _scalar_add_16,   add,  cx,  dx,  ax
GENERATE_OP_PROC_INT _scalar_add_32,   add, ecx, edx, eax
GENERATE_OP_PROC_INT _scalar_add_64,   add, rcx, rdx, rax
GENERATE_OP_PROC_FP  _scalar_add_fp32, addss
GENERATE_OP_PROC_FP  _scalar_add_fp64, addsd