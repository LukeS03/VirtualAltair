#ifndef CPU8080_H
#define CPU8080_H

#include <cstdint>

#define W_REG 0;
#define L_REG 1;

class cpu8080 {
    private:

    //input & output busses
        uint8_t input;
        uint8_t output;

    //16 bit registers:
        uint16_t _PC; //Program Counter
        uint16_t _SP; //Stack Pointer

    //8 bit general-purpose registers
        uint8_t _rA;  //Accumulator
        uint8_t _rB;
        uint8_t _RC;
        uint8_t _rD;
        uint8_t _rE;
        uint8_t _rH;
        uint8_t _rL;

    //8 bit interal registers
        uint8_t _tRZ;
        uint8_t _tRW;


    //CONDITION BITS:
        bool _cS;  //Sign condition bit
        bool _cZ;  //Zero condition bit
        bool _cP;  //Parity condition bit
        bool _cC;  //Carry condition bit
        bool _cAC; //Auxiliary condition bit

    //Signals
        int  _resetActive; //Indicates how many clock cycles the 'RESET' signal has been active.
        bool _resetSignal;
        bool _ready;
        bool bruh;

    public:
        
        // Main Methods
        void executeInstruction(uint8_t * data); //Execute a single instruction.
        void executeCycle(uint8_t * data);       //Execute a single cycle.

        //Signal input methods
        void setReset(bool state);    // Activates the 'RESET' signal.
        void setReady(bool state);    // Toggles the 'READY' signal.
        void setInterrupt(bool state); //Toggles the 'INT' signal.

        //Cycle Methods
        uint8_t * fetchCycle();
        void      memoryRead(uint8_t * address);
}

#endif
