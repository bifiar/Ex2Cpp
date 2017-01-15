//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_FIRSTFIT_H
#define EX2CPP_FIRSTFIT_H


#include "FitAlgo.h"

class FirstFit : public FitAlgo {
public:
    char *searchFreeMemAlgo(size_t memSizeBit) override;

};

#endif //EX2CPP_FIRSTFIT_H
