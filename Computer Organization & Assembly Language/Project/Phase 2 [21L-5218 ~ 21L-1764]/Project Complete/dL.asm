
%include 'sL.asm'

[org 0x100]

jmp start




; --------------------------------------------------------------------------------------
; game objects 
; data members (in order): character(for check), ascii Value, attribute 
; --------------------------------------------------------------------------------------


heart: db 'x',0x03,0x05
dirt: db 'x',0xB1,0x66
Rockford: db 'R',0x02,0x8A
TargetExit: db 'T',0x7F,0x84
Boulder: db 'B',0x09,0x05
Diamond: db 'D',0x04,0x0B
Wall: db 'W',0xDB,0x08
visitedChar: db 'V',0x00

; --------------------------------------------------------------------------------------
; postions
; data members (in order): ypos,xpos
; --------------------------------------------------------------------------------------

currRockfordPos: dw 0,0 
initpos: dw 0,0 

; --------------------------------------------------------------------------------------
; lines of text/strings
; --------------------------------------------------------------------------------------

message: db " "
GameOver: db "!!!                                Game  Over                                !!!"
gOver: dw 80
YouWin: db "!!!                                 You  Win                                 !!!"
yWin: dw 80

fLength: dw 1



start:

	
	;initialization
	mov ax,data
	
	
	mov si,3 ;row		
	mov di,1 ;column
	mov cx,0 
	jmp row
	
incY:
	mov di,1
	inc si
	
row:
	cmp si,22  
	ja terminate1
			
col:
	cmp di,78 
	ja incY
	;-------------------------------------------------	
	mov ax, di
	push ax 			;x position 
	mov ax, si
	push ax 			;ypos
	
	mov ax, 0x07 
	push ax 			;attribute 
	mov ax, data
	add ax,cx
	
	;short Jump issue tackled here
	jmp cont
	terminate1:
	jmp terminate
	cont:
	
	;-character comparison begins here 
	push si
	push di
	push cx
	

	
;DirtCheck
	mov si, ax
    mov di, dirt
    mov cx, 1			; max iterations of REPE
    repe cmpsb
    je isDirt
	
;WallCheck
	mov si, ax
    mov di, Wall
    mov cx, 1			; max iterations of REPE
    repe cmpsb
	je isWall
	
;RockfordCheck
	mov si, ax
    mov di, Rockford
    mov cx, 1			; max iterations of REPE
    repe cmpsb
	je isRockFord
	
;TargetExitCheck
	mov si, ax
    mov di, TargetExit
    mov cx, 1			; max iterations of REPE
    repe cmpsb
    je isTarget
	
;BoulderCheck
	mov si, ax
    mov di, Boulder
    mov cx, 1			; max iterations of REPE
    repe cmpsb
	je isBoulder
	
;DiamondCheck
	mov si, ax
    mov di, Diamond
    mov cx, 1			; max iterations of REPE
    repe cmpsb
	je isDiamond
	
	pop cx
	pop di
	pop si
	pop ax
	pop ax
	pop ax
	
	inc cx 
	jmp col
	
	



isDirt:
	;-attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x66			;new attr 
	push ax
	;---attr
	mov ax,dirt
	inc ax
	jmp endCharCheck
isWall:
	;-attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x08			;new attr 
	push ax
	;-attr
	mov ax,Wall
	inc ax
	jmp endCharCheck
isRockFord:
	;-attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x8A			;new attr 
	push ax
	;-attr
	mov ax, Rockford
	inc ax
	
	;the position of rockford
	mov [currRockfordPos],si;ypos
	mov [currRockfordPos+2],di;xpos
	
	jmp endCharCheck
isTarget:
	;---attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x84			;new attr 
	push ax
	;---attr
	mov ax,TargetExit
	inc ax
	jmp endCharCheck
isBoulder:
	
	;---attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x05			;new attr 
	push ax
	;---attr
	mov ax,Boulder
	inc ax
	jmp endCharCheck
isDiamond:
;---attr
	pop cx
	pop di
	pop si
	pop ax
	mov ax,0x0B			;new attr 
	push ax
	;---attr
	mov ax,Diamond
	inc ax
	jmp endCharCheck




	
endCharCheck:

	push ax 				;address of message 
	push word [fLength] 	;message length 
	call printstr 
	
	inc di
	inc cx 
	jmp col
		
terminate:

	;set inital position
	mov si, currRockfordPos
	mov di, initpos
	mov ax, [si]
	mov [di], ax
	
	mov ax, [si+2]
	mov [di+2], ax
