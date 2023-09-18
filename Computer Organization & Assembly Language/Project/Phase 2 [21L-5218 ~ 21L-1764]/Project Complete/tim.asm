%include 'fH.asm'
%include 'scr.asm'
[org 0x0100]

jmp startT

; --------------------------------------------------------------------------------------
; offsets for default interrupt handlers
; --------------------------------------------------------------------------------------


sysTimer: dd 0


; --------------------------------------------------------------------------------------
; variables for subroutines
; --------------------------------------------------------------------------------------

tickcount: dw 0
seconds: dw 0x005A

timeLeftPrompt: db ' seconds left...', 0

; --------------------------------------------------------------------------------------
; hook for IRQ 0 or int 0x08
; params: none
; --------------------------------------------------------------------------------------

myTimer: 
	push ax
	push bx
	push cx
	
	
	
	; if time's up, jump to 'gameOver'
	cmp word [cs:seconds], 0
	jne notZero_
	

	call gameOverBoulder
	
	
	
	notZero_:
		
		
		
		; decrementing a second
		cmp word [cs:tickcount], 18
		jl skipForShort_
	
		push 0x0E
		push 0
		sub word [cs:seconds], 1
		push word [cs:seconds]
		call printNum 
		mov word [cs:tickcount], 0
		skipForShort_:
			
			inc word [cs:tickcount]
			
			
			mov al, 0x20
			out 0x20, al 
		
			
			pop cx
			pop bx
			pop ax
			iret

; --------------------------------------------------------------------------------------
; hooks IRQs 0 and 1, or int 0x08 and 0x09
; params: none
; --------------------------------------------------------------------------------------

hookMyISR:
	push es
	push ax 
	
	xor ax, ax
	mov es, ax 
	mov ax, [es:8*4]
	mov [sysTimer], ax
	mov ax, [es:8*4+2]
	mov [sysTimer+2], ax
	mov ax, [es:9*4]
	
	cli 
	mov word [es:8*4], myTimer
	mov [es:8*4+2], cs 
	
	sti 
	
	pop ax
	pop es
	ret


; --------------------------------------------------------------------------------------
; unhooks IRQs 0 and 1, or int 0x08 and 0x09
; params: none
; --------------------------------------------------------------------------------------

unhookMyISR:
	push es
	push ax 
	push bx
	
	xor ax, ax
	mov es, ax 

	cli
	mov ax, [sysTimer]
	mov bx, [sysTimer+2]
	mov word [es:8*4], ax 				;contains timer routine
	mov [es:8*4+2], bx 
	sti
	cli

	mov word [es:9*4], ax
	mov [es:9*4+2], bx 
	sti
	
	pop bx
	pop ax
	pop es
	ret

startT:
