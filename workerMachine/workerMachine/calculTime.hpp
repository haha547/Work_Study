//
//  calculTime.hpp
//  workerMachine
//
//  Created by 徐浩哲 on 2018/9/29.
//  Copyright © 2018 徐浩哲. All rights reserved.
//

#ifndef calculTime_hpp
#define calculTime_hpp

#include <stdio.h>
#include "worker.hpp"
#include "machine.hpp"


class calculTime : public worker, public machine {
public:
    float LaddM;//(l+m)
    float LaddW;//(l+w)
    
    float cycleTime(){
        return ((LaddM)/(LaddW));
    }
    
    float coastPerItem(int machineNum ){
        float coast =(machineNum*(60/(LaddM)))  / ((machineNum*machineCoastPerHour)+workerCoastPerHour);
        return (coast);
    }
    
    float workerIdle(int machineNum){
        float idleTime = LaddM-machineNum*(LaddW);
        return idleTime;
    }
    
    float machineIdle(int machineNum){
        float idleTime = machineNum*(LaddW)- LaddM;
        return idleTime;
    }
};
#endif /* calculTime_hpp */
