#ifndef MEMORYCOLLECTOR_HPP
#define MEMORYCOLLECTOR_HPP

#include "BaseCollector.hpp"


class MemoryCollector: public BaseCollector {
protected:
    std::deque<State> chains;

    State next_state() override {
	    return chains[curr_iter];
	}

public:
    void collect(State iteration_state) override {
    	chains.push_back(iteration_state);
        size++;
    }

    std::deque<State> get_chains() override {return chains;}

    // Destructor and constructor
    virtual ~MemoryCollector() = default;
    // TODO constructor?
};


#endif // MEMORYCOLLECTOR_HPP
