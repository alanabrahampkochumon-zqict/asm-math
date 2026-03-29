; Arithmetic operations for scalars.
;=========================================================
;                        MACROS
;=========================================================
GENERATE_ADD_PROC_INT MACRO func_name, arg1_reg, arg2_reg, ret_reg
    PUBLIC func_name
    func_name PROC
        ADD arg1_reg, arg2_reg
        MOV ret_reg, arg1_reg
        RET
    func_name ENDP
ENDM


;=========================================================
;                     DATA SEGMENT
;=========================================================
.data


;=========================================================
;                     CODE SEGMENT
;=========================================================
.code

PUBLIC _asm_scalar_add                                                                                    ; Expose the functions so that C++ can use them
                                                                                                          
XOR RCX, RCX                                                                                              ; Clear out RCX
XOR RDX, RDX                                                                                              ; Clear out RDX
                                                                                                          
_asm_scalar_add PROC                                                                                      
	ADD RCX, RDX                                                                                          ; Adding RCX and RDX and store the result in RCX
	MOV RAX, RCX                                                                                          ; Move result into RAX before returning
	RET

_asm_scalar_add ENDP

GENERATE_ADD_PROC_INT _asm_scalar_add_8, CL, DL, AL                                                       ; Macro invocation for 8-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_16, CX, DX, AX                                                      ; Macro invocation for 16-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_32, ECX, EDX, EAX                                                   ; Macro invocation for 32-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_64, RCX, RDX, RAX                                                   ; Macro invocation for 64-bit integrals.

END