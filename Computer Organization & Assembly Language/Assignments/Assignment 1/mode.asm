;21L-5218

[org 0x0100]

jmp start

mode: dw 0 ; mode should be found here once the program ends
maxCount: dw 0 ; number of occurrences of mode value
data: dw 60h, 55h, 45h, 50h, 40h, 55h, 35h, 25h, 30h, 55h, 45h, 10h
size: dw 12 ; length of array

	
	
start:
	
	;set mode register to 0 
	mov ax,0
	;set maxCount register to 0
	mov dx,0
	
	

	;initialize i
	mov si,0
	
	;double the size to compare it with si and di since 
	;they are incremented by 2
	shl word [size],1
	for_i:							;outer loop
	
		;terminatino condition i<n
		cmp si,[size]
		ja finish
		
		;set count to 0
		mov cx,0
		
	
		;initialize j 
		mov di,0
		for_j:						;inner loop
		
			cmp di,[size]
			jnbe compareCount
			
			;comparing a[j]==a[i]
			mov bx,[data+di]
			cmp word bx,[data+si]
			je incrementCount	
			
			;increment inner loop if a[j]!=a[i] without incrementing count 
			cmp word bx,[data+si]
			jne incrementInner
		
		
compareCount:
	;comparing count and maxcount  
	;if count<=maxcount the outerloop is incremented
	cmp word cx,[maxCount]
	jbe incrementOuter
	
	;if count>maxCount, maxCount becomes count and that index a[i] becomes mode
	mov [maxCount],cx
	mov dx,[maxCount]
	mov ax,[data+si]
	mov [mode],ax
	jmp incrementOuter
	
	;increment inner loop
incrementInner:
	
	add di,2
	jmp for_j	
	
	;increment count variable and j  of inner loop 
incrementCount:
	add cx,1
	add di,2
	jmp for_j
	
	;incrementOuterLoop
incrementOuter:
	add si,2 
	jmp for_i
	
	
	
	
finish:
		
	
	mov ax, 0x4c00
	int 0x21