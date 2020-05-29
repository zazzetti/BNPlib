#ifndef BASECOLLECTOR_HPP
#define BASECOLLECTOR_HPP

#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include "output.pb.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/util/delimited_message_util.h>


//! Abstract base class for a collector that contains a chain in Protobuf form

//! This is an abstract base class for a structure called data collector, or
//! collector for short. A collector is meant to store the state of a Markov
//! chain at all iterations, composed of the allocations and the unique values
//! vectors. These values are stored in classes built via the Google Protocol
//! Buffers library, also known as Protobuf.

class BaseCollector {
protected:
    //! Current size of the chain
    unsigned int size = 0;
    //! Read cursor that indicates the current iteration
    unsigned int curr_iter = -1;

    //! Reads the next state, based on the curr_iter curson
    virtual State next_state() = 0;

public:
    // DESTRUCTOR AND CONSTRUCTORS
    virtual ~BaseCollector() = default;
    BaseCollector() = default;

    //! Initializes collector
    virtual void start() = 0;
    //! Closes collector
    virtual void finish() = 0;

    //! Reads the next state and advances the cursor by 1
    State get_next_state(){
        curr_iter++;
        if(curr_iter >= size){
            throw std::out_of_range("Error: curr_iter > size in collector");
        }
        return next_state();
    }

    //! Writes the given state to the collector
    virtual void collect(State iter_state) = 0;

    // GETTERS AND SETTERS
    //! Returns i-th state in the collector
    virtual State get_state(unsigned int i) = 0;
    //! Returns the whole chain in form of a deque of States
    virtual std::deque<State> get_chain() = 0;

    unsigned int get_size() const {return size;}
};


#endif // BASECOLLECTOR_HPP