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


; Macro definition for floating point division operation
; Macro argument list
;   %1 Function name
;   %2 Instruction
; %macro GENERATE_OP_DIV_FP 2
;     global %1                                           ; Export the function
;
;     %1:                                                 ; Function definition
;     %2 xmm0, xmm1
; %endmacro


; Macro expansion for add operations
GENERATE_OP_PROC_INT _scalar_add_8,    add,  cl,  dl,  al
GENERATE_OP_PROC_INT _scalar_add_16,   add,  cx,  dx,  ax
GENERATE_OP_PROC_INT _scalar_add_32,   add, ecx, edx, eax
GENERATE_OP_PROC_INT _scalar_add_64,   add, rcx, rdx, rax
GENERATE_OP_PROC_FP  _scalar_add_fp32, addss
GENERATE_OP_PROC_FP  _scalar_add_fp64, addsd

; Macro expansion for subtract operations
GENERATE_OP_PROC_INT _scalar_sub_8,    sub, cl,  dl,  al
GENERATE_OP_PROC_INT _scalar_sub_16,   sub, cx,  dx,  ax
GENERATE_OP_PROC_INT _scalar_sub_32,   sub, ecx, edx, eax
GENERATE_OP_PROC_INT _scalar_sub_64,   sub, rax, rdx, rcx
GENERATE_OP_PROC_FP  _scalar_sub_fp32, subss
GENERATE_OP_PROC_FP  _scalar_sub_fp64, subsd

; Macro expansion for multiply operations
GENERATE_OP_PROC_INT _scalar_mul_16,   imul, cx, dx, ax
GENERATE_OP_PROC_INT _scalar_mul_32,   imul, ecx, edx, eax
GENERATE_OP_PROC_INT _scalar_mul_64,   imul, rcx, rdx, rax
GENERATE_OP_PROC_FP  _scalar_mul_fp32, mulss
GENERATE_OP_PROC_FP  _scalar_mul_fp64, mulsd


GENERATE_OP_PROC_FP _scalar_div_fp32, divss
GENERATE_OP_PROC_FP _scalar_div_fp64, divsd
