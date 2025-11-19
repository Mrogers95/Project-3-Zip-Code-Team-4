#include "BlockPostalCode.h"
#include "HeaderRecordPostalCodeItem.h"

BlockPostalCode::BlockPostalCode() : prev(nullptr), next(nullptr) {}

BlockPostalCode::BlockPostalCode(const HeaderRecordPostalCodeItem &item) : data(item), prev(nullptr), next(nullptr) {}

BlockPostalCode::BlockPostalCode(const HeaderRecordPostalCodeItem &item, BlockPostalCode *prevBlock, BlockPostalCode *nextBlock) : data(item), prev(prevBlock), next(nextBlock) {}

void BlockPostalCode::setBlockItem(const HeaderRecordPostalCodeItem &item)
{
    data = item;
}

void BlockPostalCode::setPrev(BlockPostalCode *prevBlock)
{
    prev = prevBlock;
}

void BlockPostalCode::setNext(BlockPostalCode *nextBlock)
{
    next = nextBlock;
}

HeaderRecordPostalCodeItem BlockPostalCode::getBlockItem() const
{
    return data;
}

BlockPostalCode *BlockPostalCode::getPrev() const
{
    return prev;
}

BlockPostalCode *BlockPostalCode::getNext() const
{
    return next;
}