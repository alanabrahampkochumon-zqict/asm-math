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
global __scalar_add_8

__scalar_add_8:
    add ecx, edx
    mov eax, ecx
    ret
