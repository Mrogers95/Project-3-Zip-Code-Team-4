#ifndef BLOCK_SEQUENCE_SET_POSTAL_CODE
#define BLOCK_SEQUENCE_SET_POSTAL_CODE

#include "BlockPostalCode.h"
#include "HeaderRecordPostalCodeItem.h"

class BlockSequenceSetPostalCode
{
private:
    BlockPostalCode *headBlock;
    BlockPostalCode *tailBlock;
    int itemCount;

public:
    BlockSequenceSetPostalCode();
    bool add(const HeaderRecordPostalCodeItem &newHeaderPostalCodeItem);

    BlockPostalCode getHead() const;
    int getCurrentSize() const;
};

#include "BlockSequenceSetPostalCode.cpp"
#endif