
mov dptr, #table
mov a, #0
movc a, @a+dptr
mov 40h, a

mov a, #1
movc a, @a+dptr
mov 41h, a

mov a, #2
movc a, @a+dptr
mov 42h, a

mov a, #3
movc a, @a+dptr
mov 43h, a

mov a, #4
movc a, @a+dptr
mov 44h, a

mov a, #5
movc a, @a+dptr
mov 45h, a

mov a, 40h
add a, 42h
mov 30h, a

mov a,41h
addc a,43h
mov 31h, a

clr c

mov a, 40h
subb a, 42h
mov 32h, a

mov a,41h
subb a,43h
mov 33h, a

clr c
;23 57 * 12
mov a,44h
mov b,45h
mul ab
mov 34h, a
mov 35h, b

mov a,43h
mov b,45h
mul ab
addc a, 35h
mov 35h, a
mov a,b
mov 36h, b


clr c
mov a, 44h
mov b, 45h
div ab
mov 38h,a
mov 37h,b

table:
DB 90H, 34H, 86H, 23H, 57H,12H

end