fname:    .asciz "test2.txt"
fhandle:    .word  0
ldr r0,=fname    
mov r1,#1	 
swi 0x66		 
ldr r1,=fhandle   
str r0, [r1] 	
 
Text: .asciz "kiran!\n"  
ldr r0,=fhandle
ldr r0,[r0]
ldr r1,=Text
swi 0x69

ldr r0,=fhandle
ldr r0,[r0]


swi 0x68

swi 0x11

