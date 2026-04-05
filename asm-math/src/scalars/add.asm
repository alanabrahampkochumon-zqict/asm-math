; Arithmetic operations for scalars.
;=========================================================
;                        MACROS
;=========================================================
GENERATE_OP_PROC_INT MACRO func_name, instr_name, arg1_reg, arg2_reg, ret_reg                                   ; Macro definition for integral addition.
    PUBLIC func_name
    func_name PROC
        instr_name arg1_reg, arg2_reg
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
GENERATE_OP_PROC_INT _asm_scalar_add_8, ADD, CL, DL, AL                                             ; Addition macro invocation for 8-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_add_16, ADD, CX, DX, AX                                            ; Addition macro invocation for 16-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_add_32, ADD, ECX, EDX, EAX                                         ; Addition macro invocation for 32-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_add_64, ADD, RCX, RDX, RAX                                         ; Addition macro invocation for 64-bit integrals.
GENERATE_ADD_PROC_FLOAT _asm_scalar_add_f32, ADDSS                                                  ; Addition macro invocation for 32-bit floating point type.
GENERATE_ADD_PROC_FLOAT _asm_scalar_add_f64, ADDSD                                                  ; Addition macro invocation for 64-bit floating point type.


GENERATE_OP_PROC_INT _asm_scalar_sub_8, SUB, CL, DL, AL                                             ; Subtraction macro invocation for 8-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_sub_16, SUB, CX, DX, AX                                            ; Subtraction macro invocation for 16-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_sub_32, SUB, ECX, EDX, EAX                                         ; Subtraction macro invocation for 32-bit integrals.
GENERATE_OP_PROC_INT _asm_scalar_sub_64, SUB, RCX, RDX, RAX                                         ; Subtraction macro invocation for 64-bit integrals.

END