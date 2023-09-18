%include 'tim.asm'
%include 'dL.asm'

[org 0x0100]

jmp startM

; --------------------------------------------------------------------------------------
; postions
; data members (in order): ypos,xpos
; --------------------------------------------------------------------------------------
nextRockfordpos: dw 0,0
heartPosition: dw 24,12
   
; --------------------------------------------------------------------------------------
; postions
; --------------------------------------------------------------------------------------
scorePosition: dw 3858 
livespos: dw 3870 


; --------------------------------------------------------------------------------------
; Game Objects
; Values
; --------------------------------------------------------------------------------------
scoreValue: dw 0
lives: dw 3
	
; --------------------------------------------------------------------------------------
; prints number on screen 
; params: number, position, attribute
; --------------------------------------------------------------------------------------
printnum: 
	
	push bp 		
	mov bp, sp 
	push es 
	push ax 
	push bx 
	push cx 
	push dx 
	push di 
	mov ax, 0xb800 
	mov es, ax 
	mov ax, [bp+4] 			;load number in ax 
	mov bx, 10 				; use base 10 for division 
	mov cx, 0 				; initialize count of digits 
nextdigit: 
	mov dx, 0 				; zero upper half of dividend 
	div bx 					; divide by 10 
	add dl, 0x30 			; convert digit into ascii value 
	push dx 				; save ascii value on stack 
	inc cx 					; increment count of values 
	cmp ax, 0 				; is the quotient zero 
	jnz nextdigit 			; if no divide it again 
	mov di, [bp + 6] 		; point di to position
nextpos: 
	pop dx 					; remove a digit from the stack 
	mov dh, [bp+8] 			; use normal attribute 
	mov [es:di], dx 		; print char on screen 
	add di, 2 				; move to next screen location 
	loop nextpos 			; repeat for all digits on stack
	pop di 
	pop dx 
	pop cx 
	pop bx 
	pop ax 
	pop es 
	pop bp 
	ret 6
	
; --------------------------------------------------------------------------------------
; decrements and prints lives on screen
; params: none
; --------------------------------------------------------------------------------------	
declives:        
	mov bp,sp
	push bp 
	pusha
	mov ax,0x07
	push ax
	
	push word [livespos]
	
	mov ax,[lives]
	dec ax
	mov [lives],ax
	push ax
	call printnum
	
   
	popa
	pop bp
	ret

; --------------------------------------------------------------------------------------
; increments and prints lives on screen
; params: none
; --------------------------------------------------------------------------------------
incScore:          
	mov bp,sp
	push bp 
	pusha
	mov ax,0x07
	push ax
	push word [scorePosition]

	mov ax,[scoreValue]
	inc ax
	mov [scoreValue],ax
	push ax
	call printnum


	popa
	pop bp
	ret

; --------------------------------------------------------------------------------------
; move rockford to the next location
; params: none
; --------------------------------------------------------------------------------------           
moveRockford:
		
	pusha
   
    ;print visitedChar on current position
	mov bx,currRockfordPos          
	mov ax, 0xb800
	mov es, ax 				
	mov al, 80 				
	sub ah, ah 				; making ah 0 to make mul (byte with word)
	mul word [bx]			; ypos
	add ax, [bx+2] 			; xpos
	shl ax, 1 				
	mov di,ax 				; desired location
	mov ah,[visitedChar+1]
	mov al,[visitedChar]
	mov [es:di],ax
	
	
	;print Rockford on next position
	mov bx,nextRockfordpos
	mov ax, 0xb800
	mov es, ax 
	mov al, 80
	sub ah, ah
	mul word [bx]			 ; ypos
	add ax, [bx+2]			 ; xpos
	shl ax, 1				 
	mov di,ax				 ; desired location
	mov ah,[Rockford+2]
	mov al,[Rockford+1]
	mov [es:di],ax
	
	
	mov bx,nextRockfordpos
	
	;update rockford position
	mov dx,[nextRockfordpos]
	mov [currRockfordPos],dx
	mov dx,[nextRockfordpos+2]
	mov [currRockfordPos+2],dx
	popa 
	ret		

; --------------------------------------------------------------------------------------
; Checks live and ends game or respawns rockford
; params: none
; --------------------------------------------------------------------------------------    
livescheck:
	pusha
	call declives
	mov ax, [lives]
	cmp ax, 0
	jnz blinkLives
	
	call gameOverBoulder
		
reduceLives:
; --------------------------------------------------------------------------------------
; Heart and number of lives blink red
; --------------------------------------------------------------------------------------
blinkLives:
	
	mov bx,heartPosition
	mov ax, 0xb800
	mov es, ax					
	mov al, 80					 
	sub ah, ah
	mul word [bx]				 ; ypos
	add ax, [bx+2]				 ; xpos
	shl ax, 1					
	mov di,ax					 ; desired location
	
	;print heart
	mov ah,0x84					 ; attribute
	mov al,[heart+1]			 ; ascii of heart
	mov [es:di],ax
	
	;print x
	add di,4
	mov ah,0x84
	mov al,[dirt]
	mov [es:di],ax
	
	;print lives		
	mov ax,0x84
	push ax
	push word [livespos]
	mov ax,[lives]
	mov [lives],ax
	push ax
	call printnum
	
	;delay
	mov ax,30			  ; delay factor
	push ax
	call myDelay

; --------------------------------------------------------------------------------------
; Heart and number of lives become normal
; --------------------------------------------------------------------------------------	
unblinkLives:

	mov bx,heartPosition
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah
	mul word [bx] 			; ypos
	add ax, [bx+2] 			; xpos
	shl ax, 1 
	mov di,ax 				; desired location
	
	;print heart
	mov ah,[heart+2]		;attr
	mov al,[heart+1]		;ascii of heart
	mov [es:di],ax
	
	;print x
	add di,4
	mov ah,0x07				
	mov al,[dirt]	
	mov [es:di],ax
	
	;print lives
	mov ax,0x07
	push ax
	push word [livespos]
	mov ax,[lives]
	mov [lives],ax
	push ax
	call printnum
	

		
		
; --------------------------------------------------------------------------------------
; Rockford respawns to starting position
; --------------------------------------------------------------------------------------
	   
respawn:
	

	mov bx,currRockfordPos
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah 					; making ah 0 to make mul (byte with word)
	mul word [bx]				; ypos
	add ax, [bx+2]				; xpos
	shl ax, 1 
	mov di,ax 					; desired location
	mov ah,[visitedChar+1]
	mov al,[visitedChar]
	mov [es:di],ax
	
	;Rockford at initial position
	;blinking green
	mov bx,initpos
	mov ax, 0xb800
	mov es, ax 
	mov al, 80
	sub ah, ah
	mul word [bx] 				 ; ypos
	add ax, [bx+2]				 ; xpos
	shl ax, 1
	mov di,ax 					 ; desired location
	mov ah,0x8A
	mov al,[Rockford+1]
	mov [es:di],ax
	
	;reset initial position
	mov si, initpos
	mov di, currRockfordPos
	mov ax, [si]
	mov [di], ax
	mov ax, [si+2]
	mov [di+2], ax
	
	popa 
	ret
			

; --------------------------------------------------------------------------------------
; Rockford and Boulder blink red
; --------------------------------------------------------------------------------------
blinkRockford:

	mov bx,currRockfordPos
	mov ax, 0xb800
	mov es, ax 					
	mov al, 80 					
	sub ah, ah
	mul word [bx] 				; ypos
	add ax, [bx+2] 				; xpos
	shl ax, 1 					
	mov di,ax 					; desired location
	mov ah,0x84
	mov al,[Rockford+1]
	mov [es:di],ax
	
	;boulder blinks red
	mov bx,currRockfordPos
	mov ax,[bx]
	dec ax
	mov [bx],ax
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah
	mul word [bx] 				; ypos
	add ax, [bx+2] 				; xpos
	shl ax, 1 
	mov di,ax 					; desired location
	mov ah,0x84
	mov al,[Boulder+1]
	mov [es:di],ax
	jmp endGame
; --------------------------------------------------------------------------------------
; Game Over,You lose
; --------------------------------------------------------------------------------------
gameOverBoulder:
	jmp blinkRockford
	
endGame:
	
	pusha
	
	
	call loadEndScreen
	;Guide Message 2	
	mov ax, 70
	push ax						;xpos
	mov ax, 1
	push ax						;ypos
	mov ax, 0x8E
	push ax						;attribute 
	mov ax, GuideMessage2
	push ax 					;address of message 
	push word [gm2Length] 		;message length 
	call printstr 
	
	
			;loop until esc is pressed	
kpl:	
	mov ah,0	;ms dos service routine for keystroke
	int 0x16
	
	cmp ah,1			;esc is pressed
	jz endnxtl
	jmp kpl
	
endnxtl:
	mov ah,0			;ms dos service routine for keystroke
	int 0x16
	
	call clrscr
	
	
	

	
	popa 
	call unhookMyISR
	mov ax,0x4c00
	int 0x21
; --------------------------------------------------------------------------------------
; Game Over,You Win
; --------------------------------------------------------------------------------------

Win:

	call moveRockford
	pusha
	;loop until esc is pressed	
	
	call loadWinScreen
	
	;Guide Message 2	
	mov ax, 70
	push ax						;xpos
	mov ax, 1
	push ax						;ypos
	mov ax, 0x8E
	push ax						;attribute 
	mov ax, GuideMessage2
	push ax 					;address of message 
	push word [gm2Length] 		;message length 
	call printstr 
	
	
kpw:	
	mov ah,0	;ms dos service routine for keystroke
	int 0x16
	
	cmp ah,1			;esc is pressed
	jz endnxtw
	jmp kpw
	
endnxtw:
	
	call clrscr
	popa 
	
	call unhookMyISR
	mov ax,0x4c00
	int 0x21

; --------------------------------------------------------------------------------------
; check next step of rockford and take the action
; params: nextposition, currentposition
; -------------------------------------------------------------------------------------- 	
movement:
   
	mov bp,sp
	push bp
	pusha

		
	;Move next character from video memory to a register
	mov bx,nextRockfordpos			  
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah
	mul word [bx] 			; ypos
	add ax, [bx+2] 			; xpos
	shl ax, 1 				
	mov di,ax 				; desired location
	mov dx,[es:di]			; move nextchar to dx

	

	
	
	
	
	;compare next character
	mov ax,0x08DB			;Wall
	cmp ax,dx
	jz endMovement
	
	mov ax,0x0509			;Boulder
	cmp ax,dx
	jz endMovement
	
	
	mov ax,0x0B04			;Diamond
	cmp ax,dx
	jz diamondCheck			;incrementsScore and moves rockford
	
	
	mov ax,0x847F			;Target
	cmp ax,dx
	jz Win
	
	call moveRockford
	jmp checkBoulderAbove
	
		
diamondCheck:
	call incScore
	call moveRockford
		
       
       

checkBoulderAbove:		
	mov si,[currRockfordPos]
	mov di,[currRockfordPos+2]
	dec si
						  
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah
	mul si 						; ypos
	add ax, di 					; xpos
	shl ax, 1 					
	mov di,ax 					; desired location 								
	mov dx,[es:di]				; copy char in dx
	
	mov ax,0x0509				; Boulder
	cmp ax,dx
	jnz endMovement
	call livescheck
	
endMovement:
	popa
	pop bp
	ret
   
rightArrow:
				
	pusha
	mov ax,currRockfordPos 
	
   
	
	mov dx, [currRockfordPos]				;ypos
	
	;copy the current position into next position
	mov [nextRockfordpos],dx				;ypos  
	mov dx, [currRockfordPos+2]				;xpos
	mov [nextRockfordpos+2],dx				;xpos
	mov bx,nextRockfordpos
	
	;editing the next position according to the key
	mov dx,[bx+2]
	inc dx									;col++/xpos++
	mov [bx+2],dx
	
	call movement
	popa
	jmp getKeyPress	
	
leftArrow:

	pusha
	mov ax,currRockfordPos

	mov dx, [currRockfordPos]				;ypos
	
	;copying the current position into next position
	mov [nextRockfordpos],dx				;ypos  
	mov dx, [currRockfordPos+2]				;xpos
	mov [nextRockfordpos+2],dx				;xpos
	mov bx,nextRockfordpos
	
	;editing the next position according to the key
	mov dx,[bx+2]
	dec dx									;col--/xpos--
	mov [bx+2],dx
	
	
	call movement
	popa
	jmp getKeyPress	
	
up:

	pusha
	mov ax,currRockfordPos 
	
   
	
	mov dx, [currRockfordPos]				;ypos
	
	;copying the current position into next position
	mov [nextRockfordpos],dx				;ypos  
	mov dx, [currRockfordPos+2]				;xpos
	mov [nextRockfordpos+2],dx				;xpos
	mov bx,nextRockfordpos
	
	;editing the next position according to the key
	mov dx,[bx]
	dec dx									;row--/ypos--
	mov [bx],dx

	call movement
	popa
	jmp getKeyPress	
	
down:
	
	pusha
	mov ax,currRockfordPos 
	
   
	
	mov dx, [currRockfordPos]				;ypos
	
	;copying the current position into next position
	mov [nextRockfordpos],dx				;ypos  
	mov dx, [currRockfordPos+2]				;xpos
	
	mov [nextRockfordpos+2],dx				;xpos
	mov bx,nextRockfordpos
	
	;editing the next position according to the key
	mov dx,[bx]
	inc dx									;row++/ypos++
	mov [bx],dx
	
   
	

	
	call movement
	popa
	
	
	
	
	jmp getKeyPress	
				
       
startM:         

	
; --------------------------------------------------------------------------------------
; Print Heart and number of lives 
; --------------------------------------------------------------------------------------	

	;print heart
	mov bx,heartPosition
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	sub ah, ah
	mul word [bx] 					; ypos
	add ax, [bx+2]					; xpos
	shl ax, 1 
	mov di,ax 						; desired location
	mov ah,[heart+2]				; attr
	mov al,[heart+1]				; ascii of heart
	mov [es:di],ax
	
	;print x
	add di,4
	mov ah,0x07
	mov al,[dirt]	
	mov [es:di],ax
		
	;print lives	
	mov ax,0x07
	push ax
	push word [livespos]
	mov ax,[lives]
	mov [lives],ax
	push ax
	call printnum
	
; --------------------------------------------------------------------------------------
; subroutine to get keystrokes until esc is pressed 
; --------------------------------------------------------------------------------------
	call hookMyISR	
getKeyPress: 
		
	mov ah,0			;ms dos service routine for keystroke
	int 0x16	

	cmp ah,1			;esc is pressed
	jz quit
   
	cmp ah,0x4D			;right arrow is pressed
	jz rightArrow
	   
	cmp ah,0x4B			;left arrow is pressed
	jz leftArrow
   
	cmp ah,0x48 		;up arrow is pressed
	jz up
   
	cmp ah,0x50			;down arrow is pressed
	jz down
   
	
	jmp getKeyPress
	
	
quit:
	mov ah,0  
	int 16h

exit:
	
	call gameOverBoulder
	
	mov ah,0			;ms dos service routine for keystroke
	int 0x16

	mov ax,0x4c00
	int 0x21


