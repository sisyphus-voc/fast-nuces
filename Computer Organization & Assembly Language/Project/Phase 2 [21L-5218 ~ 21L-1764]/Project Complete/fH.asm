[org 0x0100]
jmp start1

;-------------------------------------------------------
;input
input: db 'Enter file name : ',0



;-------------------------------------------------------
;filing
filename: 	db 20
			db 0
			times 20 db 0
file_: db 'cave1.txt', 0
data: times 2000 db '0'

;-------------------------------------------------------
;errors		
error1: db 'Error: File not present!',10, 'Press any key to re-enter.',0
error2: db 'Error: Incomplete File',0

fbLength: dw 1600


;-------------------------------------------------------
clr_scr:

	push ax
	push di
	push cx
	
	mov ax,0xb800
	mov es,ax

	mov cx,2000
	mov di,0
	mov ax,0x0720
	
	rep stosw

	pop cx
	pop di
	pop ax
	
	ret

;-------------------------------------------------------
printInputString:
	push bp ;bp+10 --> input query string
			;bp+8 --> str length
			;bp+6 --> row & col num
			;bp+4 -->write mode
	mov bp,sp
	pusha
	
	mov ah,0x13		;bios service number for string printing
	mov dx,[bp+4]	
	mov al,dl
	mov bh,0 ; page number 0
	mov bl,07h ; white on  black attribute
	mov dx,[bp+6] ;0x0aba	dh is row num, dl is col num
	mov cx,[bp+8]	
	push cs
	pop es
	mov bp,[bp+10]	
	int 0x10
	
	popa
	pop bp
	ret 8

;-------------------------------------------------------

printString:
	push bp
	mov bp,sp
	pusha
	
	mov ah,0x13		
	mov dx,[bp+4]	
	mov al,dl
	mov bh,0
	mov bl,7
	mov dx,[bp+6]	
	mov cx,[bp+8]	
	push cs
	pop es
	mov bp,[bp+10]	
	mov bl,0x4
	int 0x10
	
	popa
	pop bp
	ret 8

	
	
;-------------------------------------------------------
error1_:
	call clr_scr
	push error1		;error message 1
	mov ax,	51
	push ax
	mov ax,0x0aba	
	push ax
	mov ax,1		
	push ax
	call printInputString
	mov ah,0	
	int 0x16
	jmp start1
;-------------------------------------------------------
error2_:
	call clr_scr
	push error2		;error message 2
	mov ax,15		
	push ax
	mov ax,0x0aba	
	push ax
	mov ax,1		
	push ax
	call printInputString
	jmp endFilehandling	
;-------------------------------------------------------



start1:
	
	call clr_scr

;-------------------------------------------------------
input_:
	push input		
	mov ax,18	
	push ax
	mov ax,0x0aba	
	push ax
	mov ax,1		
	push ax
	call printInputString
	
	;input

	mov ah, 0ah ;ms dos service for string input in buffer
	mov dx,filename	
	int 21h
;-------------------------------------------------------
	;checking file errors
	check_file:
		; check_default: 
			; mov ax, [filename+1]
			; cmp ax, 0
			; je setdefault
			; xor ax, ax
			
		;if file name is given	
		mov bh,0
		mov bl,[filename+1] ;length of string in buffer
		cmp bl, 0
		je makedefault
		add bl,2
		mov byte[filename+bx],0 ;buffer + 2 +length of the string = last char in buffer
			
		
		
		openfile:
		mov dx,filename+2	;start of string in buffer
		makedefault:
		mov dx, file_
		mov al,0		;read only permission
		mov ah,3dh		;ms-dos service for opening a file
		int 21h		
		;error 1 for wrong file
		jc error1_

		mov cx,1600		
		mov bx,ax		
		mov ah,3fh		
		mov dx,data
		int 21h
		;error 2 for incomplete file
		jc error1_
		cmp ax,1600
		jl error2_

		
	
		
;hide cursor		
mov ah, 01h     
mov cx, 2607h  
int 10h       


;read the file into the data block we have created
mov ah, 3fh
mov bx, ax
mov dx, data
mov cx, 1600
int 21h





;-------------------------------------------------------
;close the file
mov bx, ax
mov ah, 3eh
int 21h
;-------------------------------------------------------
jmp continue
endFilehandling:

	mov ax, 4c00h
	int 21h


	continue: