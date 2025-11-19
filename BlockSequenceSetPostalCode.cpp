#include "BlockSequenceSetPostalCode.h"
#include "BlockPostalCode.h"
#include "HeaderRecordPostalCodeItem.h"

BlockSequenceSetPostalCode::BlockSequenceSetPostalCode() : headBlock(nullptr), itemCount(0) {}

int BlockSequenceSetPostalCode::getCurrentSize() const
{
    return itemCount;
}

BlockPostalCode BlockSequenceSetPostalCode::getHead() const
{
    return *headBlock;
}

// bool BlockSequenceSetPostalCode::add(const HeaderRecordPostalCodeItem &newHeaderPostalCodeItem)
// {
//     BlockPostalCode *newBlock = new BlockPostalCode();
//     newBlock->setBlockItem(newHeaderPostalCodeItem);

//     newBlock->setNext(headBlock);
//     newBlock->setPrev(nullptr);

//     if (headBlock != nullptr)
//     {
//         headBlock->setPrev(newBlock);
//     }

//     headBlock = newBlock;

//     itemCount++;

//     return true;
// }

bool BlockSequenceSetPostalCode::add(const HeaderRecordPostalCodeItem &newHeaderPostalCodeItem)
{
    BlockPostalCode *newBlock = new BlockPostalCode();
    newBlock->setBlockItem(newHeaderPostalCodeItem);

    // newBlock->setNext(headBlock);
    // newBlock->setPrev(nullptr);

    if (headBlock == nullptr || tailBlock == nullptr)
    {
        headBlock = newBlock;
        tailBlock = newBlock;
    }
    else if (headBlock == tailBlock)
    {
        tailBlock = newBlock;
        headBlock->setNext(tailBlock);
        tailBlock->setPrev(headBlock);
    }
    else
    {
        newBlock->setPrev(tailBlock);
        tailBlock->setNext(newBlock);
        tailBlock = newBlock;
    }

    itemCount++;

    return true;
}