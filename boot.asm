[org 0x7c00]
start:
    mov si, prompt
    call print_string
    mov di, buffer
    call get_input
    
    ; So sánh lệnh
    mov si, buffer
    mov di, cmd_bin
    mov cx, 3
    repe cmpsb
    je do_bin
    mov si, buffer
    mov di, cmd_ver
    mov cx, 8
    repe cmpsb
    je do_ver
    mov si, buffer
    mov di, cmd_clr
    mov cx, 5
    repe cmpsb
    je do_clr
    mov si, buffer
    mov di, cmd_hlp
    mov cx, 4
    repe cmpsb
    je do_hlp
    jmp start

do_bin:
    mov si, buffer + 4
.p: mov al, [si]
    cmp al, 0
    je .done
    mov bx, ax
    mov cx, 8
.b: rol bl, 1
    mov al, '0'
    jnc .o
    mov al, '1'
.o: mov ah, 0x0e
    int 0x10
    loop .b
    mov al, ' '
    int 0x10
    inc si
    jmp .p
.done: call print_nl ; Xuống dòng sau khi in nhị phân
       jmp start

do_ver:
    mov si, msg_v
    call print_string
    jmp start
do_clr:
    mov ax, 0x0003
    int 0x10
    jmp start
do_hlp:
    mov si, msg_h
    call print_string
    jmp start

get_input:
    mov ah, 0x00
    int 0x16
    cmp al, 13
    je .d
    stosb
    mov ah, 0x0e
    int 0x10
    jmp get_input
.d: call print_nl ; Xuống dòng khi người dùng Enter
    ret

print_string:
    lodsb
    cmp al, 0
    je .done
    mov ah, 0x0e
    int 0x10
    jmp print_string
.done: ret

print_nl:
    mov al, 10
    int 0x10
    mov al, 13
    int 0x10
    ret

prompt: db 'SH6> ', 0
cmd_bin: db 'bin', 0
cmd_ver: db 'phienban', 0
cmd_clr: db 'clear', 0
cmd_hlp: db 'help', 0
msg_v: db 'SaHoangOS 6.0 | Dai', 10, 13, 0
msg_h: db 'bin, phienban, clear, help', 10, 13, 0
buffer: times 32 db 0
times 510-($-$$) db 0
dw 0xaa55

