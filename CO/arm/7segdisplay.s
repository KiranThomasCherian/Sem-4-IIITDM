
.equ cycles, 1000
.equ embesttimermask, 0x7fff
.equ bitrange, 0x0000ffff
.equ SEG_A,0x80
.equ SEG_B,0x40
.equ SEG_C,0x20
.equ SEG_D,0x08
.equ SEG_E,0x04
.equ SEG_F,0x02
.equ SEG_G,0x01
.equ SEG_P,0x10
array:
.word	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G @0
.word	SEG_B|SEG_C@1
.word	SEG_A|SEG_B|SEG_D|SEG_E|SEG_F @2
.word	SEG_A|SEG_B|SEG_C|SEG_D|SEG_F @3
.word	SEG_B|SEG_C|SEG_F|SEG_G @4
.word	SEG_A|SEG_G|SEG_F|SEG_C|SEG_D @5
.word	SEG_A|SEG_G|SEG_E|SEG_D|SEG_C|SEG_F @6
.word	SEG_A|SEG_B|SEG_C @7
.word	SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G @8
.word	SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G @8

Display:
ldr r2,=array
ldr r0,[r2,r3,lsl#2]
swi 0x200
bl timer
add r3,r3,#1
cmp r3,#10
subeq r3,r3,#10 
bal Display



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

