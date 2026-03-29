; Arithmetic operations for scalars.

.data

.code

PUBLIC _asm_scalar_add                        ; Expose the functions so that C++ can use them

XOR RCX, RCX                                  ; Clear out RCX
XOR RDX, RDX                                  ; Clear out RDX

_asm_scalar_add PROC
	ADD RCX, RDX                              ; Adding RCX and RDX and store the result in RCX
	MOV RAX, RCX                              ; Move result into RAX before returning
	RET

_asm_scalar_add ENDP

END