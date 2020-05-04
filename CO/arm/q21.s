fname:    .asciz "test2.txt"
fhandle:    .word  0
ldr r0,=fname    
mov r1,#0	 
swi 0X66		 
ldr r1,=fhandle   
str r0, [r1] 	
 ldr r0,=fhandle
ldr r0,[r0]
ldr r1,=texts
mov r2,#80
swi 0x6a
texts: .skip 80

ldr r0,=texts

swi 0x02
ldr r0,=fhandle
ldr r0,[r0]

swi 0x68
swi 0x11

