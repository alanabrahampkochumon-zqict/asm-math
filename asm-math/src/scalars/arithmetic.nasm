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
%macro GENERATE_OP_DIV_INT 2
    global %1                                           ; Export the function

    %1:                                                 ; Function definition
    %2 xmm0, xmm1
%endmacro



;------------------------------------------;
;            SCALAR DIVISION               ;
;------------------------------------------;

global _scalar_div_8
_scalar_div_8:
    mov al, cl                                         ; Move the dividend to destination (AL)
    mov r8b, dl                                        ; Move the divisor to GP register
    cbw                                                ; Sign extend (Byte to Word) DL:AL
    idiv r8b                                           ; Perform the division
    ret

global _scalar_div_16
_scalar_div_16:
    mov ax, cx                                        ; Move the dividend to destination (AX)
    mov r8w, dx                                       ; Move the divisor to a GP register
    cwd                                               ; Sign extend (Word to Double Word) DX:AX
    idiv r8w                                          ; Perform the division. Result stored in EAX
    ret    


global _scalar_div_32
_scalar_div_32:
    mov eax, ecx                                      ; Move the dividend to destination (EAX)
    mov r8d, edx                                      ; Move the divisor to a GP register
    cdq                                               ; Sign extend (Double Word to Quad Word) EDX:EAX
    idiv r8d                                          ; Perform the division. Result stored in EAX
    ret
    
global _scalar_div_64
_scalar_div_64:
    mov rax, rcx                                      ; Move the dividend to destination (RAX)
    mov r8, rdx                                       ; Move the divisor to a GP register
    cqo                                               ; Sign extend (Quad Word to Octo Word) RDX:RAX
    idiv r8                                           ; Perform the division. Result stored in RAX
    ret

global _scalar_div_8u
_scalar_div_8u:
    mov al, cl                                        ; Move the dividend to destination (AL)
    mov r8b, dl                                       ; Move the divisor to a GP register
    xor dl, dl                                        ; Zero out the DL register
    div r8b                                           ; Perform the division
    ret
    
global _scalar_div_16u
_scalar_div_16u:
    mov ax, cx                                        ; Move the dividend to destination (AX)
    mov r8w, dx                                       ; Move the divisor to a GP register
    xor dx, dx                                        ; Zero out the DX register
    div r8w                                           ; Perform the division
    ret

global _scalar_div_32u
_scalar_div_32u:
    mov eax, ecx                                      ; Move the dividend to destination (EAX)
    mov r8d, edx                                      ; Move the divisor to a GP register
    xor edx, edx                                      ; Zero out the DL register
    div r8d                                           ; Perform the division
    ret
    
global _scalar_div_64u
_scalar_div_64u:
    mov rax, rcx                                      ; Move the dividend to destination (AL)
    mov r8, rdx                                       ; Move the divisor to a GP register
    xor rdx, rdx                                      ; Zero out the DL register
    div r8                                            ; Perform the division
    ret


;------------------------------------------;
;            MACRO EXPANSION               ;
;------------------------------------------;

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

; Macro expansion for floating point division.--*
GENERATE_OP_PROC_FP _scalar_div_fp32, divss
GENERATE_OP_PROC_FP _scalar_div_fp64, divsd
