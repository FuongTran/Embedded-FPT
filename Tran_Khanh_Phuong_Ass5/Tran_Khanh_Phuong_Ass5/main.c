/*===Author: Tran Khanh Phuong===*/
#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*******************************************************************************
* Define
*******************************************************************************/
#define REG_BIT_SET32(add, n) (*(volatile uint32_t *)(add) |= (1U << (n)))

#define REG_BIT_CLEAR32(add, n) (*(volatile uint32_t *)(add) &= ~(1U << (n)))

#define SWAP_BYTE32(add) (*(volatile uint32_t *)(add) = \
                          (((*(volatile uint32_t *)(add) & 0x000000FFU) << 24) | \
                           ((*(volatile uint32_t *)(add) & 0x0000FF00U) << 8) | \
                           ((*(volatile uint32_t *)(add) & 0x00FF0000U) >> 8) | \
                           ((*(volatile uint32_t *)(add) & 0xFF000000U) >> 24)))

#define SWAP_BYTE16(add) (*(volatile uint16_t *)(add) = \
                          (((*(volatile uint16_t *)(add) & 0x00FFU) << 8) | \
                           ((*(volatile uint16_t *)(add) & 0xFF00U) >> 8)))
/*
    Su dung bien volatile khi compiler se focus thang vao phan cung, qua trinh optimize se khong bi bo qua neu ngat hay bien k thay doi
*/


/*******************************************************************************
* Main
*******************************************************************************/
int main() {
    uint32_t a = 0x12345678;
    uint16_t b = 0x1234;
    uint32_t c = 0;

    printf("Original a: 0x%X\n", a);
    SWAP_BYTE32(&a);
    printf("Swapped a: 0x%X\n", a);

    printf("Original b: 0x%X\n", b);
    SWAP_BYTE16(&b);
    printf("Swapped b: 0x%X\n", b);

    printf("Original c: 0x%X\n", c);
    REG_BIT_SET32(&c, 2);
    printf("After setting bit 2, c: 0x%X\n", c);

    REG_BIT_CLEAR32(&c, 2);
    printf("After clearing bit 2, c: 0x%X\n", c);

    return 0;
}
/*******************************************************************************
* EOF
*******************************************************************************/
