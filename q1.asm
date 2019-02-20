.model small
.stack 64
 .data
 string db 'hello world'
 string2 db 11 dup('*'),'$'
 .code
 main proc far
 mov ax,@data
 mov ds,ax
 mov es,ax
 lea si,string
 lea di,string2
 mov cx,11
 a20:
 mov al,[si]
 mov [di],al
 inc si
 inc di
 dec cx
 jnz a20
 mov ah,09h
 lea dx,string2
 int 21h
 mov ah,4ch
 int 21h
 main endp
 end main
 
