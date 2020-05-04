.equ cycles, 10000
.equ embesttimermask, 0x7fff
.equ bitrange, 0x0000ffff

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
swi 0x11
.end