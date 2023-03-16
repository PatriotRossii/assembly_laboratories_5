global IntegerShift_

IntegerShift_:
    ; edi for 1st argument, esi for 2nd argument
    ; rdx for 3rd argument, rcx for 4rd argument

    mov r10, rdx
    mov r11, rcx

    xor eax, eax ; Код возврата в случае ошибки
    cmp esi, 31 ; Сравнение count и 31
    ja end ; Переход, если count > 31

LeftShift:
    mov eax, edi ; eax = a

    mov cl, sil
    shl eax, cl; eax = a << count
    
    mov [r10], eax ; сохранение результатов

RightShift:
    mov eax, edi
    shr eax, cl ; eax = a >> count
    mov [r11], eax ; сохранение результата

    mov eax, 1 ; возвращаемый код успешного выполнения
end:
    ret ; Возврат в вызывающую функцию