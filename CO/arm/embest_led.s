.equ cycles, 1000
.equ embesttimermask, 0x7fff
.equ bitrange, 0x0000ffff

led:
mov r0,	#0x02
swi 0x201
bl timer
mov r0,#0x01
swi 0x201
bl timer
bal led


timer:

ldr r8,=bitrange
ldr r7,=embesttimermask
ldr r10,=cycles
SWI 0x6d                 @SWI_GetTicks
mov r1,r0 
and r1,r1,r7

repeat:
SWI 0x6d                @SWI_GetTicks
mov r2,r0 
and r2,r2,r7 
cmp r2,r1 
bge simpletime
sub r9,r8,r1
add r9,r9,r2
bal CheckInt

simpletime:
sub r9,r2,r1 
CheckInt:
cmp r9,r10 
blt repeat
bx lr

