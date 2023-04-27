start:
 mov dptr, #table
 mov a, #0
 movc a, @a+dptr
 mov 40H, a
 
 mov a, #1
 movc a, @a+dptr
 mov 41H, a
 
 mov a, #2
 movc a, @a+dptr
 mov 42H, a
 
 mov a, #3
 movc a, @a+dptr
 mov 43H, a
 
 mov a, #4
 movc a, @a+dptr
 mov 44H, a
 
 mov a, #5
 movc a, @a+dptr
 mov 45H, a



mov r0, #40H
L1:
	mov a, r0
	mov r1, a
	inc r1

	L2:
		mov a, @r1
		
		
		subb a,@r0
		jc swp
		jnc no
		swp:
			mov a, @r1
			mov b, @r0
			mov @r1, b
			mov @r0, a
		
		no:
		inc r1
		cjne r1, #46H, L2
		
	inc r0
	cjne r0, #45H, L1


	
 table:
 DB 10H, 22H, 17H, 20H, 11H, 01H
	 
end