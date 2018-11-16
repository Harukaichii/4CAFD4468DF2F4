#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include <string>
#include "AbstractLevel.h"
class LevelFour : public AbstractLevel {
    public:
        // visitor 
        void generateBlock(BlockI &b) override;
        void generateBlock(BlockJ &b) override;
        void generateBlock(BlockL &b) override;
        void generateBlock(BlockO &b) override;
        void generateBlock(BlockS &b) override;
        void generateBlock(BlockT &b) override;
        void generateBlock(BlockZ &b) override;
};
#endif