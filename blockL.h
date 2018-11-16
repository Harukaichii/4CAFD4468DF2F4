#ifndef _BLOCK_L_
#define _BLOCK_L_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockL : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockL();
        // we will check if it's movable in the player class
        // this means if we call the following method,
        // the block if always movable
        // remeber to draw in the following method
        void moveLeft() override;
        void moveRight() override;
        void moveDown() override;
        void rotateClockwise() override;
        void rotateCounterClockwise() override;
        // accept for visitor pattern
        void accept(AbstractLevel &level) override;
        // simple implementation
        // {
        //      level.generateBlock(this);
        // }
};
#endif