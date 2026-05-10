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

; Macro Definition for basic math operations
; Macro argument list
;   %1 Function Name
;   %2 Instruction (add, sub)
;   %3 LHS Register
;   %4 RHS Register
;   %5 Return Register
%macro GENERATE_OP_PROC_INT 5
    global %1                                           ; Export the function

    %1:                                                 ; Function Definition
    %2 %3, %4                                           ; Perform the operation on LHS and RHS, and store the result in LHS register
    mov %5, %3                                          ; Move the result to return register
    ret                                                 ; Return from the function
%endmacro


; Macro expansion for add operations
GENERATE_OP_PROC_INT _scalar_add_8,  add,  cl,  dl,  al
GENERATE_OP_PROC_INT _scalar_add_16, add,  cx,  dx,  ax
GENERATE_OP_PROC_INT _scalar_add_32, add, ecx, edx, eax
GENERATE_OP_PROC_INT _scalar_add_64, add, rcx, rdx, rax