// The generated block sequence set data will have the following format
// HeaderRecord + " " + Data + " " + Link to preceding block (zip code) + " " + Link to succeeding block (zip code)

#include <string>
#include "BlockPostalCode.h"
#include "BlockSequenceSetPostalCode.h"
#include "readHeaderPostalCodetoBSSBuffer.cpp"
#include <fstream>

using namespace std;

int main()
{
    string fileName = "us_postal_codes_length_indicated_header_record.txt";

    BlockSequenceSetPostalCode myBlockSequenceSetPostalCode;

    inputDatatoBlockSequenceSet(myBlockSequenceSetPostalCode, fileName);

    ofstream outputFile("block_sequence_set_data.txt");

    BlockPostalCode myBlock = myBlockSequenceSetPostalCode.getHead();

    // Write first block
    string blockRecord = to_string(myBlock.getBlockItem().getRecordLength()) + " " + myBlock.getBlockItem().getData() + " NULL " + to_string(myBlock.getNext()->getBlockItem().getZip());

    outputFile << blockRecord << endl;

    myBlock = *myBlock.getNext();

    // Loop through middle blocks
    while (myBlock.getNext() != nullptr)
    {
        blockRecord = to_string(myBlock.getBlockItem().getRecordLength()) + " " + myBlock.getBlockItem().getData() + " " + to_string(myBlock.getPrev()->getBlockItem().getZip()) + " " + to_string(myBlock.getNext()->getBlockItem().getZip());

        outputFile << blockRecord << endl;

        myBlock = *myBlock.getNext();
    }

    // Write last block
    blockRecord = to_string(myBlock.getBlockItem().getRecordLength()) + " " + myBlock.getBlockItem().getData() + " " + to_string(myBlock.getPrev()->getBlockItem().getZip()) + " NULL";

    outputFile << blockRecord << endl;

    outputFile.close();

    return 0;
}