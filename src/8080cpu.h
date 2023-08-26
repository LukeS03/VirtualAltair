#ifndef 8080CPU_H
#define 8080CPU_H

#include <cstdint>

class 8080cpu {
    private:

    //16 bit REGISTERS:
        uint16_t _PC; //Program Counter
        uint16_t _SP; //Stack Pointer

    //8 bit REGISTERS
        uint8_t _rA;  //Accumulator
        uint8_t _rB;
        uint8_t _RC;
        uint8_t _rD;
        uint8_t _rE;
        uint8_t _rH;
        uint8_t _rL;


    //CONDITION BITS:
        bool cS;  //Sign condition bit
        bool cZ;  //Zero condition bit
        bool cP;  //Parity condition bit
        bool cC;  //Carry condition bit
        bool cAC; //Auxiliary condition bit

    public:
        
        void execute(uint8_t * memory, uint64 * clockTicks); //Execute a single instruction.
}

#endif
