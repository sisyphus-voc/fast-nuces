[org 0x0100]

jmp startH
; --------------------------------------------------------------------------------------
; game objects 
; data members (in order): x coordinates, y coordinates, breadth, length, character, no animation (0)/animation (1)
; --------------------------------------------------------------------------------------

WinScreenAnim: dw 0, 0, 80, 25, 0x2220, 1

LoseScreenAnim: dw 0, 0, 80, 25, 0x4420, 1


startScreen: dw 20, 10, 40, 7, 0x4420, 1
endScreen: dw 20, 10, 40, 5, 0x0720, 1
WinScreen: dw 20, 10, 40, 5, 0x2220, 1
clearstartScreen: dw 20, 10, 40, 7, 0x0720, 1

gameTitleAttr: db 0x4E
startScreenPromptAttr: db 0xCF
; --------------------------------------------------------------------------------------
; lines of text/strings
; --------------------------------------------------------------------------------------

gameTitle: db ' -Boulder Dash Game ', 0
startScreenPrompt: db ' Press ENTER to Start Game ', 0

WinScreenPrompt: db 'You Win !', 0


endScreenPrompt: db 'Game Over', 0
endScreenPromptT: db 'Game Over : Time up', 0
scorePrompt: db 'Final Score: ', 0
score: db 'Score: ', 0


; --------------------------------------------------------------------------------------
; prints number on screen 
; params: attribute, screen location (in bytes), offset of number
; --------------------------------------------------------------------------------------

printNum: 
	push bp
	mov bp, sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di

	mov ax, 0xB800
	mov es, ax 
	mov ax, [bp + 4] 
	mov bx, 10 
	mov cx, 0 

	nextDigit_: 
		mov dx, 0 
		div bx 
		add dl, 0x30
		push dx
		inc cx 
		cmp ax, 0 
		jnz nextDigit_

	mov di, [bp + 6]
	cmp word [bp + 4], 100
	jge nextPos_
	
	; when our value < 100, we need to shift the digits one column to the right
	mov dh, [bp + 8]
	mov dl, '0'
	mov word [es:di], dx
	add di, 2

	nextPos_: 
		pop dx 
		mov dh, [bp + 8] 
		mov [es:di], dx 
		add di, 2 
		loop nextPos_ 

	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop es
	pop bp
	ret 6

; --------------------------------------------------------------------------------------
; clears screen  
; params: none
; --------------------------------------------------------------------------------------

clrscrHH:     
	push es
        push ax
        push di
        push cx

        mov ax,0xb800
        mov es,ax
        xor di,di
        mov ax,0x0720
        mov cx,2000

        cld
        rep stosw

        pop cx
        pop di
        pop ax
        pop es
        ret

; --------------------------------------------------------------------------------------
; draws the game objects 
; params: offset of game object
; --------------------------------------------------------------------------------------

drawGameObject:
	push bp
	mov bp, sp
	sub sp, 2
	push es
	push ax
	push bx
	push cx
	push si
	push di
	
	; si points to game object's offset
	mov si, [bp + 4]

	mov ax, 0xB800
	mov es, ax 
	mov al, 80 
	mul byte [si + 2]
	add ax, [si] 
	shl ax, 1 
	mov di, ax 
	mov word [bp - 2], ax
	
	; load character in ax, breadth of object in bx, and length in cx
	mov ax, [si + 8]
	mov bx, [si + 6]
	mov cx, [si + 4]
	
	

	nextLineWithAni_:
		mov [es:di], ax
		push 1
		call myDelay
		add di, 2
		dec cx
		cmp cx, 0
		jnz nextLineWithAni_
		mov cx, [si + 4]
		add word [bp - 2], 160
		mov di, [bp - 2]
		dec bx
		cmp bx, 0
		jnz nextLineWithAni_
		jmp exitdrawGameObject_
		
	nextLine_:
		rep stosw
		mov cx, [si + 4]
		add word [bp - 2], 160
		mov di, [bp - 2]
		dec bx
		cmp bx, 0
		jnz nextLine_
	
	exitdrawGameObject_:
		pop di
		pop si 
		pop cx
		pop bx
		pop ax
		pop es
		add sp, 2
		pop bp
		ret 2

; --------------------------------------------------------------------------------------
; prints text on screen  
; params: x coordinates, y coordinates, attribute, offset of string
; --------------------------------------------------------------------------------------

loadTextOnScreen:
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	
	push ds
	pop es
	mov di, [bp + 4] 
	mov cx, 0xffff 
	xor al, al 
	repne scasb 
	mov ax, 0xffff 
	sub ax, cx 
	dec ax 
	jz exitloadTextOnScreen_

	mov cx, ax
	mov ax, 0xB800
	mov es, ax 
	mov al, 80 
	mul byte [bp + 8]
	add ax, [bp + 10] 
	shl ax, 1 
	mov di, ax 
	mov si, [bp + 4] 
	mov ah, [bp + 6] 

	cld 
	nextChar_: 
		lodsb 
		stosw 
		loop nextChar_

	exitloadTextOnScreen_:
		pop di
		pop si
		pop cx
		pop ax
		pop es
		pop bp
		ret 8

; --------------------------------------------------------------------------------------
; loads countdown
; params: none
; --------------------------------------------------------------------------------------

printOne:
	push es
 	push ax
     	push cx
    	push di
     	push si
     	push dx
            
	mov ax, 0xB800
     	mov es, ax
     	mov di, 876
     	mov si, 16
			
    	 nextLocForPrtOne_:
		mov word[es:di], 0x2bdb
		add di, 2
		mov word[es:di], 0x2bdb
		add di, 2
		mov word[es:di], 0x2bdb
		add di, 156
		sub si, 1
		cmp si, 0
		jz exitPrintOne_
		jmp nextLocForPrtOne_
          
	exitPrintOne_:
          pop dx
          pop si
          pop di
          pop cx
          pop ax
          pop es
          ret
	
printTwo:
	push es
	push ax
	push cx
	push di
	push si
	push dx
 
	
	mov ax, 0xB800
	mov es, ax
	mov ax, 0x01DB
	
	mov di, 704
	mov cx, 18	
	hori_1:
		mov word [es:di], ax
		add di,2
		loop  hori_1
			
				
	mov di, 1664
	mov cx, 18
	hori_2:
		mov word [es:di], ax
		add di,2
		loop  hori_2
				
	mov di,2784
	mov cx,18
	hori_3:
		mov word [es:di], ax 
		add di,2
		loop  hori_3
	
	mov di, 738
	mov cx, 7
	verti_1:
		mov word [es:di], ax
		add di, 2
		mov word [es:di], ax
		add di, 158
		loop verti_1
			
			
	mov di, 1664
	mov cx, 7
	verti_2:
		mov word [es:di], ax
		add di, 2
		mov word [es:di], ax
		add di, 158
		loop verti_2
			
     
         pop dx
         pop si
         pop di
         pop cx
         pop ax
         pop es
         ret
	
printThree:	
	push es
	push ax
	push cx
	push di
	push si
	push dx
	
	mov ax, 0xB800
	mov es, ax
	mov ax, 0x04db
	
	mov di, 704
	mov cx, 18	
	linH_1:
		mov word [es:di], ax
		add di,2
		loop  linH_1
				
	mov di,1664
	mov cx,18
	linH_2:
		mov word [es:di], ax
		add di,2
		loop  linH_2
				
	mov di,2784
	mov cx,18
	linH_3:
		mov word [es:di], ax 
		add di,2
		loop  linH_3
				
	mov di, 900
	mov cx, 7
	linV_1:
		mov word [es:di], ax
		add di, 2
		mov word [es:di], ax
		add di, 158
		loop linV_1
			
	mov di,1700
	mov cx, 7
	linV_2:
		mov word [es:di], ax
		add di, 2
		mov word [es:di], ax
		add di, 158
		loop linV_2
	
     
         pop dx
         pop si
         pop di
         pop cx
         pop ax
         pop es
         ret

; --------------------------------------------------------------------------------------
; creates a delay  
; params: factor by which to delay
; --------------------------------------------------------------------------------------

myDelay:
	push bp
	mov bp, sp
	push cx

	; change the values  to increase delay time
	mov cx, [bp + 4]

	firstDelay_:
		push cx
		mov cx, 0xFFFF

		secondDelay_:
			loop secondDelay_

		pop cx
		loop firstDelay_

		pop cx
		pop bp
		ret 2

; --------------------------------------------------------------------------------------
; loads start screen
; params: none
; --------------------------------------------------------------------------------------

loadStartScreen:
	call clrscrHH
	mov ax, startScreen
	push ax
	call drawGameObject
	mov ax, 31
	push ax
	mov ax, 12
	push ax
	mov ax, [gameTitleAttr]
	push ax
	mov ax, gameTitle
	push ax
	call loadTextOnScreen 
	mov ax, 28
	push ax
	mov ax, 14
	push ax
	mov ax,[startScreenPromptAttr]
	push ax
	mov ax, startScreenPrompt
	push ax
	call loadTextOnScreen 
	
	ret

; --------------------------------------------------------------------------------------
; clears start screen
; params: none
; --------------------------------------------------------------------------------------

clearStartScreen:
	push ax
	enterKeyNotPressed:
	mov ah, 0
	int 0x16
	cmp al, 13
	jne enterKeyNotPressed
	mov ax, clearstartScreen
	push ax
	call drawGameObject
	
	pop ax
	ret	

; --------------------------------------------------------------------------------------
; loads countdown at game start
; params: none
; --------------------------------------------------------------------------------------

loadCountdown:
	push ax	
	call printThree
	mov ax, 10
	push ax
	call myDelay
	call clrscrHH
	call printTwo
	mov ax, 10
	push ax
	call myDelay
	call clrscrHH
	call printOne
	mov ax, 10
	push ax
	call myDelay
	call clrscrHH
	pop ax
	ret




; --------------------------------------------------------------------------------------
; loads ending screen
; params: none
; --------------------------------------------------------------------------------------

loadEndScreen:
	mov ax, endScreen
	push ax
	call drawGameObject
	mov ax, 36
	push ax
	mov ax, 11
	push ax
	mov ax, 0x84
	push ax
	mov ax, endScreenPrompt
	push ax
	call loadTextOnScreen 
	mov ax, 32
	push ax
	mov ax, 13
	push ax
	mov ax, 0x0E
	push ax
	mov ax, scorePrompt
	push ax
	call loadTextOnScreen 
	push 0x0E
	push 2174
	push word [scoreValue]
	call printNum
	
	ret


loadEndScreenT:
	mov ax, endScreen
	push ax
	call drawGameObject
	mov ax, 36
	push ax
	mov ax, 11
	push ax
	mov ax, 0x84
	push ax
	mov ax, endScreenPromptT
	push ax
	call loadTextOnScreen 
	mov ax, 32
	push ax
	mov ax, 13
	push ax
	mov ax, 0x0E
	push ax
	mov ax, scorePrompt
	push ax
	call loadTextOnScreen 
	push 0x0E
	push 2174
	push word [scoreValue]
	call printNum
	
	ret

loadWinScreen:
	mov ax, endScreen
	push ax
	call drawGameObject
	mov ax, 36
	push ax
	mov ax, 11
	push ax
	mov ax, 0x8A
	push ax
	mov ax, WinScreenPrompt
	push ax
	call loadTextOnScreen 
	mov ax, 32
	push ax
	mov ax, 13
	push ax
	mov ax, 0x0E
	push ax
	mov ax, scorePrompt
	push ax
	call loadTextOnScreen 
	push 0x0E
	push 2174
	push word [scoreValue]
	call printNum
	
	ret

startH:
	call loadStartScreen
	call clearStartScreen
	call loadCountdown
	
	
	
	
	
	
	
	