fname:    .asciz "strings2.txt"
fhandle:    .word  0
ldr r0,=fname    
mov r1,#0	 
swi 0X66		 
ldr r1,=fhandle   
str r0, [r1] 	
ldr r0,=fhandle
ldr r0,[r0]
text1: .skip 80
ldr r1,=text1
mov r2,#80
swi 0x6a

ldr r0,=fhandle
ldr r0,[r0]
text2: .skip 80
ldr r1,=text2
mov r2,#80
swi 0x6a


mov r4,#0
mov r5,#0;
ldr r0,=text1
ldr r1,=text2

lcount:
ldrb r2,[r0],#1;
ldrb r3,[r1],#1;
cmp r2,#0
addne r4,r4,#1;
cmp r3,#0
addne r5,r5,#1;
add r3,r2,r3
cmp r3,#0
bne lcount

cmp r4,r5
bne notsame
beq lsame

notsame:
notequal: .asciz "Notsame"
ldr r0,=notequal
swi 0x02
bal exitcmd


lsame:
ldr r0,=text1
ldr r1,=text2
comp:

ldrb r2,[r0],#1
ldrb r3,[r1],#1
cmp r2,r3
bne notsame
cmp r2,#0
bne comp
strsame: .asciz "aresame"
ldr r0,=strsame
swi 0x02
bal exitcmd

exitcmd:
ldr r0,=fhandle
ldr r0,[r0]
swi 0x68
swi 0x11


