; Arithmetic operations for scalars.
;=========================================================
;                        MACROS
;=========================================================
GENERATE_ADD_PROC_INT MACRO func_name, arg1_reg, arg2_reg, ret_reg                                   ; Macro definition for integral addition.
    PUBLIC func_name
    func_name PROC
        ADD arg1_reg, arg2_reg
        MOV ret_reg, arg1_reg
        RET
    func_name ENDP
ENDM


GENERATE_ADD_PROC_FLOAT MACRO func_name, add_instr
    public func_name
    func_name PROC
        add_instr XMM0, XMM1
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
GENERATE_ADD_PROC_INT _asm_scalar_add_8, CL, DL, AL                                                 ; Macro invocation for 8-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_16, CX, DX, AX                                                ; Macro invocation for 16-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_32, ECX, EDX, EAX                                             ; Macro invocation for 32-bit integrals.
GENERATE_ADD_PROC_INT _asm_scalar_add_64, RCX, RDX, RAX                                             ; Macro invocation for 64-bit integrals.

GENERATE_ADD_PROC_FLOAT _asm_scalar_add_f32, ADDSS                                                  ; Macro invocation for 32-bit floating point type.
GENERATE_ADD_PROC_FLOAT _asm_scalar_add_f64, ADDSD                                                  ; Macro invocation for 64-bit floating point type.

END