/*******************************************************************************
* Include
*******************************************************************************/
#include "allocate.h"
#include <stdlib.h>

/*******************************************************************************
* Function
*******************************************************************************/

bool allocate10Bytes(uint8_t* outPtr) {
    if (outPtr == NULL) {
        return false;
    }

    uint8_t* tempPtr = (uint8_t*)malloc(10 * sizeof(uint8_t));
    if (tempPtr == NULL) {
        return false;
    }
    /*
    * cap phat bo nho dong cho con tro tam thoi temp
    */

    *(uint8_t**)outPtr = tempPtr;
    /*
    * gan con tro temp duoc cap phat cho outPtr. ep kieu truoc khi gan de khong bi loi
    */
    return true;
}
/*******************************************************************************
* EOF
*******************************************************************************/