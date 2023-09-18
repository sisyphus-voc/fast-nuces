;21L-5218

[org 100h]
jmp start
; reserve space for 10 elements (plus one slot for -1)
; in the example, union would be 6, 9, 3, 8, 1, 2, 7, -1

union: dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
set1: dw 6, 9, 3, 8, 1, -1 ; Note, -1 is NOT a part of set
set2: dw 2, 3, 9, 7, -1

start:
	
	
	mov bx,union
	
	;initializing index register
	mov si,set1
	for_i:
		;checking the end of set1
		cmp word [si],-1
		je copySet2
		
		;moving the values of set1 in ax
		mov ax,[si]
		
		;intializing inner index register with 2nd set
		mov di,set2
		for_j:
			;the end of set2 implies lack of duplicate
			;of element of set1 in set2 hence it is copied 
			;to union array through addToUnion
			cmp word [di],-1
			je addToUnion
			
			;duplicate exites if element of set1 equals element
			;in set2 therefore it is not copied and skipped
			cmp word ax,[di]
			je incrementOuter
			
			;the elements of set2 are incremented if it is neither 
			;duplicate nor last
			cmp word ax,[di]
			jne incrementInner
			

incrementInner:
	add di,2
	jmp for_j
	
incrementOuter:
	add si,2
	jmp for_i
	
	
addToUnion:
	mov dx,[si]
	mov word [bx],dx
	add bx, 2
	add si,2
	
	jmp for_i
	
	
	;the elements of set2 are copied to union
copySet2:
	mov di,set2
	for3:
		;loop till the last element
		cmp word [di],-1
		je addMinusOne
		
		;element copied from set2 to union 
		mov dx,[di]
		mov word [bx],dx
		
		;increment union and set2 index
		add bx,2
		add di,2
		
		jmp for3
		m1 

addMinusOne:
	add bx, 2
	mov dx,-1
	mov word [bx],dx
	
	
	
	mov ax, 0x4c00
	int 0x21
	
