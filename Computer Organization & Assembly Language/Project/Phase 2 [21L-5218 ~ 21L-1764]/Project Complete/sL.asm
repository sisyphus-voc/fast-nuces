[org 0x100]
jmp start2

; --------------------------------------------------------------------------------------
; lines of text/strings
; --------------------------------------------------------------------------------------
length: dw 1 ; length of string

GameTitle: db "Boulder Dash --- N U C E S Edition"
gtLength: dw 34

GuideMessage1: db "Arrow Keys: move"
gm1Length: dw 16

GuideMessage2: db "Esc: quit"
gm2Length: dw 9

GuideMessage3: db "Score : 0"
gm3Length: dw 9

GuideMessage4: db "Level: 1"
gm4Length: dw 8


; --------------------------------------------------------------------------------------
; subroutine to clear screen
; params: none
; --------------------------------------------------------------------------------------
clrscr: 
	push es 
	push ax 
	push cx 
	push di 
	mov ax, 0xb800 
	mov es, ax ; point es to video base 
	xor di, di ; point di to top left column 
	mov ax, 0x0720 ; space char in normal attribute 
	mov cx, 2000 ; number of screen locations 
	cld ; auto increment mode 
	rep stosw ; clear the whole screen 
	pop di
	pop cx 
	pop ax 
	pop es 
	ret 
; --------------------------------------------------------------------------------------
; subroutine to print string
; params: xpos, ypos, attribute, address, messageLength
; --------------------------------------------------------------------------------------
printstr:
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	mov ax, 0xb800

	mov es, ax ; point es to video base
	mov al, 80 ; load al with columns per row
	mul byte [bp+10] ; multiply with y position
	add ax, [bp+12] ; add x position
	shl ax, 1 ; turn into byte offset
	mov di,ax ; point di to required location
	mov si, [bp+6] ; point si to string
	mov cx, [bp+4] ; load length of string in cx
	mov ah, [bp+8] ; load attribute in ah
	cld ; auto increment mode
nextchar2: 
	lodsb ; load next char in al
	stosw ; print char/attribute pair
	loop nextchar2 ; repeat for the whole string
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 10



; --------------------------------------------------------------------------------------
; Print entire Row
; params: ypos
; --------------------------------------------------------------------------------------
printBoundaryTB:
	push bp
	mov bp, sp

	push ax
	push cx
	push si
	push di
	mov cx,0
	mov si,[bp+4];row #
	mov di,0
TB:

	mov ax, di
	push ax ;push x position 
	mov ax, si
	push ax ; push y position 
	mov ax, 0x08 ; blue on black attribute 
	push ax ; push attribute 
	mov ax, Wall
	inc ax
	push ax ; push address of message 
	push word [length] ; push message length 
	call printstr ; call the printstr subroutine
	cmp cx,79
	je endTB
	inc cx
	inc di
	jmp TB



endTB:

	pop di
	pop si
	pop cx
	pop ax
	pop bp
	ret 2
; --------------------------------------------------------------------------------------
; Print entire Column
; params: xpos
; --------------------------------------------------------------------------------------
printBoundaryLR:
	push bp
	mov bp, sp

	push ax
	push cx
	push si
	push di
	mov cx,0
	mov di,[bp+4];col #
	mov si,3
LR:

	mov ax, di
	push ax ;push x position 
	mov ax, si
	push ax ; push y position 
	mov ax, 0x08 ; blue on black attribute 
	push ax ; push attribute 
	mov ax, Wall
	inc ax
	push ax ; push address of message 
	push word [length] ; push message length 
	call printstr ; call the printstr subroutine
	cmp cx,20
	je endLR
	inc cx
	inc si
	jmp LR



endLR:

	pop di
	pop si
	pop cx
	pop ax
	pop bp
	ret 2

start2:
	call clrscr ; call the clrscr subroutine 



; --------------------------------------------------------------------------------------
; Game Text Layout
; --------------------------------------------------------------------------------------

	;Game Title
	mov ax, 23
	push ax						;xpos
	mov ax, 0
	push ax						;ypos
	mov ax, 0x07 		 
	push ax						;attribute 
	mov ax, GameTitle
	push ax 			 		;address of message 
	push word [gtLength]		;message length 
	call printstr

	;Guide Message 1	
	mov ax, 1
	push ax						;xpos
	mov ax, 1
	push ax						;ypos
	mov ax, 0x07  
	push ax						;attribute 
	mov ax, GuideMessage1
	push ax 					;address of message 
	push word [gm1Length]		;message length 
	call printstr 

	;Guide Message 2	
	mov ax, 70
	push ax						;xpos
	mov ax, 1
	push ax						;ypos
	mov ax, 0x07
	push ax						;attribute 
	mov ax, GuideMessage2
	push ax 					;address of message 
	push word [gm2Length] 		;message length 
	call printstr 

	;Guide Message 3	
	mov ax, 1
	push ax 					;xpos
	mov ax, 24
	push ax 					;ypos
	mov ax, 0x07  
	push ax 					;attribute 
	mov ax, GuideMessage3
	push ax 					;address of message 
	push word [gm3Length] 		;message length 
	call printstr 

	;Guide Message 4	
	mov ax, 71
	push ax 					;xpos
	mov ax, 24
	push ax 					;ypos
	mov ax, 0x07  
	push ax 					;attribute 
	mov ax, GuideMessage4
	push ax 					;address of message 
	push word [gm4Length] 		;message length 
	call printstr 

; --------------------------------------------------------------------------------------
; Game Boundary Wall
; --------------------------------------------------------------------------------------


	mov ax, 2
	push ax 					;ypos
	call printBoundaryTB

	mov ax, 23
	push ax 					;ypos
	call printBoundaryTB

	mov ax, 0
	push ax 					;xpos
	call printBoundaryLR

	mov ax, 79
	push ax 					;xpos
	call printBoundaryLR



